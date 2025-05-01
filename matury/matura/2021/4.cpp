#include <fstream>
#include <iostream>
#include <map>
using namespace std;

#define numOfLines 2000
pair<string, char> t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int len = 0;

  for (auto [k, v] : t) {
    if (k == "DOPISZ")
      len++;
    else if (k == "USUN")
      len--;
  }

  cout << len << '\n';
  out << len << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int maxiLen = 0, len = 0;
  string maxiType = "";
  string prev = "";
  for (auto [k, v] : t) {
    if (k == prev) {
      len++;
      if (len > maxiLen) {
        maxiLen = len;
        maxiType = k;
      }
    } else
      len = 1;
    prev = k;
  }

  cout << maxiType << ' ' << maxiLen << '\n';
  out << maxiType << ' ' << maxiLen << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  map<char, int> letters;
  for (auto [k, v] : t) {
    if (k == "DOPISZ") {
      letters[v]++;
    }
  }

  char maxiLetter;
  int maxi = 0;
  for (auto [k, v] : letters) {
    if (v > maxi) {
      maxi = v;
      maxiLetter = k;
    }
  }

  cout << maxiLetter << ' ' << maxi << '\n';
  out << maxiLetter << ' ' << maxi << '\n';
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  string res = "";

  for (auto [k, v] : t) {
    if (k == "DOPISZ") {
      res += v;
    } else if (k == "USUN") {
      res = res.substr(0, res.size() - 1);
    } else if (k == "ZMIEN") {
      res = res.substr(0, res.size() - 1);
      res += v;
    } else if (k == "PRZESUN") {
      for (char& c : res) {
        if (c == v) {
          if (c == 'Z')
            c = 'A';
          else
            c += 1;
          break;
        }
      }
    }
  }

  cout << res << '\n';
  out << res << '\n';
}

int main() {
  ifstream in;

  in.open("instrukcje.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfLines; i++) {
    string s;
    char c;

    in >> s >> c;

    t[i] = make_pair(s, c);
  }

  zad1();
  zad2();
  zad3();
  zad4();

  in.close();
  out.close();
}