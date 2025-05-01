#include <fstream>
#include <iostream>
#include <set>
using namespace std;

#define numOfLines 1000
pair<int, int> t[numOfLines];

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

  int count = 0;

  for (auto [x, y] : t) {
    if (isPrime(x) && isPrime(y)) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int count = 0;

  for (auto [x, y] : t) {
    set<int> a, b;
    for (char c : to_string(x)) a.insert(c - '0');
    for (char c : to_string(y)) b.insert(c - '0');

    if (a.size() != b.size()) continue;
    bool valid = true;
    for (int i : a) {
      if (b.find(i) == b.end()) valid = false;
    }
    if (valid) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

float dist(pair<int, int> p1, pair<int, int> p2) {
  return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  float maxDist = 0;
  pair<int, int> maxPoint1, maxPoint2;
  for (auto p1 : t) {
    for (auto p2 : t) {
      float d = dist(p1, p2);
      if (d > maxDist) {
        maxDist = d;
        maxPoint1 = p1;
        maxPoint2 = p2;
      }
    }
  }

  cout << maxPoint1.first << ' ' << maxPoint1.second << '\n';
  cout << maxPoint2.first << ' ' << maxPoint2.second << '\n';
  cout << (int)maxDist << '\n';
  out << maxPoint1.first << ' ' << maxPoint1.second << '\n';
  out << maxPoint2.first << ' ' << maxPoint2.second << '\n';
  out << (int)maxDist << '\n';
}

bool isInside(pair<int, int> p) {
  if (p.first < 5000 && p.second < 5000) return true;
  return false;
}

bool isOnEdge(pair<int, int> p) {
  if ((p.first == 5000 && p.second <= 5000) ||
      (p.second == 5000 && p.first <= 5000))
    return true;
  return false;
}

bool isOutside(pair<int, int> p) {
  if (p.first > 5000 || p.second > 5000) return true;
  return false;
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  int c1 = 0, c2 = 0, c3 = 0;

  for (auto p : t) {
    if (isInside(p))
      c1++;
    else if (isOnEdge(p))
      c2++;
    else if (isOutside(p))
      c3++;
  }

  cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
  out << c1 << ' ' << c2 << ' ' << c3 << '\n';
}

int main() {
  ifstream in;

  in.open("punkty.txt");
  out.open("wyniki4.txt");

  for (int x, y, i = 0; i < numOfLines; i++) {
    in >> x >> y;
    t[i] = make_pair(x, y);
  }

  zad1();
  zad2();
  zad3();
  zad4();

  in.close();
  out.close();
}