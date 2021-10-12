/* This is class decorator factory */
function Token1(hasToken: boolean) {
  return function (constructor: Function) {
    constructor.prototype.token = hasToken;
  };
}

/* @ can be attached to only decorator
  Token(true) will basically return a class decorator
  That's why we are able to attach @ to the Token function
*/
@Token1(true)
class Teacher1 {
  constructor(public id: number, public name: string) {}
}

const teacher1 = new Teacher1(1, "John Smith");
console.log("token in Teacher class: ", teacher1["token"]);
console.log("Do we have a token property: ", teacher1.hasOwnProperty("token"));

@Token1(false)
class Student1 {
  constructor(public id: number, public name: string) {}
}

const student1 = new Student1(101, "John Bender");
console.log("token in Student class: ", student1["token"]);
console.log("Do we have a token property: ", student1.hasOwnProperty("token"));
