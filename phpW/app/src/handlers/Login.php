<?php

declare(strict_types=1);

namespace Handlers;

class Login extends Handler
{
    public function handle(): string
    {
        /* If $_SESSION has 'username' key  */
        if (isset($_SESSION['username'])) {
            $this->requestRedirect('/');
            return '';
        }
        $username = 'admin';
        /* 
            To generate password hash with command line
            > php -r "echo PHP_EOL . password_hash('admin', PASSWORD_BCRYPT) . PHP_EOL;"
        */
        /* Here we generate a hash form for our password which is 'admin'
             and username is 'admin'
        */
        $passwordHash = password_hash('admin', PASSWORD_BCRYPT);
        /* Logging to PHP server console */
        //error_log($passwordHash, 0);

        $formError = [];
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $formUsername = $_POST['username'] ?? '';
            $formPassword = $_POST['password'] ?? '';
            if ($formUsername !== $username) {
                $formError = ['username' => sprintf('The username [%s] was not found.', $formUsername)];
            } elseif (!password_verify($formPassword, $passwordHash)) {
                $formError = ['password' => 'The provided password is invalid.'];
            } else {
                $_SESSION['username'] = $username;

                /* A \ before the beginning of a function represents the Global Namespace.
                    Putting it there will ensure that the function called is from the global namespace,
                    even if there is a function by the same name in the current namespace */
                $_SESSION['loginTime'] = date(\DATE_COOKIE);

                $this->requestRedirect('/profile');
                return '';
            }
        }

        /* Here the render function returns the whole processed html name 'login-form' */
        return (new \Components\Template('login-form'))->render([
            'formError' => $formError,
            'formUsername' => $formUsername ?? ''
        ]);
    }
}
