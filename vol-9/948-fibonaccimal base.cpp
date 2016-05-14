#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

#define M 100000000
vector<int> fib;

void preCal() {
  int f1=1, f2=1, temp;
  while(f1 <= M) {
    fib.push_back(f1);
    temp = f1;
    f1 += f2;
    f2 = temp;
  }
}

string fibRep(int n) {
  string s = "";
  for(int i=fib.size()-1; i>=0; i--) {
    if(fib[i] <= n) {
      s += "1";
      n -= fib[i];
    }
    else if(s.size())
      s += "0";
  }

  return s;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  preCal();

  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << n << " = " << fibRep(n) << " (fib)\n";
  }

  return 0;
}
