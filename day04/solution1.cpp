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

    // 왼쪽, 오른쪽, 위, 아래
    if (y + 3 < v[x].size() && v[x][y] == 'X' && v[x][y + 1] == 'M' && v[x][y + 2] == 'A' && v[x][y + 3] == 'S') cnt++;
    if (y - 3 >= 0 && v[x][y] == 'X' && v[x][y - 1] == 'M' && v[x][y - 2] == 'A' && v[x][y - 3] == 'S') cnt++;
    if (x + 3 < v.size() && v[x][y] == 'X' && v[x + 1][y] == 'M' && v[x + 2][y] == 'A' && v[x + 3][y] == 'S') cnt++;
    if (x - 3 >= 0 && v[x][y] == 'X' && v[x - 1][y] == 'M' && v[x - 2][y] == 'A' && v[x - 3][y] == 'S') cnt++;

    // 왼쪽, 오른쪽, 위, 아래 대각선
    if (x + 3 < v.size() && y + 3 < v[x].size() && v[x][y] == 'X' && v[x + 1][y + 1] == 'M' && v[x + 2][y + 2] == 'A' && v[x + 3][y + 3] == 'S') cnt++;
    if (x - 3 >= 0 && y - 3 >= 0 && v[x][y] == 'X' && v[x - 1][y - 1] == 'M' && v[x - 2][y - 2] == 'A' && v[x - 3][y - 3] == 'S') cnt++;
    if (x + 3 < v.size() && y - 3 >= 0 && v[x][y] == 'X' && v[x + 1][y - 1] == 'M' && v[x + 2][y - 2] == 'A' && v[x + 3][y - 3] == 'S') cnt++;
    if (x - 3 >= 0 && y + 3 < v[x].size() && v[x][y] == 'X' && v[x - 1][y + 1] == 'M' && v[x - 2][y + 2] == 'A' && v[x - 3][y + 3] == 'S') cnt++;

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
