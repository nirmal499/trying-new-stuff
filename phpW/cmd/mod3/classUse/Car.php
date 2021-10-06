<?php

declare(strict_types=1);
// require_once 'AbstractVehicle.php';
// require_once 'DriveInterface.php';

/* This will load the classes or interfaces only when thet are called 
    This is called autoloading
*/
spl_autoload_register(function ($classOrInterfaceName) {
    require_once $classOrInterfaceName . '.php';
});


class Car extends AbstractVehicle implements DriveInterface
{
    public $doors = 4;
    public $passengerCapacity = 5;
    public $steeringWheel = true;
    public $transmission = 'Manual';

    private $hasKeyinIgnition = true;

    public function start()
    {
        if ($this->hasKeyinIgnition) {
            $this->engineStatus = true;
        }
    }

    /* All these functions should be public since they
        suppoed to be as per the interface statement
    */
    public function changeSpeed($speed)
    {
        echo "The car has been accelerated to " . $speed . " kph. " .
            PHP_EOL;
    }
    function changeGear($gear)
    {
        echo "Shifted to gear number " . $gear . ". " . PHP_EOL;
    }
    public function applyBreak()
    {
        echo "All the 4 breaks in the wheels applied. " . PHP_EOL;
    }

    /* ------------------------------------------------------------------ */
    function justForFunCar()
    {
        echo "JUST FOR calling from Car" . PHP_EOL;
        parent::justForFunAV();
    }
}

$car = new Car('Honda', 'Civic', 'Red', 4, '23CJ4567');

$car->start();
echo "The car is " . ($car->getEngineStatus() ? 'running' : 'stopped') . PHP_EOL;
$car->stop();
echo "The car is " . ($car->getEngineStatus() ? 'running' : 'stopped') . PHP_EOL;
$car->changeSpeed(65);
$car->applyBreak();
$car->changeGear(4);
$car->changeSpeed(75);
$car->applyBreak();

/* Creating Runtime attributes */
$car->ownerName = 'John Doe';
echo " Owner: " . $car->ownerName . PHP_EOL;
$car->year = 2015;
echo " Year: " . $car->year . PHP_EOL;
//$car->wipers = 90;
echo $car->wipers . PHP_EOL;

/*
Here we are creating runtime METHOD 
We can see that we are able to do method overloading -> Polymorphism 
*/
$car->honk();
$car->honk('gently');
$car->honk('louder', 'siren');

/* ----------------------------------------------------------------------- */
$car->justForFunCar();
