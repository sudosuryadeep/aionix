'use strict';

const express  = require('express');
const router   = express.Router();
const https    = require('https');

function fetchUrl(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
      let data = '';
      res.on('data', c => data += c);
      res.on('end', () => {
        try { resolve(JSON.parse(data)); }
        catch(e) { reject(new Error('Invalid JSON')); }
      });
    }).on('error', reject);
  });
}

// POST /api/ai/chat
router.post('/chat', async (req, res) => {
  try {
    const { prompt, model = 1 } = req.body;
    if (!prompt) return res.status(400).json({ error: 'Prompt required' });
    const url = `https://gptxnexu.vercel.app/mode=${model}/?txt=${encodeURIComponent(prompt)}`;
    const data = await fetchUrl(url);
    res.json({
      response:   data.response,
      model:      data.model,
      model_id:   data.model_id,
      words:      data.words,
      characters: data.characters,
      timestamp:  data.timestamp
    });
  } catch(e) {
    res.status(500).json({ error: e.message });
  }
});

// POST /api/ai/image
router.post('/image', async (req, res) => {
  try {
    const { prompt } = req.body;
    if (!prompt) return res.status(400).json({ error: 'Prompt required' });

    // Primary
    try {
      const url  = `https://nexeoimage.vercel.app/apiv1/image?text=${encodeURIComponent(prompt)}`;
      const data = await fetchUrl(url);
      if (data?.url) return res.json({ url: data.url, prompt, source: 'primary' });
    } catch(e) {}

    // Fallback
    const url2  = `https://imagexnexu.vercel.app/?prompt=${encodeURIComponent(prompt)}`;
    const data2 = await fetchUrl(url2);
    const result = typeof data2.result === 'string' ? JSON.parse(data2.result) : data2.result;
    if (!result?.data?.url) throw new Error('Image generation failed');
    res.json({
      url:      result.data.url,
      filename: result.data.filename,
      size:     result.data.size,
      expired:  result.data.expired,
      prompt,
      source: 'fallback'
    });
  } catch(e) {
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
    const url  = `https://nmqadgpmb.supabase.co/functions/v1/lookup?number=${cleaned}`;
    const data = await fetchUrl(url);
    if (!data.result?.length) return res.status(404).json({ error: 'No info found' });
    const info = data.result[0];
    res.json({ name: info.name || null, fname: info.fname || null, circle: info.circle || null });
  } catch(e) {
    res.status(500).json({ error: e.message });
  }
});

// GET /api/ai/models
router.get('/models', (req, res) => {
  res.json({
    1: '🦙 Llama 3.3 70B Pro',
    2: '🚀 DeepAI Pro Max',
    3: '💎 DeepSeek V3 Ultra',
    4: '⚡ Gemma 3B Turbo',
    5: '🌪️ Mistral 3.2 Pro',
    6: '🤖 Claude 3.5 Sonnet',
    7: '🔬 GPT-4o Mini',
    8: '🎨 Creative AI Max'
  });
});

module.exports = router;