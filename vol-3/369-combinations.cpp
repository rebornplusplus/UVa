#include <iostream>
#include <cstring>
using namespace std;

#define mini(a, b) a<b ? a : b
long long dp[101][101];

long long nCr(int n, int r) {
  if(!r || r==n) return 1;
  if(r==1) return n;

  r = mini(r, n-r);
  if(dp[n][r] == -1)
    dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);

  return dp[n][r];
}

int main()
{
  int n, r;
  long long res;
  memset(dp, -1, sizeof(dp));

  cin >> n >> r;
  while(n || r) {
    res = nCr(n, r);
    cout << n << " things taken " << r << " at a time is " << res << " exactly.\n";
    cin >> n >> r;
  }

  return 0;
}
