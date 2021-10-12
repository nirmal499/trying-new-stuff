import "reflect-metadata";

class Teacher {
  @Description("This is the id of the teacher")
  public id: number;

  @Description("This is the name of the teacher")
  public name: string;

  constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
}

/* Property Decorator factory */
function Description(message: string) {
  return function (target: any, propertyKey: string) {
    /* target will be the class name and propertyKey will be the variable name */
    // console.log("target is: ", target);
    // console.log("PropertyKey is: ", propertyKey);
    Reflect.defineMetadata("description", message, target, propertyKey);
  };
}

function showDescriptions(target: any) {
  //console.log("target has: ", target);
  for (const key in target) {
    if (Reflect.hasMetadata("description", target, key)) {
      const description = Reflect.getMetadata("description", target, key);
      console.log(`  ${key}: ${description}`);
    }
  }
}

const teacher = new Teacher(1, "John Smith");
showDescriptions(teacher);
