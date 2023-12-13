<?php

class TestClass {
  var $foo = "Foo";
  var $uninitialized;
  public $goo = "Goo";
  private $bar = "Bar";

  function foo() {
    print_r($this->foo); echo "\n";
    print_r($this->goo); echo "\n";
    // echo $this->bar . "\n"; //=> cannot access

    echo '$this->uninitialzed: '; print_r($this->uninitialized); echo "\n";
    echo '$this->uninitialzed: '; print_r(gettype($this->uninitialized)); echo "\n";

    echo '$this->nonexisting: '; print_r($this->nonexsiting); echo "\n";
    $this->nonexsiting = 123;
    echo '$this->nonexisting: '; print_r($this->nonexsiting); echo "\n";
  }
}

$instance = new TestClass();
$instance->foo();
