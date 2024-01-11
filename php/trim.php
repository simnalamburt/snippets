<?php

function a($str) {
  var_dump(trim($str));
  echo "\n";
}
function b($str, $characters) {
  var_dump(trim($str, $characters));
  echo "\n";
}
function c($str) {
  var_dump($str);
  var_dump(trim($str));
  echo "\n";
}

a("Hello world ");
b("!===Hello World===!", "=!");

echo "\n\n";

c(123.40);
c(-123.40);
c(10.1234567e10);
c(1230.12984732591475609346509132875091237);
c(1230.12984732500000000000000000000000000);
c(123456789123456.40);
c(12345678912340.40);
