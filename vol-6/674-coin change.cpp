//solved - Nov 29, 2015
#include <iostream>
#include <cstring>
using namespace std;

int coins[] = {50, 25, 10, 5, 1};
int make;
int dp[6][7490];

int func(int i, int amount);

int main()
{
  memset(dp, -1, sizeof(dp)); //make every element -1
  while(cin>>make) {
    if(!make) cout << 1 << "\n";
    else cout << func(0, make) << "\n";
  }

  return 0;
}

int func(int i, int amount)
{
  if(i >= 5) {
    if(!amount) return 1;
    else return 0;
  }
  if(dp[i][amount] != -1) return dp[i][amount];

  int ret1, ret2;
  ret1 = ret2 = 0;
  if(amount - coins[i] >= 0)
    ret1 = func(i, amount-coins[i]);  //see if coin can be used again
  ret2 = func(i+1, amount); //hope for the next coin

  return dp[i][amount] = ret1 + ret2; //assigning & returning
}
