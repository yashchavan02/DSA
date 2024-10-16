#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cout << "enter n : ";
  cin >> n;
  if (n == 0) {
    cout << n << endl;
    return 0;
  }
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i < n + 1; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[n] << endl;
  return 0;
}