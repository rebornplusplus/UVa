#include <cstdio>

int main()
{
  int n, cnt=0;
  scanf("%d", &n);

  while(n) {
    int bricks[n];
    int i, sum=0, moves;

    for(i=0; i<n; i++) {
      scanf("%d", &bricks[i]);
      sum += bricks[i];
    }
    int avg = sum/n;

    moves=0;
    for(i=0; i<n; i++) {
      if(bricks[i] > avg)
        moves += bricks[i] - avg;
    }

    printf("Set #%d\n", ++cnt);
    printf("The minimum number of moves is %d.\n\n", moves);

    scanf("%d", &n);
  }

  return 0;
}
