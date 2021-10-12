type Constructable2 = { new (...args: any[]): {} };

/* Inside Decorator factory function:
 Returned decorator function return a new constructor
that executes the new code needed by the decorator itself as well as the original
constructor. For example, if you want to write some text to the console each time you
instantiate a decorated class, you can use this decorator */
function WrapConstructor(message: string) {
  return function <T extends Constructable2>(constructor: T) {
    const wrappedConstructor: any = function (...args: any[]) {
      console.log(`Decorating ${message}`);
      const result = new constructor(...args);
      console.log(`Decorator ${message}`);
      return result;
    };

    wrappedConstructor.prototype = constructor.prototype;
    return wrappedConstructor;
  };
}

@WrapConstructor("decorator")
class Teacher {
  constructor(public id: number, public name: string) {
    console.log("Constructing a teacher class instance");
  }
}
const teacher = new Teacher(1, "John");
