<?php

declare(strict_types=1);

namespace Handlers;

use Components\Auth;
use Components\Database;
use Components\Template;

class Signup extends Handler
{
    public function handle(): string
    {
        if (Auth::userIsAuthenticated()) {
            $this->requestRedirect('/profile');
            return '';
        }
        $formError = [];
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $formError = $this->handleSignup();
            if (!$formError) {
                return '';
            }
        }

        return (new Template('signup-form'))->render([
            'formError' => $formError,
            'formUsername' => $_POST['username'] ?? ''
        ]);
    }

    private function handleSignup(): ?array
    {
        $formError = null;
        $formUsername = trim($_POST['username'] ?? '');
        $formPassword = trim($_POST['password'] ?? '');
        $formPasswordVerify = $_POST['passwordVerify'] ?? '';
        if (!$formUsername || !(strlen($formUsername) >= 4 && strlen($formUsername) <= 10)) {
            // $strlength = strlen($formUsername);
            // error_log("String length is $strlength", 0);
            $formError = ['username' => 'Please enter an username of 4-10 characters.'];
        } elseif (!ctype_alnum($formUsername)) {
            $formError = ['username' => 'The username should contain only numbers and letters.'];
        } elseif (!$formPassword || !(strlen($formPassword) >= 6 && strlen($formPassword) <= 15)) {
            $formError = ['password' => 'Please enter a password of 6-15 characters.'];
        } elseif ($formPassword !== $formPasswordVerify) {
            $formError = ['passwordVerify' => 'The passwords doesn\'t match.'];
        } else {
            $stmt = Database::instance()->addUser(strtolower($formUsername), $formPassword);
            if (!$stmt->rowCount()) {
                list(,, $error) = $stmt->errorInfo();
                $formError = ['username' => $error];
            } else {
                Auth::authenticate((int)Database::instance()->pdo->lastInsertId());
                $this->requestRedirect('/profile');
            }
        }
        return $formError;
    }
}
