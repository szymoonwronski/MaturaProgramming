#include <fstream>
#include <iostream>
#include <set>
using namespace std;

#define numOfLines 1000
int a[numOfLines][10];
int b[numOfLines][10];

ofstream out;

void solve() {
  int count = 0;
  vector<int> v;
  for (int i = 0; i < numOfLines; i++) {
    set<int> numsA, numsB;

    for (int c : a[i]) numsA.insert(c);
    for (int c : b[i]) numsB.insert(c);

    bool valid = true;
    if (numsA.size() != numsB.size()) continue;
    for (int m : numsA) {
      if (numsB.find(m) == numsB.end()) valid = false;
    }
    if (valid) {
      count++;
      v.push_back(i + 1);
    }
  }

  cout << count << '\n';
  for (int i : v) cout << i << ' ';
  cout << '\n';
  out << count << '\n';
  for (int i : v) out << i << ' ';
  out << '\n';
}

int main() {
  ifstream in1, in2;

  in1.open("dane1.txt");
  in2.open("dane2.txt");
  out.open("wyniki4_3.txt");

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