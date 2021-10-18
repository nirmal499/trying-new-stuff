interface OpenLibraryAuthor {
  personal_name: string;
  photos: number[];
}

const xhr = new XMLHttpRequest();
const url = "https://openlibrary.org/authors/OL9388A.json";
xhr.open("GET", url);
xhr.send();

xhr.onload = () => {
  if (xhr.status != 200) {
    console.log(`An error occured ${xhr.status}: ${xhr.statusText}`);
  } else {
    const response: OpenLibraryAuthor = JSON.parse(xhr.response);
    const body = document.getElementsByTagName("body")[0];
    const image = document.createElement("img");
    image.src = `http://covers.openlibrary.org/a/id/${response.photos[0]}-M.jpg`;
    body.appendChild(image);
    const name = document.createElement("h1");
    name.innerHTML = response.personal_name;
    body.appendChild(name);
  }
};
