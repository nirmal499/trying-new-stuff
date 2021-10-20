const getTheValue = async (val: number = 0): Promise<number> => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      /* When val is 0 then random number generated between 0 to 99 */
      const number = Math.floor(Math.random() * 100) + val;
      if (number % 10 === 0) {
        reject("Bad Modulus");
      } else {
        //console.log(`The value is ${number}`);
        resolve(number);
      }
    }, 1000);
  });
};

/* If no "Bad Modulus" occurred then this whole below statement
  will take 10 seconds to complete
*/
// getTheValue()
//   .then((result: number) => getTheValue(result))
//   .then((result: number) => getTheValue(result))
//   .then((result: number) => getTheValue(result))
//   .then((result: number) => getTheValue(result))
//   .then((result: number) => getTheValue(result))
//   .then((result: number) => getTheValue(result))
//   .then((result: number) => getTheValue(result))
//   .then((result: number) => getTheValue(result))
//   .then((result: number) => getTheValue(result))
//   .catch((err) => console.error(err))
//   .finally(() => console.log("We are done."));

// getTheValue()
//   .then(() => getTheValue())
//   .then(() => getTheValue())
//   .then(() => getTheValue())
//   .then(() => getTheValue())
//   .then(() => getTheValue())
//   .then(() => getTheValue())
//   .then(() => getTheValue())
//   .then(() => getTheValue())
//   .then(() => getTheValue())
//   .catch((err) => console.error(err))
//   .finally(() => console.log("We are done."));

/* ---------------------------------------------------------------------------------------------------- */

/* We can load up an array of promises and then use Promise.all to resolve all the
promises in parallel and use catch and finally to resolve errors

If we chain a series of promises, this operation will take just over 10 seconds.
By using Promise.all, we are able to run those operations in parallel and now it
takes only 1 second to complete the function.

Promise.all is useful any time you can run two or more asynchronous processes
in parallel
*/
// let count = 0;
// Promise.all([
//   getTheValue(),
//   getTheValue(),
//   getTheValue(),
//   getTheValue(),
//   getTheValue(),
//   getTheValue(),
//   getTheValue(),
//   getTheValue(),
//   getTheValue(),
//   getTheValue(),
// ])
//   .then((values) => {
//     console.log(
//       `The total is ${values.reduce((prev, current) => prev + current, 0)}`
//     );
//   })
//   .catch((err) => console.error(err))
//   .finally(() => console.log(`We are done! ${++count}`));

/* ---------------------------------------------------------------------------------------- */
/* The logic here is that Array(10) creates a new array of 10 elements,
fill(null) will initialize the array, then map will remap the array elements to
be the getTheValue() function call */
// let loopCount = 0;
// const doIt = () => {
//   Promise.all(
//     Array(10)
//       .fill(null)
//       .map(() => getTheValue())
//   )
//     .then(
//       (values) => {
//         console.log(
//           `The total is ${values.reduce((prev, current) => prev + current, 0)}`
//         );
//       }
//       /* . In this case, our business rule is we want the entire set of calculations to
//       complete and we will restart if there is an error.  That is the reason why we are providing the
//       same doIt function to catch . Note that we do not invoke the callback function here. We want to pass a
//       function and it will be invoked in the case of an error
//     */
//       /* We could also done
//       .catch((err) => { console.error(err); doIt(); }).finally( ...
//     */
//     )
//     .catch(doIt)
//     .finally(() => {
//       console.log(`Completed loop ${++loopCount}`);
//     });
// };

// doIt();

/* ----------------------------------------------------------------------------------- */
/* This method is a variation on Promise.all, which is ideal for when it's acceptable
for some of our promises to resolve successfully and some of them to be rejected */
// let count = 0;
// const generatedTheNumber = (iterations: number): void => {
//   Promise.allSettled(
//     Array(iterations)
//       .fill(null)
//       .map(() => getTheValue())
//   )
//     .then((settledResults) => {
//       // Map all the results into the failed, succeeded and total values.
//       const results = settledResults.reduce(
//         (prev, current) => {
//           console.log(current);
//           return current.status === "fulfilled"
//             ? {
//                 ...prev,
//                 succeeded: prev.succeeded + 1,
//                 total: prev.total + current.value,
//               }
//             : { ...prev, failed: prev.failed + 1 };
//         },
//         {
//           failed: 0,
//           succeeded: 0,
//           total: 0,
//         }
//       );
//       console.log(results);
//     })
//     .finally(() => console.log(`We are done ${++count}`));
// };

/* The main improvement now is the use of Promise.allSettled.
Now, Promise.allSettled allows us to have a mix of successes and failures,
unlike Promise.all, which will call the then() method if all the promises resolve
successfully or call the catch() method if any of them fail */

/* Each of the resolved promises will have a status containing the string 'fulfilled'
if the promise resolved successfully or 'rejected' if there was an error. Fulfilled
promises will have a value property containing the value the promise resolved to
and rejected promises will have a reason property containing the error. */

//generatedTheNumber(10);

/* --------------------------------------------------------------------------------------------------------- */
/* Now, Promise.race again takes an iterable of promises and executes them all. The
first promise that resolves or rejects will resolve or reject the race. This is in contrast
to Promise.any in that if the first promise in Promise.any rejects, the other
promises still have an opportunity to resolve successfully */

const oneSecond = new Promise((_resolve, reject) => {
  setTimeout(() => reject("Too slow!"), 5000);
});
const upToTwoSeconds = new Promise((resolve) => {
  setTimeout(() => resolve("Made it!"), Math.random() * 10000);
});
Promise.race([oneSecond, upToTwoSeconds])
  .then((result) => console.log(result))
  .catch((err) => console.error(err));

/* In this example, one promise always rejects in 5 second while the other resolves at a
random interval between 0 and 10 seconds. If the oneSecond promise wins the race,
the entire promise is rejected. If upToTwoSeconds takes less than a second, then
the promise resolves successfully with the message "Made It! */

/* ----------------------------------------------------------------------------------------------------------- */
