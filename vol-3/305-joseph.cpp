// Runtime 2.98 seconds in UVa. Follow the procedure commented below
#include <iostream>
using namespace std;

int main()
{
  int k;
  while(cin >> k && k) {
    for(int m=k+1, n=2*k; ; m++) {
      int pos = 0;
      bool found = true;

      for(int i=0; i<k; i++) {
        pos = (pos + m-1) % (n-i);
        if(pos < k) {
          found = false;
          break;
        }
      }
      if(found) {
        cout << m << endl;
        break;
      }
    }
  }

  return 0;
}

/*
  Or just store them in an array... like this code of mine...
  Let ans[] = { 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 }
  for every input k, output (k-1)'th element
*/
