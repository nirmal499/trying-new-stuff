interface Person {
  firstName: string;
  lastName: string;
}

let count = 0; /* Global variable */

function getFullName(person: Person) {
  count += 1;
  return `${person.firstName} ${person.lastName}`;
}

// array of persons that we need to sort
const programmers: Person[] = [
  { firstName: "Donald", lastName: "Knuth" },
  { firstName: "Barbara", lastName: "Liskow" },
  { firstName: "Lars", lastName: "Bak" },
  { firstName: "Guido", lastName: "Van Rossum" },
  { firstName: "Anders", lastName: "Hejslberg" },
  { firstName: "Edsger", lastName: "Dijkstra" },
  { firstName: "Brandon", lastName: "Eich" },
];

/*

Because in javascript, arrays are passed by reference which means that when
you make one array equal to another it will change both whenever you make an edit to one.
To fix this in your example change the following line:

var sortedWords_Array = words_Array;
to:
 //make a copy of array by using slice
 var sortedWords_Array = words_Array.slice(0);

" slice does not alter the original array, but returns a new "one level deep" copy that contains copies of the elements sliced from the original array."

*/

/* A naive and straightforward sorting function */
function naiveSortPersons(persons: Person[]) {
  /* Applying sort function in a new sliced array. So, that 
    original array does not get modified
  */
  return persons.slice().sort((first, second) => {
    const firstFullName = getFullName(first);
    const secondFullName = getFullName(second);

    return firstFullName.localeCompare(secondFullName);
  });
}

/* Use a Schwartzian transform to takes an array of persons, and return (a sorted) array of persons*/
function schwartzSortPersons(persons: Person[]): Person[] {
  // Use the array's `map` function to transform each element into a tuple
  const tuples: [Person, string][] = persons.map((person) => [
    person,
    getFullName(person),
  ]);

  /* [
        [ { firstName: 'Donald', lastName: 'Knuth' }, 'Donald Knuth' ],
        [ { firstName: 'Barbara', lastName: 'Liskow' }, 'Barbara Liskow' ],
        [ { firstName: 'Lars', lastName: 'Bak' }, 'Lars Bak' ],
        [
          { firstName: 'Guido', lastName: 'Van Rossum' },
          'Guido Van Rossum'
        ],
        [
          { firstName: 'Anders', lastName: 'Hejslberg' },
          'Anders Hejslberg'
        ],
        [ { firstName: 'Edsger', lastName: 'Dijkstra' }, 'Edsger Dijkstra' ],
        [ { firstName: 'Brandon', lastName: 'Eich' }, 'Brandon Eich' ]
    ] */
  //console.log(tuples);

  // Sort the `tuples` array of tuples, using the standard `sort` method, on the second element of the tuple
  tuples.sort((first, second) => first[1].localeCompare(second[1]));
  // Transform the sorted array of tuples into the format we want - just an array of `person` objects
  // by taking the first element of each tuple, discarding the schwartz.
  const result = tuples.map((tuple) => tuple[0]);
  // Return the new array from the function
  return result;
}

//Call the naive `sortPersons` function on our defined array
count = 0; /* ReInitializing the same global variable */
const sortedNaive = naiveSortPersons(programmers);

// Output both the sorted array, and the count variable.
console.log(sortedNaive);
console.log(
  `When called using the naive approach, the function was called ${count} times`
);

// Call the Schwartzian `sortPersons` function on our defined array
count = 0; /* ReInitializing the same global variable */
const sortedSchwartz = schwartzSortPersons(programmers);

// Output both the sorted array, and the count variable.
console.log(sortedSchwartz);
console.log(
  `When called using the Schwartzian transform approach, the function was called ${count} times`
);
