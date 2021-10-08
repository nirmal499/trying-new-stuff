<?php

declare(strict_types=1);

namespace Handlers;

class Profile extends Handler
{
    public function handle(): string
    {
        if (!array_key_exists('username', $_SESSION)) {
            /* Here inside handle function, render function is get called which returns
             the whole processed html name 'login-form' */
            return (new Login)->handle();
        }
        /* Here the render function returns the whole processed html name 'profile' */
        return (new \Components\Template('profile'))->render([
            'username' => $_SESSION['username'],
            'sessionData' => var_export($_SESSION, true),
        ]);
    }

    public function getTitle(): string
    {
        return 'Profile - ' . parent::getTitle();
    }
}
