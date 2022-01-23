#include <set>
#include <unordered_map>

using namespace std;
class StockPrice
{
public:
    unordered_map<int, int> timePrice_mp;
    multiset<int> prices;
    int maxTimeStamp;
    StockPrice()
    {
        this->maxTimeStamp = 0;
    }

    void update(int timestamp, int price)
    {
        maxTimeStamp = max(timestamp, maxTimeStamp);
        int prevPrice = timePrice_mp.count(timestamp) ? timePrice_mp[timestamp] : 0; //先前存在相同时间截
        if (prevPrice > 0)
        {
            auto temp = prices.find(prevPrice);
            if (temp != prices.end())
                prices.erase(temp); //去掉前一条
        }
        // 更新
        timePrice_mp[timestamp] = price;
        prices.emplace(price);
    }

    int current()
    {
        return timePrice_mp[maxTimeStamp];
    }

    int maximum()
    {
        return *prices.rbegin();
    }

    int minimum()
    {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */