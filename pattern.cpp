#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<pair<int, int> > directions = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<vector<char> > pattern = {
        {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};

    Solution(){};

    void
    dfs(vector<vector<bool> > visited, int i, int j, int x, int &total,
        string res) {
        int size = pattern.size();

        if (i < 0 || i >= size || j < 0 || j >= size || visited[i][j]) {
            return;
        }

        if (x == 1) {
            cout << res + pattern[i][j] << endl;
            total++;
            return;
        }

        visited[i][j] = 1;

        for (auto it : directions) {
            dfs(visited, i + it.first, j + it.second, x - 1, total,
                res + pattern[i][j]);
        }
    }

    int
    getAllPathsOfSize(char source, int x) {
        if (x > 8 || source == ' ') {
            cout << "Invalid input" << endl;
            return -1;
        }

        int size = pattern.size();
        vector<vector<bool> > visited(size, vector<bool>(size, 0));
        int                   total = 0, start_i = 0, start_j = 0;
        string                res = "";

        for (int i = 0; i < pattern.size(); i++) {
            for (int j = 0; j < pattern[i].size(); j++) {
                if (pattern[i][j] == source) {
                    start_i = i;
                    start_j = j;
                    break;
                }
            }
        }

        dfs(visited, start_i, start_j, x + 1, total, res);

        return total;
    }
};

int
main() {
    int      count = 0, size = 0;
    Solution sol;

    /* unit test */
    vector<char> test = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

    for (int i = 0; i < test.size(); i++) {
        for (int j = 0; j <= 8; j++) {
            count = sol.getAllPathsOfSize(test[i], j);
            cout << "total path for " << test[i] << " for size " << j << " = "
                 << count << endl;
            cout << "=====================================" << endl;
        }
    }

    return 0;
}