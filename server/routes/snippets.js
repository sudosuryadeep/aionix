
const express = require('express');
const router = express.Router();
const Datastore = require('nedb-promises');
const path = require('path');

const db = Datastore.create(path.join(__dirname, '../../db/snippets.db'));

// Get all snippets
router.get('/', async (req, res) => {
  try {
    const snippets = await db.find({}).sort({ createdAt: -1 });
    res.json(snippets);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Add snippet
router.post('/', async (req, res) => {
  try {
    const { title, code, language, tags } = req.body;
    const snippet = await db.insert({
      title, code, language, tags,
      createdAt: new Date()
    });
    res.json(snippet);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Delete snippet
router.delete('/:id', async (req, res) => {
  try {
    await db.remove({ _id: req.params.id });
    res.json({ success: true });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

module.exports = router;
