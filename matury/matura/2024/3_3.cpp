#include <fstream>
#include <iostream>
// #include <numeric>
using namespace std;

#define numOfLines 200
int t[numOfLines];

ofstream out;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}  // or use gcd() from "numeric"

int oddHash(int n) {
  int m = 0;
  int a = 0, b = 1;

  while (n) {
    a = n % 10;
    n /= 10;
    if (a % 2 == 1) {
      m = m + b * a;
      b *= 10;
    }
  }

  return m;
}

void solve() {
  for (int i = 0; i < numOfLines; i++) {
    int num = t[i];

    int hashed = oddHash(num);
    int gcdValue = gcd(num, hashed);

    if (gcdValue == 7) {
      cout << num << '\n';
      out << num << '\n';
    }
  }
}

int main() {
  ifstream in;

  in.open("skrot2.txt");
  out.open("wyniki3_3.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  solve();

  in.close();
  out.close();
}