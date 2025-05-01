#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 100
string t[numOfLines];

ofstream out;

int binToDec(string bin) {
  int res = 0;

  for (char c : bin) {
    res = res * 2 + c - '0';
  }

  return res;
}

string decToBin(int n) {
  string res = "";

  while (n) {
    char c = '0' + n % 2;
    res = c + res;
    n /= 2;
  }

  return res;
}

string binXOR(string a, string b) {
  string res = "";

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  if (b.size() > a.size()) {
    string temp = a;
    a = b;
    b = temp;
  }

  for (int i = 0; i < a.size(); i++) {
    if (i < b.size()) {
      char c = a[i] == b[i] ? '0' : '1';
      res = c + res;
    } else {
      res = '1' + res;
    }
  }

  return res;
}

void solve() {
  for (int i = 0; i < numOfLines; i++) {
    int half = binToDec(t[i]) / 2;
    string b = decToBin(half);
    string res = binXOR(t[i], b);

    cout << res << '\n';
    out << res << '\n';
  }
}

int main() {
  ifstream in;

  in.open("bin.txt");
  out.open("wyniki2_5.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  solve();

  in.close();
  out.close();
}