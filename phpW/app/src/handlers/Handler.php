<?php

declare(strict_types=1);

namespace Handlers;

abstract class Handler
{
    private $redirectUri = '';

    abstract public function handle(): string;

    public function getTitle(): string
    {
        return 'Learning PHP';
    }

    public function requestRedirect(string $uri)
    {
        $this->redirectUri = $uri;
        header("Location: $uri", true);
        /* This will change location of header, i.e. redirect to the URL */
    }

    public function requestRefresh()
    {
        $this->requestRedirect($_SERVER['REQUEST_URI']);
    }

    public function willRedirect(): bool
    {
        return strlen($this->redirectUri) > 0;
    }
}
