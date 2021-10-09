<?php

/** @var PDO $pdo */
$pdo = require 'connection.php';

$createStmt = "create table if not exists users (
    id int not null primary key auto_increment,
    email varchar(254) not null unique,
    signup_time datetime default current_timestamp not null
)";

// $createStmt = "CREATE TABLE users
// (
//     id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
//     email VARCHAR(254) NOT NULL UNIQUE,
//     signup_time DATETIME default CURRENT_TIMESTAMP NOT NULL
// )";

if ($pdo->exec($createStmt) === false) {
    list(,, $driverErrMsg) = $pdo->errorInfo();
    echo "Error creating the users table: $driverErrMsg" . PHP_EOL;
    return;
}

echo "The users table was successfully created." . PHP_EOL;
