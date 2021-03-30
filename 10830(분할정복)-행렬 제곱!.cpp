#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
ll n, b;

// <빠른 거듭제곱 알고리즘> O(logN)
// N이 홀수이면 A*A^(N-1)로 바꾸고 A를 결과값에 곱한다
// N이 짝수이면 (A^2)^(N/2) 즉 A를 제곱하고 N을 2로 나눈다
// N = 0이면 종료

matrix operator * (const matrix& a, const matrix& b) {

	matrix res(n, vector<ll>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1000;
		}
	}
	return res;
}

//행렬 a의 r제곱을 반환하는 함수
matrix power(matrix a, ll r) {
	matrix res(n, vector<ll>(n));
	//res를 단위행렬로 설정
	for (int i = 0; i < n; i++)
		res[i][i] = 1;
	while (r > 0) {
		if (r % 2 == 1) {
			res = res * a;
		}
		r /= 2;
		a = a * a;
	}
	return res;
}

void printRes(const matrix& res) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> b;
	matrix origin(n, vector<ll>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> origin[i][j];
		}
	}

	printRes(power(origin, b));

	return 0;
}
