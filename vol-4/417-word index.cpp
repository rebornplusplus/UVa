#include <bits/stdc++.h>
using namespace std;

map<string, int> M;

void bfs() {
  queue<string> Q;
  for(char ch='a'; ch<='z'; ch++)
    Q.push(string(1, ch));

  string s;
  int cnt=1;

  while(!Q.empty()) {
    s = Q.front();
    Q.pop();

    M[s] = cnt++;

    if(s.size() == 5) continue;
    for(char ch = s[s.size()-1]+1; ch<='z'; ch++)
      Q.push(s+ch);
  }
}

int main()
{
  //freopen("out.txt", "w", stdout);
  bfs();

  string s;
  while(cin >> s) {
    if(M.find(s) == M.end()) cout << 0 << endl;
    else cout << M[s] << endl;
  }

  return 0;
}
