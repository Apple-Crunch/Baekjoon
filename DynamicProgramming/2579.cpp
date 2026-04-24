#include <iostream>
using namespace std;
int stair[301];
int point[301][2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> stair[i];
	point[0][0] = stair[0];
	point[0][1] = 0;
	point[1][0] = stair[1];
	point[1][1] = stair[0] + stair[1];
	for (int i = 2; i < n; i++) {
		point[i][0] = max(point[i - 2][0], point[i-2][1]) + stair[i];
		point[i][1] = point[i - 1][0] + stair[i];
	}
	cout << max(point[n - 1][0], point[n - 1][1]);
}
