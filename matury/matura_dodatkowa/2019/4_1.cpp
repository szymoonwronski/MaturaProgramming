#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 300
int t[numOfLines];

ofstream out;

bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  for (int num : t) {
    if (isPrime(num) && num >= 100 && num <= 5000) {
      cout << num << '\n';
      out << num << '\n';
    }
  }
}

int main() {
  ifstream in;

  in.open("liczby.txt");
  out.open("wyniki4_1.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  solve();

  in.close();
  out.close();
}