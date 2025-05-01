#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 1000
string t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int count = 0;
  for (string bin : t) {
    int zeros = 0;
    for (char c : bin) {
      if (c == '0') zeros++;
    }

    if (zeros * 2 > bin.size()) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

bool divisibleBy2(string bin) { return bin[bin.size() - 1] == '0'; }
bool divisibleBy8(string bin) {
  return bin.size() > 3 ? bin.substr(bin.size() - 3, 3) == "000" : false;
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int count2 = 0, count8 = 0;

  for (string bin : t) {
    if (divisibleBy2(bin)) count2++;
    if (divisibleBy8(bin)) count8++;
  }

  cout << count2 << ' ' << count8 << '\n';
  out << count2 << ' ' << count8 << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  string mini = t[0], maxi = t[0];
  int miniIndex = 0, maxiIndex = 0;
  for (int i = 1; i < numOfLines; i++) {
    string bin = t[i];

    if (bin.size() < mini.size()) {
      mini = bin;
      miniIndex = i;
      continue;
    }
    if (bin.size() > maxi.size()) {
      maxi = bin;
      maxiIndex = i;
      continue;
    }

    if (bin.size() == mini.size()) {
      int miniN = 0;
      for (int j = 1; j < mini.size(); j++) {
        if (mini[j] == '0')
          miniN++;
        else
          break;
      }

      int binN = 0;
      for (int j = 1; j < bin.size(); j++) {
        if (bin[j] == '0')
          binN++;
        else
          break;
      }

      if (binN > miniN) {
        mini = bin;
        miniIndex = i;
        continue;
      }
    }

    if (bin.size() == maxi.size()) {
      int maxiN = 0;
      for (int j = 1; j < maxi.size(); j++) {
        if (maxi[j] == '1')
          maxiN++;
        else
          break;
      }

      int binN = 0;
      for (int j = 1; j < bin.size(); j++) {
        if (bin[j] == '1')
          binN++;
        else
          break;
      }

      if (binN > maxiN) {
        maxi = bin;
        maxiIndex = i;
      }
    }
  }

  cout << miniIndex + 1 << ' ' << maxiIndex + 1 << '\n';
  out << miniIndex + 1 << ' ' << maxiIndex + 1 << '\n';
}

int main() {
  ifstream in;

  in.open("liczby.txt");
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