<?php

declare(strict_types=1);

/* The above file x.php, is included twice with require_once() statement in the following file y.php.
But from the output you will get that the second instance of inclusion is ignored,  since require_once() statement 
ignores all the similar inclusions after the first one. 

<?php
require_once('x.php');
require_once('x.php');
?>

*/
require_once __DIR__ . '/../src/components/Template.php';
require_once __DIR__ . '/../src/components/Router.php';
require_once __DIR__ . '/../src/handlers/Handler.php';
require_once __DIR__ . '/../src/handlers/Login.php';
require_once __DIR__ . '/../src/handlers/Logout.php';
require_once __DIR__ . '/../src/handlers/Profile.php';

session_start();

$mainTemplate = new \Components\Template('main');
// $templateData = [
//     'title' => 'My main template',
//     'content' => 'My name is XYZ'
// ];
$templateData[] = [];

$router = new \Components\Router();
if ($handler = $router->getHandler()) {
    $content = $handler->handle();
    if ($handler->willRedirect()) {
        return;
    }
    $templateData['content'] = $content;
    $templateData['title'] = $handler->getTitle();
}

/* Here the render function returns the whole processed html named 'main' */
echo $mainTemplate->render($templateData);
