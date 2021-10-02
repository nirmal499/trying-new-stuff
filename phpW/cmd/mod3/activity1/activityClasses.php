<?php

declare(strict_types=1);

// spl_autoload_register(function ($classOrInterfaceName) {
//     // $classOrInterfaceName = str_replace('\\', '/', $classOrInterfaceName);
//     $path = './classes/' . $classOrInterfaceName;
//     //require_once $path . '.php';
//     var_dump($path);
// });

/* OR */
require_once './classes/Professor.php';
require_once './classes/Student.php';

use ProfessorNamespace\Professor;  /* It basically says that Professor class is inside the Professor namespace named as 'ProfessorNamespace' */
use StudentNamespace\Student; /* It basically says that Student class is inside the Student namespace named as 'StudentNamespace' */

$students = [
    new Student('Elwin Ransom'),
    new Student('Maurice Phipps'),
    new Student('James Dunworthy'),
    new Student('Alecto Carrow')
];

/* This is the way to provide when we use type1 */
$professor = new Professor('Charles Kingsfield', ...$students);

/* This is the way to provide when we use type2 */
// $professor2 = new Professor('Charles Kingsfield', array(
//     new Student('Elwin Ransom'),
//     new Student('Maurice Phipps'),
//     new Student('James Dunworthy'),
//     new Student('Alecto Carrow')
// ));

//$professor->setTitle('Dr.');
$professor->printStudents();
