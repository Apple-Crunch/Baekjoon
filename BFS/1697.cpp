#include <bits/stdc++.h>
using namespace std;
int line[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    if (N == K) {
        cout << 0;
        return 0;
    }
    line[N] = 1;
    queue<int>Q;
    Q.push(N);
    while (!Q.empty())
    {
        int cur_x = Q.front(); Q.pop();
        if (cur_x == K) {
            cout << line[cur_x] - 1;
            break;
        }
        int dx[3] = { cur_x - 1, cur_x + 1, cur_x * 2 };
        for (int dir = 0; dir < 3; dir++)
        {
            int nx = dx[dir];
            if (nx < 0 || nx > 100000) continue; // 선 밖으로 안나간다고는 안했으나 나가면 손해
            if (line[nx] > 0) continue; // 갔던 길
            line[nx] = line[cur_x] + 1;
            Q.push(nx);
        }
    }
}
