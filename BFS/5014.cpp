#include <bits/stdc++.h>
using namespace std;
int apart[1000001];
bool vis[26][26];
int N; 
int button[2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue <int> Q;
    bool is_possible = false;
    int F, G, S, U, D;
    cin >> F >> S >> G >> U >> D;
    button[0] = U; button[1] = -D;
    apart[S - 1] = 1; //apart[0]이 1층 S-1이 S층
    Q.push(S - 1);
    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        if (cur == G - 1) {
            is_possible = true;
            break;
        }
        for (int dir = 0; dir < 2; dir++)
        {
            int new_floor = cur + button[dir];
            if (new_floor < 0 || new_floor >= F) continue;
            if (apart[new_floor] != 0) continue;
            Q.push(new_floor);
            apart[new_floor] = apart[cur] + 1;
        }
    }
    if (is_possible) cout << apart[G - 1] - 1; //내 위치의 apart[]가 1로 시작했음
    else cout << "use the stairs";
}
