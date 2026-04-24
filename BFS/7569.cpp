#include <bits/stdc++.h>
using namespace std;
int tomato[101][101][101]; // 가로 세로 높이
int M, N, H; // M = col, N = row
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int max = 0;
    bool is_able = true;
    queue <tuple<int, int, int>> Q;
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> tomato[i][j][k]; //3차원 배열은 면, 행, 열 순서
                if (tomato[i][j][k] > 0) Q.push({ i,j,k });
            }
        }
    }
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        if (tomato[get<0>(cur)][get<1>(cur)][get<2>(cur)] >= max) max = tomato[get<0>(cur)][get<1>(cur)][get<2>(cur)];
        for (int dir = 0; dir < 6; dir++)
        {
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if (tomato[nz][nx][ny] > 0 || tomato[nz][nx][ny] < 0) continue;
            tomato[nz][nx][ny] = tomato[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({ nz,nx,ny });
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomato[i][j][k] == 0) is_able = false;
            }
        }
    }
    if (is_able)cout << max - 1;
    else cout << -1;    
}
