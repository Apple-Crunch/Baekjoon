#include <bits/stdc++.h>
using namespace std;
int dis[301][301];
int row, col;
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 }; // 세로 이동
int dy[8] = { -2, -1, 1, 2, -2, -1, 1, 2 }; // 가로 이동
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, I, cnt = 0, kx, ky, knx, kny;
    queue <pair<int, int>> Q;
    cin >> T;
    while (T--)
    {
        cin >> I;
        cin >> kx >> ky; //현재 위치
        cin >> knx >> kny; //갈 위치
        Q.push({ kx,ky });
        dis[kx][ky] = 0;
        while (!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            if (cur.first == knx && cur.second == kny)
            {
                cout << dis[cur.first][cur.second] << "\n";
                break;
            }
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if (dis[nx][ny] != 0) continue;
                dis[nx][ny] = dis[cur.first][cur.second] + 1;
                Q.push({ nx,ny });
            }
            
        }
        //다음 테스트케이스를 위한 초기화
        cnt = 0;
        for (int i = 0; i < I; i++)
        {
            for (int j = 0; j < I; j++) dis[i][j] = 0;
        }
        while (!Q.empty())Q.pop();
    }
}
