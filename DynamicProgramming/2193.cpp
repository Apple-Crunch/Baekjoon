#include <iostream>
using namespace std;
long long int ans[91]; // 오버플로우
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	long long int end_0; // 오버플로우
	cin >> N;
	ans[0] = 0;
	ans[1] = 1; // 1
	ans[2] = 1; // 10
	ans[3] = 2; // 100, 101
	ans[4] = 3; // 1000, 1010, 1001
	ans[5] = 5; // 10000, 10001, 10100, 10101, 10010
	ans[6] = 8; // 100000, 100001, 100010, 101000, 101001, 101010, 100101, 100100
	end_0 = 5;
	//ans[i] = ans[i-1]의 0으로 끝나는 경우의 이진수 * 2 + ans[i-1]의 1로 끝나는 경우의 이진수
	for (int i = 7; i <= N; i++) {
		ans[i] = end_0 * 2 + (ans[i - 1] - end_0);
		end_0 = ans[i - 1]; // end_0의 경우는 이전 경우들에 0을 다는 경우와 같음
	}
	cout << ans[N];
}
