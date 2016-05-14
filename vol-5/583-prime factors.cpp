#include <iostream>
#include <vector>
using namespace std;

#define M 50000
bool marked[M];
vector<long long> p;
vector<int> facs;

void sieve() {
  p.push_back(2);
  for(int i=3; i*i < M; i+=2) {
    if(!marked[i]) {
      p.push_back(i);
      for(int j=i*i; j < M; j += i+i)
        marked[j] = true;
    }
  }

  for(int i=p.back()+2; i<M; i+=2)
    if(!marked[i]) p.push_back(i);
}

void factor(int n) {
  facs.clear();
  for(int i=0; p[i]*p[i] <= n; i++) {
    while(n % p[i] == 0) {
      facs.push_back(p[i]);
      n /= p[i];
    }
  }

  if(n!=1) facs.push_back(n);
}

int main()
{
  sieve();

  int n;
  while((cin >> n) && n) {
    if(n < 0) factor(-n);
    else factor(n);

    cout << n << " = ";
    if(n < 0) cout << "-1 x ";
    cout << facs[0];

    for(int i=1; i < (int) facs.size(); i++)
      cout << " x " << facs[i];
    cout << endl;
  }

  return 0;
}
