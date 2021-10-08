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
    if (!session_start()) {
        echo "Cannot start the session. ";
        return;
    }

    /* This will create a session [PHPSESSID by default] 
        This is the name under which the ID is saved in cookies
    */
    $sessionName = session_name();

    /*
        You have to call session_start() in order to initialize the session. PHP will then try to load the 
        session ID stored in the PHPSESSID variable (which is the default name) from the Cookie
        request header and, if such an entry name does not exist, then a fresh session will be 
        started and the session ID will be sent back to the client with the current response in
        the headers
    */
    if (array_key_exists($sessionName, $_COOKIE)) {
        echo  sprintf('<p>The cookie with session name [%s] and value [%s] ' .
            'is set in browser, and sent to script.</p>', $sessionName, $_COOKIE[$sessionName]);
        echo sprintf('<p>The current session has the following data: <pre>%s</pre></p>', var_export($_SESSION, true));
    } else {
        echo sprintf('<p>The cookie with session name [%s] does not exist</p>', $sessionName);
        echo sprintf(
            '<p>A new cookie will be set for session name [%s], with value [%s]</p>',
            $sessionName,
            session_id()
        );
        /* We don't need to use a function to set the cookie with the generated session ID.
            This is done automatically when invoking session_start()
        */
        $names = [
            "A-Bomb (HAS)",
            "Captain America",
            "Black Panther",
        ];
        $chosen = $names[rand(0, 2)];
        /* Store the random entry in a session under the name key  */
        $_SESSION['name'] = $chosen;

        echo sprintf('<p>The name [%s] was picked and stored in current session.</p>', $chosen);
        echo sprintf(
            'List of headers to send in response: <pre>%s</pre>',
            implode("\n", headers_list())
        );
        /* Here the implode function attach all the comma separated value with '\n' */
    }
    ?>
</body>

</html>