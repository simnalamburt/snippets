object Factorial extends App {
  println(factorial(1))
  println(factorial(2))
  println(factorial(3))
  println(factorial(4))
  println(factorial(5))
  println(factorial(6))
  println(factorial(7))
  println(factorial(8))

  def factorial(n: Int): Int = {
    @annotation.tailrec
    def go(n: Int, acc: Int): Int = {
      if (n == 1) return acc
      return go(n-1, acc*n)
    }

    go(n, 1)
  }
}
