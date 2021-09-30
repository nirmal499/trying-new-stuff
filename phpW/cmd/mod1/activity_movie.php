<?php

$directors = [
    "Steven Spielberg" => [
        "The Terminal", "Minority Report", "Catch Me If You Can",
        "Lincoln", "Bridge of Spies"
    ],
    "Christopher Nolan" => [
        "Dunkirk", "Interstellar", "The Dark Knight Rises",
        "Inception", "Memento"
    ],
    "Martin Scorsese" => ["Silence", "Hugo", "Shutter Island", "The Departed", "Gangs of New York"],
    "Spike Lee" => [
        "Do the Right Thing", "Malcolm X", "Summer of Sam", "25th Hour", "Inside Man"
    ],
    "Lynne Ramsey" => ["Ratcatcher", "Swimmer", "Morvern Callar", "We Need To Talk About Kevin", "You Were Never Really Here"]
];

$no_of_directors1 = $argv[1] ?? 5;
$no_of_movies1 = $argv[2] ?? 5;

echo "\nUsing foreach loop" . PHP_EOL;

/* Using foreach loop
    You don't need to worry about $no_of_directors1 to be greater than 5 and so for
    $no_of_movies1 to be greater than 5
*/
$directorCounter = 1;
foreach ($directors as $director => $movies) {
    /* Condition for breaking out of the loop */
    if ($directorCounter > $no_of_directors1) {
        break;
    }

    echo "$director's  movies: " . PHP_EOL;

    $moviesCounter = 1;
    foreach ($movies as $movie) {
        /* Condition for breaking out of the loop */
        if ($moviesCounter > $no_of_movies1) {
            break;
        }

        echo " > $movie " . PHP_EOL;
        $moviesCounter++;
    }
    $directorCounter++;
}
