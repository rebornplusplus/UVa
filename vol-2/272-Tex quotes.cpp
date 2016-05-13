#include <cstdio>
using namespace std;

int main()
{
  char ch;
  bool flag=false;

  while(scanf("%c", &ch) == 1) {
    if(ch=='"') {
      if(!flag) {
        printf("``");
        flag = true;
      }
      else {
        printf("''");
        flag = false;
      }
    }
    else putchar(ch);
  }

  return 0;
}
