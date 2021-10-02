<?php

function add()
{
    $sum = 0;
    $args = func_get_args();
    foreach ($args as $arg) {
        if (gettype($arg) == 'integer' || gettype($arg) == 'double')
            $sum += $arg;
    }

    return $sum;
}

echo add(1, 2) . PHP_EOL; //outputs '3'
echo add(10.5, 'jkf', 'kl', 2.5) . PHP_EOL; //outputs '13'
echo add(10.5, 2.5, 'jk', 9.6, true, 55.2) . PHP_EOL; //outputs '77.8
