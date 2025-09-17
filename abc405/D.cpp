#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int,2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mp(n+1,vector<char>(m+1)),ans(n+1,vector<char>(m+1));
    queue<pii> q;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j] == 'E'){
                q.push({i,j});
                ans[i][j] = 'E';
            }
            else if(mp[i][j] == '#')ans[i][j] = '#';
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front();q.pop();
        for(int i = 0;i<4;i++){
            int xx = x + dx[i],yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m || ans[xx][yy] != 0)continue;
            switch(i){
                case 0: ans[xx][yy] = '<'; break;
                case 1: ans[xx][yy] = '>'; break;
                case 2: ans[xx][yy] = '^'; break;
                case 3: ans[xx][yy] = 'v'; break;
            }
            q.push({xx,yy});
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
