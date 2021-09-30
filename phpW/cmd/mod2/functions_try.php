<?php

declare(strict_types=1);
function createWarning(int $maxCredits, string $period, int $waitDays): string
{
    $format = <<<STRING
    You have used upto your max %d credits which you are allowed to spend in a %s.
    You will have to %s days before new credits renewed.
    STRING;

    return sprintf($format, $maxCredits, $period, $waitDays);
}

echo "Your Warning: " . createWarning(56, '5 months', 5) . PHP_EOL;

/* ---------------------------------------------------------------------------------- */

/* Show arguments passed in the functions */
function dynamicArgs()
{
    $count = func_num_args();
    $arguments = func_get_args();
    if ($count > 0) {
        for ($i = 0; $i < $count; $i++) {
            echo "Argument $i: $arguments[$i]" . PHP_EOL;
        }
    }
}

dynamicArgs(1, 2, "A string", 56.9, true);

/* ------------------------------------------------------------------- */
function countByReference(int &$count): void
{
    $count++;
}

$count = 0; //This is Global Variable
countByReference($count);
countByReference($count);
countByReference($count);
echo "The global count value is : $count" . PHP_EOL;

/* ---------------------------------------------------------------------- */

$callable0 = function (float $value): int {
    if (0 <= $value) {
        return 1;
    }
    return -1;
};
echo $callable(-11.4) . PHP_EOL;

/* Use of anonymous functions */
$a = 15;
$callable1 = function () use ($a) {
    return $a;
};
$a = 'different';

echo $callable1() . PHP_EOL;

$b = 15;
$callable2 = function () use (&$b) {
    return $b;
};
$b = 'different';
echo $callable2() . PHP_EOL;
