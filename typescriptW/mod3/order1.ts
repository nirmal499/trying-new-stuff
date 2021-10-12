/* Higher-order functions both take a function as an argument and return a new function. These functions are often
wrapping or modifying some existing functionality */
interface Order {
  id: number;
  color: string;
  size: string;
}

export const orderFactory = () => {
  let id = 0;
  return (color: string) => (size: string) => (qty: number) => {
    const orders: Order[] = [];
    for (let index = 0; index < qty; index++) {
      orders.push({ id: id++, color, size });
    }
    return orders;
  };
};

const createOrder = orderFactory();

const redLine = createOrder("red");
const redSmall = redLine("S");
const redMedium = redLine("M");

const blueSmall = createOrder("blue")("S");

const orderOne = redMedium(4);
console.log(orderOne);

const orderTwo = blueSmall(7);
console.log(orderTwo);

const orderThree = redSmall(11);
console.log(orderThree);
