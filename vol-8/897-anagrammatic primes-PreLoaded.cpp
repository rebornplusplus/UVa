#include <iostream>
using namespace std;

#define total 22
int AnaPrimes[ ] = { 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991 };

int NumLen(int n) {
  int cnt = 1;
  while(n /= 10) cnt++;
  return cnt;
}

int main()
{
  int n;
  while((cin >> n) && n) {
    int ans = 0;
    if(n < 991) {
      for(int i=0; i < total; i++) {
        if(AnaPrimes[i] > n) {
          ans = AnaPrimes[i];
          break;
        }
      }

      if(NumLen(ans) > NumLen(n)) ans = 0;
    }

    cout << ans << endl;
  }

  return 0;
}
