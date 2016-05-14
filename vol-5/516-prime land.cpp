//first off, Unclear problem statement
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

typedef pair<int, int> pii;
#define MAX 32767
bool marked[MAX+1];
vector<int> p;
vector< pii > PR;   //Prime Land Representation

void sieve() {
  p.push_back(2);

  int i, j;
  for(i=3; i*i <= MAX; i+=2) {
    if(!marked[i]) {
      p.push_back(i);
      for(j=i*i; j<=MAX; j += i+i)
        marked[j] = true;
    }
  }

  for(i=p.back()+2; i<=MAX; i+=2)
    if(!marked[i]) p.push_back(i);
}

void genPR(int n) {
  PR.clear();
  for(int i=0; p[i] * p[i] <= n; i++) {
    int cnt = 0;
    while(n % p[i] == 0) {
      n /= p[i];
      cnt++;
    }

    if(cnt) PR.push_back(pii(p[i], cnt));
  }

  if(n!=1) PR.push_back(pii(n, 1));
}

int pwr(int b, int p) {
  if(p==1) return b;
  if(p % 2) return b * pwr(b, p-1);

  int a = pwr(b, p>>1);
  return a*a;
}

int main()
{
  //freopen("out.txt", "w", stdout);
  sieve();

  string s;
  while(getline(cin, s) && s != "0") {
    stringstream str(s);

    int n=1, i, j;
    while(str >> i >> j)
      n *= pwr(i, j);

    genPR(--n);
    for(i = (int) PR.size() - 1; i>=0; i--) {
      cout << PR[i].first << " " << PR[i].second;
      if(i) cout << " ";
    }
    cout << endl;
  }

  return 0;
}
