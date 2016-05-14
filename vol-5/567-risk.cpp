#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

#define c 20
vector<int> g[c+1];
int dis[c+1];

void bfs(int src) {
  bool visited[c+1];
  int i, u, v;
  for(i=0; i<=c; i++) {
    dis[i] = 0;
    visited[i] = false;
  }

  queue<int> Q;
  Q.push(src);
  visited[src] = 1;

  while(!Q.empty()) {
    u = Q.front();
    Q.pop();

    for(i=0; i<g[u].size(); i++) {
      v = g[u][i];
      if(!visited[v]) {
        dis[v] = dis[u] + 1;
        visited[v] = true;
        Q.push(v);
      }
    }
  }
}

int main()
{
  int n, tmp, i, j, cnt=0;
  while(cin >> n) {
    i = 1;
    for(int j=0; j<n; j++) {
      cin >> tmp;
      g[i].push_back(tmp);
      g[tmp].push_back(i);
    }

    for(i=2; i<c; i++) {
      cin >> n;
      for(int j=0; j<n; j++) {
        cin >> tmp;
        g[i].push_back(tmp);
        g[tmp].push_back(i);
      }
    }

    int times, st, end, shortest;
    cin >> times;
    cout << "Test Set #" << ++cnt << endl;

    while(times--) {
      cin >> st >> end;
      bfs(st);
      shortest = dis[end];
      printf("%2d to %2d: %d\n", st, end, shortest);
    }

    cout << endl;
    for(j=0; j<=c; j++) g[j].clear();
  }

  return 0;
}
