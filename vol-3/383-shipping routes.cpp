#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;

map<string, int> M;
vector<int> G[30];
bool vis[30];
int dis[30];

int bfs(int src, int des) {
  for(int i=0; i<30; i++)
    vis[i] = false;

  queue<int> Q;
  Q.push(src);
  dis[src] = 0;
  vis[src] = true;

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();

    for(int i=0; i < (int) G[u].size(); i++) {
      int v = G[u][i];
      if(!vis[v]) {
        vis[v] = true;
        dis[v] = dis[u] + 1;
        Q.push(v);
      }

      if(v == des) return dis[v];
    }
  }

  if(!vis[des]) return -1;
  else return dis[des];
}

int main()
{
  //freopen("out.txt", "w", stdout);

  int t;
  cin >> t;
  cout << "SHIPPING ROUTES OUTPUT\n";

  for(int i=1; i<=t; i++) {
     cout << "\nDATA SET  " << i << endl << endl;

    int warH, legs, requ;
    cin >> warH >> legs >> requ;

    string s, s2;
    for(int j=0; j<warH; j++) {
      cin >> s;
      M[s] = j;
    }

    while(legs--) {
      cin >> s >> s2;
      G[ M[s] ].push_back(M[s2]);
      G[ M[s2] ].push_back(M[s]);
    }

    while(requ--) {
      int cost;
      cin >> cost >> s >> s2;
      int cnt = bfs(M[s], M[s2]);

      if(cnt == -1) cout << "NO SHIPMENT POSSIBLE\n";
      else cout << '$' << cnt * cost * 100 << endl;
    }

    M.clear();
    for(int a=0; a<30; a++) G[a].clear();
  }

  cout << "\nEND OF OUTPUT" << endl;
  return 0;
}
