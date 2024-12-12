#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
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

    vector<string> origin_map;
    tuple<int, int, int> start;

    while (getline(file, line)) {
        origin_map.push_back(line);
        if (line.find("^") != string::npos) {
            start = {origin_map.size() - 1, line.find("^"), 0};
        }
        if (line.find(">") != string::npos) {
            start = {origin_map.size() - 1, line.find(">"), 1};
        }
        if (line.find("v") != string::npos) {
            start = {origin_map.size() - 1, line.find("v"), 2};
        }
        if (line.find("<") != string::npos) {
            start = {origin_map.size() - 1, line.find("<"), 3};
        }
    }

    for (int i = 0; i < origin_map.size(); i++) {
        for (int j = 0; j < origin_map[i].size(); j++) {
            if (origin_map[i][j] == '.') {
                origin_map[i][j] = '#';

                vector<string> map = origin_map;
                set<tuple<int, int, int>> visited;
                queue<tuple<int, int, int>> q;  // x, y, dir
                q.push({get<0>(start), get<1>(start), get<2>(start)});

                while (!q.empty()) {
                    auto [x, y, dir] = q.front();
                    map[x][y] = 'X';
                    q.pop();

                    if (visited.find({x, y, dir}) != visited.end()) {
                        sum++;
                        break;
                    }
                    visited.insert({x, y, dir});

                    // 앞에 장애물이 있으면 (#): 경비원은 오른쪽으로 90도 회전.
                    if (dir == 0 && x > 0 && map[x - 1][y] == '#') q.push({x, y, 1});
                    if (dir == 1 && y <= map[0].size() && map[x][y + 1] == '#') q.push({x, y, 2});
                    if (dir == 2 && x <= map.size() && map[x + 1][y] == '#') q.push({x, y, 3});
                    if (dir == 3 && y > 0 && map[x][y - 1] == '#') q.push({x, y, 0});

                    // 앞이 비어 있으면(.): 한 칸 앞으로 이동.
                    if (dir == 0 && x > 0 && map[x - 1][y] != '#') {
                        q.push({x - 1, y, 0});
                    }
                    if (dir == 1 && y < map[0].size() - 1 && map[x][y + 1] != '#') {
                        q.push({x, y + 1, 1});
                    }
                    if (dir == 2 && x < map.size() - 1 && map[x + 1][y] != '#') {
                        q.push({x + 1, y, 2});
                    }
                    if (dir == 3 && y > 0 && map[x][y - 1] != '#') {
                        q.push({x, y - 1, 3});
                    }
                }

                origin_map[i][j] = '.';
            }
        }
    }

    cout << sum;
    return 0;
}
