#include <iostream>
#include <deque>
#include <string>

using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
			
	int n, n1,cnt=0,i = 0;
	string s,num;

	bool FR = false , err = false;

	cin >> n;

	while(n--){
		FR = true; err = false;
		deque<int> dq;
		cin >> s >> n1 >> num;
		    i = 1;
			while (num[i] != '\0'){
				int x = 0;
				while('0' <= num[i] && num[i] <= '9'){
					x *= 10;
					x += int(num[i] - '0');
					i++;
				}
				if (x != 0) {
					dq.push_back(x);
				}
				i++;
			}

		i = 0;
		while(s[i]!='\0'){
			if (s[i] == 'R'){
				FR = !FR;
			}
			else if (s[i] == 'D') {
				if (dq.empty()) {
					cout << "error" << endl;
					err = true;
					break;
				}
				if (FR) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
			i++;
		}

		if (!err){
			cout << "[";
		}

		while (!dq.empty()){
			if (FR) {
				auto c = dq.front();
				dq.pop_front();
				cout << c;
			}
			else {
				auto c = dq.back();
				dq.pop_back();
				cout << c;
			}
			if (!dq.empty()){
				cout << ",";
			}
		}
		
		if (!err) {
			cout << "]" << endl;
		}
	}
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
