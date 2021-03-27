#include <iostream>
#include <deque>
#include <string>

using namespace std;

int arr[4321][4321];
int tem[3];
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
		quadTree(s, e, size/3);
		quadTree(s, e+size/3, size/3);
		quadTree(s, e + size *2/ 3, size / 3);
		quadTree(s+size/3, e + size * 2 / 3, size / 3);
		quadTree(s+size/3, e, size/3);
		quadTree(s + size*2 / 3, e, size / 3);
		quadTree(s + size * 2 / 3, e+size/3, size / 3);
		quadTree(s+size/3, e+size/3, size/3);
		quadTree(s + size * 2 / 3, e + size * 2 / 3, size / 3);
	}
	else
	{
		tem[temp+1]++;
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
			cin >> arr[i][j];
		}
	}

	quadTree(0,0,n);

	cout << tem[0]<< "\n" << tem[1] << "\n" << tem[2];
}
