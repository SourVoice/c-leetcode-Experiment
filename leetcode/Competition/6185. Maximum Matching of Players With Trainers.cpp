// 6185. 运动员和训练师的最大匹配数
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
// 贪心
class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));
        int i = 0, j = 0; // i for players, j for trainers
        int match = 0;
        while (i < players.size() && j < trainers.size())
        {
            if (players[i] <= trainers[j])
            {
                i++, j++;
                match++;
            }
            else
                j++;
        }
        return match;
    }
};
// 优先队列
class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        // use minheap
        priority_queue<int, vector<int>, std::greater<int>> pq_trainer(begin(trainers), end(trainers));
        priority_queue<int, vector<int>, std::greater<int>> pq_player(begin(players), end(players));

        int match = 0;
        while (!pq_trainer.empty() && !pq_player.empty())
        {
            if (!pq_trainer.empty() && pq_trainer.top() < pq_player.top())
                pq_trainer.pop();
            else
            {
                pq_player.pop();
                pq_trainer.pop();
                match++;
            }
        }
        return match;
    }
};
