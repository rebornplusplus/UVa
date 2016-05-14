#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int match(int x) {
  int i;
  for(i=0; i<v.size(); i++) {
    if(v[i] == x) break;
  }

  if(i<v.size()) return i;
  return -1;
}

int main()
{
  int cnt=0, cylen, indx;
  int z, l, i, m, nxt;

  cin >> z >> i >> m >> l;
  while(z || l || i || m) {
    v.clear();
    v.push_back(l);

    do {
      nxt = (z*l+i) % m;
      indx = match(nxt);

      if(indx < 0) {
        v.push_back(nxt);
        l = nxt;
      }
    } while(indx < 0);

    cylen = (int)v.size() - indx;
    cout << "Case " << ++cnt << ": " << cylen << endl;
    cin >> z >> i >> m >> l;
  }

  return 0;
}
