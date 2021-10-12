/* decorator factories are not
decorators per se. They are functions that need to be executed in order to return a
decorator. This means that they are executed in source code order, that is, top-down */

function First() {
  console.log("Generating first decorator");
  return function (constructor: Function) {
    console.log("Applying first decorator");
  };
}

function Second() {
  console.log("Generating second decorator");
  return function (constructor: Function) {
    console.log("Applying second decorator");
  };
}

@First()
@Second()
class Target {}

/* The generation process will generate the first decorator before the second, but in the
application process, the second will be applied, and then the first
SEE THE OUTPUT
*/
