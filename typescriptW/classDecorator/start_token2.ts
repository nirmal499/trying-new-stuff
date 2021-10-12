type Constructable1 = { new (...args: any[]): {} };

function Token2(hasToken: boolean) {
  return function <T extends Constructable1>(constructor: T) {
    return class extends constructor {
      token: boolean = hasToken;
    };
  };
}

/* Here we are able to create decorator that will add the token property
  not on the prototype but on the constructed object
*/

@Token2(true)
class Teacher2 {
  constructor(public id: number, public name: string) {}
  // teacher specific code
}

const teacher2 = new Teacher2(1, "John Smith");
console.log("Do we have a token:", teacher2["token"]);
console.log("Do we have a token property: ", teacher2.hasOwnProperty("token"));
