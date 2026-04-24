#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K, A[10], money = 0, cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = N - 1; i >= 0; i--) {
		while (money + A[i] <= K) {
			money += A[i];
			cnt++;
		}
	}
	cout << cnt;
}
