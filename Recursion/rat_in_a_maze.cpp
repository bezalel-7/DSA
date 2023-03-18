#include <iostream>
#include <vector>
using namespace std;

// User function template for C++

class Solution
{
private:
    void solve(vector<vector<int>> m, vector<vector<int>> visited, int srcX, int n, int srcY, vector<string> &ans, string output)
    {
        visited[srcX][srcY] = 1;
        if ((srcX == n - 1) && (srcY == n - 1))
        {
            ans.push_back(output);
            return;
        }
        else
        {
            // 'U'(up)
            if (srcX - 1 >= 0)
            {
                if (m[srcX - 1][srcY] == 1 && visited[srcX - 1][srcY] == 0)
                {
                    output += 'U';
                    solve(m, visited, srcX - 1, n, srcY, ans, output);
                    output.pop_back();
                }
            }
            // 'D'(down)
            if (srcX + 1 <= n - 1)
            {
                if (m[srcX + 1][srcY] == 1 && visited[srcX + 1][srcY] == 0)
                {
                    output += 'D';
                    solve(m, visited, srcX + 1, n, srcY, ans, output);
                    output.pop_back();
                }
            }
            // 'L' (left)
            if (srcY - 1 >= 0)
            {
                if (m[srcX][srcY - 1] == 1 && visited[srcX][srcY - 1] == 0)
                {
                    output += 'L';
                    solve(m, visited, srcX, n, srcY - 1, ans, output);
                    output.pop_back();
                }
            }
            // 'R' (right)
            if (srcY + 1 <= n - 1)
            {
                if (m[srcX][srcY + 1] == 1 && visited[srcX][srcY + 1] == 0)
                {
                    output += 'R';
                    solve(m, visited, srcX, n, srcY + 1, ans, output);
                    output.pop_back();
                }
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        int srcX = 0;
        int srcY = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;
        solve(m, visited, srcX, n, srcY, ans, "");
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}