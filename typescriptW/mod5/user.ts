class User {
  /* We do not want child classes to access properties directly */
  private userName: string;
  private token: string = "";
  readonly timeStamp: number = new Date().getTime();

  constructor(userName: string, token: string) {
    this.userName = userName;
    this.token = token;
  }

  logOut(): void {
    this.userName = "";
    this.token = "";
  }

  getUser() {
    return {
      userName: this.userName,
      token: this.token,
      createdAt: this.timeStamp,
    };
  }

  /* This method is accessable by its own class and the derived ones  */
  protected renewToken(newToken: string) {
    this.token = newToken;
  }
}

class Cashier extends User {
  balance: number = 0;
  float: number = 0;

  start(balance: number, float: number): void {
    this.balance = balance;
    this.float = float;
  }
}

class Inventory extends User {
  products: string[] = [];

  /* override constructor method, add new prop */
  constructor(userName: string, token: string, products: string[]) {
    /* call parent constructor method */
    super(userName, token);
    /* set new prop */
    this.products = products;
  }
}

class FloorWorker extends Inventory {
  floorStock: string[] = [];

  checkOut(id: number) {
    if (this.products.length >= 0 && this.products.length - 1 <= id) {
      this.floorStock.push(this.products[id]);
    }
  }
}

const basicUser = new User("user1", "1234567bu");
console.log(basicUser);
// init cashier user
const cashUser = new Cashier("user2", "1234567cu");
console.log(cashUser);
cashUser.start(10, 1.5);
console.log(cashUser);
// init inventory
const iUser = new Inventory("user3", "1234567iu", [
  "orange",
  "mango",
  "playStation 2",
]);
console.log(iUser);
// FloorWorker
const fUser = new FloorWorker("user4", "1234567fu", [
  "orange",
  "mango",
  "playStation 2",
]);
fUser.checkOut(0);
console.log(fUser.products);
console.log(fUser.floorStock);
