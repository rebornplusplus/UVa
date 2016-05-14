#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define M 1000      //cause, there's no AnaPrime > 991
bool marked[M], checked[M];
vector<int> p, ap;

void sieve() {
  p.push_back(2);
  int i, j;

  for(i=3; (j=i*i) < M; i+=2) {
    if(!marked[i]) {
      p.push_back(i);
      for( ; j<M; j += i+i)
        marked[j] = true;
    }
  }

  for(i=p.back()+2; i<M; i+=2)
    if(!marked[i]) p.push_back(i);
}

bool isPrime(int n) {
  if(n < 2) return false;
  if(n == 2) return true;
  if(n % 2 == 0) return false;

  return marked[n] == false;
}

bool isAnaPrime(int n) {
  if(n < 10) return true;

  vector<int> t;
  int tmp, i;

  while(n) {
    tmp = n % 10;
    n /= 10;
    if(tmp % 2 == 0) return false;
    t.push_back(tmp);
  }

  sort(t.begin(), t.end());
  do {
    n = 0;
    for(i=0; i < (int) t.size(); i++)
      n = n*10 + t[i];
    if(!isPrime(n)) return false;
  } while( next_permutation(t.begin(), t.end()) );

  return true;
}

void PreCal() {
  sieve();
  for(int i=0; i < (int) p.size(); i++)
    if(isAnaPrime(p[i])) ap.push_back(p[i]);
}

int NumLen(int n) {
  int cnt = 1;
  while(n /= 10) cnt++;
  return cnt;
}

int main()
{
  //freopen("out.txt", "w", stdout);
  PreCal();

  int n;
  while((cin >> n) && n) {
    int ans = 0;
    if(n < 991) {
      for(int i=0; i < (int) ap.size(); i++) {
        if(ap[i] > n) {
          ans = ap[i];
          break;
        }
      }

      if(NumLen(ans) > NumLen(n)) ans = 0;
    }

    cout << ans << endl;
  }

  return 0;
}
