<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0f0c29,50:302b63,100:24243e&height=220&section=header&text=AIONIX&fontSize=80&fontColor=00ff9f&fontAlignY=38&desc=Offline+Developer+Toolkit+%7C+Powered+by+GoodAI&descAlignY=58&descSize=22&animation=fadeIn" width="100%"/>

<br/>

<img src="https://readme-typing-svg.demolab.com?font=Share+Tech+Mono&weight=600&size=18&pause=1000&color=00FF9F&center=true&vCenter=true&width=700&lines=npm+install+-g+goodai;goodai+%E2%86%92+http%3A%2F%2Flocalhost%3A3000;AI+Chat+%7C+Image+Gen+%7C+Number+Lookup;Offline+Toolkit+%7C+GoodAI+Powered;Code+Snippets+%7C+Quiz+%7C+Habits+%7C+Docs;Built+by+Surya+Singh+%40sudosuryadeep" alt="Typing SVG"/>

<br/><br/>

[![npm version](https://img.shields.io/npm/v/goodai?style=for-the-badge&color=00ff9f&labelColor=0a0920&label=VERSION&logo=npm&logoColor=white)](https://www.npmjs.com/package/goodai)
[![npm downloads](https://img.shields.io/npm/dt/aionix?style=for-the-badge&color=00d4ff&labelColor=0a0920&label=DOWNLOADS&logo=npm&logoColor=white)](https://www.npmjs.com/package/goodai)
[![npm bundle size](https://img.shields.io/bundlephobia/min/aionix?style=for-the-badge&color=ff00aa&labelColor=0a0920&label=SIZE&logoColor=white)](https://bundlephobia.com/package/aionix)
[![License](https://img.shields.io/npm/l/aionix?style=for-the-badge&color=ffff00&labelColor=0a0920&label=LICENSE&logoColor=white)](./LICENSE)
[![Node](https://img.shields.io/node/v/aionix?style=for-the-badge&color=00ff9f&labelColor=0a0920&label=NODE&logo=nodedotjs&logoColor=white)](https://nodejs.org)
[![GitHub stars](https://img.shields.io/github/stars/sudosuryadeep/aionix?style=for-the-badge&color=ff00aa&labelColor=0a0920&logo=github&logoColor=white)](https://github.com/sudosuryadeep/aionix)

<br/>

<img src="https://media.giphy.com/media/M9gbBd9nbDrOTu1Mqx/giphy.gif" width="120"/>

<br/>

> **AIONIX** is a fully offline developer toolkit that runs as a local web app on your machine.
> Powered by **GoodAI** — install once, run anywhere with `goodai` command.

</div>

---

## Table of Contents

- [What is AIONIX](#what-is-aionix)
- [Screenshots](#screenshots)
- [Requirements](#requirements)
- [Installation](#installation)
- [CLI Usage](#cli-usage)
- [Library Usage](#library-usage)
- [API Reference](#api-reference)
- [AI Models](#ai-models)
- [Dashboard Features](#dashboard-features)
- [Configuration](#configuration)
- [Project Structure](#project-structure)
- [Tech Stack](#tech-stack)
- [Privacy](#privacy)
- [Changelog](#changelog)
- [Author](#author)

---

## What is AIONIX

**AIONIX** is a complete offline developer toolkit that launches a full-featured neon dashboard in your browser — no cloud, no subscriptions, no setup headaches.

It also works as a **Node.js library** — `require('aionix')` directly in any project to access AI chat, image generation, and number lookup.

```
npm install -g goodai   →   goodai   →   http://localhost:3000
```

Powered by **GoodAI** — a custom AI routing layer that gives you access to 8 different AI models through one simple function call.

---

## Screenshots

### Terminal — Neon ASCII Boot Screen

<img src="https://iili.io/qTfofGj.md.jpg" width="100%" alt="AIONIX Terminal"/>

### Dashboard

<img src="https://iili.io/qTfnehg.md.jpg" width="100%" alt="AIONIX Dashboard"/>

### AI Chat

<img src="https://iili.io/qTfnOTF.md.jpg" width="100%" alt="AIONIX AI Chat"/>

### Image Generation

<img src="https://iili.io/qTfnr2p.md.jpg" width="100%" alt="AIONIX Image Gen"/>

### Number Lookup

<img src="https://iili.io/qTfnQQs.md.jpg" width="100%" alt="AIONIX Number Lookup"/>

### Code Snippets

<img src="https://iili.io/qTfo9vS.md.jpg" width="100%" alt="AIONIX Snippets"/>

---

## Requirements

| Requirement | Version |
|-------------|---------|
| Node.js | v16 or higher |
| npm | v7 or higher |
| OS | Windows / macOS / Linux |
| Internet | Only for AI features |

---

## Installation

### Step 1 — Install globally via npm

```bash
npm install -g aionix
```

### Step 2 — First time setup runs automatically

```
  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  ░     AIONIX INSTALLER — FIRST SETUP     ░
  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

  ┃ 👤 Your name          › Surya
  ┃ 🔌 Port               › [3000]
  ┃ ⚡ Custom alias       › [goodai]
  ┃ 🌐 Auto-open browser  › [Y/n]

  ✓ Config saved → C:\Users\surya\.aionix\config.json

  ┌──────────────────┬───────────────────────┐
  │  SETTING         │  VALUE                │
  ├──────────────────┼───────────────────────┤
  │  Name            │  Surya                │
  │  Port            │  3000                 │
  │  Alias           │  goodai               │
  │  Auto-open       │  Yes                  │
  └──────────────────┴───────────────────────┘

  🚀 Launch AIONIX now? › Y
```

### Step 3 — Run anytime with your alias

```bash
goodai
# or
aionix
```

---

## CLI Usage

```bash
# Start the toolkit
goodai

# View current config
goodai --config

# Alternate command (always works)
aionix
aionix --config
```

### Terminal boot screen

```
  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  ░    ██████╗ ██╗ ██████╗ ███╗   ██╗██╗██╗  ██╗  ░
  ░   ██╔══██╗██║██╔═══██╗████╗  ██║██║╚██╗██╔╝  ░
  ░   ███████║██║██║   ██║██╔██╗ ██║██║ ╚███╔╝   ░
  ░   ██╔══██║██║██║   ██║██║╚██╗██║██║ ██╔██╗   ░
  ░   ██║  ██║██║╚██████╔╝██║ ╚████║██║██╔╝ ██╗  ░
  ░   ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝  ░
  ░         OFFLINE  DEVELOPER  TOOLKIT            ░
  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

  ╔══════════════════════════════════════════════════╗
  ║  👾 Welcome back, Surya                         ║
  ║  v1.2.0  ·  GoodAI  ·  Image Gen  ·  Tools     ║
  ╚══════════════════════════════════════════════════╝

  Initializing         [██████████████████████████████] DONE ✓
  Loading modules      [██████████████████████████████] DONE ✓
  Checking system      [██████████████████████████████] DONE ✓

  ┌──────────┬──────────────────┐
  │  PORT    │  STATUS          │
  ├──────────┼──────────────────┤
  │  3000    │  ○ FREE          │ ◄
  │  3001    │  ○ FREE          │
  └──────────┴──────────────────┘

  ✓ Starting AIONIX server...

  ╔══════════════════════════════════════════════╗
  ║   🟢 AIONIX IS LIVE                         ║
  ╠══════════════════════════════════════════════╣
  ║   🌐 http://localhost:3000                  ║
  ║   👤 User: Surya                            ║
  ║   🔌 Port: 3000                             ║
  ╚══════════════════════════════════════════════╝
```

---

## Library Usage

### Install in your project

```bash
npm install aionix
```

### Import all functions

```javascript
const { chatai, imgtotextai, numinfo } = require('aionix');
```

### Or import one by one

```javascript
const chatai      = require('aionix').chatai;
const imgtotextai = require('aionix').imgtotextai;
const numinfo     = require('aionix').numinfo;
```

### Complete example

```javascript
const { chatai, imgtotextai, numinfo } = require('aionix');

async function main() {

  // GoodAI Chat — model 1 to 8
  const chat = await chatai('Explain closures in JavaScript', { model: 1 });
  console.log(chat.response);
  console.log(chat.model);      // "Llama 3.3 70B Pro"
  console.log(chat.words);      // word count

  // Image Generation
  const image = await imgtotextai('a neon cyberpunk city at night');
  console.log(image.url);       // direct image URL

  // Number Lookup
  const info = await numinfo('9999999999');
  console.log(info.name);       // subscriber name
  console.log(info.fname);      // father name
  console.log(info.circle);
  console.log(info.adress);    // telecom circle

}

main();
```

---

## API Reference

### `chatai(prompt, options)`

Send a message to a GoodAI model.

**Parameters:**

| Parameter | Type | Required | Default | Description |
|-----------|------|----------|---------|-------------|
| `prompt` | `string` | Yes | — | Your message / question |
| `options.model` | `number` | No | `1` | GoodAI model ID — 1 to 8 |

**Returns:** `Promise<Object>`

```javascript
{
  response:   "AI generated response text",
  model:      "Llama 3.3 70B Pro",
  model_id:   1,
  words:      48,
  characters: 240,
  timestamp:  "2026-03-08T10:00:00.000Z"
}
```

**Examples:**

```javascript
// Model 1 — Llama (default)
const r = await chatai('What is Node.js?');
console.log(r.response);

// Model 3 — DeepSeek (best for logic)
const r = await chatai('What is 25 * 48 + 100?', { model: 3 });

// Model 6 — Claude 3.5 (best for instructions)
const r = await chatai('Write a to-do app in Express.js', { model: 6 });

// Model 8 — Creative AI (best for creative)
const r = await chatai('Write a poem about debugging at 3am', { model: 8 });
```

---

### `imgtotextai(prompt)`

Generate an image from a text description. Uses primary API with automatic fallback.

**Parameters:**

| Parameter | Type | Required | Description |
|-----------|------|----------|-------------|
| `prompt` | `string` | Yes | Text description of the image |

**Returns:** `Promise<Object>`

```javascript
{
  url:      "https://tmpfiles.org/dl/XXXXXXXX/image.png",
  filename: "image.png",
  size:     "1.4 MB",
  expired:  "2026-03-08 13:00 UTC",
  prompt:   "your original prompt",
  source:   "primary"  // or "fallback"
}
```

**Examples:**

```javascript
const img1 = await imgtotextai('red fox sitting on snow at sunset');
console.log(img1.url);

const img2 = await imgtotextai('futuristic India 2077 with flying rickshaws');
console.log(img2.url);

const img3 = await imgtotextai('wolf howling at blood moon in dark forest');
console.log(img3.url);
```

> Images expire after approximately 1 hour. Download and save them if needed.

---

### `numinfo(number)`

Look up basic subscriber information for a mobile number.

**Parameters:**

| Parameter | Type | Required | Description |
|-----------|------|----------|-------------|
| `number` | `string` or `number` | Yes | 10-digit mobile number |

**Returns:** `Promise<Object>`

```javascript
{
  name:   "Subscriber Name",
  fname:  "Father Name",
  circle: "JIO UP WEST"
}
```

**Rate limit:** 5 lookups per number per day.

**Examples:**

```javascript
const info = await numinfo('9XXXXXXXXX');
console.log(info.name);    // subscriber name
console.log(info.fname);   // father name
console.log(info.circle);  // telecom circle

// Number with spaces or dashes also works
const info2 = await numinfo('98765-43210');
```

---

### Error Handling

All three functions throw errors on failure. Always wrap in `try/catch`:

```javascript
const { chatai, imgtotextai, numinfo } = require('aionix');

async function safeRun() {

  // Chat errors
  try {
    const chat = await chatai('Hello!', { model: 1 });
    console.log(chat.response);
  } catch (err) {
    console.error(err.message);
    // Possible errors:
    // "prompt is required"
    // "model must be 1-8"
    // "Network Error: ..."
  }

  // Image errors
  try {
    const img = await imgtotextai('sunset over mountains');
    console.log(img.url);
  } catch (err) {
    console.error(err.message);
    // "Image generation failed"
  }

  // Numinfo errors
  try {
    const info = await numinfo('9XXXXXXXXX');
    console.log(info.name);
  } catch (err) {
    console.error(err.message);
    // "Number is required"
    // "Invalid number format"
    // "No info found for this number"
    // "Daily limit reached for this number (5/day)"
  }
}
```

---

## AI Models

All models route through **GoodAI**.

| ID | Model | Strength |
|----|-------|----------|
| `1` | Llama 3.3 70B Pro | General purpose, coding |
| `2` | DeepAI Pro Max | Creative writing, stories |
| `3` | DeepSeek V3 Ultra | Logic, math, deep analysis |
| `4` | Gemma 3B Turbo | Fast, lightweight responses |
| `5` | Mistral 3.2 Pro | Multilingual tasks |
| `6` | Claude 3.5 Sonnet | Reasoning, step-by-step |
| `7` | GPT-4o Mini | Balanced, all-round |
| `8` | Creative AI Max | Artistic, creative, poems |

---

## Dashboard Features

| Module | What it does |
|--------|-------------|
| Dashboard | Stats, quick launch buttons, today's habits at a glance |
| AI Chat | Chat with 8 GoodAI models, live typing indicator, model switcher |
| Image Gen | Text to image, generated gallery, preview modal, download link |
| Number Lookup | Subscriber info — name, father name, telecom circle |
| Code Snippets | Save, search, filter by language, copy to clipboard, delete |
| Quiz | Topic-wise MCQ — JavaScript, React, Node.js, CSS with scoring |
| Habit Tracker | Add habits, mark daily complete, streak counter, delete |
| Offline Docs | JS, React, Node.js, CSS reference — works without internet |
| Playground | HTML + JavaScript live editor with iframe output preview |

---

## Configuration

Config is saved at `~/.aionix/config.json` after first setup.

```json
{
  "name": "Surya",
  "port": 3000,
  "alias": "goodai",
  "autoOpen": true,
  "installedAt": "2026-03-08T10:00:00.000Z",
  "version": "1.2.0"
}
```

**View current config:**
```bash
goodai --config
```

**Edit config file:**
```bash
# Windows
notepad %USERPROFILE%\.aionix\config.json

# Mac / Linux
nano ~/.aionix/config.json
```

**Reset and re-run setup:**
```bash
# Windows
del %USERPROFILE%\.aionix\config.json
goodai

# Mac / Linux
rm ~/.aionix/config.json
goodai
```

---

## Project Structure

```
aionix/
├── bin/
│   ├── index.js          CLI entry — neon terminal, loading bars, port checker
│   ├── install.js        First-time setup wizard with typewriter effect
│   └── aionix.cmd        Windows command file (required for cmd to work)
├── client/
│   └── index.html        Full dashboard UI — neon cyberpunk theme, vanilla JS
├── db/
│   ├── habits.db         NeDB local habits (auto-created on first run)
│   ├── quiz.db           NeDB quiz questions — JS, React, Node.js, CSS
│   └── snippets.db       NeDB snippets (auto-created on first run)
├── lib/
│   ├── chatai.js         GoodAI Chat wrapper with rate limit
│   ├── imgtotextai.js    Image gen wrapper — primary + fallback
│   ├── numinfo.js        Number lookup with 5/day rate limit
│   └── index.js          Main export file — require('aionix') entry
├── server/
│   ├── app.js            Express server — auto port detection
│   └── routes/
│       ├── ai.js         /api/ai — chat, image, numinfo endpoints
│       ├── docs.js       /api/docs — offline reference data
│       ├── habits.js     /api/habits — CRUD + streak tracking
│       ├── quiz.js       /api/quiz — MCQ by topic
│       └── snippets.js   /api/snippets — CRUD + language filter
└── package.json
```

---

## Tech Stack

<div align="center">

![Node.js](https://img.shields.io/badge/Node.js-339933?style=for-the-badge&logo=nodedotjs&logoColor=white)
![Express](https://img.shields.io/badge/Express-000000?style=for-the-badge&logo=express&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white)
![npm](https://img.shields.io/badge/npm-CB3837?style=for-the-badge&logo=npm&logoColor=white)

</div>

| Package | Version | Purpose |
|---------|---------|---------|
| `express` | ^4.18.2 | Local HTTP server |
| `nedb-promises` | ^6.2.1 | Embedded offline database (no setup) |
| `chalk` | ^4.1.2 | Terminal neon color output |
| `open` | ^8.4.2 | Auto-open browser on start |

Zero frontend framework — pure HTML, CSS variables, and vanilla JavaScript for the neon cyberpunk theme.

---

## Privacy

- All data (snippets, habits, quiz scores) is stored **locally** in `db/` files — never sent anywhere
- AI Chat and Image Generation make API calls to third-party services — internet required only for these
- Number Lookup returns only name and telecom circle — address and ID are **intentionally not exposed**
- Rate limiting enforced: 5 lookups per number per day
- No analytics, no telemetry, no tracking of any kind

---

## Changelog

### v1.2.0
- GoodAI integration — all AI features now powered by GoodAI
- `goodai` command alias support via setup wizard
- AI Chat with 8-model selector and typing indicator
- Image Generation with gallery, preview modal, and download
- Number Lookup with clean neon result card
- Full neon cyberpunk terminal — ASCII banner, animated loading bars, port status table
- Auto port detection — starts on next free port if preferred is busy
- `goodai --config` / `aionix --config` command

### v1.1.0
- Added `lib/` folder — package usable as Node.js library
- `require('aionix')` support with `chatai`, `imgtotextai`, `numinfo`

### v1.0.0
- Initial release
- Offline dashboard: Code Snippets, Quiz, Habit Tracker, Docs, Playground

---

## Author

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0f0c29,50:302b63,100:24243e&height=130&section=header&text=Surya+Singh&fontSize=36&fontColor=00ff9f&fontAlignY=50&animation=fadeIn" width="65%"/>

<img src="https://readme-typing-svg.demolab.com?font=Share+Tech+Mono&size=14&pause=1000&color=00FF9F&center=true&vCenter=true&width=500&lines=Full+Stack+Developer;Building+AIONIX+%26+LearnoNix;Node.js+%7C+React+%7C+Python+%7C+C%2B%2B" alt="Typing SVG"/>

<br/>

[![GitHub](https://img.shields.io/badge/GitHub-%40sudosuryadeep-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/sudosuryadeep)
[![npm](https://img.shields.io/badge/npm-%40learnonix-CB3837?style=for-the-badge&logo=npm&logoColor=white)](https://www.npmjs.com/~learnonix)

<br/>

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white)
![Node.js](https://img.shields.io/badge/Node.js-339933?style=for-the-badge&logo=nodedotjs&logoColor=white)

</div>

---

## License

MIT License — see [LICENSE](./LICENSE) for details.

Free to use, modify, and distribute.

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:24243e,50:302b63,100:0f0c29&height=120&section=footer&animation=fadeIn" width="100%"/>

**Made with focus by [Surya Singh](https://github.com/sudosuryadeep)**

`npm install -g aionix` &nbsp;·&nbsp; `goodai` &nbsp;·&nbsp; `http://localhost:3000`

</div>
