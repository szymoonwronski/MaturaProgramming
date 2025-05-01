#include <fstream>
#include <iostream>
#include <set>
using namespace std;

#define numOfLines 200
int t[numOfLines];

ofstream out, out2;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int firstNum = 0, count = 0;

  for (int num : t) {
    string n = to_string(num);
    if (n[0] == n[n.size() - 1]) {
      count++;
      if (!firstNum) firstNum = num;
    }
  }
  cout << count << ' ' << firstNum << '\n';
  out << count << ' ' << firstNum << '\n';
}

pair<int, int> factors(int n) {
  multiset<int> factors;
  set<int> uniqueFactors;

  int prime = 2;
  while (n != 1) {
    if (n % prime == 0) {
      n /= prime;
      factors.insert(prime);
      uniqueFactors.insert(prime);
    } else
      prime++;
  }

  return {factors.size(), uniqueFactors.size()};
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int maxiF = 0, maxiUF = 0;
  int maxiFNum, maxiUFNum;

  for (int num : t) {
    auto [f, uf] = factors(num);

    if (f > maxiF) {
      maxiF = f;
      maxiFNum = num;
    }
    if (uf > maxiUF) {
      maxiUF = uf;
      maxiUFNum = num;
    }
  }

  cout << maxiFNum << ' ' << maxiF << ' ' << maxiUFNum << ' ' << maxiUF << '\n';
  out << maxiFNum << ' ' << maxiF << ' ' << maxiUFNum << ' ' << maxiUF << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int count3 = 0, count5 = 0;

  for (int z : t) {
    for (int y : t) {
      if (z % y != 0 || z == y) continue;
      for (int x : t) {
        if (y % x != 0 || y == x) continue;
        count3++;

        cout << x << ' ' << y << ' ' << z << '\n';
        out2 << x << ' ' << y << ' ' << z << '\n';

        for (int w : t) {
          if (x % w != 0 || x == w) continue;
          for (int u : t) {
            if (w % u != 0 || w == u) continue;
            count5++;

            cout << u << ' ' << w << ' ' << x << ' ' << y << ' ' << z << '\n';
          }
        }
      }
    }
  }

  cout << "a) " << count3 << '\n';
  cout << "b) " << count5 << '\n';

  out << "a) " << count3 << '\n';
  out << "b) " << count5 << '\n';
}

int main() {
  ifstream in;

  in.open("liczby.txt");
  out.open("wyniki4.txt");
  out2.open("trojki.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
  out2.close();
}