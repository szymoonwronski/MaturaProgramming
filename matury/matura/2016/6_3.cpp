#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 3000
pair<string, string> t[numOfLines];

ofstream out;

string cipher(string word, int k) {
  string enrypted = "";
  k %= 26;

  for (char c : word) {
    char n = c + k;
    if (n > 'Z') n -= 26;
    enrypted += n;
  }

  return enrypted;
}

void solve() {
  for (auto [word, goal] : t) {
    bool valid = false;

    for (int k = 0; k < 26; k++) {
      string encrypted = cipher(word, k);

      if (encrypted == goal) valid = true;
    }

    if (!valid) {
      cout << word << '\n';
      out << word << '\n';
    }
  }
}

int main() {
  ifstream in;

  in.open("dane_6_3.txt");
  out.open("wyniki_6_3.txt");

  for (int i = 0; i < numOfLines; i++) {
    string a, b;
    in >> a >> b;

    t[i] = make_pair(a, b);
  }

  solve();

  in.close();
  out.close();
}