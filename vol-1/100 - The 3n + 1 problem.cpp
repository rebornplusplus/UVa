#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, n, i, cnt, max;
  int tmp_a, tmp_b;

  while(cin >> a >> b) {
    tmp_a = a;
    tmp_b = b;
    if(a>b) swap(a, b);

    max = 0;
    while(a<=b) {
      n=a++;
      cnt=0;

      while(n!=1) {
        if(n%2) {
          n = 3*n+1;
          n = n >> 1;
          cnt += 2;
        }
        else {
          n = n >> 1;
          cnt++;
        }
      }
      cnt++;

      if(max < cnt) max = cnt;
    }

    cout << tmp_a << " " << tmp_b << " " << max << endl;
  }

  return 0;
}
