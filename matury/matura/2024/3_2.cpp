#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 200
int t[numOfLines];

ofstream out;

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
  int count = 0, maxi = 0;

  for (int i = 0; i < numOfLines; i++) {
    int num = t[i];
    int hashed = oddHash(num);

    if (hashed == 0) {
      count++;
      maxi = max(maxi, num);
    }
  }

  cout << count << " " << maxi;
  out << count << " " << maxi;
}

int main() {
  ifstream in;

  in.open("skrot.txt");
  out.open("wyniki3_2.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  solve();

  in.close();
  out.close();
}