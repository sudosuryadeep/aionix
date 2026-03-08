'use strict';

const express = require('express');
const router  = express.Router();
const https   = require('https');

const API_HOST = 'aionix-eobk.onrender.com';
const APIKEY   = process.env.AIONIX_API_KEY || 'aionix_secret_key_change_this';

const MODELS = {
  1: '🦙 Llama 3.3 70B Pro',
  2: '🚀 DeepAI Pro Max',
  3: '💎 DeepSeek V3 Ultra',
  4: '⚡ Gemma 3B Turbo',
  5: '🌪️ Mistral 3.2 Pro',
  6: '🤖 Claude 3.5 Sonnet',
  7: '🔬 GPT-4o Mini',
  8: '🎨 Creative AI Max'
};

function request(path, body) {
  return new Promise((resolve, reject) => {
    const data = JSON.stringify(body);
    const options = {
      hostname: API_HOST,
      path,
      method: 'POST',
      headers: {
        'Content-Type':   'application/json',
        'x-api-key':      APIKEY,
        'Content-Length': Buffer.byteLength(data)
      }
    };

    const req = https.request(options, (res) => {
      let raw = '';
      res.on('data', chunk => raw += chunk);
      res.on('end', () => {
        try {
          const json = JSON.parse(raw);
          if (!json.success) return reject(new Error(json.error || 'API Error'));
          resolve(json.data);
        } catch {
          reject(new Error('Invalid JSON response'));
        }
      });
    });

    req.on('error', reject);
    req.write(data);
    req.end();
  });
}

// POST /api/ai/chat
router.post('/chat', async (req, res) => {
  try {
    const { prompt, model = 1 } = req.body;
    if (!prompt) return res.status(400).json({ error: 'Prompt required' });
    if (!MODELS[model]) return res.status(400).json({ error: 'Invalid model. Choose 1-8' });

    const data = await request('/api/chat', { prompt, model });
    res.json({
      response:   data.response,
      model:      data.model,
      model_id:   data.model_id,
      words:      data.words,
      characters: data.characters,
      timestamp:  data.timestamp
    });
  } catch (e) {
    res.status(500).json({ error: e.message });
  }
});

// POST /api/ai/image
router.post('/image', async (req, res) => {
  try {
    const { prompt } = req.body;
    if (!prompt) return res.status(400).json({ error: 'Prompt required' });

    const data = await request('/api/image', { prompt });
    res.json({
      url:      data.url,
      prompt,
      filename: data.filename || null,
      size:     data.size     || null,
      expired:  data.expired  || null
    });
  } catch (e) {
    res.status(500).json({ error: e.message });
  }
});

// POST /api/ai/numinfo
router.post('/numinfo', async (req, res) => {
  try {
    const { number } = req.body;
    if (!number) return res.status(400).json({ error: 'Number required' });

    const cleaned = String(number).replace(/\D/g, '');
    if (cleaned.length < 10) return res.status(400).json({ error: 'Invalid number' });

    const data = await request('/api/numinfo', { number: cleaned });
    res.json({
      name:    data.name    || null,
      fname:   data.fname   || null,
      circle:  data.circle  || null,
      address: data.address || null,
      alt:     data.alt     || null,
      id:      data.id      || null
    });
  } catch (e) {
    res.status(500).json({ error: e.message });
  }
});

// GET /api/ai/models
router.get('/models', (req, res) => {
  res.json(MODELS);
});

module.exports = router;