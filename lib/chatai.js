'use strict';

const https = require('https');

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

const BASE = 'https://aionix-eobk.onrender.com';
const APIKEY = process.env.AIONIX_API_KEY || 'aionix_secret_key_change_this';

function request(path, body) {
  return new Promise((resolve, reject) => {

    const data = JSON.stringify(body);

    const options = {
      hostname: 'aionix-eobk.onrender.com',
      path,
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        'x-api-key': APIKEY,
        'Content-Length': Buffer.byteLength(data)
      }
    };

    const req = https.request(options, (res) => {

      let raw = '';

      res.on('data', chunk => raw += chunk);

      res.on('end', () => {

        try {

          const json = JSON.parse(raw);

          if (!json.success)
            return reject(new Error(json.error || 'API Error'));

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

async function chatai(prompt, options = {}) {

  if (!prompt)
    throw new Error('Prompt is required');

  const model = options.model || 1;

  if (!MODELS[model])
    throw new Error('Invalid model. Choose 1-8');

  const result = await request('/api/chat', {
    prompt,
    model
  });

  return {
    response: result.response,
    model: result.model,
    model_id: result.model_id,
    words: result.words,
    characters: result.characters,
    timestamp: result.timestamp
  };

}

chatai.models = MODELS;

module.exports = chatai;