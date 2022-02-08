// 1001. 网格照明

#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

//多个哈希
class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        unordered_map<int, int> row, col, diagonal, antiDiagonal;
        auto hash_p = [](const pair<int, int> &p) -> size_t
        {
            static hash<long long> hash_ll;
            return hash_ll(p.first + (static_cast<long long>(p.second) << 32));
        };
        unordered_set<pair<int, int>, decltype(hash_p)> points(0, hash_p);
        for (auto &lamp : lamps)
        {
            if (points.count({lamp[0], lamp[1]}))
            {
                continue;
            }
            points.insert({lamp[0], lamp[1]});
            row[lamp[0]]++;
            col[lamp[1]]++;
            diagonal[lamp[0] - lamp[1]]++;
            antiDiagonal[lamp[0] + lamp[1]]++;
        }
        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int r = queries[i][0], c = queries[i][1];
            if (row.count(r) > 0 && row[r] > 0)
            {
                ret[i] = 1;
            }
            else if (col.count(c) > 0 && col[c] > 0)
            {
                ret[i] = 1;
            }
            else if (diagonal.count(r - c) > 0 && diagonal[r - c] > 0)
            {
                ret[i] = 1;
            }
            else if (antiDiagonal.count(r + c) > 0 && antiDiagonal[r + c] > 0)
            {
                ret[i] = 1;
            }
            for (int x = r - 1; x <= r + 1; x++)
            {
                for (int y = c - 1; y <= c + 1; y++)
                {
                    if (x < 0 || y < 0 || x >= n || y >= n)
                    {
                        continue;
                    }
                    auto p = points.find({x, y});
                    if (p != points.end())
                    {
                        points.erase(p);
                        row[x]--;
                        col[y]--;
                        diagonal[x - y]--;
                        antiDiagonal[x + y]--;
                    }
                }
            }
        }
        return ret;
    }
};

class Solution2
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        unordered_map<int, int> r, c, x1, x2;
        unordered_map<int, unordered_set<int>> points;
        auto add = [&](int x, int y) -> void
        {
            r[x]++;
            c[y]++;
            x1[x - y]++;
            x2[n - x + y - 1]++;
        };
        auto rem = [&](int x, int y) -> void
        {
            r[x]--;
            c[y]--;
            x1[x - y]--;
            x2[n - x + y - 1]--;
        };
        auto has = [&](int x, int y) -> bool
        {
            auto it = points.find(x);
            if (it == points.end())
            {
                return false;
            }
            auto jt = it->second.find(y);
            if (jt == it->second.end())
            {
                return false;
            }
            return it->second.erase(*jt), true;
        };
        auto is = [&](int x, int y) -> bool
        {
            return r[x] || c[y] || x1[x - y] || x2[n - x + y - 1];
        };
        for (auto &p : lamps)
        {
            points[p[0]].insert(p[1]);
        }
        for (auto &kv : points)
        {
            for (auto &c : kv.second)
            {
                add(kv.first, c);
            }
        }
        vector<int> ans;
        for (auto &q : queries)
        {
            int x = q[0], y = q[1];
            ans.push_back(is(x, y));
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (has(x + i, y + j))
                    {
                        rem(x + i, y + j);
                    }
                }
            }
        }
        return move(ans);
    }
};