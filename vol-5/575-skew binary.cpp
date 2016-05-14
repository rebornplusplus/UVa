#include <iostream>
#include <cstring>
using namespace std;

unsigned int pwr2_1(int p) {
  if(!p) return 1;

  unsigned int val=2;
  for(int i=2; i<=p; i++) val *= 2;
  return val-1;
}

int main()
{
  char skew[32];
  int n, i, len, tmp;

  cin >> skew;
  len = strlen(skew);

  while(!(len==1 && skew[0]=='0')) {
    n = 0;

    for(i=len-1; i>=0; i--) {
      tmp = skew[i] - 48;
      if(tmp) n += tmp * pwr2_1(len-i);
    }

    cout << n << endl;

    cin >> skew;
    len = strlen(skew);
  }

  return 0;
}
