/* ...args here represents any no.of arguments of any type in an array */
type AnyFunction = (...args: any[]) => any;
type KeyGetter<Fn extends AnyFunction> = (...args: Parameters<Fn>) => string;
/* Parameters<T>, takes in a type of a function and returns the parameters it takes 
    Obtain the parameters of a function type in a tuple
*/

function memoize<Fn extends AnyFunction>(fn: Fn, keyGetter?: KeyGetter<Fn>) {
  const cache: Record<string, ReturnType<Fn>> = {};
  /* ReturnType<T> takes in a type of a function and returns the return type of that function */

  return (...args: Parameters<Fn>) => {
    console.log("Args:", args);
    const key = (keyGetter || JSON.stringify)(args);
    console.log("Key is :", key);

    if (!(key in cache)) {
      /* Here I am spreading out the args with ... */
      cache[key] = fn(...args);
    }

    return cache[key];
  };
}

/* This takes 10 seconds to return result */
function expensiveCalculation(a: number, b: number) {
  const timeout = 10000;
  const start = Date.now();
  while (Date.now() <= start + timeout);

  return a + b;
}

const memoizeExpensiveCalculation = memoize(expensiveCalculation);
//expensiveCalculation(3, 4);
console.log("This will long time(10s)..");
memoizeExpensiveCalculation(10, 4);
console.log("Now it is memoized so it will not take that long(10s)");
memoizeExpensiveCalculation(10, 4);
// console.log("Now it is memoized so it will not take that long(10s)");
// memoizeExpensiveCalculation(10, 4);
// console.log("Now it is memoized so it will not take that long(10s)");
// memoizeExpensiveCalculation(10, 4);
console.log("Done");
