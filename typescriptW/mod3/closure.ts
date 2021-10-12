/* When a function is declared (be it function statement,expression or arrow function) 
    , it encloses any variable in a higher scope. This is called a closure.
    Any function can be a closure. A closure is simply a function that has enclosed variables
*/

/* The concept of scope simply means that each function creates a new scope. As we've
seen, functions can be declared inside other functions. The inner function can
read any variables declared in the outer function, but the outer function cannot see
variables declared in the inner function. This is scope. */

const fibonacci = () => {
  let next = 0;
  let increment = 1;
  let current = 0;

  return () => {
    [current, next, increment] = [next, increment, next + increment];
    return current;
  };
};

const getNext1 = fibonacci();
const getNext2 = fibonacci();
for (let i = 0; i < 10; i++) {
  console.log(`${getNext1()} -- ${getNext2()}`);
}

/* Calling the fibonacci function will return a new function that has access to the
variables declared in fibonacci. If we wanted to run another Fibonacci sequence,
we could call fibonacci() again to get a fresh scope with initialized variables */

/* In both cases, the closures have closed over the variables in a higher scope and are
still available on function calls. */
