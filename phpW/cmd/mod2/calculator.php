<?php

declare(strict_types=1);

/**
 * It returns factorial of the given input
 */
function factorial(int $number): int
{
    $fact = 1;
    for ($i = $number; $i > 1; $i--) {
        $fact *= $i;
    }
    return $fact;
}

/**
 * It returns the sum of the paramters passed
 * @return float
 */
function sum(): float
{
    return array_sum(func_get_args());
}

/**
 * Check if the given number is prime or not
 * @param int $number
 * @return bool
 */
function prime(int $number): bool
{
    if ($number <= 2) {
        return false;
    }

    for ($i = 2; $i <= sqrt($number); $i++) {
        if ($number % $i === 0) {
            return false;
        }
    }
    return true;
}

function performOperation(string $operation)
{
    switch ($operation) {
        case 'factorial':
            /* get the 2nd paramter. It must be an int so, we typecasted it */
            $number = (int) func_get_arg(1);
            return factorial($number);
        case 'sum':
            /* get all parameters */
            $params = func_get_args();
            /*  remove the first paramter, since it is the operation that we are */
            array_shift($params);
            return call_user_func_array('sum', $params);

        case 'prime':
            $number = (int)func_get_arg(1);
            return prime($number);
        default:
            echo "ERROR!! UNDEFINED OPERATION" . PHP_EOL;
    }
}

echo "Factorial: " . performOperation('factorial', 3) . PHP_EOL;
echo "Sum: " . performOperation('sum', 4, 2.5, 1) . PHP_EOL;
echo "isPrime: " . performOperation('prime', 7) ? "It is prime" : "It is not prime";
echo PHP_EOL;
