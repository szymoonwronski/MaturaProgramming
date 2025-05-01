#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 100
string t[numOfLines];

ofstream out;

int numOfSegments(string bin) {
  int count = 1;

  char pv = bin[0];
  for (char v : bin) {
    if (v != pv) count++;
    pv = v;
  }

  return count;
}

int binToDec(string bin) {
  int res = 0;

  for (char c : bin) {
    res = res * 2 + c - '0';
  }

  return res;
}

void zad1() {
  cout << "Zad 2.2:\n";
  out << "Zad 2.2:\n";

  int count = 0;
  for (string bin : t) {
    int n = numOfSegments(bin);
    if (n <= 2) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2.3:\n";
  out << "Zad 2.3:\n";

  string maxiBin = "";
  int maxi = 0;
  for (string bin : t) {
    int n = binToDec(bin);

    if (n > maxi) {
      maxi = n;
      maxiBin = bin;
    }
  }

  cout << maxiBin << '\n';
}

int main() {
  ifstream in;

  in.open("bin.txt");
  out.open("wyniki2.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();

  in.close();
  out.close();
}