// 2013. 检测正方形

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
//嵌套哈希表
class DetectSquares
{
public:
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        mp_yCoordinate[point[1]][point[0]]++; // some cooridinate y: x: nums
    }

    int count(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        int ans = 0;
        for (auto &[x_in_Map, nums] : mp_yCoordinate[y])
        {
            int len = fabs(x - x_in_Map);
            if (len == 0)
                continue;
            if (mp_yCoordinate.count(y - len)) // there been y
            {
                ans += nums * mp_yCoordinate[y - len][x] * mp_yCoordinate[y - len][x_in_Map]; // below point; take left for example: ((x-len,y)'s nums in left of point)*((x-len,y-len)'s num)*((x,y-len)'s num)
            }
            if (mp_yCoordinate.count(y + len))
            {
                ans += nums * mp_yCoordinate[y + len][x] * mp_yCoordinate[y + len][x_in_Map];
            }
        }
        return ans;
    }

private:
    multiset<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> mlst;
    multiset<pair<int, int>> point_mlst;
    int point_mlst_size;
    unordered_map<int, unordered_map<int, int>> mp_yCoordinate;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */