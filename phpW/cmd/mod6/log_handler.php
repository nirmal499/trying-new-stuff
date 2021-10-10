<?php

$errorHandler = function (int $code, string $message, string $file, int $line) {
    /* $stream is cached for subsequent calls using the static keyword
        to initialize the stream variable */
    static $stream;
    if (is_null($stream)) {
        $stream = fopen(__DIR__ . '/app2.log', 'a');
    }
    fwrite(
        $stream,
        date(DATE_W3C) . " :: $message, in [$file] on line [$line] (error code $code)" . PHP_EOL
    );
};

set_error_handler($errorHandler, E_ALL);

echo $width / $height, PHP_EOL;
