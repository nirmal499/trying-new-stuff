<?php

declare(strict_types=1);

namespace StudentNamespace;

class Student
{
    private string $name;

    function __construct(string $name)
    {
        $this->name = $name;
    }

    public function changeName(string $name)
    {
        $this->name = $name;
    }

    public function getName()
    {
        return $this->name;
    }
}
