// Can be done with bfs too... I think that's better.

#include <iostream>
#include <vector>
using namespace std;

#define M 1000
vector<int> G[M+1];
int color[M+1];
bool access[M+1];

void dfs_visit(int u) {
  color[u] = 1;
  for(int i=0; i<G[u].size(); i++) {
    int v = G[u][i];
    access[v] = true;
    if(color[v] == 0) dfs_visit(v);
  }
  color[u] = 2;
}

void dfs(int n, int src) {
  for(int i=1; i<=n; i++)
    color[i] = access[i] = 0;
  dfs_visit(src);
}

int main()
{
  int vertices;
  while(cin >> vertices && vertices) {
    for(int i=1; i<=vertices; i++) G[i].clear();

    int u, v;
    while(cin >> u && u)
      while(cin >> v && v)
        G[u].push_back(v);

    int n, src;
    cin >> n;
    while(n--) {
      cin >> src;
      dfs(vertices, src);

      vector<int> res;
      for(int i=1, cnt=0; i<=vertices; i++) {
        if(!access[i]) {
          ++cnt;
          res.push_back(i);
        }
      }

      cout << res.size();
      for(int i=0; i<res.size(); i++) cout << " " << res[i];
      cout << endl;
    }
  }

  return 0;
}
