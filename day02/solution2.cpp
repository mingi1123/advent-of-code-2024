#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool check_safe(vector<int> v) {
    bool asc = true;
    if (v[0] > v[1]) asc = false;
    if (abs(v[0] - v[1]) > 3 || abs(v[0] - v[1]) < 1) return false;

    for (int i = 2; i < v.size(); i++) {
        if (asc) {  // asc
            if (v[i - 1] > v[i]) return false;
        } else {  // desc
            if (v[i - 1] < v[i]) return false;
        }
        if (abs(v[i - 1] - v[i]) > 3 || abs(v[i - 1] - v[i]) < 1) return false;
    }

    return true;
}

bool remove_one(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        vector<int> temp = v;
        temp.erase(temp.begin() + i);
        if (check_safe(temp)) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return 1;

    string line;
    int res = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> levels;
        int num;

        while (iss >> num) {
            levels.push_back(num);
        }

        if (check_safe(levels))
            res++;
        else {  // removing a single level
            if (remove_one(levels)) res++;
        }
    }
    cout << res;

    return 0;
}
