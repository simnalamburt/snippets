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
t("foo[0]=yo");
t("foo[00]=yo");
t("foo[-0]=yo");
t("foo[+0]=yo");
t("foo[3]=yo");
t("foo[03]=yo");
t("foo[-3]=yo");
t("foo[+3]=yo");
t("yolo=sw %0%0%0 ag");
t("str=string%20with%20%00%00%00%20nulls");

parse_str("str=string%20with%20%00%00%00%20nulls", $output);
$decoded = $output['str'];
for ($i = 0; $i < strlen($decoded); $i++) {
  echo str_pad(dechex(ord($decoded[$i])), 2, '0', STR_PAD_LEFT);
  echo ' ';
}
echo "\n\n";

t("foo[ 3=yo");
// foo__3 in PHP 8.3
// foo_ 3 in PHP 5.6

t("foo[ ]=yo"); // foo[0]
t("foo[  ]=yo"); // foo["  "]
t("x[3]=1&x[0]=1&x[]=1&x[]=1&x[]=1&x[]=1");

t("foo[-3][-3]=yo");
t("yo;lo&foo = bar%ZZ&yolo + = + swag");
