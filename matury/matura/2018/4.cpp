#include <fstream>
#include <iostream>
#include <set>
using namespace std;

#define numOfLines 1000
string t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  string res = "";
  for (int i = 39; i <= numOfLines; i += 40) {
    res += t[i][9];
  }

  cout << res << '\n';
  out << res << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int maxLen = 0;
  string maxWord = "";
  for (string s : t) {
    set<char> letters;
    for (char c : s) {
      letters.insert(c);
    }

    if (letters.size() > maxLen) {
      maxLen = letters.size();
      maxWord = s;
    }
  }

  cout << maxWord << ' ' << maxLen << '\n';
  out << maxWord << ' ' << maxLen << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  for (string s : t) {
    bool valid = true;

    for (char a : s) {
      for (char b : s) {
        if (b - a > 10) valid = false;
      }
    }

    if (valid) {
      cout << s << '\n';
      out << s << '\n';
    }
  }
}

int main() {
  ifstream in;

  in.open("sygnaly.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}