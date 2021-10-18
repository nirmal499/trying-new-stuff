/* This is consumer for the logger in a new file called main.ts in the src folder.
Notice that we use the @inject decorator to tell InversifyJS that we want the
Logger type */

import "reflect-metadata";

import { inject, injectable } from "inversify";
import { container } from "./ioc.config";
import { Logger } from "./logger.interface";
import { TYPES } from "./types";

@injectable()
class Main {
  constructor(@inject(TYPES.Logger) private logger: Logger) {}

  run() {
    this.logger.log("Hello from InversifyJS!");
  }
}

// Run the app
const main = container.resolve(Main);
main.run();
