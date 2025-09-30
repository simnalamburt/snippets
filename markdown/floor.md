아래 성질이 유용한 경우가 많다

```
i < floor(x) + 1  for all integer i and real number x
  <=>
i <= x  for all integer i and real number x (equality holds at x == floor(x))
```

## Definition of floor(x)
```
floor(x) === 부등식 N <= x < N + 1 을 만족하는 유일한 N
```

`floor(x)`의 정의에 의해 아래가 항상 성립한다

```
floor(x) <= x < floor(x) + 1 (equality holds at x == floor(x))
```

## proof of `<==`
```
i <= x && x < floor(x) + 1
==> i <= x < floor(x) + 1
==> i < floor(x) + 1
```

## proof of `==>`
경우의 수를 둘로 나눠 증명

- case A: `i < floor(x)`

  ```
  i < floor(x) && floor(x) <= x \
  ==> i < floor(x) <= x \
  ==> i < x
  ```

- case B: `i >= floor(x)`

  `floor(x)`와 `i` 모두 정수이므로, `floor(x) <= i < floor(x) + 1` 를 만족하는 `i`는 `i == floor(x)` 뿐임

  ```
  ==> i == floor(x) <= x (equality holds at x == floor(x))
  ==> i <= x (equality holds at x == floor(x))
  ```
