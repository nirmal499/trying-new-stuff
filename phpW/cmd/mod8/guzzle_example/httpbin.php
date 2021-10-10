<?php

require 'vendor/autoload.php';

use GuzzleHttp\Client;

$client = new Client(['base_uri' => 'http://httpbin.org/']);

try {
    /* Sending POST request to http://httpbin.org/response-headers */
    $response = $client->request('POST', '/response-headers', [
        'headers' => [
            'Accept' => 'application-json'
        ],
        'query' => [
            'first' => 'John',
            'last' => 'Doe'
        ]
    ]);

    if ($response->getStatusCode() !== 200) {
        throw new Exception("Status code was {$response->getStatusCode()}, not 200");
    }
    $responseObject = json_decode($response->getBody()->getContents());
    echo "The web service responded with {$responseObject->first} {$responseObject->last}" . PHP_EOL;
} catch (\Throwable $e) {
    echo "An error occurred: " . $e->getMessage() . PHP_EOL;
}
