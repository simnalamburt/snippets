import java.util.function.*;

@FunctionalInterface
interface λ {
  int eval();
}

public class Finally {
  public static void main(String[] argv) {
    int x = ((λ)() -> {
      for (int i = 0; i < 5; ++i) {
        try {
          return i;
        } finally {
          if (i != 3) continue;
        }
      }
      return -1; // 이거없으면 컴파일안됨
    }).eval();

    System.out.println(x); // 3
  }
}
