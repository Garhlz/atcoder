#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int n, r, c;
int dx[200010];
int dy[200010];
int d1[128], d2[128];
string s;
map<pair<int, int>, int> mp;
/*
对移动轨迹作前缀和，对于每一个前缀和查找，减掉目标位置之后的位置是否存在于之前的前缀和中，用一个map维

*/
int main() {
    cin >> n >> r >> c >> s;
    s = " " + s;
    d1['N'] = -1;
    d1['S'] = 1;
    d2['W'] = -1;
    d2['E'] = 1;
    mp[make_pair(0, 0)] = 1;
    for (int i = 1; i <= n; i++) {
        dx[i] = dx[i - 1] + d1[s[i]];
        dy[i] = dy[i - 1] + d2[s[i]];
        if (mp.count(make_pair(dx[i] - r, dy[i] - c)))
            cout << "1";
        else
            cout << "0";
        mp[make_pair(dx[i], dy[i])] = 1;
    }
    cout << endl;
    return 0;
}