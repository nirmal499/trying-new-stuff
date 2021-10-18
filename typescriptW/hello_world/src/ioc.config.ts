import { Container } from "inversify";
import { ConsoleLogger } from "./console_logger";
import { Logger } from "./logger.interface";
import { TYPES } from "./types";

export const container = new Container();

container.bind<Logger>(TYPES.Logger).to(ConsoleLogger);

/* This is what ties all three things (console-logger, logger.interface, and
types) together */
