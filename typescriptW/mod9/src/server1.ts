///<reference path="../node_modules/@types/node/index.d.ts"/>
import * as http from "http";
/* now use the import XXX from 'XXX' (ES Modules) syntax instead of const XXX = require('XXX') (CommonJS) syntax */

function logWithTime(message: string) {
  console.log(`[${new Date().toISOString()}]: ${message}`);
}

http
  .createServer((req, res) => {
    logWithTime(`START: ${req.url}`);

    /* 'http://localhost:3000/john' -> john  */
    const name = req.url.split("/")[1] || "Default";
    const greeting = fetchGreetingWithoutCallback(name);

    res.write(greeting);
    res.end();

    logWithTime(`END: ${req.url}`);
  })
  .listen(3000, () => console.log("Server1 Port is running on 3000"));

function fetchGreetingWithoutCallback(name: string) {
  const now = Date.now();
  const fakeRequestTime = 5000;

  logWithTime(`START: fetchGreeting for user: ${name}`);

  while (Date.now() < now + fakeRequestTime);

  logWithTime(`END: fetchGreeting for user: ${name}`);

  return `Hello ${name}`;
}
