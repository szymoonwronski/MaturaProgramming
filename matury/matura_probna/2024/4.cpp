#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

#define numOfLines 5000
pair<int, int> t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int smallestArea = INT32_MAX, biggestArea = 0;
  for (auto [x, y] : t) {
    int area = x * y;

    if (area > biggestArea) biggestArea = area;
    if (area < smallestArea) smallestArea = area;
  }

  cout << smallestArea << ' ' << biggestArea << '\n';
  out << smallestArea << ' ' << biggestArea << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int len = 1;
  int maxLen = 1;
  int h, w;

  for (int i = 1; i < numOfLines; i++) {
    if (t[i].first <= t[i - 1].first && t[i].second <= t[i - 1].second) {
      len++;
    } else {
      len = 1;
    }
    if (len > maxLen) {
      maxLen = len;
      h = t[i].first;
      w = t[i].second;
    }
  }

  cout << maxLen << ' ' << h << ' ' << w << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  map<int, vector<int>> kv;

  for (auto [h, w] : t) {
    kv[h].push_back(w);
  }

  int maxWidth2 = 0, maxWidth3 = 0, maxWidth5 = 0;

  for (auto [k, v] : kv) {
    sort(v.begin(), v.end(), greater());

    int width = 0;
    if (v.size() >= 2) {
      width = v[0] + v[1];
      if (width > maxWidth2) maxWidth2 = width;
    }
    if (v.size() >= 3) {
      width = v[0] + v[1] + v[2];
      if (width > maxWidth3) maxWidth3 = width;
    }
    if (v.size() >= 5) {
      width = v[0] + v[1] + v[2] + v[3] + v[4];
      if (width > maxWidth5) maxWidth5 = width;
    }
  }

  cout << maxWidth2 << ' ' << maxWidth3 << ' ' << maxWidth5 << '\n';
  out << maxWidth2 << ' ' << maxWidth3 << ' ' << maxWidth5 << '\n';
}

int main() {
  ifstream in;

  in.open("prostokaty.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i].first >> t[i].second;
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}