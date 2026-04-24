#include <iostream>
using namespace std;
int T[501][501]; // 삼각형에 쓰인 점수
int S[501][501]; // S[삼각형의 위에서 부터 센 층][해당 층의 해당 칸에 대한 최대 점수]
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, max_score = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> T[i][j];
		}
	}
	S[0][0] = T[0][0];
	S[1][0] = T[0][0] + T[1][0];
	S[1][1] = T[0][0] + T[1][1];
	S[2][0] = S[1][0] + T[2][0];
	S[2][1] = max(S[1][0], S[1][1]) + T[2][1]; // 해당 칸에 도달 가능한 경우의 수 중 max를 선택
	S[2][2] = S[1][1] + T[2][2];
	//해당 원리를 적용
	for (int i = 3; i < n; i++) {
		S[i][0] = S[i - 1][0] + T[i][0];
		S[i][i] = S[i - 1][i - 1] + T[i][i];
		for (int j = 1; j <= i - 1; j++) 
			S[i][j] = max(S[i - 1][j - 1], S[i - 1][j]) + T[i][j];
	}
	for (int i = 0; i < n; i++) 
		if (max_score < S[n - 1][i]) max_score = S[n - 1][i];
	cout << max_score;
}
