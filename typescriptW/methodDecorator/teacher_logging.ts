export {};
const logger = {
  info: (message: string) => {
    console.log(`[INFO]: ${message}`);
  },
};

/* The most common usage of method decorators is to use it to wrap the original
method, adding some custom cross-cutting code. Examples would be adding some
general error handling or adding automatic logging capabilities.

In order to do that, you need to change the function that is being called. You can do
that using the value property of method property descriptors, and by using the get
and set properties of the property accessor descriptors */

function LogMethod(message: string) {
  return function (
    target: any,
    propertyName: string,
    descriptor: PropertyDescriptor
  ) {
    if (descriptor.value) {
      const original = descriptor.value;
      descriptor.value = function (...args: any[]) {
        logger.info(`${message}: Method ${propertyName} invoked`);
        /* we're passing in the original arguments to the original method */
        return original.apply(this, args);
      };
    }
    if (descriptor.get) {
      const original = descriptor.get;
      descriptor.get = function () {
        logger.info(`${message}: Getter for ${propertyName} invoked`);
        /* getter accessors do not take parameters */
        return original.apply(this, []);
      };
    }
    if (descriptor.set) {
      const original = descriptor.set;
      descriptor.set = function (value: any) {
        logger.info(`${message}: Setter for ${propertyName} invoked`);
        /* setter accessors take a single parameter, i.e. the value to be set */
        return original.apply(this, [value]);
      };
    }
  };
}

class Teacher {
  constructor(public name: string) {}

  private _title: string = "";

  @LogMethod("Title property")
  public get title() {
    return this._title;
  }

  public set title(value: string) {
    this._title = value;
  }

  @LogMethod("Teach method")
  public teach() {
    console.log(`${this.name} is teaching`);
  }
}

const teacher = new Teacher("John Smith");
teacher.teach(); /* Invoking teach method */
teacher.title = "Mr."; /* Invoking set method */
console.log(`${teacher.title} ${teacher.name}`); /* Invoking get method */
