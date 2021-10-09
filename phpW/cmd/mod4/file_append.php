<?php

$fileFwrite = 'sample/file_to_append1.txt';
/* 'a+' -> Open for reading and writing; and rest are the same as 'a' 
    'a' -> Open for writing only; place the file pointer at the end of the file
    If file does not exists, attempt to create it.
*/
$fp = fopen($fileFwrite, 'a+');

echo "-----------------------------------------Using a+----------------------------------------------------------" . PHP_EOL;
$written = fwrite($fp, 'File written with fwrite().' . PHP_EOL);/* We are also appending EOL */

if (false === $written) {
    echo 'Error writing with fwrite.' . PHP_EOL;
} else {
    echo sprintf("> Successfully written %d bytes to [%s] with fwrite():", $written, $fileFwrite) . PHP_EOL;
    fseek($fp, 0);
    echo fread($fp, filesize($fileFwrite)) . PHP_EOL;
}
fclose($fp);

echo "-----------------------------------------Using file_put_contents()----------------------------------------------------------" . PHP_EOL;

$fileFpc = 'sample/file_to_append2.txt';
$written = file_put_contents($fileFpc, 'File written with file_put_contents().' . PHP_EOL, FILE_APPEND);

if (false === $written) {
    echo 'Error writing with fwrite.' . PHP_EOL;
} else {
    echo sprintf("> Successfully written %d bytes to [%s] with file_put_contents():", $written, $fileFpc) . PHP_EOL;
    echo file_get_contents($fileFpc) . PHP_EOL;
}
