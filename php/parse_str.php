<?php

class TestClass {
  public $field = "initialvalue";
}

$test = new TestClass();

$str = "first=value&arr[]=foo+bar&arr[]=baz&foo[bar]=foobar&test.field=testing";

// DISCOURAGED
parse_str($str);

print_r($first); echo "\n";
print_r($arr); echo "\n";
print_r($foo); echo "\n";
print_r($test); echo "\n";
echo "\n\n\n";

// max nested limit
error_reporting(E_ALL);
ini_set("display_errors", "stderr");
$str = "x[x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x]=nesting";
parse_str($str, $output);
print_r($output); echo "\n";
