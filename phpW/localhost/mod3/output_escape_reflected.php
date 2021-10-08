<?php

declare(strict_types=1);

if (isset($_GET['s'])) {
    echo sprintf('<p>You have searched for: <strong>%s</strong></p>', htmlentities($_GET['s']));
} else {
    echo "Use the form to start searching.";
}
?>

<form action="./output_escape_reflected.php" method="get">
    <label for="search">Search term:</label>
    <!-- You are asked to print the searched value back to the page and to keep the current search term in the search input field.-->
    <input type="text" id="search" name="s" value="<?= htmlentities($_GET['s'] ?? '', ENT_QUOTES); ?>">
    <input type="submit" value="Search">
</form>

<!-- Note that this time, we use ENT_QUOTES as the second argument, which will make the function
escape both the single and double quotes; without this argument, only the double
quotes are escaped. The reason we use this approach, even though the value
attribute is assigned the value using double quotes, is that it allows the use of single
quotes as well, so it's safer to escape both types of quotes 
-->