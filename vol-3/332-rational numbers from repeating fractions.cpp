#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

inline int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int p10(int p) {
  int ret = 1;
  while(p--) ret *= 10;
  return ret;
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int j, cnt=0;
  string s;

  do {
    cin >> j;
    if(j == -1) break;

    cin >> s;
    s = s.substr(2);

    int num = atoi(s.c_str());
    if(j && j != s.size()) num -= atoi( s.substr(0, s.size()-j).c_str() );
    int den = p10( s.size() );
    if(j) den -= p10( s.size() - j );

    int g = gcd(den, num);
    num /= g;
    den /= g;

    cout << "Case " << ++cnt << ": " << num << "/" << den << endl;

  } while(true);

  return 0;
}
