interface OpenLibraryAuthor {
  personal_name: string;
  photos: number[];
}

const getAuthor = () => {
  const result = new Promise<OpenLibraryAuthor>((resolve, reject) => {
    const xhr = new XMLHttpRequest();
    const url = "https://openlibrary.org/authors/OL9388A.json";
    xhr.open("GET", url);
    xhr.send();

    xhr.onload = () => {
      if (xhr.status != 200) {
        reject({
          error: xhr.status,
          message: xhr.statusText,
        });
      } else {
        const response = JSON.parse(xhr.response);
        resolve(response);
      }
    };
  });
  return result;
};

getAuthor()
  .then((author) => {
    const body = document.getElementsByTagName("body")[0];
    const image = document.createElement("img");
    image.src = `http://covers.openlibrary.org/a/id/${author.photos[0]}-M.jpg`;
    body.appendChild(image);
    const name = document.createElement("h1");
    name.innerHTML = author.personal_name;
    body.appendChild(name);
  })
  .catch((error) => {
    console.log(`An error occured ${error.error}: ${error.message}`);
  });
