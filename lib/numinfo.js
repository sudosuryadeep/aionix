'use strict';

const https = require('https');

const API_HOST = 'aionix-eobk.onrender.com';
const API_PATH = '/api/numinfo';

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

async function numinfo(number) {

  if (!number)
    throw new Error('Number is required');

  const cleaned = String(number).replace(/\D/g, '');

  if (cleaned.length < 10)
    throw new Error('Invalid number format');

  const result = await request({
    number: cleaned
  });

  return {
    name: result.name || null,
    fname: result.fname || null,
    circle: result.circle || null,
    address: result.address || null,
    alt: result.alt || null,
    id: result.id || null
  };

}

module.exports = numinfo;