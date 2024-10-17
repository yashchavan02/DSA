#include <iostream>
using namespace std;

int count(int i, int n) {
  if (i == n) {
    return 1;
  }
  if (i > n) {
    return 0;
  }
  return count(i + 1, n) + count(i + 2, n);
}

int main() {
  int n;
  cin >> n;
  cout << count(0, n) << endl;
  return 0;
}