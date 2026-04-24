#include <iostream>
#include <utility> 
#include <queue>

using namespace std;
//BFS
int board[502][502] = { 0, };
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int row, col; // row = 행의 수, col = 열의 수
//x가 행, y가 열의 방향
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0, max_area = 0, cnt = 0;
    cin >> col >> row;
    queue<pair<int, int> > Q;
    //가로세로 정상화
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (board[i][j] == 1 && vis[i][j] != 1)
            {
                ans++; // 시작 지점의 넓이 1더하기
                cnt++; //그림 갯수
                vis[i][j] = 1;
                Q.push({ i,j });
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= col || ny < 0 || ny >= row) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({ nx,ny });
                        ans++;
                    }
                }
                if (max_area <= ans) max_area = ans;
                ans = 0;
            }
        }
    }
    cout << cnt << "\n" << max_area;
}
