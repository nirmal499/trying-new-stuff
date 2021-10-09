<?php

$fileFwrite = './sample/file_to_write1.txt';
/* 'w+' -> Open for reading and writing; rest is same as 'w'
    For 'w' -> Open for writing only. Place the file pointer at the
    beginning of the file and truncate the file to zero length;
    If file does not exist, attempt to create
*/
$fp = fopen($fileFwrite, 'w+');

echo "---------------------------------------------------------Using w+-------------------------------------------------------" . PHP_EOL;
$written = fwrite($fp, 'File written with fwrite().' . PHP_EOL);

if (false === $written) {
    echo 'Error writing with fwrite.' . PHP_EOL;
} else {
    echo sprintf("> Successfully written %d bytes to [%s] with fwrite():", $written, $fileFwrite) . PHP_EOL;
    fseek($fp, 0);
    echo fread($fp, filesize($fileFwrite)) . PHP_EOL;
}
fclose($fp);


echo "---------------------------------------------------------Using file_put_contents()-------------------------------------------------------" . PHP_EOL;
$fileFpc = 'sample/file_to_write2.txt';
$written = file_put_contents($fileFpc, 'File written with file_put_contents().' . PHP_EOL);

if (false === $written) {
    echo 'Error writing with fwrite.' . PHP_EOL;
} else {
    echo sprintf("> Successfully written %d bytes to [%s] with file_put_contents():", $written, $fileFpc) . PHP_EOL;
    echo file_get_contents($fileFpc) . PHP_EOL;
}
