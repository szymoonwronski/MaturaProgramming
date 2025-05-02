#include <fstream>
#include <iostream>
#include <map>
using namespace std;

#define numOfLines 100
int t[numOfLines];

ofstream out;

bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int count = 0;
  for (int i : t) {
    if (isPrime(i - 1)) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

int numOfWays(int n) {
  int count = 0;

  for (int i = 2; i <= n / 2; i++) {
    if (isPrime(i) && isPrime(n - i)) count++;
  }

  return count;
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int mini = INT32_MAX, maxi = 0;
  int miniNum, maxiNum;
  for (int i : t) {
    int n = numOfWays(i);

    if (n < mini) {
      mini = n;
      miniNum = i;
    } else if (n > maxi) {
      maxi = n;
      maxiNum = i;
    }
  }

  cout << maxiNum << ' ' << maxi << '\n';
  cout << miniNum << ' ' << mini << '\n';
  out << maxiNum << ' ' << maxi << '\n';
  out << miniNum << ' ' << mini << '\n';
}

char lookup[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                   '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string decToHex(int n) {
  string res = "";
  while (n) {
    int r = n % 16;
    res = lookup[r] + res;
    n /= 16;
  }

  return res;
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  map<char, int> kv;

  for (int i : t) {
    string hex = decToHex(i);
    for (char c : hex) kv[c]++;
  }

  for (char i : lookup) {
    cout << i << ':' << kv[i] << '\n';
    out << i << ':' << kv[i] << '\n';
  }
}

int main() {
  ifstream in;

  in.open("liczby.txt");
  out.open("wyniki3.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad2();
  zad3();
  zad4();

  in.close();
  out.close();
}