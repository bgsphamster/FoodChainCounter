#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Node {
    bool val;
    bool flag;
};

void F(int &ans, vector<vector<Node>> &v, int x = 1) {
    for (int i = 0; i < v.size(); i++) {
        //存在一组吃与被吃的关系
        if (v[x][i].val) {
            //是否到达最高级消费者
            if (v[x][i].flag) {
                ans++;
                return;
            } else {
                F(ans, v, i);
            }
        }
    }
}

Node g() {
    return {false, false};
}


int main() {
    int n;
    cin >> n;
    vector<vector<Node>> v;
    v.resize(n);
    for (auto &item: v) {
        item.resize(n);
        std::generate(item.begin(), item.end(), g);
    }
    int x, y;
    vector<pair<int, int>> vp; // 缓存数据
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        vp.emplace_back(x, y);
    }
    for (auto &item: vp) {
        if (item.second == 0) {
            //寻找first == item.second的输入条目
            for (auto &i: vp) {
                if (item.first == i.second) {
                    v[i.first][i.second].flag = true;
                }
            }
        }
    }
    for (auto &item: vp) {
        if (item.second != 0) {
            v[item.first][item.second].val = true;
        }
    }
    int ans = 0;
    F(ans, v);
    cout << ans << endl;
    return 0;
}