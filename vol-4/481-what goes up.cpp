#include <bits/stdc++.h>
using namespace std;

const long long inf = (long long) 1 << 40;
vector<long long> seq, dp, I;

int LIS_logk() {
  const int n = seq.size();
  I.push_back(-inf);
  for(int i=1; i<=n; i++) I.push_back(inf);

  int LIS=0;
  for(int i=0; i<n; i++) {
    int st=0, en=LIS, mid;
    while(st <= en) {
      mid = (st + en)/2;
      if(I[mid] < seq[i]) st = mid+1;
      else en = mid-1;
    }

    I[st] = seq[i];
    dp.push_back(st);
    if(LIS < st) LIS = st;
  }

  return LIS;
}

inline void printLIS(int crr) {
  long long LIS[crr];
  int len = crr;

  for(int i=seq.size()-1; i>=0 && crr; i--) {
    if(dp[i] == crr) {
      if(crr != len && LIS[crr] <= seq[i]) continue;
      LIS[--crr] = seq[i];
    }
  }
  for(int i=0; i<len; i++) cout << LIS[i] << "\n";
}

int main()
{
  int temp;
  while(cin >> temp) seq.push_back(temp);

  int LIS = LIS_logk();
  cout << LIS << "\n-\n";
  printLIS(LIS);

  return 0;
}
