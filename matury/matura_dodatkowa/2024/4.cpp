#include <fstream>
#include <iostream>
#include <map>
#include <set>
using namespace std;

#define numOfLines 1024
int t[numOfLines + 1];

ofstream out;

void zad2() {
  cout << "Zad 2:\n";
  out << "Zad 2:\n";

  set<int> machines;
  for (int i = 1; i <= numOfLines; i++) machines.insert(t[i]);

  int n = numOfLines - machines.size();

  cout << n << '\n';
  out << n << '\n';
}

pair<bool, int> hasReturned(vector<int> v) {
  for (int i = 1; i <= numOfLines; i++) {
    if (v[i] == i) return make_pair(true, i);
  }
  return make_pair(false, 0);
}

void zad3() {
  cout << "Zad 3:\n";
  out << "Zad 3:\n";

  vector<int> state({0});
  for (int i = 1; i <= numOfLines; i++) state.push_back(i);

  int round = 0;
  do {
    round++;
    for (int i = 1; i <= numOfLines; i++) {
      int machine = state[i];
      state[i] = t[machine];
    }
  } while (!hasReturned(state).first);

  cout << round << ' ' << hasReturned(state).second << '\n';
  out << round << ' ' << hasReturned(state).second << '\n';
}

int maxPackets(vector<int> v) {
  map<int, int> counter;

  for (int i = 1; i <= numOfLines; i++) {
    int machine = v[i];
    counter[machine]++;
  }

  int maxi = 0;
  for (auto [k, v] : counter) {
    if (v > maxi) maxi = v;
  }
  return maxi;
}

void zad4() {
  cout << "Zad 4:\n";
  out << "Zad 4:\n";

  vector<int> state({0});
  for (int i = 1; i <= numOfLines; i++) state.push_back(i);

  set<int> rounds = {1, 2, 4, 8};
  int round = 0;
  do {
    round++;
    for (int i = 1; i <= numOfLines; i++) {
      int machine = state[i];
      state[i] = t[machine];
    }
    if (rounds.find(round) != rounds.end()) cout << maxPackets(state) << ' ';
  } while (round < 8);
}

int main() {
  ifstream in;

  in.open("odbiorcy.txt");
  out.open("wyniki4.txt");

  for (int i = 1; i <= numOfLines; i++) {
    in >> t[i];
  }

  zad2();
  zad3();
  zad4();

  in.close();
  out.close();
}