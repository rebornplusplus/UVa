#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int par[26], freq[26];  //freq is used as number of appearance before

void MakeSet(int x) {
  for(int i=0; i<x; i++) {
    par[i] = i;
    freq[i] = 0;
  }
}

int FIND(int x) {
  if(x != par[x]) par[x] = FIND(par[x]);
  return par[x];
}

void makeUnion(int &a, int &b) {
  int u, v;
  u = FIND(a); v = FIND(b);

  if(freq[u] > freq[v])
    par[v] = u;
  else {
    par[u] = v;
    if(freq[u]==freq[v]) freq[v]++;
  }
}

int main()
{
  int t;
  scanf("%d\n\n", &t);

  while(t--) {
    char c;
    int n, ans, x, y;
    string s;

    getline(cin, s);
    n = s[0] - 'A' + 1;
    MakeSet(n);
    ans = n;

    while(1) {
      if(!getline(cin, s) || s.empty()) break;

      x = s[0] - 'A';
      y = s[1] - 'A';
      if(FIND(x) != FIND(y)) {
        makeUnion(x, y);
        ans--;
      }
    }

    cout << ans << endl;
    if(t) cout << endl;
  }

  return 0;
}
