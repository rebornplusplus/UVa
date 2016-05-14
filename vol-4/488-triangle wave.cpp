#include <cstdio>

int main()
{
  int t;
  char str[][10] = { "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999" };
  scanf("%d", &t);

  while(t--) {
    int a, f, i;
    scanf("%d %d", &a, &f);

    while(f--) {
      for(i=0; i<a; i++) puts(str[i]);
      for(i=a-2; i>=0; i--) puts(str[i]);

      if(!t && !f) ;
      else printf("\n");
    }
  }

  return 0;
}
