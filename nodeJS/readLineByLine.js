const fs = require('fs');
const readLine = require('readline');

const readInterface = readLine.createInterface({
  input: fs.createReadStream('check.txt'),
  output: process.stdout,
  console: false
})

readInterface.on('line', function (line) {
  console.log(line);
  console.log('**********************************************');
  break;
})
