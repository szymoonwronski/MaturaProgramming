#include <fstream>
#include <iostream>
using namespace std;

ofstream out;

bool solve(int n, string s, int k1, int k2) {
  // cout << n << ' ' << s << ' ' << k1 << ' ' << k2 << '\n';
  s = "0" + s;
  int i = k1;
  int j = k2;
  while (i <= n && j <= n) {
    if (s[i] == s[j]) {
      i++;
      j++;
    } else {
      if (s[i] < s[j])
        return true;
      else
        return false;
    }
  }
  if (j <= n)
    return true;
  else
    return false;
}

int main() {
  ifstream in;

  out.open("wyniki2_2.txt");

  for (int i = 1; i < 4; i++) {
    string file = "slowa";
    char num = '0' + i;
    file += num;
    file += ".txt";
    in.open(file);

    int n, k1, k2;
    string s;
    in >> n >> s >> k1 >> k2;

    bool res = solve(n, s, k1, k2);

    cout << i << ".\n";
    out << i << ".\n";
    if (res) {
      cout << "TAK\n";
      out << "TAK\n";
    } else {
      cout << "NIE\n";
      out << "NIE\n";
    }
    in.close();
  }

  out.close();
}