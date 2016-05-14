#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
  int n;
  string s;

  while(cin >> n >> s) {
    int max=0;
    string temp, maxStr;
    map<string, int> m;

    for(int pos=0; pos <= s.size()-n; pos++) {
      temp = s.substr(pos, n);
      if(m.find(temp) == m.end()) m[temp] = 1;
      else ++m[temp];

      if(m[temp] > max) {
        max = m[temp];
        maxStr = temp;
      }
    }

    cout << maxStr << '\n';
  }

  return 0;
}
