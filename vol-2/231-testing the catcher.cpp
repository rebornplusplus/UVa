#include <bits/stdc++.h>
using namespace std;

int LDS_nlogk(vector<int> &seq) {
  const int n = seq.size(), inf = 32768;
  int I[n+1];
  I[0] = inf;
  for(int i=1; i<=n; i++) I[i] = -inf;

  int LDS = 0;
  for(int i=0; i<n; i++) {
    int st=0, en=LDS, mid;
    while(st <= en) {
      mid = (st+en)/2;
      if(I[mid] >= seq[i]) st = mid+1;
      else en = mid-1;
    }

    I[st] = seq[i];
    if(LDS < st) LDS = st;
  }

  return LDS;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int temp, cnt=0;
  while(cin >> temp && temp != -1) {
    vector<int> seq(1, temp);
    while(cin >> temp && temp != -1)
      seq.push_back(temp);

    int ans = LDS_nlogk(seq);
    if(cnt) cout << "\n";
    cout << "Test #" << ++cnt << ":\n";
    cout << "  maximum possible interceptions: " << ans << "\n";
  }

  return 0;
}
