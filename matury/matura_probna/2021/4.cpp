#include <fstream>
#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Line {
  string code;
  string city;
  vector<pair<int, int>> v;
};

#define numOfLines 10
Line t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";
  map<string, int> kv;

  for (Line i : t) {
    kv[i.code]++;
  }

  for (auto [k, v] : kv) {
    cout << k << ' ' << v << '\n';
    out << k << ' ' << v << '\n';
  }
}

void zad2() {
  cout << "Zad 2a:\n";
  out << "Zad 2a:\n";

  map<string, int> kv;

  for (Line i : t) {
    int sum = 0, n = 0;

    for (auto [x, y] : i.v) {
      sum += x * y;
      if (x != 0 && y != 0) n++;
    }

    kv[i.city] = sum;

    cout << i.city << ' ' << sum << ' ' << n << '\n';
    out << i.city << ' ' << sum << ' ' << n << '\n';
  }

  cout << "Zad 2b:\n";
  out << "Zad 2b:\n";

  string miniC, maxiC;
  int miniSum = INT32_MAX, maxiSum = 0;
  for (auto [k, v] : kv) {
    if (v > maxiSum) {
      maxiSum = v;
      maxiC = k;
    }
    if (v < miniSum) {
      miniSum = v;
      miniC = k;
    }
  }

  cout << maxiC << ' ' << maxiSum << '\n';
  cout << miniC << ' ' << miniSum << '\n';
  out << maxiC << ' ' << maxiSum << '\n';
  out << miniC << ' ' << miniSum << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  string miniC, maxiC;
  int miniArea = INT32_MAX, maxiArea = 0;
  for (auto i : t) {
    set<int> areas;
    for (auto [x, y] : i.v) {
      int area = x * y;
      areas.insert(area);
    }

    int n = areas.size() - 1;

    if (n < miniArea) {
      miniArea = n;
      miniC = i.city;
    }
    if (n > maxiArea) {
      maxiArea = n;
      maxiC = i.city;
    }
  }

  cout << maxiC << ' ' << maxiArea << '\n';
  cout << miniC << ' ' << miniArea << '\n';
  out << maxiC << ' ' << maxiArea << '\n';
  out << miniC << ' ' << miniArea << '\n';
}

int main() {
  ifstream in;

  in.open("galerie_przyklad.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfLines; i++) {
    string code;
    string city;
    in >> code >> city;

    t[i].code = code;
    t[i].city = city;
    for (int j = 0; j < 70; j++) {
      int x, y;
      in >> x >> y;

      t[i].v.push_back({x, y});
    }
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}