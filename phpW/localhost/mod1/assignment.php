<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" rel="stylesheet" />
  <title>PHP Workshop</title>
</head>

<body>
  <div class="container">
    <?php

    echo '<u>Assignment by value</u><br/>';
    $animal1 = 'Cat';
    $animal2 = $animal1;
    echo $animal1 . ' - ' . $animal2;
    echo '<hr/>';

    echo '<u>Assignment by reference</u><br/>';
    $animal3 = 'Elephant';

    /* $animal4 is like an alias name to variable $animal3 */
    $animal4 = &$animal3;
    echo $animal3 . ' - ' . $animal4;
    echo '<br/>';

    $animal4 = 'Giraffe';
    echo $animal3 . ' - ' . $animal4;
    echo '<hr/>';

    echo '<u>Isset Check</u><br/>';
    $name1 = '';
    $name2 = null;
    echo 'Checking $name1 : ';
    var_dump(isset($name1));
    echo '<br/>';

    echo 'Checking $name2 : ';
    var_dump(isset($name2));
    echo '<br/>';

    echo 'Checking undecalared variable $name3: ';
    var_dump(isset($name3));
    echo '<hr/>';

    echo '<u>Information about Avengers</u><br/>';
    $movieName = $_GET['movieName'] ?? 'DefaultName';
    $movieStar = $_GET['movieStar'] ?? 'DefaultStar';
    $movieYear = $_GET['movieYear'] ?? 2001;

    echo 'Based on the input, here is the information so far: <br/>';
    echo "<b>$movieStar</b> starred in the movie <b>$movieName</b> which was released in year <b>$movieYear</b><br/>";

    $preferedHost = 'Linux';
    $preferedLanguage = 'PHP';
    $storeString = <<<STRING
    This string is spanned across multiple lines.
    The preferred host in this example is $preferedHost.
    The preferred language in this example is $preferedLanguage.
    STRING;

    echo "The String is : $storeString";

    ?>
  </div>
</body>

</html>