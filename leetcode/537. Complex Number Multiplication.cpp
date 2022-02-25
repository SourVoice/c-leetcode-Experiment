// 537. 复数乘法

#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        string front = num1.substr(0, num1.find('+') - 0);
        if (front.find('-') != string::npos)
        {
            real1 = -stoi(front.substr(front.find('-'), front.size()));
        }
        else
        {
            real1 = stoi(front);
        }
        string back = num1.substr(num1.find('+') + 1, num1.size());
        if (back.find('-') != string::npos)
        {
            image1 = -stoi(back.substr(back.find('-'), back.size()));
        }
        else
        {
            image1 = stoi(back);
        }
        cout << real1 << " " << image1 << endl;

        front = num2.substr(0, num2.find('+'));
        if (front.find('-') != string::npos)
        {
            real2 = -stoi(front.substr(front.find('-'), front.size()));
        }
        else
        {
            real2 = stoi(front);
        }

        back = num2.substr(num2.find('+') + 1, num2.size());
        if (back.find('-') != string::npos)
        {
            image2 = -stoi(back.substr(back.find('-'), back.size()));
        }
        else
        {
            image2 = stoi(back);
        }
        cout << real2 << " " << image2 << endl;
        int real = real1 * real2 - image1 * image2;
        int image = real1 * image2 + real2 * image1;

        return to_string(real) + "+" + to_string(image) + "i";
    }

private:
    int real1 = 0;
    int image1 = 0;

    int real2 = 0;
    int image2 = 0;
};

//占位符
class Solution2
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int real1 = 0, image1 = 0;
        int real2 = 0, image2 = 0;
        sscanf(num1.c_str(), "%d+%di", &real1, &image1);
        sscanf(num2.c_str(), "%d+%di", &real2, &image2);

        int real = real1 * real2 - image1 * image2;
        int image = real1 * image2 + real2 * image1;
        return to_string(real) + "+" + to_string(image) + "i";
    }
};