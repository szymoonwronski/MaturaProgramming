#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 1000
pair<int, int> t[numOfLines];

ofstream out;

bool valid(int x, int y) {
  while (y > x) {
    y /= 2;
    if (x == y) return true;
  }
  return false;
}

void solve() {
  for (auto [x, y] : t) {
    if (valid(x, y)) {
      cout << x << ' ' << y << '\n';
      out << x << ' ' << y << '\n';
    }
  }
}

int main() {
  ifstream in;

  in.open("pary.txt");
  out.open("wyniki2.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i].first >> t[i].second;
  }

  solve();

  in.close();
  out.close();
}