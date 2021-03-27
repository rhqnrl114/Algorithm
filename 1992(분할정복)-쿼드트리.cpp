#include <iostream>
#include <deque>
#include <string>

using namespace std;

int arr[65][65];
char c;

void quadTree(int s, int e, int size)
{
	bool check = true;
	int temp = arr[s][e];
	for (int i = s; i < s+size; i++) {
		for (int j = e; j < e+size; j++) {
			if (temp != arr[i][j])
			{
				check = false;
				break;
			}
		}
	}

	if (!check) {
		cout << "(";
		quadTree(s, e, size/2);
		quadTree(s, e+size/2, size/2);
		quadTree(s+size/2, e, size/2);
		quadTree(s+size/2, e+size/2, size/2);
		cout << ")";
	}
	else
	{
		cout << temp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
			
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	quadTree(0,0,n);
}

/*
#include<iostream>
#include<cmath>
using namespace std;

int dp[301], n = 0;
int arr[301]={0,};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
			cin >>arr[i];
	}

	dp[0] = arr[0];
	dp[1] = max(arr[1], arr[0] + arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	}

	cout << dp[n-1];
	return 0;
}*/


//1463
/*cin >> n;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[n];*/

//666문제
/*int n,count = 0,title = 665;
	string s;
	cin >> n;
	while (++title)
	{
		s = to_string(title);

		if (s.find("666") != -1) {
			++count;
		}

		if (count == n)
		{
			cout << title << endl;
			break;
		}

	}*/

//문자열로 큰수 계산
/*string a, b, result;
	cin >> a >> b;
	if (a.size() > b.size())
	{
		string c;
		for (int i = 0; i < a.size() - b.size(); i++)
		{
			c += '0';
		}
		b = c + b;
	}
	else
	{
		string c;
		for (int i = 0; i < b.size() - a.size(); i++)
		{
			c += '0';
		}
		a = c + a;
	}

	int carry = 0;
	while (a.size() != 0 && b.size() != 0)
	{
		int aback = a.back() - '0';
		int bback = b.back() - '0';
		int remain = (carry + aback + bback) % 10;
		carry = (carry + aback + bback) / 10;
		result = (char)(remain + '0') + result;
		a.pop_back();
		b.pop_back();
	}
	if (carry)
		result = (char)(carry + '0') + result;
	cout << result << endl;*/


//지그재그 공식
/*int x;
	cin >> x;
	int i;
	for (i = 1; x > 0; i++)
	{
		x = x - i;
	}

	if (i % 2 == 1)
	{
		cout << i + x - 1 << "/" << 1 - x;
	}
	else if(i%2 == 0)
	{
		cout << 1 - x << "/" << i + x - 1;
	}*/
