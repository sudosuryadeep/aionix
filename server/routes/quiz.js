
const express = require('express');
const router = express.Router();
const Datastore = require('nedb-promises');
const path = require('path');

const db = Datastore.create(path.join(__dirname, '../../db/quiz.db'));

// Seed default questions if empty
async function seedQuestions() {
  const count = await db.count({});
  if (count === 0) {
    await db.insert([
      { topic: 'JavaScript', question: 'What is closure?', options: ['A function inside a function', 'A loop', 'An array method', 'None'], answer: 0, difficulty: 'medium' },
      { topic: 'JavaScript', question: 'What does "=== " mean?', options: ['Assignment', 'Loose equality', 'Strict equality', 'None'], answer: 2, difficulty: 'easy' },
      { topic: 'React', question: 'What is JSX?', options: ['A database', 'JS + HTML syntax', 'A CSS framework', 'None'], answer: 1, difficulty: 'easy' },
      { topic: 'Node.js', question: 'What is npm?', options: ['Node Package Manager', 'New Program Mode', 'None', 'Network Protocol'], answer: 0, difficulty: 'easy' },
      { topic: 'CSS', question: 'What is flexbox used for?', options: ['Animations', 'Layout', 'Colors', 'Fonts'], answer: 1, difficulty: 'easy' },
    ]);
  }
}
seedQuestions();

// Get questions by topic
router.get('/:topic', async (req, res) => {
  try {
    const query = req.params.topic === 'all' ? {} : { topic: req.params.topic };
    const questions = await db.find(query);
    res.json(questions);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Get all topics
router.get('/', async (req, res) => {
  try {
    const questions = await db.find({});
    const topics = [...new Set(questions.map(q => q.topic))];
    res.json(topics);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

module.exports = router;
