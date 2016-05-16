const https = require('https');
const util = require('util');

const token = 'ㅇㅅㅇ~';

const options = {
  method: 'GET',
  host: 'api.github.com',
  path: '/repos/simnalamburt/test/releases',
  headers: {
    'user-agent': 'Mozilla/5.0',
    'authorization': `token ${token}`
  }
};

var data = '';

const req = https.request(options, res => {
  console.log(`STATUS: ${res.statusCode}\n\n`);
  res.setEncoding('utf8');
  res.on('data', chunk => data += chunk);

  res.on('end', _ => {
    console.log(util.inspect(JSON.parse(data), { colors: true, depth: null }));
  });
});
req.on('error', e => console.error(e));
req.end();
