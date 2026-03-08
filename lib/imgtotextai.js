'use strict';

const https = require('https');

const API_HOST = 'aionix-eobk.onrender.com';
const API_PATH = '/api/image';

const APIKEY = process.env.AIONIX_API_KEY || 'aionix_secret_key_change_this';

function request(body) {
  return new Promise((resolve, reject) => {

    const data = JSON.stringify(body);

    const options = {
      hostname: API_HOST,
      path: API_PATH,
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
            return reject(new Error(json.error || 'API error'));

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

async function imgtotextai(prompt) {

  if (!prompt)
    throw new Error('Prompt is required');

  const result = await request({
    prompt
  });

  return {
    url: result.url,
    prompt: prompt,
    filename: result.filename || null,
    size: result.size || null,
    expired: result.expired || null
  };

}

module.exports = imgtotextai;