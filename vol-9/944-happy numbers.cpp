//storing the happy numbers and then binary-searching (>=)L and iterating can reduce runtime
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define M 405     //  5 * 9^2 = 405
#define MAX 99999
int shift[MAX+1];
bool again[M+1];

int sqrSum(int n) {
  int sum=0, temp;
  while(n) {
    temp = n % 10;
    n /= 10;
    sum += temp * temp;
  }
  return sum;
}

int dp(int n) {
  if(n<=M && again[n]) return 0;
  if(shift[n] != -1) return shift[n];

  if(n<=M) again[n] = true;
  int temp = dp(sqrSum(n));
  if(!temp) shift[n] = 0;
  else shift[n] = 1 + temp;
  return shift[n];
}

void preCal() {
  memset(shift, -1, sizeof(shift));
  shift[1] = 1;

  for(int i=1; i<=MAX; i++) {
    memset(again, false, sizeof(again));
    dp(i);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  preCal();

  int L, R;
  for(int i=0; cin >> L >> R; i++) {
    if(i) cout << '\n';
    for(int j=L; j<=R; j++)
      if(shift[j]) cout << j << ' ' << shift[j] << '\n';
  }

  return 0;
}
