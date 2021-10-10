<?php

/* We will define a custom exception, with extended functionality, which
we will throw and catch, and the custom formatted message will then be printed on the
screen. Specifically, this is a script that validates an email address: */

class InvalidEmail extends Exception
{
    private $context = [];

    public function setContext(array $context)
    {
        $this->context = $context;
    }

    public function getContext(): array
    {
        return $this->context;
    }
}

function validateEmail(array $input)
{
    if (!isset($input[1])) {
        /* Throwing */
        throw new InvalidArgumentException('No value to check.');
    }
    $testInput = $input[1];
    if (!filter_var($testInput, FILTER_VALIDATE_EMAIL)) {
        $error = new InvalidEmail('The email validation has failed.');
        $error->setContext(['testValue' => $testInput]);
        /* Throwing */
        throw $error;
    }
}

try {
    validateEmail($argv);
    echo 'The input value is valid email.', PHP_EOL;
} catch (Throwable $e) {
    /* Catching */
    echo sprintf(
        'Caught [%s]: %s (file: %s, line: %s, context: %s)',
        get_class($e),
        $e->getMessage(),
        $e->getFile(),
        $e->getLine(),
        $e instanceof InvalidEmail ? json_encode($e->getContext()) : 'N/A'
    ) . PHP_EOL;
}
