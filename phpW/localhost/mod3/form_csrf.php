<?php

declare(strict_types=1);

/* This will create a session [PHPSESSID by default] 
    This is the name under which the ID [session_id()] is saved in cookies */
session_start();

/* In that genrated session we check if it contains 'csrf-token' key
    if not found then we will create one 'csrf-token' key with
    some random value [64-character token]
*/
if (!array_key_exists('csrf-token', $_SESSION)) {
    $_SESSION['csrf-token'] = bin2hex(random_bytes(32));
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (!array_key_exists('csrf-token', $_POST)) {
        echo '<p>ERROR: The CSRF Token was not found in POST payload.</p>';
    } elseif ($_POST['csrf-token'] !== $_SESSION['csrf-token']) {
        echo '<p>ERROR: The CSRF Token is not valid.</p>';
    } else {
        echo '<p>OK: The CSRF Token is valid. Will continue with email validation...</p>';
    }
}

?>
<br>
<form method="post">
    <label for="email">New email:</label><br>
    <input type="text" name="email" id="email" value=""><br>
    <button type="submit">Submit without CSRF Token</button>
    <button type="submit" name="csrf-token">Submit with empty/invalid CSRF Token</button>
    <button type="submit" name="csrf-token" value="<?php echo $_SESSION['csrf-token'] ?>">Submit with CSRF Token
    </button>
</form>