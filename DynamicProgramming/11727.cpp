#include <iostream>
using namespace std;
int S[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	S[0] = 1;// n = 1
	S[1] = 3;// n = 2
	S[2] = 5;// n = 3
	S[3] = 11;// n = 4
	//S[i]가 만들어 지는 경우는 
	// 1. S[i-1]에 1x2 붙이기
	// 2. S[i-2]에 2x1 2개 붙이기 or S[i-2]에 2x2 1개 붙이기
	// S[i-2]에 1x2 2개는 붙이는 과정에서 1.과 다른게 없기에 포함?
	// S[i] = S[i-1] + 2*S[i-2]
	for (int i = 4; i < n; i++) {
		S[i] = (S[i - 1] + 2 * S[i - 2]) % 10007;
	}
	cout << S[n - 1];
}
