#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
using namespace std;

#define numOfLines 2000
int t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  set<int> squares;

  for (int i = 10; i * i <= 9999; i++) squares.insert(i * i);

  int count = 0;
  int firstNum = -1;

  for (int i : t) {
    if (squares.find(i) != squares.end()) {
      count++;
      if (firstNum == -1) firstNum = i;
    }
  }

  cout << count << " " << firstNum << '\n';
  out << count << " " << firstNum << '\n';
}

bool hasAtleast5PrimeFactors(int num) {
  int prime = 2;
  set<int> factors;

  while (num > 1) {
    if (num % prime == 0) {
      factors.insert(prime);
      num /= prime;
    } else
      prime++;
  }

  return factors.size() >= 5;
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  for (int i : t) {
    if (hasAtleast5PrimeFactors(i)) {
      cout << i << '\n';
      out << i << '\n';
    }
  }
}

int numDiff(int i) {
  string num = to_string(i);
  sort(num.begin(), num.end());
  int small = stoi(num);
  sort(num.begin(), num.end(), greater());
  int big = stoi(num);

  return big - small;
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int countS = 0, countE = 0, countG = 0;
  vector<int> v;

  for (int i : t) {
    int diff = numDiff(i);
    if (diff < i)
      countS++;
    else if (diff == i) {
      v.push_back(i);
      countE++;
    } else
      countG++;
  }

  cout << countS << ' ' << countE << ' ' << countG << '\n';
  out << countS << ' ' << countE << ' ' << countG << '\n';

  for (int i : v) {
    cout << i << ' ';
    out << i << ' ';
  }
}

int main() {
  ifstream in;

  in.open("liczby.txt");
  out.open("wyniki3.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}