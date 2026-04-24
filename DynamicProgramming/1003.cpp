#include <iostream>
using namespace std;
int cnt[41][2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int T, N;
    cin >> T;
    cnt[0][0] = 1; cnt[0][1] = 0; // N = 0
    cnt[1][0] = 0; cnt[1][1] = 1; // N = 1
    cnt[2][0] = 1; cnt[2][1] = 1; // N = 2
    //N을 넣으면 실제로 호출은 N-1과 N-2이 하니까 N-1과 N-2일 때 호출 수의 합을 더하면 된다.
    for (int i = 3; i <= 40; i++) {
        cnt[i][0] = cnt[i - 1][0] + cnt[i - 2][0];
        cnt[i][1] = cnt[i - 1][1] + cnt[i - 2][1];
    }
    while (T--) {
        cin >> N;
        cout << cnt[N][0] << " " << cnt[N][1] << "\n";
    }
}
