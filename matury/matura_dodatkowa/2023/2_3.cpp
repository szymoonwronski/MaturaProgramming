#include <iostream>
using namespace std;

bool czy_mniejszy(int n, string s, int k1, int k2) {
  // cout << n << ' ' << s << ' ' << k1 << ' ' << k2 << '\n';
  string a = "0" + s;
  int i = k1;
  int j = k2;
  while (i <= n && j <= n) {
    if (a[i] == a[j]) {
      i++;
      j++;
    } else {
      if (a[i] < a[j])
        return true;
      else
        return false;
    }
  }
  if (j <= n)
    return true;
  else
    return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  int n = s.size();

  int t[n + 1];
  for (int i = 1; i <= n; i++) t[i] = i;

  for (int k = 0; k < n; k++) {
    for (int i = 2; i <= n; i++) {
      if (czy_mniejszy(n, s, t[i], t[i - 1])) {
        int temp = t[i - 1];
        t[i - 1] = t[i];
        t[i] = temp;
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << t[i] << ' ';
}