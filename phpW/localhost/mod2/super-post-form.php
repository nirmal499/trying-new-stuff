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
    if (array_key_exists('hero', $_POST) && array_key_exists($_POST['hero'], $heroes)) {
        $heroKey = $_POST['hero'];
        $selectedHero = $heroes[$heroKey];
    }
    ?>


    <form action="./super-post-form.php" method="post" enctype="application/x-www-form-urlencoded">
        <label for="hero_select">Select your hero: </label>
        <select name="hero" id="hero_select">
            <?php foreach ($heroes as $heroKey => $heroData) { ?>
                <option value="<?= $heroKey ?>">
                    <?= $heroData['name'] ?>
                </option>
            <?php } ?>
        </select>
        <input type="submit" value="Show">
    </form>

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
    <p>The value of $_POST is:</p>
    <pre><?= var_export($_POST, true); ?></pre>

</body>

</html>