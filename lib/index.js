
'use strict';

const chatai = require('./chatai');
const imgtotextai = require('./imgtotextai');
const numinfo = require('./numinfo');

module.exports = {
  chatai,
  imgtotextai,
  numinfo,
  all: { chatai, imgtotextai, numinfo }
};
