#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 1000
int a[numOfLines][10];
int b[numOfLines][10];

ofstream out;

void solve() {
  for (int i = 0; i < numOfLines; i++) {
    vector<int> v;

    for (int c : a[i]) v.push_back(c);
    for (int c : b[i]) v.push_back(c);

    sort(v.begin(), v.end());

    for (int c : v) cout << c << ' ';
    cout << '\n';
    for (int c : v) out << c << ' ';
    out << '\n';
  }
}

int main() {
  ifstream in1, in2;

  in1.open("dane1.txt");
  in2.open("dane2.txt");
  out.open("wyniki4_4.txt");

  for (int i = 0; i < numOfLines; i++) {
    for (int j = 0; j < 10; j++) {
      in1 >> a[i][j];
    }
  }

  for (int i = 0; i < numOfLines; i++) {
    for (int j = 0; j < 10; j++) {
      in2 >> b[i][j];
    }
  }

  solve();

  in1.close();
  in2.close();
  out.close();
}