module.exports = (sampleDataForHumans) => {
  const headerAndData = sampleDataForHumans.split('\r').join('').split('Mikal Hart\n\n')
  const rows = headerAndData[1].split('\n\n')

  let location, dateTime, altitude, pressure, temp;
  let locationAndRest, dateTimeAndRest, altitudeAndRest, pressureAndRest, tempAndRest;
  const csv = rows.map(row => {
    locationAndRest = row.split("  Date/Time: ")
    location = locationAndRest[0].split("Location: ")[1]

    if (!locationAndRest[1]) { return }
    dateTimeAndRest = locationAndRest[1].split('\n Altitude(ft): ')
    dateTime = dateTimeAndRest[0]

    if (!dateTimeAndRest[1]) { return }
    altitudeAndRest = dateTimeAndRest[1].split('\n Pressure(Pa): ')
    if (!altitudeAndRest) { return }
    altitude = altitudeAndRest[0]

    if (!altitudeAndRest[1]) { return }
    pressureAndRest = altitudeAndRest[1].split('\n Temp(f):      ');
    pressure = pressureAndRest[0]
    temp = pressureAndRest[1]
    if (!temp) { return }

    return `${location}, ${dateTime}, ${altitude}, ${pressure}, ${temp}`;
  }).join('\n')

  return csv;
}
