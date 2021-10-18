/* The basic idea in InversifyJS, as in most other implementations for an IoC container,
is to have one place that defines all the concrete implementations of functionality,
and the rest of the app only depends on abstractions (for example, interfaces). */

/* create the abstraction for our logger using an interface
    This is what consumers will reference later
*/
export interface Logger {
  log(message: string): void;
}

/* Next, create a concrete implementation for Logger. This implementation
is what the consumers of the code will get injected with when they require
Logger later on file console_logger.ts*/
