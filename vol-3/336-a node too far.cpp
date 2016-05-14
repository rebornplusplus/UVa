//using bfs in graph theory
//mine. but it's much complicated. See the BETTER WAY @ github.cpp
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 35
vector<int> graph[MAX];
int dis[MAX];
bool visited[MAX];
int vCount;   //how many nodes visited
map<int, int> m;

void bfs_disCal(int src);
int notReachable(int ttl);

int main()
{
  int t, i=0, cnt;
  cin >> t;

  while(t) {
    cnt = 0;
    int x, y;
    while(t--) {
      cin >> x >> y;
      if(m.find(x) == m.end()) m[x] = cnt++;
      if(m.find(y) == m.end()) m[y] = cnt++;

      graph[ m[x] ].push_back(m[y]);
      graph[ m[y] ].push_back(m[x]);
    }

    int source, ttl, tooFar;
    cin >> source >> ttl;
    while(source || ttl) {
      bfs_disCal(m[source]);
      tooFar = notReachable(ttl) + cnt - vCount;
      cout << "Case " << ++i << ": " << tooFar << " nodes not reachable from node " << source << " with TTL = " << ttl << ".\n";
      cin >> source >> ttl;
    }

    for(int j=0; j<MAX; j++) graph[j].clear();    //clearing graph
    m.erase(m.begin(), m.end());                  //clearing map
    cin >> t;
  }

  return 0;
}

void bfs_disCal(int src) {
  queue<int> Q;
  int i, j, u, v;
  for(i=0; i<MAX; i++) {
    dis[i] = 0;
    visited[i] = false;
  }

  Q.push(src);
  visited[src] = true;
  vCount = 1;

  while(!Q.empty()) {
    u = Q.front();
    Q.pop();

    for(i=0; i<graph[u].size(); i++) {
      v = graph[u][i];
      if(!visited[v]) {
        dis[v] = dis[u] + 1;
        visited[v] = true;
        vCount++;
        Q.push(v);
      }
    }
  }
}

int notReachable(int ttl) {
  int cnt=0;
  for(int i=0; i<MAX; i++) {
    if(dis[i] > ttl) cnt++;
  }

  return cnt;
}
