
const express = require('express');
const router = express.Router();
const Datastore = require('nedb-promises');
const path = require('path');

const db = Datastore.create(path.join(__dirname, '../../db/habits.db'));

// Get all habits
router.get('/', async (req, res) => {
  try {
    const habits = await db.find({}).sort({ createdAt: -1 });
    res.json(habits);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Add habit
router.post('/', async (req, res) => {
  try {
    const { name, frequency } = req.body;
    const habit = await db.insert({
      name, frequency,
      streak: 0,
      completedDates: [],
      createdAt: new Date()
    });
    res.json(habit);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Mark habit complete today
router.patch('/:id/complete', async (req, res) => {
  try {
    const today = new Date().toDateString();
    const habit = await db.findOne({ _id: req.params.id });
    if (!habit.completedDates.includes(today)) {
      await db.update(
        { _id: req.params.id },
        { $push: { completedDates: today }, $inc: { streak: 1 } }
      );
    }
    res.json({ success: true });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Delete habit
router.delete('/:id', async (req, res) => {
  try {
    await db.remove({ _id: req.params.id });
    res.json({ success: true });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

module.exports = router;
