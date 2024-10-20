#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 2, -1);
  dp[n] = 1;
  dp[n+1] = 0;
  for(int i = n-1;i > -1; i--){
   dp[i] = dp[i+1] + dp[i+2];
  }
  cout<<dp[0]<<endl;
  return 0;
}