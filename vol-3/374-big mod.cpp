#include <iostream>
using namespace std;

#define sqr(x) x*x

int bigmod(int b, int p, int m) {
  if(p==0) return 1 % m;
  else if(p%2==0) return sqr(bigmod(b, p/2, m)) % m;
  return ((b % m) * bigmod(b, p-1, m)) % m;
}

int main()
{
  int base, pwr, mod;
  while(cin >> base >> pwr >> mod)
    cout << bigmod(base, pwr, mod) << endl;

  return 0;
}
