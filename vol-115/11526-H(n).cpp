/*
	Solution: For the smaller values like 1, 2, 3, .... sqrt(n) we can actually calculate how many are there.
	For any 1 <= i <= sqrt(n), there's actually (n-n/2-n/3-...-n/(i+1)) of them.
	And for the bigger values, we now know that there are sqrt(n) (-1) left of them. So we just calculate them the naive way
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll H(ll n) {
	ll nn = n, res = 0, sq = sqrt(n);
	for(int i=1; i<=sq; ++i) {
		ll temp = nn - (n / (i+1));
		res += i * temp;
		nn -= temp;
		if(nn-i >= 0) res += n/i;
	}

	return res;
}

int main()
{
	int t;
	cin >> t;

	while(t--) {
		ll n;
		cin >> n;
		cout << H(n) << "\n";
	}

	return 0;
}
