#include <iostream>

using namespace std;

class ParseError {
  string msg;

public:
  explicit ParseError(const string &msg) : msg(msg) { }

  string what() const { return msg; }
};

[[ noreturn ]]
void error(const char* msg) {
  throw ParseError(msg);
}

struct Token {
  static constexpr char number = '8';
  static constexpr char quit = 'q';
  static constexpr char print = ';';

  char kind;
  double value;
};

class TokenStream {
  Token buffer;
  bool buffer_empty = true;

public:
  Token get() {
    if (!buffer_empty) {
      buffer_empty = true;
      return buffer;
    }

    char ch;
    cin >> ch; // Skips whitespaces

    switch (ch) {
    case '(':
    case ')':
    case ';':
    case 'q':
    case '+':
    case '-':
    case '*':
    case '/':
      return Token { ch };

    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
      cin.putback(ch);
      double val;
      cin >> val;
      return Token { Token::number, val };
    }

    default:
      throw ParseError("Bad token");
    }
  }

  void putback(const Token &token) {
    if (!buffer_empty) { throw ParseError("putback() into a full buffer"); }

    buffer_empty = false;
    buffer = token;
  }
} ts;

double expression();

double primary() {
  Token t = ts.get();
  switch (t.kind) {
    case '(': {
      double d = expression();
      Token t = ts.get();
      if (t.kind != ')') { throw ParseError("Expected ')'"); }
      return d; }
    case Token::number:
      return t.value;
    default:
      throw ParseError("Expected primary");
  }
}

double term() {
  double left = primary();
  while (true) {
    Token t = ts.get();
    switch (t.kind) {
    case '*': left *= primary(); break;
    case '/': {
      double right = primary();
      if (right == 0.0) { throw ParseError("Devide by zero"); }
      left /= right;
      break; }
    default:
      ts.putback(t);
      return left;
    }
  }
}

double expression() {
  double left = term();
  while (true) {
    Token t = ts.get();
    switch (t.kind) {
    case '+': left += term(); break;
    case '-': left -= term(); break;
    default:
      ts.putback(t);
      return left;
    }
  }
}

int main() try {
  constexpr auto prompt = "> ";
  constexpr auto result = "= ";

  while (true) {
    try {
      double val;
      cout << prompt;
      while (cin) {
        Token t = ts.get();
        if (t.kind == Token::quit) { return 0; }
        if (t.kind == Token::print) {
          cout << result << val << endl;
        } else {
          ts.putback(t);
        }
        val = expression();
      }
    } catch(const ParseError &e) {
      cout << e.what() << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unhandled exception" << endl;
  return 1;
}
