const PI = 3.14;

interface Shape {
  area?: number;
  type: "circle" | "rectangle" | "rightTriangle" | "square";
}

interface Circle extends Shape {
  radius: number;
  type: "circle";
}

interface Rectangle extends Shape {
  length: number;
  type: "rectangle";
  width: number;
}

interface RightTriangle extends Shape {
  base: number;
  height: number;
  type: "rightTriangle";
}

interface Square extends Shape {
  type: "square";
  width: number;
}

const getArea = (shape: Shape): number => {
  switch (shape.type) {
    case "circle":
      return getCircleArea(shape as Circle);
    case "rectangle":
      return getRectangleArea(shape as Rectangle);
    case "rightTriangle":
      return getRightTriangleArea(shape as RightTriangle);
    case "square":
      return getSquareArea(shape as Square);
    default:
      return -1;
  }
};

const getCircleArea = (circle: Circle): number => {
  const { radius } = circle;
  return radius * radius * PI;
};

const getRectangleArea = (rectangle: Rectangle): number => {
  const { length, width } = rectangle;
  return length * width;
};

const getSquareArea = (square: Square) => {
  const { width } = square;
  return getRectangleArea({
    length: width,
    type: "rectangle",
    width,
  });
};

const getRightTriangleArea = (rightTriangle: RightTriangle): number => {
  const { base, height } = rightTriangle;
  return (base * height) / 2;
};

const circle: Circle = { radius: 4, type: "circle" };
console.log({ ...circle, area: getArea(circle) });

const rectangle: Rectangle = { type: "rectangle", length: 7, width: 4 };
console.log({ ...rectangle, area: getArea(rectangle) });

const square: Square = { type: "square", width: 5 };
console.log({ ...square, area: getArea(square) });

const rightTriangle: RightTriangle = {
  type: "rightTriangle",
  base: 9,
  height: 4,
};
console.log({ ...rightTriangle, area: getArea(rightTriangle) });
