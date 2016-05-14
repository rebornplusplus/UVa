#include <cstdio>

int main()
{
  int h, m;
  double angle;
  scanf("%d%*c%d", &h, &m);

  while(h || m) {
    if(h==12) h=0;

    angle = 6.0 * (m - 5*h - m/12.0);
    if(angle<0) angle = -angle;
    if(angle>180) angle = 360 - angle;

    printf("%0.3lf\n", angle);
    scanf("%d%*c%d", &h, &m);
  }

  return 0;
}
