#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<string, vector<string> > G;
map<string, bool> vis;
map<string, bool> reachable;
map<string, string> parent;

void bfs(string, string);
void printPath(string, string);

int main()
{
  int t, i=0;
  while(cin >> t) {
    string s1, s2;
    while(t--) {
      cin >> s1 >> s2;
      G[s1].push_back(s2);
      G[s2].push_back(s1);
    }

    cin >> s1 >> s2;
    bfs(s1, s2);
    if(i) cout << endl;
    else i++;
    printPath(s1, s2);

    G.erase(G.begin(), G.end());
  }

  return 0;
}

void bfs(string st, string en) {
  vis.erase(vis.begin(), vis.end());
  reachable.erase(reachable.begin(), reachable.end());
  parent.erase(parent.begin(), parent.end());

  string u, v;
  queue<string> Q;
  Q.push(st);
  vis[st] = true;
  reachable[st] = true;

  while(!Q.empty()) {
    u = Q.front();
    Q.pop();

    for(int i=0; i<G[u].size(); i++) {
      v = G[u][i];
      if(vis.find(v) == vis.end()) {
        vis[v] = true;
        reachable[v] = true;
        parent[v] = u;
        Q.push(v);
      }

      if(v == en) return;
    }
  }

  return;
}

void printPath(string st, string en) {
  if(reachable.find(en) == reachable.end()) cout << "No route\n";
  else {
    string v;
    vector<string> route;
    do {
      v = parent[en];
      route.push_back(string(v + " " + en + "\n"));
      en = v;
    } while(en != st);

    for(int i=route.size()-1; i>=0; i--) cout << route[i];
  }

  return;
}
