<?php

// Reference:
//   https://www.php.net/manual/en/function.parse-str.php
//
// Implementation:
//   https://github.com/php/php-src/blob/php-5.6.40/main/php_variables.c#L450-L496
//
// Test cases:
//   https://github.com/php/php-src/blob/php-8.3.0/ext/standard/tests/strings/parse_str_basic1.phpt
//   https://github.com/php/php-src/blob/php-8.3.0/ext/standard/tests/strings/parse_str_basic2.phpt
//   https://github.com/php/php-src/blob/php-8.3.0/ext/standard/tests/strings/parse_str_basic3.phpt
//   https://github.com/php/php-src/blob/php-8.3.0/ext/standard/tests/strings/parse_str_basic4.phpt
//   https://github.com/php/php-src/blob/php-8.3.0/ext/standard/tests/strings/parse_str_memory_error.phpt
//   https://github.com/php/php-src/blob/php-8.3.0/ext/standard/tests/strings/bug77439.phpt

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

// ill input
parse_str("yo;lo&foo  =   bar%ZZ&yolo + = + swag", $output);
print_r($output); echo "\n";
