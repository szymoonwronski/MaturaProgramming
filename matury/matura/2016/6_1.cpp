#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 100
string t[numOfLines];

ofstream out;

void solve() {
  int k = 107;

  for (string s : t) {
    string encrypted = "";
    k %= 26;

    for (char c : s) {
      char n = c + k;
      if (n > 'Z') n -= 26;
      encrypted += n;
    }

    cout << encrypted << '\n';
    out << encrypted << '\n';
  }
}

int main() {
  ifstream in;

  in.open("dane_6_1.txt");
  out.open("wyniki_6_1.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  solve();

  in.close();
  out.close();
}