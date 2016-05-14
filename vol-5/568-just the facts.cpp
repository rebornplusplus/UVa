#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

const int mod = 1000000;
int ans[10001];

void preCal() {
  ans[0] = 1;
  long long temp;

  for(int i=1; i<=10000; i++) {
    temp = (long long) ans[i-1] * i;
    while(temp % 10 == 0) temp /= 10;
    ans[i] = temp % mod;
  }
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  preCal();

  int n;
  while(cin >> n)
    cout << setw(5) << n << " -> " << ans[n] % 10 << '\n';
  return 0;
}
