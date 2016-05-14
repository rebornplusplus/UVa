#include <iostream>
using namespace std;

#define M 50
long long fib[M+1];

void preCal() {
  fib[0] = fib[1] = 1;
  for(int i=2; i<=M; i++)
    fib[i] = fib[i-1] + fib[i-2];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  preCal();

  int n;
  while(cin >> n && n) cout << fib[n] << '\n';
  return 0;
}
