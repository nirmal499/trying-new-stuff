<?php

// namespace CompanyName;

// class Example
// {
//     public function doSomething()
//     {
//         echo "PHP is great!" . PHP_EOL;
//     }
// }
namespace CompanyName;

use Monolog\Logger;
use Ramsey\Uuid\Uuid;

class Example
{
    protected $logger;
    public function __construct(Logger $logger)
    {
        $this->logger = $logger;
    }

    public function doSomething()
    {
        echo "Something" . PHP_EOL;

        $this->logger->info('This is an informational message');
        $this->logger->error('This message logs an error condition');
        $this->logger->critical('This message logs unexpected exceptions');
    }

    public function printUuid()
    {
        echo Uuid::uuid4()->toString() . PHP_EOL;
    }
}
