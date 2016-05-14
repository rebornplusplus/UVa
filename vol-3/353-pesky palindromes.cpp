#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isPali(string s) {
  int st=0, en=s.size()-1;
  while(st < en) {
    if(s[st] != s[en]) return false;
    st++, en--;
  }
  return true;
}

int main()
{
  string s;
  while(cin >> s) {
    set<string> uniquePali;
    for(int len=1; len<=s.size(); len++)
      for(int i=0; i<=s.size()-len; i++)
        if(isPali(s.substr(i, len)))
          uniquePali.insert(s.substr(i, len));

    cout << "The string '" << s << "' contains " << uniquePali.size() << " palindromes.\n";
  }

  return 0;
}
