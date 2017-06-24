--TEST--
Check for example presence
--SKIPIF--
<?php if (!extension_loaded("example")) print "skip"; ?>
--FILE--
<?php 
use Example\SimpleClass;

$simpleClass = new SimpleClass;

$simpleClass->helloWorld();
--EXPECT--
hello world!!!
