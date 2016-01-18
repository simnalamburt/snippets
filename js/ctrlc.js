const http = require('http');
const port = 4567;

http.createServer((_, res) => {
  res.writeHead(200, {"Content-Type": "text/plain"});
  res.write("Hello World");
  res.end();
}).listen(port);

process.on('SIGINT', () => {
  console.log('\n\nGoodbye!\n');
  process.exit();
});

console.log(`
HTTP Server is Ready!

See http://localhost:${port}/`);
