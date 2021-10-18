/*  define an injection token that consumers can rely on later to ask InversifyJS to inject whatever
implementation is behind it at runtime */

export const TYPES = {
  Logger: Symbol.for("Logger"),
};

/* we'll stick with the recommended approach of creating a TYPES
object that resolves to a Symbol for each type (using an injection token is
required in most DI libraries in TypeScript, since interfaces don't exist at runtime,
so InversifyJS can't rely on them) */

/* If your target environment doesn't support symbols, you can instead use a
plain string. Just ensure that you don't have the same string registered for
multiple types */
