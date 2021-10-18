const numbers2 = ["One", "Two", "Three", "Four", "Five"];

const delay2 = (ms: number) => {
  const result = new Promise<void>((resolve, reject) => {
    setTimeout(() => {
      resolve();
    }, ms);
  });
  return result;
};

async function countNumbers() {
  //   await delay2(1000);
  //   console.log(numbers2[0]);

  //   await delay2(1000);
  //   console.log(numbers2[1]);

  //   await delay2(1000);
  //   console.log(numbers2[2]);

  //   await delay2(1000);
  //   console.log(numbers2[3]);

  //   await delay2(1000);
  //   console.log(numbers2[4]);

  for (const number of numbers2) {
    await delay2(1000);
    console.log(number);
  }
}

countNumbers();
