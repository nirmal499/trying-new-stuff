<?php

declare(strict_types=1);

namespace Components;

class Template
{
    public static $viewsPath = __DIR__ . '/../templates';

    private $name;

    public function __construct(string $name)
    {
        $this->name = $name;
    }

    private function getFilepath(): string
    {
        /* Returns the path for the specified named template from 'templates' directory */
        return self::$viewsPath . DIRECTORY_SEPARATOR . $this->name . '.php';
    }

    function render(array $data = []): string
    {

        /* We will use the built-in extract() function to import the variables into the current symbol table from the
            data array (extract($data, EXTR_OVERWRITE);). This means that if 
            $data = ['name' => 'John'];, the extract() function will import the $name variable that will have
            the value John.
        */
        extract($data, EXTR_OVERWRITE);

        /* The ob_start() function creates an output buffer. A callback function can be passed in to do processing on the 
        contents of the buffer before it gets flushed from the buffer */
        ob_start();

        /* The include (or require) statement takes all the text/code/markup that exists in the specified file and 
        copies it into the file that uses the include statement. 

        require will produce a fatal error (E_COMPILE_ERROR) and stop the script
        include will only produce a warning (E_WARNING) and the script will continue
        */
        require $this->getFilepath();

        /* $this->getFilepath() will return a template file path 
            And then require function statement takes all the html markups that exists in the specified file and
            copies it into the file that uses the require statement.
        */


        $rendered = ob_get_clean();
        /* Here The ob_get_clean() function returns the contents of the output buffer to $rendered variable
         and then deletes the contents from the buffer */

        /* We return the whole processed html as string */
        return (string)$rendered;
    }
}
