#include <fstream>
#include <iostream>
#include <set>
using namespace std;

#define numOfLines 500
int t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  set<int> powers;

  int n = 1;
  while (n <= 100000) {
    powers.insert(n);
    n *= 3;
  }

  int count = 0;
  for (int num : t) {
    if (powers.find(num) != powers.end()) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

int factorial(int n) {
  int x = 1;
  for (int i = 2; i <= n; i++) x *= i;
  return x;
}

int sumOfFactorials(int n) {
  int sum = 0;
  while (n) {
    sum += factorial(n % 10);
    n /= 10;
  }
  return sum;
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  for (int num : t) {
    if (num == sumOfFactorials(num)) {
      cout << num << '\n';
      out << num << '\n';
    }
  }
}

int gcd2(int a, int b) { return b == 0 ? a : gcd2(b, a % b); }

int gcd(vector<int> v, int last) {
  // for (int c : v) cout << c << ' ';
  // cout << " --- " << last << '\n';
  if (v.size() == 1) return gcd2(v.back(), last);
  int last2 = v.back();
  v.pop_back();
  return gcd2(gcd(v, last2), last);
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int maxiLen = 0, maxiGcd = 0, maxiNum = 0;
  for (int len = 2; len <= numOfLines; len++) {
    bool found = false;
    for (int startIndex = 0; startIndex + len - 1 < numOfLines; startIndex++) {
      vector<int> x;
      for (int i = 0; i < len - 1; i++) x.push_back(t[startIndex + i]);
      int gcdV = gcd(x, t[startIndex + len - 1]);

      if (gcdV != 1) {
        found = true;
        maxiLen = len;
        maxiNum = t[startIndex];
        maxiGcd = gcdV;
      }
    }
    if (!found) break;
  }

  cout << maxiNum << ' ' << maxiLen << ' ' << maxiGcd << '\n';
  out << maxiNum << ' ' << maxiLen << ' ' << maxiGcd << '\n';
}

int main() {
  ifstream in;

  in.open("liczby.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}