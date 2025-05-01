#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 200
string t[numOfLines];

ofstream out;

pair<string, string> split(string s) {
  string a = s.substr(0, 3);
  string b = s.substr(3, 7);
  return {a, b};
}

int sumOfDigits(string s) {
  int sum = 0;
  for (char c : s) sum += c - '0';
  return sum;
}

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  vector<string> ans;
  int maxSum = 0;
  for (string i : t) {
    auto [a, b] = split(i);
    int sum = sumOfDigits(b);
    if (sum > maxSum) {
      maxSum = sum;
      ans.clear();
      ans.push_back(i);
    } else if (sum == maxSum) {
      ans.push_back(i);
    }
  }
  for (string i : ans) {
    cout << i << '\n';
    out << i << '\n';
  }
}

bool isPalindrome(string s) {
  string r = string(s.rbegin(), s.rend());
  // cout << s << ' ' << r << '\n';
  return s == r;
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  for (string i : t) {
    auto [a, b] = split(i);

    if (isPalindrome(a) || isPalindrome(b)) {
      cout << i << '\n';
      out << i << '\n';
    }
  }
}

bool isValid(string i) {
  const int weights[] = {7, 3, 1, 0, 7, 3, 1, 7, 3, 1};
  auto [a, b] = split(i);
  int check = i[3] - '0';

  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    int n = a[i] - 'A' + 10;
    sum += n * weights[i];
  }
  for (int i = 0; i < b.size(); i++) {
    int n = b[i] - '0';
    sum += n * weights[i + 3];
  }

  if (sum % 10 == check) return true;
  return false;
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  for (string i : t) {
    bool valid = isValid(i);
    if (!valid) {
      cout << i << '\n';
      out << i << '\n';
    }
  }
}

int main() {
  ifstream in;

  in.open("identyfikator.txt");
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