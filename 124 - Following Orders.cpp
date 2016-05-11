// Print out all possible TopSorts

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

map<char, int> indegree;
map<char, vector<char> > G;
map<char, bool> visited;
string s1, s2, res;

inline void remove(string &s, char ch) {
  for(int i=0; i<s.size(); i++)
    if(s[i] == ch) s.erase(i--, 1);
}

void topSort_all() {
  bool flag=false, none=true;
  int i, j;
  char c;

  for(i=0; i<s1.size(); i++) {
    c = s1[i];

    if(!indegree[c] && !visited[c]) {
      for(j=0; j<G[c].size(); j++)
        --indegree[ G[c][j] ];
      visited[c] = true;
      res += c;
      topSort_all();

      visited[c] = false;
      res.pop_back();
      for(j=0; j<G[c].size(); j++)
        ++indegree[ G[c][j] ];

      flag = true;
      none = false;
    }
  }

  if(!flag && ( res.size() == s1.size() || !none ))
    cout << res << endl;
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cnt=0;
  while(getline(cin, s1)) {
    getline(cin, s2);
    remove(s1, ' ');
    remove(s2, ' ');
    sort(s1.begin(), s1.end());

    for(int i=0; i<s1.size(); i++) {
      indegree[ s1[i] ] = 0;
      visited[ s1[i] ] = false;
    }
    for(int i=0; i<s2.size()-1; i+=2) {
      G[ s2[i] ].push_back(s2[i+1]);
      ++indegree[ s2[i+1] ];
    }

    if(cnt++) cout << '\n';
    res = "";
    topSort_all();

    indegree.clear();
    G.clear();
    visited.clear();
  }

  return 0;
}
