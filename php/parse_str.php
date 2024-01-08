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

// Remove in PHP 8.0
//
// class TestClass { public $field = "initialvalue"; }
// $test = new TestClass();
// parse_str("first=value&arr[]=foo+bar&arr[]=baz&foo[bar]=foobar&test.field=testing");
// var_dump($first); echo "\n";
// var_dump($arr); echo "\n";
// var_dump($foo); echo "\n";
// var_dump($test); echo "\n";

function t($str) {
  parse_str($str, $output);
  var_dump($output);
  echo "\n";
}

t("first=value&arr[]=foo+bar&arr[]=baz&foo[bar]=foobar&test.field=testing");
// max nested limit
t("x[x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x]=nesting");
// ill input
t("yo;lo&foo  =   bar%ZZ&yolo + = + swag");
t("arr[]=A&arr[]=B&arr[9]=C&arr[]=D&arr[foo]=E&arr[]=F&arr[15.1]=G&arr[]=H");
t("=123&[]=123&[foo]=123&[3][var]=123");
t("arr[2][]=sid&arr[2][]=fred");
t("arr[2][]=sid&arr[4][]=fred");
t("arr[2][]=sid&arr[][4]=fred");
t("arr[2][]=sid&arr[][]=fred");
t("2=222&3.14=3.14&arr[123]=asdf&arr[3.14]=asdf");
t("foo&arr[]&arr[]&arr[]=val");
t("foo[03]=yo");
t("foo[-3]=yo");
