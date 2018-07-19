// g++ -std=c++14 constexpr.cpp

#include <cstdio>

constexpr const char* filename(const char * const path) {
  const char *begin = path;

  while (*begin != 0) { ++begin; };
  while (*begin != '/' && begin != path) { --begin; };
  if (*begin == '/') { ++begin; };

  return begin;
}

int main() {
  constexpr auto name = filename(__FILE__);

  puts(__FILE__);
  puts(filename(__FILE__));
  puts(filename("a.out"));
  puts(filename("./a"));
  puts(filename("/a"));
  puts(filename("a"));
  puts(filename("///"));
  puts(filename("//a.out/"));
  puts(filename(""));
  puts(filename("/"));
  puts(filename("/////////////////////////"));
}
