#include <iostream>
#include <queue>
using namespace std;
int dis[1000001];
int dx[3] = { -1, -1, -1 }; // 연산1, 2, 3순서
int main(void) { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    queue<int> Q;
    cin >> N;
    Q.push(N);
    dis[N] = 1;
    //BFS로 풀기 
    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        if (cur % 3 == 0) dx[0] = cur / 3; // 연산 1에 해당
        else dx[0] = -1;
        if (cur % 2 == 0) dx[1] = cur / 2; // 연산 2에 해당
        else dx[1] = -1;
        for (int dir = 0; dir < 3; dir++)
        {
            int nx;            
            if (dir <= 2 && dx[dir] != -1) nx = dx[dir];
            else if(dir == 2) nx = cur + dx[2]; // 연산 3에 해당
            else continue;
            if (nx <= 0) continue;
            if (dis[nx] > 0) continue;
            Q.push(nx);
            dis[nx] = dis[cur] + 1; 
        }
    }
    cout << dis[1] - 1;
}
