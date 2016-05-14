#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int a[50];

inline int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main()
{
  int n, i, j;
  do{
    cin >> n;
    if(!n) break;

    for(i=0; i<n; i++) cin >> a[i];
    int cnt=0;

    for(i=0; i<n; i++)
      for(j=i+1; j<n; j++)
        if(gcd(a[i], a[j]) == 1) cnt++;

    if(!cnt) cout << "No estimate for this data set.\n";
    else {
      double ans = 6.0 / cnt;
      ans *= ((n * (n-1)) / 2);
      ans = sqrt(ans);
      cout << fixed << setprecision(6) << ans << endl;
    }
  } while(true);

  return 0;
}
