
// Luckily there is a pattern
// if n <= 9, Stan wins
// else if n <= 9*2 Ollie wins
// else if n <= 9*2*9 Stan wins
// else if n <= 9*2*9*2, Ollie wins

#include <iostream>
using namespace std;

int main()
{
  long long n, i;

  while(cin >> n) {
    bool stan;
    for(i=1, stan=true; ; ) {
      if(stan) {
        if(n > i && n <= i*9) break;
        i *= 9, stan = false;
      }
      else {
        if(n > i && n <= i*2) break;
        i *= 2, stan = true;
      }
    }

    if(stan) cout << "Stan wins.\n";
    else cout << "Ollie wins.\n";
  }

  return 0;
}

/*  // Game Theory solution but Too Slow
#include <iostream>
using namespace std;

long long n;

bool canWin(long long p) {
  if(p >= n) return false;
  for(int i=2; i<=9; i++)
    if(canWin(p*i) == false) return true;
  return false;
}

int main()
{
  while(cin >> n) {
    if(canWin(1)) cout << "Stan wins.\n";
    else cout << "Ollie wins.\n";
  }

  return 0;
}
*/
