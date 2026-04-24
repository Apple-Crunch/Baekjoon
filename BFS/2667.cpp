#include <bits/stdc++.h>
using namespace std;
int apart[26][26];
bool vis[26][26];
int N; 
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue <pair<int, int>> Q;
    string s;
    vector<int> area;
    int K, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            apart[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int danji_area = 0;
            if (apart[i][j] == 1 && vis[i][j] == false) {
                Q.push({ i,j });
                vis[i][j] = true;
                danji_area++;
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
                    if (apart[nx][ny] == 0 || vis[nx][ny] == true) continue;
                    Q.push({ nx,ny });
                    vis[nx][ny] = true;
                    danji_area++;
                }
            }
            if (danji_area)area.push_back(danji_area);
        }
    }
    cout << cnt << "\n";
    sort(area.begin(), area.end());
    for (int i = 0; i < area.size(); i++)
    {
        cout << area[i] << "\n";
    }
}
