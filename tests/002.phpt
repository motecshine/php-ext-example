--TEST--
Check for example presence
--SKIPIF--
<?php if (!extension_loaded("example")) print "skip"; ?>
--FILE--
<?php 
$arr = ["key"=> 2];
eg_array_search($arr, "key");
$arr = ["key"=> "value"];
eg_array_search($arr, "key");
?>
--EXPECT--
find {key:key value:2}
find {key:key value:value}
