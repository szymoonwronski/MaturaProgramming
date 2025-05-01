#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 999
pair<string, int> t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int count = 0;

  for (auto [num, base] : t) {
    if (base == 8) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int count = 0;

  for (auto [num, base] : t) {
    if (base == 4 && num.find('0') == string::npos) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int count = 0;

  for (auto [num, base] : t) {
    if (base == 2 && num[num.size() - 1] == '0') count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

int octToDec(string oct) {
  int res = 0;

  for (char c : oct) {
    res = res * 8 + c - '0';
  }

  return res;
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  long long sum = 0;

  for (auto [num, base] : t) {
    if (base == 8) sum += octToDec(num);
  }

  cout << sum << '\n';
  out << sum << '\n';
}

int toDec(string n, int base) {
  int res = 0;

  for (char c : n) {
    res = res * base + c - '0';
  }

  return res;
}

void zad5() {
  cout << "Zad 5:\n";
  out << "Zad 5:\n";

  int maxi = 0, mini = INT32_MAX;
  string maxiCode, miniCode;

  for (auto [num, base] : t) {
    int dec = toDec(num, base);
    if (dec < mini) {
      mini = dec;
      miniCode = num;
      miniCode += '0' + base;
    }
    if (dec > maxi) {
      maxi = dec;
      maxiCode = num;
      maxiCode += '0' + base;
    }
  }

  cout << miniCode << ' ' << mini << '\n';
  cout << maxiCode << ' ' << maxi << '\n';
  out << miniCode << ' ' << mini << '\n';
  out << maxiCode << ' ' << maxi << '\n';
}

int main() {
  ifstream in;

  in.open("liczby.txt");
  out.open("wyniki6.txt");

  for (int i = 0; i < numOfLines; i++) {
    string s;
    in >> s;
    t[i] = make_pair(s.substr(0, s.size() - 1), s[s.size() - 1] - '0');
  }

  zad1();
  zad2();
  zad3();
  zad4();
  zad5();

  in.close();
  out.close();
}