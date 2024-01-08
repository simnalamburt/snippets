<?php

function t($str) {
  $decoded = urldecode($str);
  var_dump($decoded);
  for ($i = 0; $i < strlen($decoded); $i++) {
    echo str_pad(dechex(ord($decoded[$i])), 2, '0', STR_PAD_LEFT);
    echo ' ';
  }
  echo "\n\n";
}

t("a+b");
t("red%0blue");
