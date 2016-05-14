#include <iostream>
#include <string>
using namespace std;

inline int mini(int a, int b, int c, int d) {
  if(a>b) a=b;
  if(a>c) a=c;
  if(a>d) a=d;

  return a;
}

int main()
{
  int h;
  int i, j, k, l, cnt;
  int humble[5842];
  string suffix;

  humble[0] = 1;
  i = j = k = l = 0;
  for(cnt=1; cnt<5842; cnt++) {
    humble[cnt] = mini(2*humble[i], 3*humble[j], 5*humble[k], 7*humble[l]);

    if(humble[cnt] % 2 == 0) i++;
    if(humble[cnt] % 3 == 0) j++;
    if(humble[cnt] % 5 == 0) k++;
    if(humble[cnt] % 7 == 0) l++;
  }

  cin >> h;
  while(h) {
    int h0 = h % 10;
    int h1 = h % 100;

    if(h0==1 && h1!=11) suffix = "st";
    else if(h0==2 && h1!=12) suffix = "nd";
    else if(h0==3 && h1!=13) suffix = "rd";
    else suffix = "th";

    cout << "The " << h << suffix << " humble number is " << humble[h-1] << ".\n";
    cin >> h;
  }

  return 0;
}
