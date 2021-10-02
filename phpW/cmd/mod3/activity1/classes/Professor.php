<?php

declare(strict_types=1);

namespace ProfessorNamespace;

require_once 'Student.php';

use StudentNamespace\Student;

class Professor
{
    private string $name;
    private string $title = 'Prof. ';
    private $students = array();

    /* type1 */
    function __construct(string $name, Student ...$students)
    {
        $this->name = $name;
        $this->students = $students;
    }

    /* OR type2*/
    // function __construct(str$name, string $lastName, array $students)
    // {
    //     $this->firstName = $firstName;
    //     $this->lastName = $lastName;
    //     foreach ($students as $student) {
    //         if ($student instanceof Student) {
    //             $this->students[] = $student;
    //         }
    //     }
    // }

    public function changeName(string $name)
    {
        $this->name = $name;
    }

    public function getName()
    {
        return $this->name;
    }

    public function setTitle($title)
    {
        $this->title = $title;
    }

    public function printStudents()
    {
        $noOfStudents = count($this->students);
        echo "$this->title $this->name's students( $noOfStudents ) " . PHP_EOL;
        for ($i = 0; $i < $noOfStudents; $i++) {
            echo $i + 1 . " " . $this->students[$i]->getName() . PHP_EOL;
        }
    }
}
