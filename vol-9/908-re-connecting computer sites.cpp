#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct edge {
  int u, v, w;

  edge(int i, int j, int k) : u(i), v(j), w(k) { }
  bool operator < (const edge &p) const {
    return w < p.w;
  }
};

#define MAXN 1000000
vector<edge> e;
int par[MAXN+1];
int freq[MAXN+1];

inline int Find(int r) {
  return (par[r]==r) ? r : Find(par[r]);
}

inline void MakeSet(int r) {
  par[r] = r;
  freq[r] = 0;
}

long long mst(int n) {
  sort(e.begin(), e.end());

  int i;
  for(i=1; i<=n; i++) MakeSet(i);

  int cnt=0, u, v;
  long long s=0;
  for(i=0; i<(int) e.size(); i++) {
    u = Find(e[i].u);
    v = Find(e[i].v);

    if(u!=v) {
      if(freq[u] > freq[v]) par[v] = u;
      else {
        par[u] = v;
        if(freq[u]==freq[v]) freq[v]++;
      }

      s += e[i].w;
      cnt++;
      if(cnt==n-1) break;
    }
  }

  return s;
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int n, k, m, cnt=0;
  while(cin >> n) {
    int u, v, w, i;
    int pastCost=0;
    long long preCost;

    for(i=1; i<n; i++) {
      cin >> u >> v >> w;
      pastCost += w;
    }

    cin >> k;
    while(k--) {
      cin >> u >> v >> w;
      e.push_back(edge(u, v, w));
    }

    cin >> m;
    while(m--) {
      cin >> u >> v >> w;
      e.push_back(edge(u, v, w));
    }

    preCost = mst(n);
    e.clear();

    if(cnt++) cout << endl;
    cout << pastCost << endl;
    cout << preCost << endl;
  }

  return 0;
}
