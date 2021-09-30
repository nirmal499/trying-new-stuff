<?php

$directors = [
    "steven-spielberg" => [
        "The Terminal", "Minority Report", "Catch Me If You Can",
        "Lincoln", "Bridge of Spies"
    ],
    "christopher-nolan" => [
        "Dunkirk", "Interstellar", "The Dark Knight Rises",
        "Inception", "Memento"
    ],
    "martin-scorsese" => ["Silence", "Hugo", "Shutter Island", "The Departed", "Gangs of New York"],
    "spike-lee" => [
        "Do the Right Thing", "Malcolm X", "Summer of Sam", "25th Hour", "Inside Man"
    ],
    "lynne-ramsey" => ["Ratcatcher", "Swimmer", "Morvern Callar", "We Need To Talk About Kevin", "You Were Never Really Here"]
];

/* function for processing Director Name */
function processDirectorName(string $name): string
{
    $nameParts = explode('-', $name);
    $firstName = ucfirst($nameParts[0]);
    $lastName = strtoupper($nameParts[1]);

    return "$firstName $lastName";
}

/* function for processing Movies Array */
function processMovies(string ...$movies): string
{
    $formattedStrings = [];
    for ($i = 0; $i < count($movies); $i++) {
        $formattedStrings[] = '"' . strtoupper($movies[$i]) . '"';
    }
    return implode(",", $formattedStrings);
}

ksort($directors);
foreach ($directors as $key => $value) {
    echo processDirectorName($key) . " : ";
    echo processMovies(...$value);
    echo PHP_EOL;
}
