#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int p[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

void cal(int n) {
  vector<int> ans;
  for(int i=0; i<25 && p[i]<=n; i++) {
    int cnt=0, temp = p[i];
    while(temp <= n) {
      cnt += n / temp;
      temp *= p[i];
    }
    ans.push_back(cnt);
  }

  printf("%3d! =", n);
  for(int i=0; i<ans.size(); i++) {
    if(i && i%15==0) printf("\n      ");
    printf("%3d", ans[i]);
  }
  putchar('\n');
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int n;
  while(cin >> n && n) cal(n);
  return 0;
}
