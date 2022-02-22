// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    /* void check(int i, int j, vector<vector<int>> &res, vector<vector<int>> &vis, vector<vector<char>> &matrix, bool t)
    {
        if (matrix[i][j] == 'O')
        {
            if (vis[i][j] == 0)
            {
                vis[i][j] = 1;
                res[i][j] = 1;
                if (t)
                {
                    res[i][j] = 2;
                }
            }
            else if (vis[i][j] == 1 && !t)
            {
                res[i][j] = 1;
            }
        }
    } */
    struct tr
    {
        int first;
        int second;
        int third;
    };
    void BFS(int i, int j, vector<vector<int>> &res, vector<vector<int>> &vis, vector<vector<char>> &matrix, int M, int N)
    {
        queue<tr> qu;
        vector<vector<int>> vis2 = vis;
        qu.push({i,j,0});
        tr t;
        while(!qu.empty())
        {
            t = qu.front();
            qu.pop();
            int dirx[] = {-1,1,0,0};
            int diry[] = {0,0,1,-1};
            for(int i = 0;i<4;i++)
            {
                int x = t.first + dirx[i];
                int y = t.second + diry[i];
                if(x>=0 && y>=0 && x< M && y < N && vis2[x][y] == 0)
                {
                    qu.push({x,y,t.third + 1});
                    res[x][y] = min(res[x][y],t.third + 1);
                    vis2[x][y] = true;
                }
            }
        }
        /* int a = i - 1, b = j - 1, c = i + 1, d = j + 1;
        bool t;
        if (a >= 0)
        {
            if (b >= 0)
            {
                t = true;
                check(a, b, res, vis, matrix, t);
            }
            t = false;
            check(a, j, res, vis, matrix, t);
            if (d < N)
            {
                t = true;
                check(a, d, res, vis, matrix, t);
            }
        }
        if (d < N)
        {
            t = false;
            check(i, d, res, vis, matrix, t);
        }
        if (c < M)
        {
            if (d < N)
            {
                t = true;
                check(c, d, res, vis, matrix, t);
            }
            t = false;
            check(c, j, res, vis, matrix, t);
            if (b >= 0)
            {
                t = true;
                check(c, b, res, vis, matrix, t);
            }
        }
        if (b >= 0)
        {
            t = false;
            check(i, b, res, vis, matrix, t);
        } */
        /* while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            // for diagonals
            if (i - x == 1 && j - y == 1 || i - x == 1 && j - y == -1 || i - x == -1 && j - y == -1 || i - x == -1 && j - y == 1)
            {
                if (matrix[x][y] == 'O' && vis[x][y] == 0)
                {
                    vis[x][y] = 1;
                    res[x][y] = 2;
                }
                else if (matrix[x][y] == 'B' && vis[x][y] == 0)
                {
                    vis[x][y] = 1;
                    q.pop();
                    BFS(x, y, res, vis, matrix, M, N, q);
                }
                else if (matrix[x][y] == 'W')
                {
                    vis[x][y] = 1;
                    res[x][y] = -1;
                }
            }
            else if (matrix[x][y] == 'B' && vis[x][y] == 0)
            {
                vis[x][y] = 1;
                q.pop();
                BFS(x, y, res, vis, matrix, M, N, q);
            }
            else if (matrix[x][y] == 'W')
            {
                res[x][y] = -1;
            }
            else if (matrix[x][y] == 'O')
            {
                vis[x][y] = 1;
                res[x][y] = 1;
            }
            q.pop();
        } */
    }
    vector<vector<int>> findDistance(vector<vector<char>> &matrix, int M, int N)
    {
        vector<vector<int>> res(M, vector<int>(N, 0));
        vector<vector<int>> vis(M, vector<int>(N, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] == 'B')
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                else if (matrix[i][j] == 'W')
                {
                    vis[i][j] = 1;
                    res[i][j] = -1;
                }
                else
                {
                    res[i][j] = INT_MAX;
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            BFS(x, y, res, vis, matrix, M, N);
            q.pop();
        }
        for(int i = 0;i<M;i++)
        {
            for(int j = 0; j< N;j++)
            {
                if(res[i][j] == INT_MAX)
                {
                    res[i][j] = -1;
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
/*
1
3 3
O O O
W B B
W O O */

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int M, N;
        cin >> M;
        cin >> N;

        vector<vector<char>> matrix(M);
        for (int i = 0; i < M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin >> matrix[i][j];
        }

        vector<vector<int>> result;
        Solution obj;
        result = obj.findDistance(matrix, M, N);
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout << result[i][j] << " ";
            cout << "\n";
        }
    }

    return 0;
} // } Driver Code Ends