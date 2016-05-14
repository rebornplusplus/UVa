#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define ic(ch) (int) ch - 48
#define ci(i) (char) (i+48)
string add(string, string);

int main()
{
  vector<string> v(5001);
  v[0] = "0"; v[1] = "1";
  for(int i=2; i<=5000; i++) v[i] = add(v[i-2], v[i-1]);

  int n;
  while(cin >> n) {
    string tmp = v[n];
    reverse(tmp.begin(), tmp.end());
    cout << "The Fibonacci number for " << n << " is " << tmp << endl;
  }

  return 0;
}

string add(string s1, string s2) {
  string ans="";
  int i, sum, carry=0;

  for(i=0; i<s1.size(); i++) {
    sum = ic(s1[i]) + ic(s2[i]) + carry;
    carry = sum/10;
    sum %= 10;
    ans += ci(sum);
  }
  if(!carry)
    for( ; i<s2.size(); i++) ans += s2[i];
  else {
    for( ; i<s2.size(); i++) {
      sum = ic(s2[i]) + carry;
      carry = sum/10;
      sum %= 10;
      ans += ci(sum);
    }
    if(carry) ans += ci(carry);
  }

  return ans;
}
