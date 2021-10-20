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

    fetchGreetingWithCallback(name, (greeting) => {
      logWithTime(`START: callback for ${name}`);
      res.write(greeting);
      res.end();
      logWithTime(`END: callback for ${name}`);
    });

    logWithTime(`END: ${req.url}`);
  })
  .listen(4000, () => console.log("Server2 Port is running on 4000"));

function fetchGreetingWithCallback(
  name: string,
  cb: (greeting: string) => void
) {
  const fakeRequestTime = 5000;

  logWithTime(`START: fetchGreeting for user: ${name}`);

  setTimeout(() => {
    logWithTime(`Fetched greeting for user: ${name}`);
    cb(`Hello ${name}`);
  }, fakeRequestTime);

  logWithTime(`END: fetchGreeting for user: ${name}`);

  return `Hello ${name}`;
}
