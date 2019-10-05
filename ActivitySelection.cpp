#include <iostream>
using namespace std;

#define NUM 50

void GreedySelector(int n, int s[], int f[], bool b[])
{
    b[1] = true;  //默认将第一个活动先安排
    int j = 1;    //记录最近一次加入b中的活动

    //依次检查活动i是否与当前已选择的活动相容
    for (int i = 2; i <= n; i++)
    {
        if (s[i] >= f[j])
        {
            b[i] = true;
            j = i;
        }
        else
            b[i] = false;
    }
}

int main()
{
    int s[] = { 0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };          //存储活动开始时间
    int f[] = { 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };      //存储活动结束时间
    bool b[NUM];  //存储被安排的活动编号
    int n = (sizeof(s) / sizeof(s[0])) - 1;

    GreedySelector(n, s, f, b);

    for (int i = 1; i <= n; i++)      //输出被安排的活动编号和它的开始时间和结束时间
    {
        if (b[i]) cout << "Activity " << i << " :" << "(" << s[i] << "," << f[i] << ")" << endl;
    }
    getchar();
    return 0;
}
