<?php

declare(strict_types=1);

/* The built-in filter_input() function is used to process the data from the request and, if needed, will alter it to match the expected format */

$stars = filter_input(INPUT_POST, 'stars', FILTER_SANITIZE_NUMBER_INT);
$message = filter_input(INPUT_POST, 'message', FILTER_SANITIZE_STRING);

/* ------------------------------------------------------------------------------------------------------------------------------ */
/* Simpler approach */
//$stars = (int)$_POST['stars'] ?? 0;
/* ------------------------------------------------------------------------------------------------------------------------------- */

/* NULL will be returned when the input does not exist, FALSE if the filter fails, and a scalar otherwise */
if (null === $stars) {
    //  treat the case when input does not exist
    echo '<p>Stars input is not set.</p>';
} elseif (false === $stars) {
    //  treat the case when the filter fails
    echo '<p>Stars failed to pass the sanitization filter.</p>';
} else {
    /*first approach for validating stars input */
    $stars = (int)$stars;
    if ($stars < 1 || $stars > 5) {
        echo '<p>Stars can have values between 1 and 5.</p>';
    }
    /*second approach */
    // $stars = filter_var($stars, FILTER_VALIDATE_INT, [
    //     'options' => [
    //         'default' => 0, // value to return if the filter fails
    //         'min_range' => 1,
    //         'max_range' => 5,
    //     ]
    // ]);
    // if (0 === $stars) {
    //     echo '<p>Stars can have values between 1 and 5.</p>';
    // }
}

/* Validate the message input */
if ($message === null) {
    // treat the case when input does not exist
    echo '<p>Message input is not set.</p>';
} elseif (false === $message) {
    // treat the case when the filter fails
    echo '<p>Message failed to pass the sanitization filter.</p>';
}

echo sprintf("<p>Stars: %s</p><p>Message: %s</p>", var_export($stars, true), var_export($message, true));

?>

<hr />

<form method="post">
    <label for="stars">Stars: </label><br>
    <input type="text" name="stars" id="stars"><br>
    <label for="message">Message: </label><br>
    <textarea name="message" id="message" rows="10" cols="40"></textarea><br>
    <input type="submit" value="Send">
</form>