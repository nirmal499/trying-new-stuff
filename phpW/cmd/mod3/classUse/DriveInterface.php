<?php

interface DriveInterface
{
    /* All the functions inside the interface are public
        no other access modifiers is allowed
    */
    public function changeSpeed($speed);
    function changeGear($gear);
    function applyBreak();
}
