
#include <iostream>
using namespace std;

int main()
{
  int n, k;
  unsigned long long ans;

  do {
    cin >> n >> k;
    if(!n && !k) break;

    ans = 1;
    if(k > n-k) k = n-k;

    for(int i=0; i<k; i++) {
      ans *= (n - i);
      ans /= (1 + i);
    }

    cout << ans << endl;
  } while(true);

  return 0;
}

/*
//What's the problem with this code? Getting WA!

#include <iostream>
using namespace std;

inline int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main()
{
  int n, k;
  do {
    cin >> n >> k;
    if(!n && !k) break;

    if(!k || k==n) cout << 1 << endl;
    else {
      if(n-k > k) k = n-k;
      long long num=1, den=1;

      for(int i=k+1, j=1; i<=n; i++) {
        if(j <= n-k) {
          int g = gcd(i, j);
          num *= ( i / g );
          den *= ( j / g );
          j++;
        }
        else num *= i;
      }

      int ans = num / den;
      cout << ans << endl;
    }
  } while(true);

  return 0;
}

*/
