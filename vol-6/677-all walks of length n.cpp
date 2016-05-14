#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool G[10][10];
bool taken[10];
vector<int> ans;
int r, n, cnt;

void backtrack() {
  if(ans.size() == r+1) {
    cout << '(';
    for(int i=0; i<=r; i++) {
      if(i) cout << ',';
      cout << ans[i]+1;
    }
    cout << ")\n";

    ++cnt;
    return;
  }

  for(int i=0; i<n; i++) {
    if( G[ans.back()][i] && !taken[i] ) {
      taken[i] = true;
      ans.push_back(i);

      backtrack();

      taken[i] = false;
      ans.pop_back();
    }
  }
}

int main()
{
  //freopen("out.txt", "w", stdout);

  while(cin >> n) {
    if(n == -9999) {
      cout << endl;
      continue;
    }
    cin >> r;

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> G[i][j];

    for(int i=0; i<10; i++) taken[i] = false;
    ans.clear();
    ans.push_back(0);
    taken[0] = true;
    cnt = 0;
    backtrack();

    if(!cnt) cout << "no walk of length " << r << endl;
  }

  return 0;
}
