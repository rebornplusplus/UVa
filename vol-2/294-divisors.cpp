#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define M 32000
bool marked[M];
vector<int> p;

void sieve() {
  p.push_back(2);
  for(int i=3; i*i < M; i+=2) {
    if(!marked[i]) {
      p.push_back(i);
      for(int j=i*i; j<M; j += i+i)
        marked[j] = true;
    }
  }

  for(int i=p.back()+2; i<M; i+=2)
    if(!marked[i]) p.push_back(i);
}

int divCnt(int n) {
  int div = 1;
  for(int i=0; p[i]*p[i] <= n; i++) {
    if(n % p[i] == 0) {
      int cnt = 1;
      while(n % p[i] == 0) {
        n /= p[i];
        cnt++;
      }

      div *= cnt;
    }
  }

  if(n!=1) div *= 2;

  return div;
}

int main()
{
  sieve();

  int t, L, U;
  cin >> t;

  while(t--) {
    cin >> L >> U;

    int MaxD=0, MaxN;
    for(int i=L; i<=U; i++) {
      int tmp = divCnt(i);
      if(tmp > MaxD) {
        MaxD = tmp;
        MaxN = i;
      }
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, MaxN, MaxD);
  }

  return 0;
}

