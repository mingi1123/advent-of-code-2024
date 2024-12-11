#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<char>> v;

unordered_map<int, vector<int>> rules;

int check_order(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        int page = v[i];
        for (int j = i + 1; j < v.size(); j++) {
            int nextpage = v[j];
            if (find(rules[page].begin(), rules[page].end(), nextpage) == rules[page].end()) return 0;
        }
    }

    return v[v.size() / 2];
}

// 올바르지 않은 순서를 찾아서 수정
int order_incorrect(vector<int> &v) {
    std::sort(v.begin(), v.end(), [&](int a, int b) {
        if (rules.find(a) == rules.end()) return true;
        if (std::find(rules[a].begin(), rules[a].end(), b) != rules[a].end()) return false;
        return true;
    });

    return v[v.size() / 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return 1;

    string line;
    int sum = 0;
    bool parsing_flag = true;

    while (getline(file, line)) {
        if (line.empty()) {
            parsing_flag = false;
            continue;
        }

        if (parsing_flag) {
            int x, y;
            char delimiter;  // |
            stringstream ss(line);
            ss >> x >> delimiter >> y;
            rules[x].push_back(y);
        } else {
            vector<int> update;
            stringstream ss(line);
            int page;
            char delimiter;
            while (ss >> page) {
                update.push_back(page);
                ss >> delimiter;  // ,
            }
            if (!check_order(update)) sum += order_incorrect(update);
        }
    }

    cout << sum;
    return 0;
}
