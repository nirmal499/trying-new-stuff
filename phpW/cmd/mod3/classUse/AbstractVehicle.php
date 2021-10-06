<?php

declare(strict_types=1);

require_once 'PriceTrait.php';

abstract class AbstractVehicle
{

    use Pricetrait;

    public string $make;
    public string $model;
    public string $color;
    protected int $noOfWheels; /* Can be accessed by the derived class */
    private string $engineNumber;
    public static $counter = 0;
    protected bool $engineStatus =  false;
    protected float $price;
    /* This is for creating runtime attributes
        Since we are not specifying that which and how many attributes
        are accepted. So, infinite number of attributes can be created at
        runtime
    */
    private $runtimeAttributes = array();


    /* Special functions for creating runtime attributes */
    function __set($attribute, $value)
    {
        $this->runtimeAttributes[$attribute] = $value;
    }

    function __get($attribute)
    {
        if (array_key_exists($attribute, $this->runtimeAttributes)) {
            return $this->runtimeAttributes[$attribute];
        } else {
            echo "Error: undefined attribute. " . PHP_EOL;
        }
    }

    /* Special function for creating runtime non static method */
    function __call($method, $arguments)
    {
        /* By doing this we can allow calling specific method */
        switch ($method) {
            case 'honk':
                if (isset($arguments[0])) {
                    echo "Honking $arguments[0]" . PHP_EOL;
                } else {
                    echo "No arguments provided..." . PHP_EOL;
                }

                if (isset($arguments[1])) {
                    echo "$arguments[1] enabled..." . PHP_EOL;
                }
                break;
            default:
                echo "The method $method() called. " . PHP_EOL;
                break;
        }
    }

    /* This constructor is for derived class
        Keep in mind that with this contructor AbstractVehicle class should never be
        instantiated since it an abstract class
    */
    function __construct(
        string $make = 'DefaultMake',
        string $model = 'DefaultModel',
        string $color = 'DefaultColor',
        int $noOfWheels = 4,
        string $engineNo = 'XXXXXXXX',
        float $price = 1000.0
    ) {
        $this->make = $make;
        $this->model = $model;
        $this->color = $color;
        $this->noOfWheels = $noOfWheels;
        $this->engineNumber = $engineNo;
        self::$counter++;
        $this->price = $price;
        echo "Abstract Parent contructor called" . PHP_EOL;
    }

    /* All set functions */
    function setNoOfWheels(string $noOfWheels)
    {
        $this->noOfWheels = $noOfWheels;
    }
    function setEngineNo(string $engineNumber)
    {
        $this->engineNumber = $engineNumber;
    }


    /* All gets functions */
    function getNoOfWheels()
    {
        return $this->noOfWheels;
    }
    function getEngineNumber()
    {
        return $this->engineNumber;
    }

    abstract function start();

    function stop()
    {
        $this->engineStatus = false;
    }

    function getEngineStatus()
    {
        return $this->engineStatus;
    }

    protected function justForFunAV()
    {
        echo "JUST FOR calling from AbstractVehicle" . PHP_EOL;
    }
}
