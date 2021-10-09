<?php

$filePath = __DIR__ . '/sample/sample_list.csv';
/* 'r' -> Open for reading only; placce the file pointer at the beginning of the file */
$fileResource = fopen($filePath, 'r');

if ($fileResource === false) {
    exit(sprintf('Cannot read [%s] file.', $filePath));
}

echo "-------------------------------------------Using fread----------------------------------" . PHP_EOL;

$readLength = 64;
$iterations = 0;
while (!feof($fileResource)) {
    $iterations++;
    $chunk = fread($fileResource, $readLength);
    echo $chunk;
}
//fclose($fileResource);

echo sprintf("\n%d iteration(s)", $iterations);
echo PHP_EOL;

echo "-------------------------------------------Using fgets-----------------------------------------" . PHP_EOL;

/* We move the pointer at the beginning of the file */
fseek($fileResource, 0);

$lineNumber = 0;
while (!feof($fileResource)) {
    $lineNumber++;
    $line = fgets($fileResource);
    echo sprintf("Line %d: %s", $lineNumber, $line);
}
//fclose($fileResource);

echo PHP_EOL;

echo "-------------------------------------------Using fgetcsv-----------------------------------------" . PHP_EOL;

/* We move the pointer at the beginning of the file */
fseek($fileResource, 0);

$recordNumber = 0;
while (!feof($fileResource)) {
    $recordNumber++;
    $line = fgetcsv($fileResource);
    echo sprintf("Line %d: %s", $recordNumber, print_r($line, true));
}
fclose($fileResource);

echo PHP_EOL;
