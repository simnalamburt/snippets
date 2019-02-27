const utcFormatter = new Intl.DateTimeFormat('en-US', {
  timeZone: 'UTC',
  localeMatcher: 'lookup',
  formatMatcher: 'basic',
  hour12: false,
  day: 'numeric',
  hour: 'numeric',
  minute: 'numeric',
})

function offsetOfTimezone(timeZone, date = new Date()) {
  const zonedFormatter = new Intl.DateTimeFormat('en-US', {
    timeZone,
    localeMatcher: 'lookup',
    formatMatcher: 'basic',
    hour12: false,
    day: 'numeric',
    hour: 'numeric',
    minute: 'numeric',
  })

  const [zoned, utc] = [zonedFormatter, utcFormatter].map(formatter =>
    formatter
    .formatToParts(date)
    .reduce((accum, cur) => {
      const val = cur.value | 0
      switch(cur.type) {
        case 'day': return accum + 1440*val
        case 'hour': return accum + 60*val
        case 'minute': return accum + val
        default: return accum
      }
    }, 0)
  )

  return zoned - utc
}

module.exports = offsetOfTimezone
