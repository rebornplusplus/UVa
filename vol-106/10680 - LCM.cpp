#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define M 1000
bool marked[M];
vector<int> p;

#define MAX 1000000
long long lcm[MAX+1];   // to store 7 digits of lcm form 1 to i
int used[MAX+1];        // how many times we used prime i in lcm till i-1

void sieve() {
  for(int i=3; i*i < M; i+=2) if(!marked[i]) for(int j=i*i; j<M; j += i+i) marked[j] = true;
  p.push_back(2);
  for(int i=3; i<M; i+=2) if(!marked[i]) p.push_back(i);
}

void preCal() {
  sieve();
  lcm[1] = 1;

  for(int i=2; i<=MAX; i++) {
    lcm[i] = lcm[i-1];
    //prime factorzing i (aka 'n')
    int n = i;
    for(int j=0; j<p.size(); j++) {
      int cnt = 0;
      while(n % p[j] == 0) {
        ++cnt;
        n /= p[j];
      }
      //updating used
      while(used[ p[j] ] < cnt) {
        lcm[i] *= p[j];
        ++used[ p[j] ];
      }
    }

    if(n!=1) {
      if(used[n] < 1) {
        ++used[n];
        lcm[i] *= n;
      }
    }

    while(lcm[i] % 10 == 0) lcm[i] /= 10;
    lcm[i] %= 10000000;
  }
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  preCal();

  int n;
  do {
    cin >> n;
    if(!n) break;
    cout << lcm[n] % 10 << endl;
  } while(true);

  return 0;
}
