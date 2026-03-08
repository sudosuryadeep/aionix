
const express = require('express');
const router = express.Router();

const docs = {
  javascript: [
    { title: 'Variables', content: 'var, let, const - use let/const always. let is block scoped, const cannot be reassigned.' },
    { title: 'Arrow Functions', content: 'const fn = (a, b) => a + b; — shorter syntax, no own "this"' },
    { title: 'Promises', content: 'new Promise((resolve, reject) => {}). Use .then() .catch() or async/await' },
    { title: 'Array Methods', content: 'map(), filter(), reduce(), find(), forEach(), some(), every()' },
    { title: 'Destructuring', content: 'const {a, b} = obj; or const [x, y] = arr;' },
  ],
  react: [
    { title: 'useState', content: 'const [state, setState] = useState(initialValue); — for local component state' },
    { title: 'useEffect', content: 'useEffect(() => { }, [deps]); — runs after render, deps array controls when' },
    { title: 'Props', content: 'Pass data to child components. function Child({name}) { return <p>{name}</p> }' },
    { title: 'JSX Rules', content: 'Return single root element, use className not class, self-close empty tags' },
  ],
  nodejs: [
    { title: 'require vs import', content: 'require() is CommonJS (Node default). import is ES Modules (add "type":"module")' },
    { title: 'fs module', content: 'fs.readFile(), fs.writeFile(), fs.existsSync() — for file operations' },
    { title: 'Express basics', content: 'app.get/post/put/delete(route, handler). req.body, req.params, res.json()' },
  ],
  css: [
    { title: 'Flexbox', content: 'display:flex; justify-content; align-items; flex-direction; flex-wrap;' },
    { title: 'Grid', content: 'display:grid; grid-template-columns; grid-gap; grid-area;' },
    { title: 'Variables', content: ':root { --color: red; } then use var(--color)' },
  ]
};

router.get('/', (req, res) => {
  res.json(Object.keys(docs));
});

router.get('/:lang', (req, res) => {
  const lang = req.params.lang.toLowerCase();
  if (docs[lang]) {
    res.json(docs[lang]);
  } else {
    res.status(404).json({ error: 'Docs not found' });
  }
});

module.exports = router;
