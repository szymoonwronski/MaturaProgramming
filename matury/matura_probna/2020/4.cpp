#include <fstream>
#include <iostream>
#include <map>
using namespace std;

#define numOfLines 1000
int t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int mini = INT32_MAX, maxi = 0;
  for (int i = 1; i < numOfLines; i++) {
    int diff = abs(t[i] - t[i - 1]);
    if (diff < mini) mini = diff;
    if (diff > maxi) maxi = diff;
  }

  cout << maxi << ' ' << mini << '\n';
  out << maxi << ' ' << mini << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int firstNum = t[0], lastNum = t[0], maxLen = 0, len = 2;
  for (int i = 2; i < numOfLines; i++) {
    int prevDiff = abs(t[i - 1] - t[i - 2]);
    int diff = abs(t[i] - t[i - 1]);
    if (diff == prevDiff) {
      len++;
    } else {
      if (len > maxLen) {
        maxLen = len;
        firstNum = t[i - len];
        lastNum = t[i - 1];
      }
      len = 2;
    }
  }

  cout << maxLen << ' ' << firstNum << ' ' << lastNum << '\n';
  out << maxLen << ' ' << firstNum << ' ' << lastNum << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  map<int, int> counter;
  for (int i = 1; i < numOfLines; i++) {
    int diff = abs(t[i] - t[i - 1]);
    counter[diff]++;
  }

  int maxV = 0;
  for (auto [k, v] : counter) {
    if (v > maxV) maxV = v;
  }
  cout << maxV << '\n';
  out << maxV << '\n';
  for (auto [k, v] : counter) {
    if (v == maxV) {
      cout << k << ' ';
      out << k << ' ';
    }
  }
  cout << '\n';
  out << '\n';
}

int main() {
  ifstream in;

  in.open("dane4.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}