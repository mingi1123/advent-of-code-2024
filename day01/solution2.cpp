#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return 1;

    vector<int> left;
    unordered_map<int, int> right;
    string line;

    while (getline(file, line)) {
        int idx = line.find(" ");
        left.push_back(stoi(line.substr(0, idx)));
        right[stoi(line.substr(idx))]++;
    }

    int sum = 0;
    for (int i = 0; i < left.size(); i++) {
        if (right.find(left[i]) != right.end()) sum += left[i] * right[left[i]];
    }

    cout << sum;

    return 0;
}
