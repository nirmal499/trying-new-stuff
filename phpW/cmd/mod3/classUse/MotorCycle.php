<?php

declare(strict_types=1);

/* This approach ends up including a good number of files in any PHP script */
// require_once 'AbstractVehicle.php';
// require_once 'DriveInterface.php';

/* This will load the classes or interfaces only when thet are called 
    This is called autoloading
*/
spl_autoload_register(function ($classOrInterfaceName) {
    require_once $classOrInterfaceName . '.php';
});

class MotorCycle extends AbstractVehicle implements DriveInterface
{
    /* Since in the Abstract class $noOfWheels is protected
        so, here the $noOfWheels can be either public or protected
        but not private [Since when keeping it private gives us a error like this
            Access level to MotorCycle::$noOfWheels must be protected (as in class AbstractVehicle) or weaker
        ]
    */
    protected int $noOfWheels = 2; /* Attribute overriding */
    private int $stroke = 4;
    private bool $hasKey = true;
    private bool $hasKicked = true;
    public function start()
    {
        if ($this->hasKey && $this->hasKicked) {
            $this->engineStatus = true;
        }
    }

    /* Method Overriding 
        Imagine there is a discount of 5% on all kinds of motorcycles for a special occasion
    */
    function getPrice()
    {
        return $this->price - $this->price * 0.05;
    }

    /* All these functions should be public since they
        suppoed to be as per the interface statement
    */
    public function changeSpeed($speed)
    {
        echo "The motorcycle has been accelerated to " . $speed . " kph. " .
            PHP_EOL;
    }
    public function changeGear($gear)
    {
        echo "Gear shifted to " . $gear . ". " . PHP_EOL;
    }
    function applyBreak()
    {
        echo "The break applied. " . PHP_EOL;
    }
}

$motorcycle = new Motorcycle('Kawasaki', 'Ninja', 'Orange', 2, '53WVC14598', 2000.0);
$motorcycle->setPrice(5000);
echo "The price is " . $motorcycle->getPrice() . PHP_EOL;

$motorcycle->start();
echo "The motorcycle is " . ($motorcycle->getEngineStatus() ? 'running' : 'stopped') . PHP_EOL;
$motorcycle->stop();
echo "The motorcycle is " . ($motorcycle->getEngineStatus() ? 'running' : 'stopped') . PHP_EOL;
$motorcycle->changeSpeed(45);
$motorcycle->changeGear(3);
$motorcycle->applyBreak();
