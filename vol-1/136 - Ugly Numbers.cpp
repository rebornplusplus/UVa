#include <cstdio>

inline int mini(int a, int b, int c) {
  if(a>b) a=b;
  if(a>c) a=c;

  return a;
}

int main()
{
  int i, j, k;  //to multiply with 2, 3, 5
  int cnt;
  int arr[1500];
  int mi;

  arr[0] = 1;
  i = j = k = 0;

  for(cnt=1; cnt<1500; cnt++) {
    arr[cnt] = mini(2*arr[i], 3*arr[j], 5*arr[k]);

    if(arr[cnt] % 2 == 0) i++;
    if(arr[cnt] % 3 == 0) j++;
    if(arr[cnt] % 5 == 0) k++;
  }

  printf("The 1500'th ugly number is %d.\n", arr[1499]);
  return 0;
}
