#include <fstream>
#include <iostream>
#include <map>
using namespace std;

#define numOfLines 10000
int t[numOfLines];

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int count = 0;
  for (int i = 0; i + 1 < numOfLines; i++) {
    int num = t[i] * 10 + t[i + 1];

    if (num > 90) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  map<string, int> counter;

  for (char a = 0; a <= 9; a++) {
    for (char b = 0; b <= 9; b++) {
      string k = "";
      k += '0' + a;
      k += '0' + b;

      counter[k] = 0;
    }
  }

  for (int i = 0; i + 1 < numOfLines; i++) {
    string k = "";
    k += '0' + t[i];
    k += '0' + t[i + 1];

    counter[k]++;
  }

  string miniK = "00", maxiK = "00";
  int miniV = counter[miniK], maxiV = counter[maxiK];
  for (auto [k, v] : counter) {
    if ((v < miniV) || (v == miniV && stoi(k) < stoi(miniK))) {
      miniV = v;
      miniK = k;
    }
    if ((v > maxiV) || (v == maxiV && stoi(k) < stoi(maxiK))) {
      maxiV = v;
      maxiK = k;
    }
  }

  cout << miniK << ' ' << miniV << '\n';
  cout << maxiK << ' ' << maxiV << '\n';
  out << miniK << ' ' << miniV << '\n';
  out << maxiK << ' ' << maxiV << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int count = 0;
  for (int startIndex = 0; startIndex + 5 < numOfLines; startIndex++) {
    bool valid = false;
    for (int k = 2; k <= 4; k++) {
      bool kValid = true;

      for (int i = 0; i + 1 < k; i++) {
        if (t[startIndex + i + 1] <= t[startIndex + i]) kValid = false;
      }
      for (int i = k; i <= 4; i++) {
        if (t[startIndex + i] <= t[startIndex + i + 1]) kValid = false;
      }

      if (kValid) valid = true;
    }

    if (valid) count++;
  }

  cout << count << '\n';
  out << count << '\n';
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  int maxiIndex = 0;
  string maxiSeq = "";

  for (int len = 4; len <= numOfLines; len++) {
    for (int startIndex = 0; startIndex + len - 1 < numOfLines; startIndex++) {
      bool valid = false;
      string seq = "";
      for (int k = 2; k <= len - 2; k++) {
        seq = "";
        bool kValid = true;

        for (int i = 0; i + 1 < k; i++) {
          seq += '0' + t[startIndex + i];
          if (t[startIndex + i + 1] <= t[startIndex + i]) {
            kValid = false;
            break;
          }
        }
        seq += '0' + t[startIndex + k - 1];
        if (!kValid) break;
        for (int i = k; i <= len - 2; i++) {
          seq += '0' + t[startIndex + i];
          if (t[startIndex + i] <= t[startIndex + i + 1]) {
            kValid = false;
            break;
          }
        }
        seq += '0' + t[startIndex + len - 1];

        if (kValid) {
          valid = true;
          break;
        }
      }

      if (valid && len > maxiSeq.size()) {
        maxiSeq = seq;
        maxiIndex = startIndex + 1;
        break;
      }
    }
  }

  cout << maxiIndex << '\n' << maxiSeq << '\n';
  out << maxiIndex << '\n' << maxiSeq << '\n';
}

int main() {
  ifstream in;

  in.open("pi.txt");
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