#include <fstream>
#include <iostream>
using namespace std;

// #define numOfLines 100
string t;

ofstream out;

void zad1() {
  cout << "Zad 1:\n";
  out << "Zad 1:\n";

  int count = 0;
  for (int i = 1; i < t.size(); i++) {
    if (t[i] != t[i - 1]) count++;
  }
  cout << count << '\n';
  out << count << '\n';
}

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  int pointsA = 0, pointsB = 0;
  for (char c : t) {
    if (c == 'A')
      pointsA++;
    else
      pointsB++;

    if ((pointsA >= 1000 || pointsB >= 1000) && abs(pointsA - pointsB) >= 3) {
      break;
    }
  }

  if (pointsA > pointsB) {
    cout << 'A';
    out << 'A';
  } else {
    cout << 'B';
    out << 'B';
  }
  cout << ' ' << pointsA << ' ' << pointsB << '\n';
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  int countA = 0, countB = 0;
  int streakA = 0, streakB = 0;
  int maxStreakA = 0, maxStreakB = 0;

  for (int i = 0; i < t.size(); i++) {
    if (t[i] == 'A') {
      if (streakB >= 10) {
        countB++;
        if (streakB > maxStreakB) maxStreakB = streakB;
      }

      streakA++;
      streakB = 0;
    } else {
      if (streakA >= 10) {
        countA++;
        if (streakA > maxStreakA) maxStreakA = streakA;
      }

      streakB++;
      streakA = 0;
    }
  }

  cout << countA + countB << ' ';
  out << countA + countB << ' ';
  if (maxStreakA > maxStreakB) {
    cout << maxStreakA << " A\n";
    out << maxStreakA << " A\n";
  } else {
    cout << maxStreakB << " B\n";
    out << maxStreakB << " B\n";
  }
}

int main() {
  ifstream in;

  in.open("mecz.txt");
  out.open("wyniki1.txt");

  in >> t;

  zad1();
  zad2();
  zad3();

  in.close();
  out.close();
}