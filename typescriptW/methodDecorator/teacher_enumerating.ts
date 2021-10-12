function Enumerable(value: boolean) {
  return function (
    target: any,
    propertyName: string,
    descriptor: PropertyDescriptor
  ) {
    descriptor.enumerable = value;
  };
}

class Teacher5 {
  constructor(public name: string) {}

  private _title: string = "";

  @Enumerable(true)
  public get title() {
    return this._title;
  }

  public set title(value: string) {
    this._title = value;
  }

  @Enumerable(true)
  public teach() {
    console.log(`${this.name} is teaching`);
  }
}

const teacher5 = new Teacher5("John Smith");
for (const key in teacher5) {
  console.log(key);
}
