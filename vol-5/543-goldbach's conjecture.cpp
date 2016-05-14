#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define MAX 1000000
bool marked[MAX];
vector<int> p;  //primes without 2

void sieve() {
  for(int i=3; i*i < MAX; i+=2) {
    if(!marked[i]) {
      p.push_back(i);
      for(int j=i*i; j<MAX; j += i+i)
        marked[j] = true;
    }
  }

  for(int i=p.back()+2; i<MAX; i+=2)
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
  //freopen("out.txt", "w", stdout);
  sieve();
  int n;

  while((cin >> n) && n) {
    int a=0, b=0;
    for(int i=0; n-p[i] >= 3; i++) {
      a = n - p[i];
      if(isPrime(a)) {
        b = p[i];
        break;
      }
    }

    if(b) printf("%d = %d + %d\n", n, b, a);
    else printf("Goldbach's conjecture is wrong.\n");
  }

  return 0;
}
