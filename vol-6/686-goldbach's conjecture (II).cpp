#include <iostream>
#include <vector>
using namespace std;

#define M 32768
bool marked[M];
vector<int> p;

void sieve() {
  p.push_back(2);
  int i, j;

  for(i=3; (j=i*i) < M; i+=2) {
    if(!marked[i]) {
      p.push_back(i);
      for( ; j<M; j += i+i)
        marked[j] = true;
    }
  }

  for(i=p.back()+2; i<M; i+=2)
    if(!marked[i]) p.push_back(i);
}

bool isPrime(int n) {
  if(n < 2) return false;
  if(n == 2) return true;
  if(n % 2 == 0) return false;

  return marked[n] == false;
}

int main()
{
  sieve();

  int n, i, j;
  while((cin >> n) && n) {
    int cnt = 0;
    for(i=0; (j = n - p[i]) >= p[i]; i++)
      if(isPrime(j)) cnt++;
    cout << cnt << endl;
  }

  return 0;
}
