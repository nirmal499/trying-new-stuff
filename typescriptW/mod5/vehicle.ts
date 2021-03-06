class Motor {
  private name: string;
  wheels: number;
  bodyType: string;

  constructor(name: string, wheels: number, bodyType: string) {
    this.name = name;
    this.wheels = wheels;
    this.bodyType = bodyType;
  }

  protected getName(): string {
    return this.name;
  }

  buildMotor() {
    return {
      wheels: this.wheels,
      bodyType: this.bodyType,
      name: this.name,
    };
  }
}

/* Car class */
class Car extends Motor {
  rideHeight: number;
  /* Overriding constructor of parent class */
  constructor(
    name: string,
    wheels: number,
    bodyType: string,
    rideHeight: number
  ) {
    super(name, wheels, bodyType);
    this.rideHeight = rideHeight;
  }

  _buildMotor() {
    return {
      ...super.buildMotor,
      rideHeight: this.rideHeight,
    };
  }
}

/* Truck Class */
class Truck extends Motor {
  offRoad: boolean;
  /* Overriding constructor of parent class */
  constructor(
    name: string,
    wheels: number,
    bodyType: string,
    offRoad: boolean
  ) {
    super(name, wheels, bodyType);
    this.offRoad = offRoad;
  }

  _buildMotor() {
    return {
      wheels: this.wheels,
      bodyType: this.bodyType,
      offRoad: this.offRoad,
    };
  }
}
class Suv extends Truck {
  roofRack: boolean;
  thirdRow: boolean;

  /* Overriding constructor of parent class */
  constructor(
    name: string,
    wheels: number,
    bodyType: string,
    offRoad: boolean,
    roofRack: boolean,
    thirdRow: boolean
  ) {
    super(name, wheels, bodyType, offRoad);
    this.roofRack = roofRack;
    this.thirdRow = thirdRow;
  }
}
const car: Car = new Car("blueBird", 4, "sedan", 14);
const truck: Truck = new Truck("blueBird", 4, "sedan", true);
const suv: Suv = new Suv("xtrail", 4, "box", true, true, true);
console.log(car);
console.log(truck);
console.log(suv);
