const fs = require('fs');

const humanFile = './data-2019-06-20/lowAltitude/LOG00026.TXT'
const csvFile = './data-2019-06-20/lowAltitude/parsedLOG00026.TXT'

const humanData = fs.readFileSync(humanFile, 'utf8', (err, data) => {
  if (err) throw err;
  return data;
});

const humansToComputersParser = require('./humansToComputersParser')

const csvToWrite = humansToComputersParser(humanData);
fs.writeFileSync(csvFile, csvToWrite, 'utf8')
console.log("File written to ", csvFile);
