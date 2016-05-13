#include <iostream>
#include <utility>
#include <cstdio>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

bool inc[1000001];

inline int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

pii cal(int N) {
  for(int i=1; i<=N; i++) inc[i] = false;
  int cnt = 0, c2 = 0;
  int m = 2, m2 = 4;

  while(m2 < N) {
    int n = (m % 2) ? 2 : 1;
    int n2 = n*n;
    while(n2 < m2) {
      if(gcd(m, n) == 1) {
        int a = m2 - n2;
        int b = 2*m*n;
        int c = m2 + n2;

        if(c <= N && gcd(a,b) == 1 && gcd(b,c) == 1) cnt++;
        for(int i=1; i<=N/c; i++)
          inc[a*i] = inc[b*i] = inc[c*i] = true;
      }

      n++;
      n2 = n*n;
    }

    m++;
    m2 = m*m;
  }

  for(int i=1; i<=N; i++) if(!inc[i]) c2++;
  return pii(cnt, c2);
}

int main()
{
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  int n;
  while(cin >> n) {
    pii res = cal(n);
    cout << res.x << " " << res.y << endl;
  }
  return 0;
}
