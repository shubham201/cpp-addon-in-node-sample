const addon = require('./build/Release/addon');

// Use the C++ addon to add two numbers
const sum = addon.add(3, 5);
console.log(`Sum: ${sum}`);
