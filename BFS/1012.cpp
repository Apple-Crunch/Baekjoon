#include <bits/stdc++.h>
using namespace std;
int baechu[51][51];
bool vis[51][51];
int M, N; //M = col, N = row
int dx[4] = { 1,0,-1,0 }; // 세로 이동
int dy[4] = { 0,1,0,-1 }; // 가로 이동
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, K, X, Y, cnt = 0;
    queue <pair<int, int>> Q;
    cin >> T;
    while (T--)
    {
        cin >> M >> N >> K;
        while (K--)
        {
            cin >> Y >> X;
            baechu[X][Y] = 1;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (baechu[i][j] == 1 && vis[i][j] != true)
                {
                    Q.push({ i,j });
                    vis[i][j] = true;
                    while (!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx > N || ny < 0 || ny > M) continue;
                            if (vis[nx][ny] || baechu[nx][ny] != 1)continue;
                            baechu[nx][ny] = 1;
                            vis[nx][ny] = true;
                            Q.push({ nx,ny });
                        }
                    }
                    cnt++;
                }
            }
        }
        std::cout << cnt << "\n";
        for (int i = 0; i < N; i++) //밭 초기화
        {
            for (int j = 0; j < M; j++)
            {
                baechu[i][j] = 0;
                vis[i][j] = false;
            }
        }
        while (!Q.empty()) Q.pop(); //큐 초기화
        cnt = 0;
    }
    
    
}
