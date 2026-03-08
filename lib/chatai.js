
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

function fetchUrl(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
      let data = '';
      res.on('data', chunk => data += chunk);
      res.on('end', () => {
        try { resolve(JSON.parse(data)); }
        catch(e) { reject(new Error('Invalid JSON response')); }
      });
    }).on('error', reject);
  });
}

async function chatai(prompt, options = {}) {
  if (!prompt) throw new Error('Prompt is required');
  const model = options.model || 1;
  if (!MODELS[model]) throw new Error(`Invalid model. Choose 1-8`);
  const encoded = encodeURIComponent(prompt);
  const url = `https://gptxnexu.vercel.app/mode=${model}/?txt=${encoded}`;
  const data = await fetchUrl(url);
  if (!data.success) throw new Error('API request failed');
  return {
    response: data.response,
    model: data.model,
    model_id: data.model_id,
    words: data.words,
    characters: data.characters,
    timestamp: data.timestamp
  };
}

chatai.models = MODELS;
module.exports = chatai;
