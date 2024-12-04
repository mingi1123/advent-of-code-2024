#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input1.txt");
    if (!file.is_open()) return 1;

    vector<int> left, right;
    string line;

    while (getline(file, line)) {
        int idx = line.find(" ");
        left.push_back(stoi(line.substr(0, idx)));
        right.push_back(stoi(line.substr(idx)));
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int sum = 0;
    for (int i = 0; i < left.size(); i++) {
        sum += abs(left[i] - right[i]);
    }

    cout << sum;

    return 0;
}
