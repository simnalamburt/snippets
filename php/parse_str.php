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

var_dump($first); echo "\n";
var_dump($arr); echo "\n";
var_dump($foo); echo "\n";
var_dump($test); echo "\n";
echo "\n\n\n";

// max nested limit
error_reporting(E_ALL);
ini_set("display_errors", "stderr");
$str = "x[x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x]=nesting";
parse_str($str, $output);
var_dump($output); echo "\n";

// ill input
parse_str("yo;lo&foo  =   bar%ZZ&yolo + = + swag", $output);
var_dump($output); echo "\n";

parse_str("arr[]=A&arr[]=B&arr[9]=C&arr[]=D&arr[foo]=E&arr[]=F&arr[15.1]=G&arr[]=H", $output);
var_dump($output); echo "\n";

parse_str("=123&[]=123&[foo]=123&[3][var]=123", $output); var_dump($output); echo "\n";

parse_str("arr[2][]=sid&arr[2][]=fred", $output); var_dump($output); echo "\n";
parse_str("arr[2][]=sid&arr[4][]=fred", $output); var_dump($output); echo "\n";
parse_str("arr[2][]=sid&arr[][4]=fred", $output); var_dump($output); echo "\n";
parse_str("arr[2][]=sid&arr[][]=fred", $output); var_dump($output); echo "\n";
parse_str("3.14=adsf&arr[123]=asdf&arr[3.14]=asdf", $output); var_dump($output); echo "\n";
var_dump(gettype(array_keys($output['arr'])[0])); echo "\n";
var_dump(gettype(array_keys($output['arr'])[1])); echo "\n";
