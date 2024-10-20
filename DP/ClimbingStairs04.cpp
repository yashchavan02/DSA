#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dp(3, -1);
  dp[1] = 1;
  dp[2] = 0;
  for (int i = n - 1; i > -1; i--) {
    dp[0] = dp[1] + dp[2];
    dp[2] = dp[1];
    dp[1] = dp[0];
  }
  cout << dp[0] << endl;
  return 0;
}