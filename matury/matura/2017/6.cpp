#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 200
#define numOfColumns 320
int t[numOfLines][numOfColumns];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int maxi = t[0][0], mini = t[0][0];
  for (int i = 0; i < numOfLines; i++) {
    for (int j = 0; j < numOfColumns; j++) {
      int v = t[i][j];

      if (v > maxi) maxi = v;
      if (v < mini) mini = v;
    }
  }

  cout << maxi << ' ' << mini << '\n';
  out << maxi << ' ' << mini << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int count = 0;

  for (int i = 0; i < numOfLines; i++) {
    bool valid = true;
    for (int j = 0; j < numOfColumns / 2; j++) {
      if (t[i][j] != t[i][numOfColumns - 1 - j]) valid = false;
    }
    if (!valid) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int count = 0;
  for (int i = 0; i < numOfLines; i++) {
    for (int j = 0; j < numOfColumns; j++) {
      bool exists = false;

      if (i - 1 >= 0 && abs(t[i][j] - t[i - 1][j]) > 128) exists = true;
      if (i + 1 < numOfLines && abs(t[i][j] - t[i + 1][j]) > 128) exists = true;
      if (j - 1 >= 0 && abs(t[i][j] - t[i][j - 1]) > 128) exists = true;
      if (j + 1 < numOfColumns && abs(t[i][j] - t[i][j + 1]) > 128)
        exists = true;

      if (exists) count++;
    }
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  int maxi = 0;
  for (int j = 0; j < numOfColumns; j++) {
    int count = 1;
    for (int i = 1; i < numOfLines; i++) {
      if (t[i - 1][j] == t[i][j])
        count++;
      else
        count = 1;

      if (count > maxi) maxi = count;
    }
  }

  cout << maxi << '\n';
}

int main() {
  ifstream in;

  in.open("dane.txt");
  out.open("wyniki6.txt");

  for (int i = 0; i < numOfLines; i++) {
    for (int j = 0; j < numOfColumns; j++) {
      in >> t[i][j];
    }
  }

  zad1();
  zad2();
  zad3();
  zad4();

  in.close();
  out.close();
}