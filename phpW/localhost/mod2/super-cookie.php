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
    if (array_key_exists('refcode', $_GET)) {
        //store for 30 days
        setcookie('ref', $_GET['refcode'], time() + 60 * 60 * 24 * 30);
        /* Inorder to know what the code was , we include a link to the same script
            , without the query string to avoid storing the cookie on page refresh.
        */
        echo sprintf(
            '<p>The referral code [%s] was stored in a cookie. ' .
                'Reload the page to see the cookie value above. ' .
                '<a href="super-cookie.php">Clear the query string</a>.</p>',
            $_GET['refcode']
        );
        /* In the href giving mod2/super-cookie.php will do
            GET /mod2/mod2/super-cookie.php - No such file or directory
            when click the link
        */
    } else {
        echo sprintf('<p>No referral code was set in query string</p>');
    }

    echo sprintf('<p>Referral code (sent by browser as cookie): [%s]</p>', array_key_exists('ref', $_COOKIE) ? $_COOKIE['ref'] : '-None-');
    ?>
    <!-- Giving mod2/super-cookie will do GET /mod2/mod2/super-cookie.php?refcode=EVN45 - No such file or directory -->
    <form action="super-cookie.php" method="get">
        <input type="text" name="refcode" placeholder="EVENT108" value="EVENT108">
        <input type="submit" value="Apply referral code">
    </form>
</body>

</html>