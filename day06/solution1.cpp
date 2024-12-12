#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return 1;

    string line;
    int sum = 0;
    bool parsing_flag = true;

    vector<string> map;
    queue<tuple<int, int, int>> q;  // x, y, dir

    while (getline(file, line)) {
        map.push_back(line);
        if (line.find("^") != string::npos) {
            q.push({map.size() - 1, line.find("^"), 0});
        }
        if (line.find(">") != string::npos) {
            q.push({map.size() - 1, line.find(">"), 1});
        }
        if (line.find("v") != string::npos) {
            q.push({map.size() - 1, line.find("v"), 2});
        }
        if (line.find("<") != string::npos) {
            q.push({map.size() - 1, line.find("<"), 3});
        }
    }

    while (!q.empty()) {
        auto [x, y, dir] = q.front();
        map[x][y] = 'X';
        q.pop();

        // 앞에 장애물이 있으면 (#): 경비원은 오른쪽으로 90도 회전.
        if (dir == 0 && x > 0 && map[x - 1][y] == '#') q.push({x, y, 1});
        if (dir == 1 && y <= map[0].size() && map[x][y + 1] == '#') q.push({x, y, 2});
        if (dir == 2 && x <= map.size() && map[x + 1][y] == '#') q.push({x, y, 3});
        if (dir == 3 && y > 0 && map[x][y - 1] == '#') q.push({x, y, 0});

        // 앞이 비어 있으면(.): 한 칸 앞으로 이동.
        if (dir == 0 && x > 0 && map[x - 1][y] != '#') {
            q.push({x - 1, y, 0});
            if (map[x - 1][y] == '.') sum++;
        }
        if (dir == 1 && y < map[0].size() - 1 && map[x][y + 1] != '#') {
            q.push({x, y + 1, 1});
            if (map[x][y + 1] == '.') sum++;
        }
        if (dir == 2 && x < map.size() - 1 && map[x + 1][y] != '#') {
            q.push({x + 1, y, 2});
            if (map[x + 1][y] == '.') sum++;
        }
        if (dir == 3 && y > 0 && map[x][y - 1] != '#') {
            q.push({x, y - 1, 3});
            if (map[x][y - 1] == '.') sum++;
        }
    }

    cout << sum + 1;
    return 0;
}
