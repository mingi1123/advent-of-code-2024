#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int parse_num(const string& line, int& i) {
    int num = 0;
    while (i < line.length() && isdigit(line[i])) {
        num = num * 10 + (line[i] - '0');
        i++;
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return 1;

    string line;
    int sum = 0;
    bool pass = false;

    while (getline(file, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line.substr(i, 4) == "do()") {
                pass = false;
                i += 3;
            } else if (line.substr(i, 7) == "don't()") {
                pass = true;
                i += 6;
            } else if (line.substr(i, 4) == "mul(") {
                if (pass) continue;
                int j = i + 4;
                int num1 = parse_num(line, j);

                if (j >= line.length() || line[j] != ',') continue;
                j++;

                int num2 = parse_num(line, j);
                if (j >= line.length() || line[j] != ')') continue;

                sum += num1 * num2;
                i = j;
            }
        }
    }

    cout << sum;
    return 0;
}
