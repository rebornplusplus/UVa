#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> v, res;
bool taken[17];

bool isPrime(int n) {
  if(n < 2) return false;
  if(n == 2) return true;
  if(n % 2 == 0) return false;

  for(int i=3; i*i <= n; i+=2)
    if(n % i == 0) return false;
  return true;
}

void backtrack() {
  if( res.size() == n ) {
    if( isPrime(1 + res.back()) ) {
      putchar('1');
      for(int i=1; i < (int) res.size(); i++)
        printf(" %d", res[i]);
      putchar('\n');
    }

    return;
  }

  for(int i=2; i<=n; i++) {
    if( !taken[i] && isPrime(i + res.back()) ) {
      taken[i] = true;
      res.push_back(i);

      backtrack();

      taken[i] = false;
      res.pop_back();
    }
  }
}

int main()
{
  //freopen("out.txt", "w", stdout);

  int cnt=0, i, j;
  while(cin >> n) {

    for(i=0; i<=n; i++) taken[i] = false;
    v.clear(); res.clear();
    for(i=1; i<=n; i++) v.push_back(i);
    res.push_back(1);

    if(cnt++) putchar('\n');
    printf("Case %d:\n", cnt);
    backtrack();
  }

  return 0;
}
