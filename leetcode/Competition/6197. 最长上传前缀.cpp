
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
class LUPrefix
{
public:
    LUPrefix(int n)
    {
        loaded.resize(n, 0);
        this->n = n;
        this->max_len = 0;
    }

    void upload(int video)
    {
        loaded[video - 1] = 1;
    }
    int longest()
    {
        for (int i = max_len; i < n; i++)
        {
            if (loaded[i] == 1)
                max_len++;
            else
                break;
        }
        return max_len;
    }

private:
    vector<bool> loaded;
    int n;
    int max_len;
};