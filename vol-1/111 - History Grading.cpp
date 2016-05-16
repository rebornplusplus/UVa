// be careful. Given numbers are the positions of events
// read the problem statement carefully...

#include <bits/stdc++.h>
using namespace std;

int lcs(vector<int> &v1, vector<int> &v2) {
  int m = v1.size();
  int n = v2.size();
  int L[2][n+1];

  for(int i=0; i<=m; i++) {
    int ii = i % 2;
    for(int j=0; j<=n; j++) {
      if(i==0 || j==0)
        L[ii][j] = 0;
      else if(v1[i-1] == v2[j-1])
        L[ii][j] = 1 + L[1-ii][j-1];
      else
        L[ii][j] = max(L[1-ii][j], L[ii][j-1]);
    }
  }

  return L[m%2][n];
}

int main()
{
  int n, cnt=0, temp;
  scanf("%d%*c", &n);
  string s;
  vector<int> v1(n), v2(n);

  while(getline(cin, s)) {
    stringstream ss(s);
    for(int i=1; i<=n; i++) {
      ss >> temp;
      v2[temp-1] = i;
    }

    if(cnt == 0) v1 = v2;
    else cout << lcs(v1, v2) << "\n";
    cnt++;
  }

  return 0;
}
