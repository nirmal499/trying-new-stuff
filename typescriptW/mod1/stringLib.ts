/* 

"war AND peace" => "War And Peace"
"Catcher in the Rye" => "Catcher In The Rye"
"tO kILL A mOCKINGBIRD" => "To Kill A MockingBird

*/
export function toTitleCase(input: string): string {
  const words = input.split(" ");
  const titleWords: string[] = [];

  for (const word of words) {
    const initialAlphabet = word.slice(0, 1).toUpperCase();
    const restAlphabets = word.slice(1).toLowerCase();
    titleWords.push(`${initialAlphabet}${restAlphabets}`);
  }

  const output = titleWords.join(" ");
  return output;
}

/* 

"War and Peace" => 3
"catcher-in-the-rye" => 4
"for_whom the-bell-tolls" => 5

Words are delimited by spaces, dashes (-), or underscores (_)

*/
export function countWords(input: string): number {
  /* Split the words using a regex that will match any occurrence of a space,
      underscore, or dash character */
  const words = input.split(/[ _-]/);

  return words.length;
}

/* 

"War and Peace" => [War, and, peace]
"catcher-in-the-rye" => [catcher, in, the, rye]
"for_whom the-bell-tolls" => [for, whom, the, bell, tolls]

*/
export function toWords(input: string): string[] {
  const words = input.split(/[ _-]/);
  return words;
}

/* 

"War", 3 => "WarWarWar"
"rye", 1 => "rye"
"bell", 0 => ""

*/
export function repeat(input: string, times: number): string {
  /* 
    create a new array that with length of `times` and set each element to the value of the `input` string
  */
  const instances = new Array(times).fill(input); // ["War","War","War"]
  const result = instances.join(""); // join the elements of the array together with no space
  return result;
}

/* 

isAlpha returns true if the string only has alpha characters (that is, letters).

"War and Peace" => false
"Atonement" => true
"1Q84" => false

*/
export function isAlpha(input: string): boolean {
  /* 
  
   In particular, the character group [a-z] will check for
    a single character and if we use the star quantifier (*), we can tell the regular
    expression to check for all the characters. We can add the i modifier to the
    regular expression to make the match case-insensitive, so we don't need to
    worry about letter casing
  */
  const alphaRegex = /^[a-z]*$/i;

  /* 
  
  Let's take a regex pattern that may be a bit useful. Let's say I have two strings
  "The bat of Matt Jones" and "Matthew's last name is Jones".
  The pattern ^Matt.*Jones$ will match "Matthew's last name is Jones".
  Why? The pattern says - the string should start with Matt and end with Jones and
  there can be zero or more characters (any characters) in between them
  
  */

  /*
  Since we only need to know whether the
  string matches, we can use the test method of the regular expression and return
  its result
  */
  const result = alphaRegex.test(input);

  return result;
}

/* 

isBlank returns true if the string is blank, that is, it consists only of whitespace characters

"War and Peace" => false
" " => true
"" => true

*/
export function isBlank(input: string): boolean {
  /* test if the first character of our input is an empty space */
  while (input[0] === " ") {
    /* successively slice off the first character of the input */
    input = input.slice(1);
  }
  /* the loop will stop on the first character that is not a //space.
  if we're left with an empty string, we only have spaces in the
  input string */
  const result = input === "";
  return result;
}
