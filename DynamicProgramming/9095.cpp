#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, n, cnt, d[12];
	cin >> T;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	while (T--) {
		cnt = 0;
		cin >> n;
		for (int i = 4; i <= n; i++) {
			// i-1에 1 더하면 i니까 i-1 만드는 경우의 수 다 더함
			// i-2, i-3도 각각 2, 3 더하면 i니까 마찬가지로 다 더함
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << "\n";
	}

}
