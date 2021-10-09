<?php

$sourceFilePath = 'sample/file_to_copy.txt';
$targetFilePath = 'sample/file_to_copy.txt.bak';

if (!is_file($sourceFilePath)) {
    echo sprintf('The [%s] file does not exist.', $sourceFilePath) . PHP_EOL;
    return;
}

/* If destination file already exists, then it will be overwritten */
if (copy($sourceFilePath, $targetFilePath)) {
    echo sprintf('The [%s] file was copied to [%s].', $sourceFilePath, $targetFilePath) . PHP_EOL;
} else {
    echo sprintf('The [%s] file cannot be copied to [%s].', $sourceFilePath, $targetFilePath) . PHP_EOL;
}
