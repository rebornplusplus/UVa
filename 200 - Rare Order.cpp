#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<char, string> G;
map<char, int> visited;
string nodes, TSorted;
bool cycle, taken[26];

void dfs_visit(char u) {
  if(visited[u] == 2 || cycle) return;
  else if(visited[u] == 1) {
    cycle = true;
    return;
  }

  visited[u] = 1;
  for(int i=0; i<G[u].size(); i++) dfs_visit(G[u][i]);
  visited[u] = 2;
  TSorted.push_back(u);   // TopSort
}

void dfs() {
  for(int i=0; i<nodes.size(); i++)
    visited[ nodes[i] ] = 0;
  cycle = false;

  for(int i=0; i<nodes.size(); i++)
    dfs_visit(nodes[i]);
  reverse(TSorted.begin(), TSorted.end());
}

void calNodes(string &s) {
  for(int i=0; i<s.size(); i++) {
    if(!taken[ s[i]-65 ]) {
      nodes += s[i];
      taken[ s[i]-65 ] = true;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s1="", s2;
  nodes = "";

  while(cin >> s2) {
    if(s2 != "#") {
      calNodes(s2);
      for(int i=0; i<s1.size() && i<s2.size(); i++)
        if(s1[i] != s2[i]) {
          G[ s1[i] ].push_back(s2[i]);
          break;
        }
      s1 = s2;
    }
    else {
      sort(nodes.begin(), nodes.end());
      dfs();
      cout << TSorted << endl;

      s1 = nodes = "";
      TSorted.clear();
      G.clear();
      for(int i=0; i<26; i++) taken[i] = false;
    }
  }

  return 0;
}
