#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 1000
bool marked[MAX+1];
vector<int> p;

void sieve() {
  p.push_back(1);
  p.push_back(2);

  for(int i=3; i*i <= MAX; i+=2) {
    if(!marked[i]) {
      p.push_back(i);
      for(int j=i*i; j<=MAX; j += i+i)
        marked[j] = true;
    }
  }

  for(int i=p.back()+2; i<=MAX; i+=2)
    if(!marked[i]) p.push_back(i);
}

int main()
{
  //freopen("out.txt", "w", stdout);
  sieve();

  int n, c, cc;
  while(cin >> n >> c) {
    cc = c;

    int len, i;
    for(i=0; i<p.size(); i++) {
      if(p[i] > n) {
        len = i;
        break;
      }
    }
    if(i == (int) p.size()) len = i;

    c *= 2;
    if(len % 2) c--;

    int st=0, en=len;
    if(c < len) {
      st = (len - c) / 2;
      en = st + c;
    }

    cout << n << ' ' << cc << ":";
    for(i=st; i<en; i++) cout << ' ' << p[i];
    cout << endl << endl;
  }

  return 0;
}
