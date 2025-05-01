#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define numOfLines 100
pair<int, string> t[numOfLines];

ofstream out;

bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;

  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;

  return true;
}

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  for (auto [k, v] : t) {
    if (k % 2 == 1) continue;

    for (int i = 3; i <= k; i++) {
      if (isPrime(i) && isPrime(k - i)) {
        cout << k << ' ' << i << ' ' << k - i << '\n';
        out << k << ' ' << i << ' ' << k - i << '\n';
        break;
      }
    }
  }
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  for (auto [k, v] : t) {
    char maxiC = v[0], prev = ' ';
    int maxi = 1, len = 0;

    for (char c : v) {
      if (c == prev) {
        len++;
        if (len > maxi) {
          maxi = len;
          maxiC = c;
        }
      } else {
        len = 1;
      }
      prev = c;
    }
    string ans = string(maxi, maxiC);

    cout << ans << ' ' << maxi << '\n';
    out << ans << ' ' << maxi << '\n';
  }
}

bool comp(pair<int, string> a, pair<int, string> b) {
  return (a.first < b.first || (a.first == b.first && a.second < b.second))
             ? true
             : false;
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  vector<pair<int, string>> x;

  for (auto p : t) {
    if (p.first == p.second.size()) x.push_back(p);
  }

  sort(x.begin(), x.end(), comp);

  auto p = x[0];

  cout << p.first << ' ' << p.second << '\n';
  out << p.first << ' ' << p.second << '\n';
}

int main() {
  ifstream in;

  in.open("pary.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfLines; i++) {
    string s;
    int x;
    in >> x >> s;

    t[i] = make_pair(x, s);
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}