const fs = require('fs');
const dataForHumans = fs.readFileSync('./flightTracker/parser/sampleDataForHumans.txt', 'utf8', (err, data) => {
  if (err) throw err;
  return data;
});

const humansToComputersParser = require('./humansToComputersParser')

console.log(humansToComputersParser(dataForHumans));
