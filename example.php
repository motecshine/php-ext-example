<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('example')) {
	dl('example.' . PHP_SHLIB_SUFFIX);
}
$a = 4;
$b = closure(function () use ($a) {
    return ++$a;
});
echo $a . "\n";
echo $b . "\n";

$arr = ["key"=> 2];
eg_array_search($arr, "key");
$arr = ["key"=> "value"];
eg_array_search($arr, "key");

use Example\SimpleClass;

$simpleClass = new SimpleClass;

$simpleClass->helloWorld();
?>
