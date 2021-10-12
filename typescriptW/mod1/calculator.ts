enum Operator {
  Add = "add",
  Subtract = "subtract",
  Multiply = "multiply",
  Divide = "divide",
}

type Operation = (x: number, y: number) => number;

/* This will be a tuple */
const operations: [Operator, Operation][] = [];

/* add function */
const add: Operation = function (first: number, second: number) {
  return first + second;
};

operations.push([Operator.Add, add]);

/* subtract function */
const subtract: Operation = function (first: number, second: number) {
  return first - second;
};
operations.push([Operator.Subtract, subtract]);

/* multiply function */
const multiply: Operation = function (first: number, second: number) {
  return first * second;
};
operations.push([Operator.Multiply, multiply]);

/* divide function */
const divide: Operation = function (first: number, second: number) {
  return first / second;
};
operations.push([Operator.Divide, divide]);

const calculator = function (first: number, second: number, op: Operator) {
  const tuple = operations.find((tp) => tp[0]);
  if (tuple !== undefined) {
    const operation = tuple[1];
    const result = operation(first, second);
    return result;
  }
};

console.log(calculator(4, 6, Operator.Add));
console.log(calculator(4, 6, Operator.Subtract));
console.log(calculator(4, 6, Operator.Multiply));
console.log(calculator(4, 6, Operator.Divide));
