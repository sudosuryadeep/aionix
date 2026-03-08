
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

async function imgtotextai(prompt, options = {}) {
  if (!prompt) throw new Error('Prompt is required');
  const encoded = encodeURIComponent(prompt);
  
  // Primary API
  const primaryUrl = `https://nexeoimage.vercel.app/apiv1/image?text=${encoded}`;
  // Fallback API  
  const fallbackUrl = `https://imagexnexu.vercel.app/?prompt=${encoded}`;

  try {
    const data = await fetchUrl(primaryUrl);
    if (data && data.url) {
      return {
        url: data.url,
        prompt: prompt,
        source: 'primary'
      };
    }
    throw new Error('Primary API failed');
  } catch(e) {
    // Fallback
    const data = await fetchUrl(fallbackUrl);
    let result;
    try {
      result = typeof data.result === 'string' ? JSON.parse(data.result) : data.result;
    } catch(e) {
      throw new Error('Both APIs failed');
    }
    if (!result?.data?.url) throw new Error('Image generation failed');
    return {
      url: result.data.url,
      filename: result.data.filename,
      size: result.data.size,
      expired: result.data.expired,
      prompt: prompt,
      source: 'fallback'
    };
  }
}

module.exports = imgtotextai;
