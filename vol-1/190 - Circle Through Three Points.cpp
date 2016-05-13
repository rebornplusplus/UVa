#include <cstdio>
#include <cmath>

int main()
{
  double ax, ay, bx, by, cx, cy;
  double a1, a2, b1, b2, c1, c2;
  double g, h, r, c;
  double tmp;
  char gc, hc, cc;

  while(scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy) == 6) {
    a1 = 2*(bx-cx);
    a2 = 2*(ax-bx);

    b1 = 2*(by-cy);
    b2 = 2*(ay-by);

    c1 = cy*cy + cx*cx - bx*bx - by*by;
    c2 = by*by + bx*bx - ax*ax - ay*ay;

    tmp = a1*b2 - a2*b1;

    g = (b1*c2 - b2*c1)/tmp;
    h = (c1*a2 - c2*a1)/tmp;
    r = sqrt((ax-g)*(ax-g) + (ay-h)*(ay-h));
    c = g*g + h*h - r*r;

    if(g>=0) gc = '-';
    else {
      gc = '+';
      g = -g;
    }

    if(h>=0) hc = '-';
    else {
      hc = '+';
      h = -h;
    }

    if(c>=0) cc = '+';
    else {
      cc = '-';
      c = -c;
    }

    printf("(x %c %0.3lf)^2 + (y %c %0.3lf)^2 = %0.3lf^2\n", gc, g, hc, h, r);
    printf("x^2 + y^2 %c %0.3lfx %c %0.3lfy %c %0.3lf = 0\n\n", gc, 2*g, hc, 2*h, cc, c);
  }

  return 0;
}
