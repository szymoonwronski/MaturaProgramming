#include <fstream>
#include <iostream>
#include <set>
using namespace std;

#define numOfLines 10
pair<int, string> t[numOfLines];

ofstream out;

void solve() {
  for (auto [n, s] : t) {
    set<string> suffixes;
    for (int i = 0; i < n; i++) {
      string suffix = s.substr(i, n - i);
      suffixes.insert(suffix);
    }

    cout << *suffixes.begin() << '\n';
    out << *suffixes.begin() << '\n';
  }
}

int main() {
  ifstream in;

  in.open("slowa4.txt");
  out.open("wyniki2_4.txt");

  for (int i = 0; i < numOfLines; i++) {
    int n;
    string s;
    in >> n >> s;

    t[i] = make_pair(n, s);
  }

  solve();

  in.close();
  out.close();
}