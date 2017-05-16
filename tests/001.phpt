--TEST--
Check for example presence
--SKIPIF--
<?php if (!extension_loaded("example")) print "skip"; ?>
--FILE--
<?php 
$a = 4;
$b = closure(function () use ($a) {
    return ++$a;
});
echo $a . "\n";
echo $b . "\n";
?>
--EXPECT--
4
5
