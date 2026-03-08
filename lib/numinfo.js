
'use strict';

const https = require('https');

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

// Rate limiting
const callLog = {};
const LIMIT = 5; // 5 calls per number per day

function checkLimit(number) {
  const today = new Date().toDateString();
  const key = `${number}_${today}`;
  callLog[key] = (callLog[key] || 0) + 1;
  if (callLog[key] > LIMIT) throw new Error(`Daily limit reached for this number (${LIMIT}/day)`);
}

async function numinfo(number) {
  if (!number) throw new Error('Number is required');
  const cleaned = String(number).replace(/\D/g, '');
  if (cleaned.length < 10) throw new Error('Invalid number format');

  checkLimit(cleaned);

  const url = `https://nmdllpezcocquamhgpmb.supabase.co/functions/v1/lookup?number=${cleaned}`;
  const data = await fetchUrl(url);

  if (!data.result || !data.result.length) throw new Error('No info found for this number');

  const info = data.result[0];

  // Only return basic info — no sensitive data
  return {
    name: info.name || null,
    fname: info.fname || null,
    circle: info.circle || null
  };
}

module.exports = numinfo;
