<?php
$filePath = '../../details.txt';
header('Content-Type: text/plain');
header('Content-Length: ' . filesize($filePath));
header(sprintf(
    'Content-Disposition: attachment; filename=ā%sā',
    basename($filePath)
));
readfile($filePath);
