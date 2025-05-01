#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

#define numOfPrimes 3000
#define numOfNums 20
int primes[numOfPrimes];
int nums[numOfNums];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int count = 0;

  for (int prime : primes) {
    for (int num : nums) {
      if (num % prime == 0) {
        count++;
        break;
      }
    }
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int sorted[numOfPrimes];
  for (int i = 0; i < numOfPrimes; i++) {
    sorted[i] = primes[i];
  }

  sort(sorted, sorted + numOfPrimes, greater());

  cout << sorted[100] << '\n';
  out << sorted[100] << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  map<int, int> got, need;

  for (int prime : primes) {
    got[prime]++;
  }

  for (int num : nums) {
    int x = num;
    bool enough = true;
    int prime = 2;

    while (x != 1) {
      if (x % prime == 0) {
        x /= prime;
        need[prime]++;
      } else {
        prime++;
      }
    }

    for (auto [k, v] : need) {
      if (v > got[k]) {
        enough = false;
        break;
      }
    }

    if (enough) {
      cout << num << '\n';
      out << num << '\n';
    }

    need.clear();
  }
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  float maxiAvg = 0;
  int maxiLen = 0, maxiStartNum = 0;

  for (int len = 50; len <= numOfPrimes; len++) {
    for (int startIndex = 0; startIndex + len - 1 < numOfPrimes; startIndex++) {
      int startNum = primes[startIndex];

      int sum = 0;
      for (int i = 0; i < len; i++) {
        sum += primes[startIndex + i];
      }

      float avg = sum / (float)len;

      if (avg > maxiAvg) {
        maxiAvg = avg;
        maxiLen = len;
        maxiStartNum = startNum;
      }
    }
  }

  cout << maxiAvg << " " << maxiLen << " " << maxiStartNum << '\n';
  out << maxiAvg << " " << maxiLen << " " << maxiStartNum << '\n';
}

int main() {
  ifstream in;

  in.open("liczby.txt");
  out.open("wyniki4.txt");

  for (int i = 0; i < numOfPrimes; i++) {
    in >> primes[i];
  }

  for (int i = 0; i < numOfNums; i++) {
    in >> nums[i];
  }

  zad1();
  zad2();
  zad3();
  zad4();

  in.close();
  out.close();
}