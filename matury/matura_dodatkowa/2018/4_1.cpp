#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 1000
int a[numOfLines][10];
int b[numOfLines][10];

ofstream out;

void solve() {
  int count = 0;

  for (int i = 0; i < numOfLines; i++) {
    if (a[i][9] == b[i][9]) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

int main() {
  ifstream in1, in2;

  in1.open("dane1.txt");
  in2.open("dane2.txt");
  out.open("wyniki4_1.txt");

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