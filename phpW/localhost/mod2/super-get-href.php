<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    $heroes = [
        "a-bomb" => [
            "id" => 1017100,
            "name" => "A-Bomb (HAS)",
        ],
        "captain-america" => [
            "id" => 1009220,
            "name" => "Captain America",
        ],
        "black-panther" => [
            "id" => 1009187,
            "name" => "Black Panther",
        ],
    ];

    $selectedHero = [];

    /* Check if hero is provided in query string */
    if (array_key_exists('hero', $_GET) && array_key_exists($_GET['hero'], $heroes)) {
        $heroKey = $_GET['hero'];
        $selectedHero = $heroes[$heroKey];
    }

    /* Path function */
    function path(array $queryData)
    {
        /* $queryData = (
            'hero'=>'a-bomb'
        )
        echo http_build_query($queryData) . "\n";
        hero=a-bomb
        */
        return sprintf('./super-get-href.php?%s', http_build_query($queryData));
    }

    $heroLinks = [];
    foreach ($heroes as $heroKey => $heroData) {
        $heroLinks[] = sprintf('<a href="%s">%s</a>', path(['hero' => $heroKey]), $heroData['name']);
    }
    echo sprintf('<p>%s</p>', implode('//', $heroLinks));
    ?>

    <div style="background: #eee">
        <p>Selected hero:</p>
        <?php if ($selectedHero) { ?>
            <h3>ID: <?= $selectedHero['id'] ?></h3>
            <h4><?= $selectedHero['name'] ?></h3>
            <?php } else { ?>
                <p>None</p>
            <?php } ?>
    </div>
    <br>
    <p>The value of $_GET is:</p>
    <pre><?= var_export($_GET, true); ?></pre>
</body>

</html>