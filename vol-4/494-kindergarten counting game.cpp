#include <cstdio>
#include <cctype>

int main()
{
  char ch;
  bool flag=false;
  int cnt=0;

  while(scanf("%c", &ch) == 1) {
    if(isalpha(ch)) {
      if(!flag) {
        flag = true;
        cnt++;
      }
    }
    else flag = false;

    if(ch == '\n') {
      printf("%d\n", cnt);
      cnt = 0;
    }
  }

  return 0;
}
