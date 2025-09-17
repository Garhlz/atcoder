#include <bits/stdc++.h>
using namespace std;

#define int long long  // 使用 long long 确保大数处理安全
const int MAX_N = 1e6 + 10;  // 数组最大长度

int n;              // 输入的饼数量
int cake[MAX_N];    // 存储每个饼的大小
int total_mirror_cakes = 0;  // 最终镜饼数量

signed main() {
    ios::sync_with_stdio(false);  // 加速输入输出
    cin.tie(0);
    cout.tie(0);

    // 输入饼的数量
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cake[i];  // 输入每个饼的大小
    }

    // 对饼的大小进行升序排序，便于贪心处理
    sort(cake + 1, cake + n + 1);

    // q1: 存储已选镜饼方案的优先队列，按较大值从小到大排序
    // pair<较大值, 较小值>，小顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> selected_pairs;
    
    // q2: 存储未选饼的优先队列，从小到大排序，小顶堆，用作小的
    priority_queue<int, vector<int>, greater<int>> unused_cakes;

    // 从小到大扫描每个饼
    for (int i = 1; i <= n; i++) {
        int current_cake = cake[i];  // 当前处理的饼大小，从小的开始

        // 情况 1: 如果未选饼中有满足条件的较小值，直接配对
        if (!unused_cakes.empty() && unused_cakes.top() * 2 <= current_cake) {
            int small_cake = unused_cakes.top();  // 取出未选饼中的最小值
            unused_cakes.pop();                   // 从未选饼中移除
            selected_pairs.push({current_cake, small_cake});  // 组成镜饼，存入已选方案
            total_mirror_cakes++;                 // 镜饼数量加一
        }
        // 情况 2: 如果已选方案中有较大值小于当前值，进行反悔调整
        else if (!selected_pairs.empty() && selected_pairs.top().first < current_cake) {
            pair<int, int> least_optimal = selected_pairs.top();  // 取出较大值最小的方案
            selected_pairs.pop();                                 // 移除原方案
            unused_cakes.push(least_optimal.first);               // 将原较大值放入未选饼
            selected_pairs.push({current_cake, least_optimal.second});  // 用当前值替换
        }
        // 情况 3: 无法配对或调整，暂时存入未选饼队列
        else {
            unused_cakes.push(current_cake);
        }
    }

    // 输出最终镜饼数量
    cout << total_mirror_cakes << endl;
    return 0;
}