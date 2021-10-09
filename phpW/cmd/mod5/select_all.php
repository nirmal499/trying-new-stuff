<?php

/** @var PDO $pdo */
$pdo = require 'connection.php';

$statement = "SELECT * FROM users";

$result = $pdo->query($statement);
if ($result === false) {
    list(,, $driverErrMsg) = $pdo->errorInfo();
    echo "Error querying the users table: $driverErrMsg" . PHP_EOL;
    return;
}

/* Here we print the All records line and iterate over all the result
set records and print them, joining the record data using the tab delimiter: */
echo "All records" . PHP_EOL;
while ($record = $result->fetch()) {
    echo implode("\t", $record) . PHP_EOL;
}

$result = $pdo->query("SELECT * FROM users LIMIT 2");
echo PHP_EOL . "Use LIMIT 2" . PHP_EOL;
while ($record = $result->fetch()) {
    echo implode("\t", $record) . PHP_EOL;
}

$result = $pdo->query("SELECT * FROM users WHERE id > 3");
echo PHP_EOL . "Use WHERE id > 3" . PHP_EOL;
while ($record = $result->fetch()) {
    echo implode("\t", $record) . PHP_EOL;
}

$result = $pdo->query("SELECT * FROM users ORDER BY id DESC");
echo PHP_EOL . "Use ORDER BY id DESC" . PHP_EOL;
while ($record = $result->fetch()) {
    echo implode("\t", $record) . PHP_EOL;
}
