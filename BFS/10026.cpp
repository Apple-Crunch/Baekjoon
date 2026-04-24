#include <bits/stdc++.h>
using namespace std;
char color_RGB[101][101];
bool vis_RGB[101][101];
int row, col;
int dx[4] = { 1,0,-1,0 }; // 세로 이동
int dy[4] = { 0,1,0,-1 }; // 가로 이동
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, cnt_RGB = 0, cnt_RB = 0;
    string colors;
    queue <pair<int, int>> Q;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> colors;
        for (int j = 0; j < N; j++) color_RGB[i][j] = colors[j];
    }
    for (int i = 0; i < N; i++) //적록색약이 아닌 사람
    {
        for (int j = 0; j < N; j++)
        {
            if (vis_RGB[i][j] == false)
            {
                Q.push({ i,j });
                vis_RGB[i][j] = true;
                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx > N || ny < 0 || ny > N) continue;
                        if (color_RGB[nx][ny] != color_RGB[cur.first][cur.second] || vis_RGB[nx][ny] != false) continue;
                        Q.push({ nx,ny });
                        vis_RGB[nx][ny] = true;
                    }
                }
                cnt_RGB++;
            }
        }
    }
    for (int i = 0; i < N; i++) //초록을 빨간색으로 바꿔서 구분 못하게 함
    {
        for (int j = 0; j < N; j++) {
            if (color_RGB[i][j] == 'G') color_RGB[i][j] = 'R';
            vis_RGB[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) //적록색약인 사람
    {
        for (int j = 0; j < N; j++)
        {
            if (vis_RGB[i][j] == false)
            {
                Q.push({ i,j });
                vis_RGB[i][j] = true;
                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx > N || ny < 0 || ny > N) continue;
                        if (color_RGB[nx][ny] != color_RGB[cur.first][cur.second] || vis_RGB[nx][ny] != false) continue;
                        Q.push({ nx,ny });
                        vis_RGB[nx][ny] = true;
                    }
                }
                cnt_RB++;
            }
        }
    }
    cout << cnt_RGB << " " << cnt_RB;
}
