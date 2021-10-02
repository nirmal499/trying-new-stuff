<?php

class A
{
    public function say()
    {
        echo 'Base ';
    }
}

trait T
{
    public function say()
    {
        parent::say();
        echo ' Trait';
    }
}

class B extends A
{
    use T;
}

$obj = new B();
$obj->say();
echo PHP_EOL;
