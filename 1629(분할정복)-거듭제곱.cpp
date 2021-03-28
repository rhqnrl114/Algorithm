#include <iostream>
#include <deque>
#include <string>

using namespace std;

long long int pow(int x, int y,int c) {
	if (y == 0) {
		return 1;
	}

	long long int n = pow(x, y / 2,c);
	long long int temp = n * n % c;

	if (y % 2 == 0) {
		return temp;
	} else {
		return x * temp%c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
			
	int a,b,c;

	cin >> a>>b>>c;

	cout << pow(a, b,c);
}
