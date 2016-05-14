#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  char c;
  while((c=cin.get())!=EOF) {
    if(c=='\n') cout<<'\n';
    else cout<<(char)(((int)c)-7);
  }

  return 0;
}
