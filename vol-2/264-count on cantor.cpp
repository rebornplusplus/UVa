#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num;
  while(cin >> num) {
    double check;
    int n, numerator, denominator, x;

    check = (-1.0 + sqrt(1.0+8.0*num))/2.0;
    n = (int) check;
    if(check-n > 0) n++;

    x = (n*(n+1))/2;
    if(n%2) {
      numerator = x - num + 1;
      denominator = n+1 - numerator;
    }
    else {
      denominator = x - num + 1;
      numerator = n+1 - denominator;
    }

    cout << "TERM " << num << " IS " << numerator << "/" << denominator << endl;
  }

  return 0;
}
