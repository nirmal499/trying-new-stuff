<?php

class Magic
{
    private $arr = array('attribute1' => NULL, 'attribute2' => NULL);

    /* These special functions must be public
        These are for creating runtime attributes
    */
    function __set($attribute, $value)
    {
        if (array_key_exists($attribute, $this->arr)) {
            $this->arr[$attribute] = $value;
        } else {
            echo 'Error: The attribute is not allowed';
        }
    }

    public function __get($attribute)
    {
        if (array_key_exists($attribute, $this->arr)) {
            return $this->arr[$attribute];
        } else {
            echo 'Error: undefined attribute';
        }
    }

    /* These special functions must be public
        These are for creating runtime METHOD
    */
    public function __call($methodName, $arguments)
    {
        echo "Runtime method created" . PHP_EOL;
        var_dump($arguments);
        /* By doing this we can allow calling specific METHOD */
        switch ($methodName) {
            case 'magicShow1':
                if (isset($arguments[0])) {
                    echo "magic showing $arguments[0]" . PHP_EOL;
                } else {
                    echo "No arguments provided..." . PHP_EOL;
                }

                if (isset($arguments[1])) {
                    echo "$arguments[1] enabled..." . PHP_EOL;
                }
                break;
            default:
                echo "The Unspecified method $methodName() called. " . PHP_EOL;
                break;
        }
    }

    public static function __callStatic($methodName, $arguments)
    {
        echo "Runtime static method named as $methodName() created" . PHP_EOL;
        var_dump($arguments);
    }
}

$obj = new Magic();
$obj->attribute1 = 'This is loaded in runtime';
$obj->attribute2 = 45;

echo "Everything is okay!" . PHP_EOL;


echo PHP_EOL;
echo PHP_EOL;
$obj->atttribute3 = 78; /* The attribute is not allowed since it was not specified $arr  */
echo PHP_EOL;
echo PHP_EOL;


echo "attribute1: $obj->attribute1" . PHP_EOL;
echo "attribute2: $obj->attribute2" . PHP_EOL;

$obj->magicShow1('firt-argument', 45, true);
echo PHP_EOL;
Magic::magicShow2('first-arggument', 45, 'KO');
echo PHP_EOL;
$obj->magicShow2('firt-argument', 45, true);
