const numbers = ["One", "Two", "Three", "Four", "Five"];

/* Callback hell */
setTimeout(() => {
  console.log(numbers[0]);
  setTimeout(() => {
    //console.log(numbers[1]);
    setTimeout(() => {
      console.log(numbers[2]);
      setTimeout(() => {
        console.log(numbers[3]);
        setTimeout(() => {
          console.log(numbers[4]);
          console.log("5");
          console.log("***************************************");
        }, 1000);
        console.log("4");
      }, 1000);
      console.log("3");
    }, 1000);
    console.log(numbers[1]);
    console.log("2");
  }, 1000);
  console.log("1");
}, 1000);
