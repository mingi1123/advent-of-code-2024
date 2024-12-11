#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<char>> v;

int find_xmas(int x, int y) {
    int cnt = 0;

    // A
    if (v[x][y] != 'A') return 0;

    // 범위
    if (x - 1 < 0 || y - 1 < 0 || x + 1 >= v.size() || y + 1 >= v[x].size()) return 0;

    // 대각선
    if (v[x - 1][y - 1] == 'M' && v[x + 1][y - 1] == 'M' && v[x - 1][y + 1] == 'S' && v[x + 1][y + 1] == 'S') cnt++;
    if (v[x - 1][y - 1] == 'S' && v[x + 1][y - 1] == 'S' && v[x - 1][y + 1] == 'M' && v[x + 1][y + 1] == 'M') cnt++;
    if (v[x - 1][y - 1] == 'M' && v[x + 1][y - 1] == 'S' && v[x - 1][y + 1] == 'M' && v[x + 1][y + 1] == 'S') cnt++;
    if (v[x - 1][y - 1] == 'S' && v[x + 1][y - 1] == 'M' && v[x - 1][y + 1] == 'S' && v[x + 1][y + 1] == 'M') cnt++;

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return 1;

    string line;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        v.push_back(row);
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            sum += find_xmas(i, j);
        }
        cout << '\n';
    }

    cout << sum;
    return 0;
}
