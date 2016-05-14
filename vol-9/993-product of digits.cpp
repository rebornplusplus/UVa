#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    if(n == 0) cout << "0\n";
    else if(n == 1) cout << "1\n";
    else {
      int digCnt[10] = { 0 };
      for(int i=9; i>1; i--) {
        while(n % i == 0) {
          n /= i;
          ++digCnt[i];
        }
      }

      if(n > 1) cout << "-1\n";
      else {
        for(int i=2; i<10; i++)
          for(int j=1; j<=digCnt[i]; j++) cout << i;
        cout << endl;
      }
    }
  }

  return 0;
}
