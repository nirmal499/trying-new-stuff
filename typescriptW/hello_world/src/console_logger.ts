import { injectable } from "inversify";
import { Logger } from "./logger.interface";

@injectable()
export class ConsoleLogger implements Logger {
  log(message: string) {
    console.log(message);
  }
}

/* Note that ConsoleLogger implements Logger. This ensures that we write a
compatible implementation to what our consumers expect, and that they don't
break at runtime. In addition, the @injectable decorator is used to indicate to
InversifyJS that this implementation can be used as a dependency, and also that it
can be injected to other dependencies. This is how we make InversifyJS aware that
ConsoleLogger is something that it should be aware of */
