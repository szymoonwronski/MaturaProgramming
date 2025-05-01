#include <fstream>
#include <iostream>
using namespace std;

#define numOfLines 500
int t[numOfLines];

ofstream out;

const string barcodes[] = {"10101110111010", "11101010101110", "10111010101110",
                           "11101110101010", "10101110101110", "11101011101010",
                           "10111011101010", "10101011101110", "11101010111010",
                           "10111010111010"};

const string START = "11011010";
const string STOP = "11010110";

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  for (int num : t) {
    int sumEven =
        to_string(num)[0] + to_string(num)[2] + to_string(num)[4] - 3 * '0';
    int sumOdd =
        to_string(num)[1] + to_string(num)[3] + to_string(num)[5] - 3 * '0';

    cout << sumEven << ' ' << sumOdd << '\n';
    out << sumEven << ' ' << sumOdd << '\n';
  }
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  for (int num : t) {
    int sumEven =
        to_string(num)[1] + to_string(num)[3] + to_string(num)[5] - 3 * '0';
    int sumOdd =
        to_string(num)[0] + to_string(num)[2] + to_string(num)[4] - 3 * '0';

    int sum = 3 * sumEven + sumOdd;
    int r = sum % 10;
    r = 10 - r;
    r = r % 10;

    cout << r << ' ' << barcodes[r] << '\n';
    out << r << ' ' << barcodes[r] << '\n';
  }
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  for (int num : t) {
    int sumEven =
        to_string(num)[1] + to_string(num)[3] + to_string(num)[5] - 3 * '0';
    int sumOdd =
        to_string(num)[0] + to_string(num)[2] + to_string(num)[4] - 3 * '0';

    int sum = 3 * sumEven + sumOdd;
    int r = sum % 10;
    r = 10 - r;
    r = r % 10;

    string res = START;
    for (char c : to_string(num)) res += barcodes[c - '0'];
    res += barcodes[r];
    res += STOP;

    cout << res << '\n';
    out << res << '\n';
  }
}

int main() {
  ifstream in;

  in.open("kody.txt");
  out.open("wyniki6.txt");

  for (int i = 0; i < numOfLines; i++) {
    in >> t[i];
  }

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}