sealed abstract class Iter[A] {
  def next(): Option[(A, Iter[A])]
}

case class INil[A]() extends Iter[A] {
  override def next() = None
}

class ICons[A](head: =>A, tail: =>Iter[A]) extends Iter[A] {
  override def next() = Some((head, tail))
}

// Companions must be defined together
object ICons {
  def apply[A](head: =>A, tail: =>Iter[A]) = new ICons(head, tail)
}
