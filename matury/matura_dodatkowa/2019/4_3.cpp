#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 200
int t[numOfLines];

ofstream out;

int w(int n) {
  if (n < 10) return n;

  int sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return w(sum);
}

void solve() {
  int count = 0;
  for (int num : t) {
    if (w(num) == 1) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

int main() {
  ifstream in;

  in.open("pierwsze.txt");
  out.open("wyniki4_3.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  solve();

  in.close();
  out.close();
}