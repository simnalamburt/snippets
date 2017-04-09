// C++14
#include <iostream>
#include <locale>
#include <codecvt>
#include <regex>

using namespace std;

auto text_into_morse(const string &input) {
  // 출력이 저장될 string 변수
  auto output = string();

  auto regexp = regex(R"(\s+)");
  auto tokens = sregex_token_iterator(input.begin(), input.end(), regexp, -1);
  const auto end = sregex_token_iterator();
  for (auto i = 0; tokens != end; ++tokens, ++i) {
    if (i != 0) { output += "   "; }

    auto token = tokens->str();
    auto j = 0;
    for (auto ch : token) {
      if ((j++) != 0) { output += " "; }

      ch = toupper(ch);

      switch (ch) {
        case 'A': output += ".-"  ; break;
        case 'B': output += "-..."; break;
        case 'C': output += "-.-."; break;
        case 'D': output += "-.." ; break;
        case 'E': output += "."   ; break;
        case 'F': output += "..-."; break;
        case 'G': output += "--." ; break;
        case 'H': output += "...."; break;
        case 'I': output += ".."  ; break;
        case 'J': output += ".---"; break;
        case 'K': output += "-.-" ; break;
        case 'L': output += ".-.."; break;
        case 'M': output += "--"  ; break;
        case 'N': output += "-."  ; break;
        case 'O': output += "---" ; break;
        case 'P': output += ".--."; break;
        case 'Q': output += "--.-"; break;
        case 'R': output += ".-." ; break;
        case 'S': output += "..." ; break;
        case 'T': output += "-"   ; break;
        case 'U': output += "..-" ; break;
        case 'V': output += "...-"; break;
        case 'W': output += ".--" ; break;
        case 'X': output += "-..-"; break;
        case 'Y': output += "-.--"; break;
        case 'Z': output += "--.."; break;
        case '0': output += "-----"; break;
        case '1': output += ".----"; break;
        case '2': output += "..---"; break;
        case '3': output += "...--"; break;
        case '4': output += "....-"; break;
        case '5': output += "....."; break;
        case '6': output += "-...."; break;
        case '7': output += "--..."; break;
        case '8': output += "---.."; break;
        case '9': output += "----."; break;
        case '/': output += "-..-."; break;
        case '?': output += "..--.."; break;
        case ',': output += "--..--"; break;
        case '.': output += ".-.-.-"; break;
        case '+': output += ".-.-."; break;
        case '=': output += "-...-"; break;
      }
    }
  }

  return output;
}

auto text_from_morse(const string& input) {
  auto output = string();

  auto regexp = regex("   ");
  auto words = sregex_token_iterator(input.begin(), input.end(), regexp, -1);
  const auto end = sregex_token_iterator();
  for (auto i = 0; words != end; ++words, ++i) {
    auto word = words->str();

    if (i != 0) { output += " "; }

    auto regexp = regex(" ");
    auto chars = sregex_token_iterator(word.begin(), word.end(), regexp, -1);
    for (; chars != end; ++chars) {
      auto ch = chars->str();

      if (ch.compare(".-") == 0) { output +=          'A'; }
      else if (ch.compare("-...") == 0) { output +=   'B'; }
      else if (ch.compare("-.-.") == 0) { output +=   'C'; }
      else if (ch.compare("-..") == 0) { output +=    'D'; }
      else if (ch.compare(".") == 0) { output +=      'E'; }
      else if (ch.compare("..-.") == 0) { output +=   'F'; }
      else if (ch.compare("--.") == 0) { output +=    'G'; }
      else if (ch.compare("....") == 0) { output +=   'H'; }
      else if (ch.compare("..") == 0) { output +=     'I'; }
      else if (ch.compare(".---") == 0) { output +=   'J'; }
      else if (ch.compare("-.-") == 0) { output +=    'K'; }
      else if (ch.compare(".-..") == 0) { output +=   'L'; }
      else if (ch.compare("--") == 0) { output +=     'M'; }
      else if (ch.compare("-.") == 0) { output +=     'N'; }
      else if (ch.compare("---") == 0) { output +=    'O'; }
      else if (ch.compare(".--.") == 0) { output +=   'P'; }
      else if (ch.compare("--.-") == 0) { output +=   'Q'; }
      else if (ch.compare(".-.") == 0) { output +=    'R'; }
      else if (ch.compare("...") == 0) { output +=    'S'; }
      else if (ch.compare("-") == 0) { output +=      'T'; }
      else if (ch.compare("..-") == 0) { output +=    'U'; }
      else if (ch.compare("...-") == 0) { output +=   'V'; }
      else if (ch.compare(".--") == 0) { output +=    'W'; }
      else if (ch.compare("-..-") == 0) { output +=   'X'; }
      else if (ch.compare("-.--") == 0) { output +=   'Y'; }
      else if (ch.compare("--..") == 0) { output +=   'Z'; }
      else if (ch.compare("-----") == 0) { output +=  '0'; }
      else if (ch.compare(".----") == 0) { output +=  '1'; }
      else if (ch.compare("..---") == 0) { output +=  '2'; }
      else if (ch.compare("...--") == 0) { output +=  '3'; }
      else if (ch.compare("....-") == 0) { output +=  '4'; }
      else if (ch.compare(".....") == 0) { output +=  '5'; }
      else if (ch.compare("-....") == 0) { output +=  '6'; }
      else if (ch.compare("--...") == 0) { output +=  '7'; }
      else if (ch.compare("---..") == 0) { output +=  '8'; }
      else if (ch.compare("----.") == 0) { output +=  '9'; }
      else if (ch.compare("-..-.") == 0) { output +=  '/'; }
      else if (ch.compare("..--..") == 0) { output += '?'; }
      else if (ch.compare("--..--") == 0) { output += ','; }
      else if (ch.compare(".-.-.-") == 0) { output += '.'; }
      else if (ch.compare(".-.-.") == 0) { output +=  '+'; }
      else if (ch.compare("-...-") == 0) { output +=  '='; }
    }
  }

  return output;
}

int main() {
  cout << "모스부호로 변환할 문장을 입력하세요." << endl;

  while (true) {
    auto input = string();

    cout << "> " << flush;
    getline(cin, input);

    if (cin.eof()) { break; }

    auto morse = text_into_morse(input);
    auto roundtrip = text_from_morse(morse);

    cout
      << "모스 부호 : " << morse << endl
      << "왕복 결과 : " << roundtrip << endl
      << endl;
  }
  cout << endl;
}
