#include <fstream>
#include <iostream>
#include <map>
using namespace std;

#define numOfLines 100
int t[numOfLines];

ofstream out;

int mirror(int n) {
  string s = to_string(n);
  reverse(s.begin(), s.end());
  return stoi(s);
}

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  for (int n : t) {
    int mirrored = mirror(n);

    if (mirrored % 17 != 0) continue;

    cout << mirrored << '\n';
    out << mirrored << '\n';
  }
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int maxDiff = 0, num = 0;

  for (int n : t) {
    int mirrored = mirror(n);

    int diff = abs(n - mirrored);

    if (diff > maxDiff) {
      maxDiff = diff;
      num = n;
    }
  }

  cout << num << ' ' << maxDiff << '\n';
  out << num << ' ' << maxDiff << '\n';
}

bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  for (int n : t) {
    int mirrored = mirror(n);

    if (isPrime(n) && isPrime(mirrored)) {
      cout << n << '\n';
      out << n << '\n';
    }
  }
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  map<int, int> kv;

  for (int n : t) {
    kv[n]++;
  }

  int numOf2 = 0, numOf3 = 0;
  for (auto [k, v] : kv) {
    if (v == 2) numOf2++;
    if (v == 3) numOf3++;
  }

  cout << kv.size() << ' ' << numOf2 << ' ' << numOf3 << '\n';
  out << kv.size() << ' ' << numOf2 << ' ' << numOf3 << '\n';
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
  zad4();

  in.close();
  out.close();
}