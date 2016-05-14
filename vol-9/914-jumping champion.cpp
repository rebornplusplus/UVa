#include <iostream>
#include <vector>
using namespace std;

#define M 1000000
bool marked[M];
vector<int> p;

void sieve() {
  p.push_back(2);
  int i, j;

  for(i=3; i*i < M; i+=2) {
    if(!marked[i]) {
      p.push_back(i);
      for(j=i*i; j<M; j += i+i)
        marked[j] = true;
    }
  }

  for(i=p.back()+2; i<M; i+=2)
    if(!marked[i]) p.push_back(i);
}

void func(int pL, int pR) {
  int i, diff[115];
  for(i=0; i<115; i++) diff[i] = 0;

  do {
    ++pL;
    ++diff[ p[pL] - p[pL-1] ];
  } while(pL < pR);

  int m = 0, indx = -1;
  for(i=1; i<115; i++) {
    if(diff[i] == m) indx = -1;
    if(diff[i] > m) {
      indx = i;
      m = diff[i];
    }
  }

  if(indx != -1) cout << "The jumping champion is " << indx << endl;
  else cout << "No jumping champion\n";
}

int main()
{
  sieve();
  int t, i;
  cin >> t;

  while(t--) {
    int L, R;
    cin >> L >> R;

    int posL=0, posR = -1;
    for(i=0; i < (int) p.size(); i++) {
      if(L > p[i]) posL = i+1;
      if(R >= p[i]) posR = i;
    }

    if(posR == -1 || (posR-posL) < 1) cout << "No jumping champion\n";
    else func(posL, posR);
  }

  return 0;
}

