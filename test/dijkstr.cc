#include <iostream>
#include <vector>
using namespace std;

// ## 参考文章
// * http://baike.baidu.com/view/1712262.htm?fromtitle=Dtra%E7%AE%97%E6%B3%95&fromid=215612&type=syn#2
// * http://blog.csdn.net/jnu_simba/article/details/8866705

// # 算法步骤
// * S: 最短路径集合，一个顶点属于集合S当且仅当从源到该顶点的最短路径长度已知。
// * G: 所有顶点
// * G-S: 未处理的顶点
// * d[i]: 从源点到顶点i的相对最短路径
// * 初始化: 设置源点，按有向图初始化源点到各个顶点的距离，将源点添加到S中
// * 贪心: 每次循环取出d中距离源点最小的顶点，将其添加到S中
// * 迭代：设u是S中最短路径顶点集合的末端，更新d中的相对最短路径
// * 结束：S = G
// ps: 所谓相对最短路径，就是指相对于u而言

// 最简单的实现方式，时间复杂度O(V^2)
void Dijkstra()
{
    // 顶点数
    const int n = 5;
    // 源点
    const int start = 0;
    // 邻接矩阵
    //定义有向图
    int map[][n] = {                     
        {0, 6, INT_MAX, INT_MAX, 3},
        {INT_MAX, 0, 1, INT_MAX, 2},
        {INT_MAX, INT_MAX, 0, 4, INT_MAX},
        {9, INT_MAX, INT_MAX, 0, 8},
        {INT_MAX, INT_MAX, 5, INT_MAX, 0}
    };
    // 源点到各顶点的相对最短路径
    int d[n];
    // 已找到的最短路径集合
    int S[n];
    // 标志是否在S中
    vector<bool> isInS(n, false);
    
    // 根据有向图初始化
    for(int i = 0; i < n; ++i)
    {
        d[i] = map[start][i];
    }
    S[0] = start;
    isInS[start] = true;
    
    // 最短路径的末端顶点
    int u = start;
    // 循环n - 1次
    for (int i = 1; i < n; i++)
    {
        // 寻找不在S集合中距离源点最小的节点
        int td = INT_MAX;
        for(int j = 0; j < n; j++)
        {
            // cout << d[j] << " ";
            if(isInS[j] == false && d[j] < td)
            {
                u = j;
                td = d[j];
            }
        }

        // cout << endl;

        // 放入S集合中
        S[i] = u;
        isInS[u] = true;

        // 更新距离
        for (int j = 0; j < n; j++)
        {
            if (isInS[j] == false && map[u][j] < INT_MAX)
            {
                int temp = d[u] + map[u][j];
                if (temp < d[j])
                {
                    d[j] = temp;
                }
            }
        }
    }

    cout << "最短路径顶点集合：";
    for (int i = 0; i < n; ++i)
    {
        cout << S[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i)
    {
        cout << "源点" << start << "到顶点" << i << "的最短距离为：" << d[i] << endl;
    }
}


int main()
{
    Dijkstra();

    return 0;
}
