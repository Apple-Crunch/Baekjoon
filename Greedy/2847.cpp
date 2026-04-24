#include <iostream>
#include <vector>
using namespace std;
vector<int> V;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, cnt = 0;
	cin >> N;
	V.resize(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	for (int i = N - 1; i >= 0; i--) {
		if (i >= 1) {
			if (V[i] <= V[i - 1]) { //최고 난이도의 점수가 낮거나 같으면
				cnt += V[i - 1] - V[i] + 1; //점수 차이 + 1
				V[i - 1] = V[i] - 1;
			}
		}
	}
	cout << cnt;
}
