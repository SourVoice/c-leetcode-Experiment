// 929. 独特的电子邮件地址
#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> s;
        for (auto &email : emails)
        {
            string local = email.substr(0, email.find('@'));
            string domain = email.substr(email.find('@') + 1);
            if (find(local.begin(), local.end(), '+') != local.end())
                local = local.substr(0, local.find('+'));
            local.erase(remove(local.begin(), local.end(), '.'), local.end());
            string newEmail = local + '@' + domain;
            if (s.count(newEmail) == 0)
                s.insert(newEmail);
        }
        return s.size();
    }
};