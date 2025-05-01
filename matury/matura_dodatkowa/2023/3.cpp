#include <fstream>
#include <iostream>
#include <map>
#include <set>
using namespace std;

#define numOfLines 1000
string t[numOfLines];

ofstream out;

pair<int, int> countDigits(string bin) {
  int count0 = 0, count1 = 0;
  for (char c : bin) {
    if (c == '0')
      count0++;
    else
      count1++;
  }
  return {count0, count1};
}

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int equal = 0, almostEqual = 0;

  for (string bin : t) {
    auto [count0, count1] = countDigits(bin);

    if (count0 == count1) equal++;
    if (abs(count0 - count1) == 1) almostEqual++;
  }

  cout << equal << '\n' << almostEqual << '\n';
  out << equal << '\n' << almostEqual << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  map<int, vector<string>> kv;

  for (string bin : t) {
    if (bin.size() != 8) continue;
    auto [count0, count1] = countDigits(bin);
    count1--;

    int diff = abs(count0 - count1);

    kv[diff].push_back(bin);
  }

  int mini = 10;
  for (auto [k, v] : kv) {
    if (k < mini) mini = k;
  }

  for (string bin : kv[mini]) {
    cout << bin << '\n';
    out << bin << '\n';
  }
}

int binToDec(string bin) {
  int res = 0;

  for (char c : bin) {
    res = res * 2 + c - '0';
  }

  return res;
}

string decToBin(int n) {
  string bin = "";

  while (n) {
    char c = '0' + n % 2;
    bin = c + bin;
    n /= 2;
  }

  return bin;
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int maxi = 0;
  for (int i = 0; i + 1 < numOfLines; i++) {
    int diff = abs(binToDec(t[i]) - binToDec(t[i + 1]));
    if (diff > maxi) maxi = diff;
  }

  cout << decToBin(maxi) << '\n';
  out << decToBin(maxi) << '\n';
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  vector<int> dec;
  for (string bin : t) dec.push_back(binToDec(bin));

  int countLacking0 = 0;
  for (int i : dec) {
    string s = to_string(i);
    if (s.find('0') == string::npos) countLacking0++;
  }

  cout << countLacking0 << '\n';
  out << countLacking0 << '\n';

  int maxi = 0, maxiNum = 0;
  for (int i : dec) {
    int num = i;

    set<int> digits;
    while (num) {
      digits.insert(num % 10);
      num /= 10;
    }

    int sum = 0;
    for (int d : digits) sum += d;
    if (sum > maxi) {
      maxi = sum;
      maxiNum = i;
    }
  }

  cout << maxiNum << '\n';
  out << maxiNum << '\n';
}

int main() {
  ifstream in;

  in.open("anagram.txt");
  out.open("wyniki3.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();
  zad4();

  in.close();
  out.close();
}