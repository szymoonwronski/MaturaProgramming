#include <fstream>
#include <iostream>
#include <map>
#include <regex>
using namespace std;

#define numOfLines 1000
string t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int count = 0;

  for (string s : t) {
    regex r("k.t");
    if (regex_search(s, r)) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int count = 0;
  string word = "";
  for (string s : t) {
    string encrypted = "";
    for (char c : s) {
      unsigned char n = c + 13;
      if (n > 'z') n -= 26;
      encrypted += n;
    }
    reverse(encrypted.begin(), encrypted.end());
    if (s == encrypted) {
      count++;
      if (s.size() > word.size()) word = s;
    }
  }

  cout << count << ' ' << word << '\n';
  out << count << ' ' << word << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  for (string s : t) {
    map<char, int> letters;
    for (char c : s) letters[c]++;

    for (auto [k, v] : letters) {
      if (v * 2 >= s.size()) {
        cout << s << '\n';
        out << s << '\n';
        break;
      }
    }
  }
}

int main() {
  ifstream in;

  in.open("slowa.txt");
  out.open("wyniki3.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}