#include <iostream>
using namespace std;

int count(int i) {
  if (i <= 1)
    return 1;
  return count(i - 1) + count(i - 2);
}

int main() {
  int n;
  cin >> n;
  cout << count(n) << endl;
  return 0;
}