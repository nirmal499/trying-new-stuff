function inner() {
  console.log("Inside inner function");
}

function middle() {
  console.log("Starting middle function");
  inner();
  console.log("Ending middle function");
}

function outer() {
  console.log("Starting outer function");
  middle();
  console.log("Ending outer function");
}

outer();

/* ------------------------------------------------------------------------------- */
console.log("1. Print immediately");

setTimeout(() => {
  console.log("1. Printed after 1 second");
}, 1000);

setTimeout(() => {
  console.log("1. Printed after 2 second");
}, 2000);

/* -------------------------------------------------------------------------------- */
console.log("2. Print immediately");

setTimeout(() => {
  console.log("2. Printed after 2 second");
}, 2000);
setTimeout(() => {
  console.log("2. Printed after 1 second");
}, 1000);

/* ---------------------------------------------------------------------------------- */
setTimeout(() => {
  console.log("3. Printed after 2 second");
}, 2000);
setTimeout(() => {
  console.log("3. Printed after 1 second");
}, 1000);

console.log("3. Print immediately");

/* ----------------------------------------------------------------------------------- */
setTimeout(function () {
  console.log("#1 Printed immediately?");
}, 0);

console.log("#2 Printed immediately.");
