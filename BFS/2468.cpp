#include <bits/stdc++.h>
using namespace std;
int area[101][101];
bool vis[101][101];
int N; 
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue <pair<int, int>> Q;
    cin >> N;
    int max = 0, cnt = 0, cnt_max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];
            if (area[i][j] > max) max = area[i][j];
        }
    }
    for (int water = 0; water < max; water++)
    {
        cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (area[i][j] > water && vis[i][j] == false) {
                    Q.push({ i,j });
                    vis[i][j] = true;
                    cnt++;
                }
                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (area[nx][ny] <= water || vis[nx][ny] != false) continue; // 수위 이하의 건물이 잠김
                        Q.push({ nx,ny });
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) //수위가 변하니 방문기록 초기화
        {
            for (int j = 0; j < N; j++)
            {
                vis[i][j] = false;
            }
        }
        if (cnt > cnt_max) cnt_max = cnt;
    }
    cout << cnt_max;
}
