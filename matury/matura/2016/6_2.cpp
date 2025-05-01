#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 3000
pair<string, int> t[numOfLines];

ofstream out;

void solve() {
  for (auto [encrypted, key] : t) {
    string decrypted = "";
    key %= 26;

    for (char c : encrypted) {
      char n = c - key;
      if (n < 'A') n += 26;
      decrypted += n;
    }

    cout << decrypted << '\n';
    out << decrypted << '\n';
  }
}

int main() {
  ifstream in;

  in.open("dane_6_2.txt");
  out.open("wyniki_6_2.txt");

  for (int i = 0; i < numOfLines; i++) {
    string a;
    int b;
    in >> a >> b;

    t[i] = make_pair(a, b);
  }

  solve();

  in.close();
  out.close();
}