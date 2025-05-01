#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 310
int t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int count = 0, len = 1;
  for (int i = 1; i < numOfLines; i++) {
    if (t[i] > t[i - 1]) {
      len++;
    } else {
      if (len > 3) count++;
      len = 1;
    }
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int mini = t[0], maxi = t[0];
  int miniIndex = 0, maxiIndex = 0;
  for (int i = 0; i < numOfLines; i++) {
    if (t[i] > maxi) {
      maxi = t[i];
      maxiIndex = i + 1;
    }
    if (t[i] < mini) {
      mini = t[i];
      miniIndex = i + 1;
    }
  }

  cout << maxi << ' ' << maxiIndex << '\n';
  cout << mini << ' ' << miniIndex << '\n';
  out << maxi << ' ' << maxiIndex << '\n';
  out << mini << ' ' << miniIndex << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int maxLen = 0, len = 0;
  int diff = 0;
  for (int i = 1; i < numOfLines; i++) {
    if (t[i] > t[i - 1]) {
      len++;
    } else {
      if (len > maxLen) {
        maxLen = len;
        diff = t[i - 1] - t[i - len];
      }
      len = 1;
    }
  }

  cout << maxLen << ' ' << diff << '\n';
  out << maxLen << ' ' << diff << '\n';
}

int main() {
  ifstream in;

  in.open("dziennik.txt");
  out.open("wyniki5.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}