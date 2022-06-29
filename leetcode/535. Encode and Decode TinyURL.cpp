// 535. TinyURL 的加密与解密
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shorturl = "http://tinyurl.com/";
        while (1)
        {
            for (int i = 0; i < 6; i++)
            {
                shorturl += ref[rand() % (ref.size())];
            }
            if (!mp.count(shorturl))
            {
                mp[shorturl] = longUrl;
                return shorturl;
            }
        }
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return mp[shortUrl];
    }
    unordered_map<string, string> mp;
    string ref = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));