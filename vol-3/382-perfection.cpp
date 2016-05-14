#include <cstdio>
#include <cmath>

int main()
{
  int n, i, cnt=0, start, diff;
  int sum, sq;

  while(scanf("%d", &n) && n) {
    cnt++;
    if(cnt==1) printf("PERFECTION OUTPUT\n");

    sum=1;
    sq = (int) sqrt(n);

    if(n%2) {
      start = 3;
      diff = 2;
    }
    else {
      start = 2;
      diff = 1;
    }

    for(i=start; i<=sq; i+=diff) {
      if(n%i == 0) sum += i + n/i;
    }
    if(sq*sq==n) sum -= sq;

    printf("%5d  ", n);
    if(sum==n) printf("PERFECT");
    else if(sum < n) printf("DEFICIENT");
    else printf("ABUNDANT");
    printf("\n");
  }

  printf("END OF OUTPUT\n");
  return 0;
}
