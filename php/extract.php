<?php

$_GET = [
  "foo" => "FooFoo",
  "bar" => "BarBar",
];

extract($_GET);

echo $foo . "\n"; // FooFoo
echo $bar . "\n"; // BarBar
print_r($_GET);
echo "\n";

$foo = "foofoofoofoo";

echo $foo . "\n"; // FooFoo
echo $bar . "\n"; // BarBar
print_r($_GET);
echo "\n";
