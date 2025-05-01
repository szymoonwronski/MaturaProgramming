#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 1000
string t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int count = 0;
  for (string s : t) {
    for (char c : s)
      if (c >= '0' && c <= '9') count++;
  }
  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int j = 0;
  string res = "";
  for (int i = 19; i < numOfLines; i += 20) {
    res += t[i][j];
    j++;
  }

  cout << res << '\n';
  out << res << '\n';
}

bool isPalindrome(string s) {
  string reversed = s;
  reverse(reversed.begin(), reversed.end());
  return s == reversed;
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  string res = "";
  for (string s : t) {
    string c1 = s + s[0];
    string c2 = s[s.size() - 1] + s;

    if (isPalindrome(c1)) {
      res += c1[c1.size() / 2];
    } else if (isPalindrome(c2)) {
      res += c2[c2.size() / 2];
    }
  }

  cout << res << '\n';
  out << res << '\n';
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  string res = "";

  for (string s : t) {
    string digits = "";
    for (char c : s)
      if (c >= '0' && c <= '9') digits += c;

    if (digits.size() % 2 == 1) digits.pop_back();

    for (int i = 0; i + 1 < digits.size(); i += 2) {
      string pair = digits.substr(i, 2);
      int n = stoi(pair);

      if (n >= 'A' && n <= 'Z') res += (char)n;

      if (res.size() > 3 && res.substr(res.size() - 3, 3) == "XXX") {
        cout << res << '\n';
        out << res << '\n';
        return;
      }
    }
  }
}

int main() {
  ifstream in;

  in.open("napisy.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();
  zad4();

  in.close();
  out.close();
}