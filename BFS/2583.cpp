#include <bits/stdc++.h>
using namespace std;
int paper[101][101];
bool vis[101][101];
int M, N; // N = col, M = row
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue <pair<int, int>> Q;
    vector<int> area;
    int K, cnt = 0;
    int x1, y1, x2, y2;
    cin >> N >> M >> K;
    //그림을 오른쪽으로 90도 회전 시키면 (0,0)이 왼쪽 위로 와서 쉬움
    while (K--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        //x1과 y1은 x2과 y2보다 작음
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                paper[i][j] = 1; // 그린 곳이 1 안 그린 곳이 0
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int paper_area = 0;
            if (paper[i][j] == 0 && vis[i][j] != true) {
                Q.push({ i,j });
                vis[i][j] = true;
                cnt++;
                paper_area++;
            }
            while (!Q.empty())
            {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                    if (paper[nx][ny] != 0 || vis[nx][ny] != false) continue;
                    Q.push({ nx,ny });
                    vis[nx][ny] = true;
                    paper_area++;
                }
            }
            if(paper_area)area.push_back(paper_area); //배열에 추가
        }
    }
    sort(area.begin(), area.end()); // 정렬
    cout << cnt << "\n";
    for (int i = 0; i < area.size(); i++)
    {
        cout << area[i] << " ";
    }
}
