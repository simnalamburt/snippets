object NthPrime {
  private def is_prime(number: Int): Boolean = {
    @annotation.tailrec
    def impl(i: Int): Boolean = {
      if (!(i*i > number)) {

        if (!(number % i == 0)) {
          impl(i + 1)
        } else {
          false
        }

      } else {
        true
      }
    }

    impl(2)
  }

  // 자연로그와 같은 실수연산 없이 정수연산만으로 N번째 소수 계산하기
  //
  // 자연로그를 쓸 경우, 아래 부등식을 활용해 더 효율적으로 계산할 수 있다.
  //
  // For k >= 6, following inequality holds:
  //   k*ln(k) + k*ln(ln(k)) - k < P_k < k*ln(k) + k*ln(ln(k))
  //
  // References:
  //   Rosser's theorem <https://doi.org/10.1112/plms/s2-45.1.21>
  //   Rosser, Barkley (1941) <https://doi.org/10.2307/2371291>
  //   Dusart, Pierre (1999) <https://doi.org/10.1090/S0025-5718-99-01037-6>
  def nthprime(n: Int): Int = {
    @annotation.tailrec
    def impl(i: Int, count: Int): Int = {
      if (!(is_prime(i))) {
        impl(i + 1, count)
      } else {
        if (!(count + 1 == n)) {
          impl(i + 1, count + 1)
        } else {
          i
        }
      }
    }

    impl(2, 0)
  }

  def main(args: Array[String]) = {
    def test_is_prime(n: Int, expected: Boolean) = {
      val actual = is_prime(n)
      if (actual == expected) {
        println(s"O (is_prime($n) == $expected)")
      } else {
        println(s"X (is_prime($n) is $expected not $actual)")
      }
    }

    def test_nthprime(n: Int, expected: Int) = {
      val actual = nthprime(n)
      if (actual == expected) {
        println(s"O (nthprime($n) == $expected)")
      } else {
        println(s"X (nthprime($n) is $expected not $actual)")
      }
    }

    test_is_prime(2, true)
    test_is_prime(3, true)
    test_is_prime(4, false)
    test_is_prime(5, true)
    test_is_prime(6, false)
    test_is_prime(7, true)
    test_is_prime(8, false)
    test_is_prime(9, false)
    test_is_prime(10, false)
    test_is_prime(11, true)
    test_is_prime(12, false)
    test_is_prime(13, true)
    test_is_prime(14, false)
    test_is_prime(15, false)
    test_is_prime(16, false)
    test_is_prime(17, true)
    test_is_prime(18, false)
    test_is_prime(19, true)
    test_is_prime(20, false)
    test_is_prime(21, false)
    test_is_prime(22, false)
    test_is_prime(23, true)
    test_is_prime(24, false)

    test_nthprime(1, 2)
    test_nthprime(2, 3)
    test_nthprime(3, 5)
    test_nthprime(4, 7)
    test_nthprime(5, 11)
    test_nthprime(6, 13)
    test_nthprime(7, 17)
    test_nthprime(8, 19)
    test_nthprime(9, 23)
    test_nthprime(10, 29)
    test_nthprime(100, 541)
  }
}
