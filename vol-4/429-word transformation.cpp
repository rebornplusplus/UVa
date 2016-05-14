// UVa 429 - Word Transformation
// Though the problem states, "The starting and ending words will appear in the dictionary".
// In some test cases, it isn't true. Make sure you handle them

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <sstream>
using namespace std;

#define M 205
vector<string> words;
vector<int> G[M];
bool vis[M];
int dis[M];

bool dif_1(string &s1, string &s2) {
  if(s1.size() != s2.size()) return false;

  int i, cnt;
  for(i=0, cnt=0; i<s1.size() && cnt<2; i++)
    if(s1[i] != s2[i]) cnt++;
  return cnt == 1;
}

int bfs(int src, int des) {
  if(src == des) return 0;
  if(words[src].size() != words[des].size()) return -1;

  for(int i=0; i<M; i++) vis[i] = false;
  queue<int> Q;
  Q.push(src);
  vis[src] = true;
  dis[src] = 0;

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();

    for(int i=0; i<G[u].size(); i++) {
      int v = G[u][i];
      if(!vis[v]) {
        vis[v] = true;
        dis[v] = dis[u] + 1;
        Q.push(v);
      }

      if(v == des) return dis[des];
    }
  }

  return -1;
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--) {
    string s, s2;
    while(getline(cin, s) && s!="*") words.push_back(s);

    for(int i=0; i<words.size()-1; i++)
      for(int j=i+1; j<words.size(); j++)
        if(dif_1(words[i], words[j])) {
          G[i].push_back(j);
          G[j].push_back(i);
        }

    string src, des;
    while(getline(cin, s) && !s.empty()) {
      stringstream ss(s);
      ss >> src >> des;

      int srcPos = find(words.begin(), words.end(), src) - words.begin();
      int desPos = find(words.begin(), words.end(), des) - words.begin();
      cout << src << " " << des << " ";
      if(srcPos==words.size() || desPos==words.size()) cout << "-1\n";
      cout << bfs(srcPos, desPos) << "\n";
    }
    if(t) cout << '\n';

    words.clear();
    for(int i=0; i<M; i++) G[i].clear();
  }

  return 0;
}
