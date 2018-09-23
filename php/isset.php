<?php

echo "Hi\n";
var_dump($wgAWSCredentials);
$a = $wgAWSCredentials['asdf'];

var_dump(isset($wgAWSCredentials));
var_dump(isset($a));

$a = NULL;

var_dump(isset($wgAWSCredentials));
var_dump(isset($a));

$a = 'asdf';

var_dump(isset($wgAWSCredentials));
var_dump(isset($a));
