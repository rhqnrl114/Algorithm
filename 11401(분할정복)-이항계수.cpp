#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

#define P 1000000007LL

typedef long long ll;

ll fac[4000001], n, k, inv[4000001];

ll power(ll x, ll y) {
	ll ret = 1;
	while (y > 0){
		if (y % 2) {
			ret *= x;
			ret %= P;
		}
		x *= x;
		x %= P;
		y /= 2;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fac[1] = 1;
	for (int i = 2; i <= 4000000; i++)
		fac[i] = (fac[i - 1] * i) % P;			//factorial 전처리
	inv[4000000] = power(fac[4000000], P - 2);
	for (int i = 4000000 - 1; i > 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % P;


	cin >> n >> k;
	if (n == k || !k) {
		cout << 1;
		return 0;
	}
	ll r = (fac[n] * inv[n - k]) % P;
	r = (r * inv[k]) % P;
	cout << r;
	return 0;
}
