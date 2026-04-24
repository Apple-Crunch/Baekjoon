#include <bits/stdc++.h>
using namespace std;
char area[31][31][31];
int dis[31][31][31];
bool vis[31][31][31];
int L, R, C; // L은 층 R은 행 C는 열
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    queue <tuple<int, int, int>> Q;
    cin >> L >> R >> C;
    int x, y, z;
    while (L != 0 && R != 0 && C != 0)
    {
        bool is_possible = false;
        int minute = 0;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                cin >> s;
                //cin은 개행을 제외한 문자를 저장
                for (int k = 0; k < C; k++)
                {
                    area[i][j][k] = s[k];
                    //벽은 -1 길은 0 지나간 길은 양의 정수
                    if (s[k] == 'S') {
                        Q.push({ i,j,k });
                        vis[i][j][k] = true;
                        dis[i][j][k] = 1;
                    }
                    else if (s[k] == '#') dis[i][j][k] = -1;
                }
            }
        }
        while (!Q.empty()) 
        {
            auto cur = Q.front(); Q.pop();
            minute++;
            if (area[get<0>(cur)][get<1>(cur)][get<2>(cur)] == 'E') {
                is_possible = true;
                z = get<0>(cur);
                x = get<1>(cur);
                y = get<2>(cur);
                break;
            }
            for (int dir = 0; dir < 6; dir++)
            {
                int nz = get<0>(cur) + dz[dir];
                int nx = get<1>(cur) + dx[dir];
                int ny = get<2>(cur) + dy[dir];
                if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (dis[nz][nx][ny] != 0) continue;
                Q.push({ nz,nx,ny });
                dis[nz][nx][ny] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }
        if (is_possible) cout << "Escaped in " << dis[z][x][y] - 1 << " minute(s).\n";
        else cout << "Trapped!\n";
        //다음 테스트케이스를 위한 초기화
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j <= R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    vis[i][j][k] = false;
                    dis[i][j][k] = 0;
                }
            }
        }
        while (!Q.empty())Q.pop();
        cin >> L >> R >> C;
    }
}
