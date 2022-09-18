// 6184. 统计共同度过的日子数
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        int m_alice_arrive = atoi(arriveAlice.substr(0, 2).c_str()), d_alice_arrive = atoi(arriveAlice.substr(3, 2).c_str());
        int m_alice_leave = atoi(leaveAlice.substr(0, 2).c_str()), d_alice_leave = atoi(leaveAlice.substr(3, 2).c_str());

        int m_bob_arrive = atoi(arriveBob.substr(0, 2).c_str()), d_bob_arrive = atoi(arriveBob.substr(3, 2).c_str());
        int m_bob_leave = atoi(leaveBob.substr(0, 2).c_str()), d_bob_leave = atoi(leaveBob.substr(3, 2).c_str());

        cout << m_alice_arrive << " " << d_alice_arrive << " "
             << m_alice_leave << " " << d_alice_leave << " "
             << m_bob_arrive << " " << d_bob_arrive << " "
             << m_bob_leave << " " << d_bob_leave << endl;
        int start_alice = accumulate(month.begin(), month.begin() + m_alice_arrive - 1, 0) + d_alice_arrive;
        int end_alice = accumulate(month.begin(), month.begin() + m_alice_leave - 1, 0) + d_alice_leave;

        int start_bob = accumulate(month.begin(), month.begin() + m_bob_arrive - 1, 0) + d_bob_arrive;
        int end_bob = accumulate(month.begin(), month.begin() + m_bob_leave - 1, 0) + d_bob_leave;
        cout << start_alice << " " << end_alice << " "
             << start_bob << " " << end_bob << endl;
        int set_begin = max(start_bob, start_alice);
        int set_end = min(end_bob, end_alice);
        return (set_end - set_begin) < 0 ? 0 : set_end - set_begin + 1;
    }
};
