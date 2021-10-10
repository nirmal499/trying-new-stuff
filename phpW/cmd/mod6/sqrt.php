<?php

/* The E_ERROR and E_USER_ERROR error types will cause the
script to be halted immediately on account of their nature */
//require_once 'error_handler.php';

require_once 'all_error_handler.php';

if (!array_key_exists(1, $argv)) {
    /* Here program will halt */
    trigger_error('This script requires a number as first argument.', E_USER_ERROR);
}

$input = $argv[1];

if (!is_numeric($input)) {
    /* Here also program will halt */
    trigger_error(sprintf('A number is expected, got %s.', $input), E_USER_ERROR);
}

if (is_float($input * 1)) {
    $input = round($input);
    trigger_error(
        sprintf(
            'Decimal numbers are not allowed for this operation. Will use the rounded integer value [%d].',
            $input
        ),
        E_USER_WARNING
    );
}

if ($input < 0) {
    $input = abs($input);
    trigger_error(
        sprintf(
            'A negative number is not allowed for this operation. Will use the absolute value [%d].',
            $input
        ),
        E_USER_WARNING
    );
}

echo sprintf('sqrt(%d) = ', $input), sqrt($input), PHP_EOL;
