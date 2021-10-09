<?php


$host = '127.0.0.1';
$db   = 'phpdb';
$user = 'phpuser';
$pass = '4K2#f%[&u!+5M[M{';
$port = "3306";
$charset = 'utf8mb4';

$dsn = "mysql:host=$host;dbname=$db;port=$port;charset=$charset";
$options = [
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    //    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
];
$pdo = new PDO($dsn, $user, $pass, $options);

// echo sprintf(
//     "Connected to MySQL server v%s, on %s",
//     $pdo->getAttribute(PDO::ATTR_SERVER_VERSION),
//     $pdo->getAttribute(PDO::ATTR_CONNECTION_STATUS)
// ) . PHP_EOL;

return $pdo;
