#include <iostream>
using namespace std;

#define M 10
int a[M+1];

void preCal() {
  a[0] = a[1] = 1;
  for(int i=2; i<=M; i++) {
    a[i] = 0;
    for(int j=0; j<i; j++) a[i] += ( a[j] * a[i-1-j] );
  }
}

int main()
{
  preCal();

  int n, cnt=0;
  while(cin >> n) {
    if(cnt++) cout << "\n";
    cout << a[n] << '\n';
  }

  return 0;
}
