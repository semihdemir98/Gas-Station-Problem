//dynamic.h
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int dynamic_solve(vector<int> &mlist, vector<int> &plist, int k, int f, int distance)
{

#define NMAX 50000
    struct station
    {
        int pos, cost;
    };
    station stations[NMAX];

    int s[NMAX];
    int nextSmall[NMAX];

    int n = mlist.size(), maxGas = f, curGas = f, dist = distance;

    for (int i = 0; i < n; i++)
    {
        stations[i].pos = mlist[i];
        stations[i].cost = plist[i];
    }

    // find next cheaper station for each station
    int stacklen = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (stacklen > 0 && stations[s[stacklen - 1]].cost >= stations[i].cost)
        {
            stacklen--;
        }
        nextSmall[i] = (stacklen == 0 ? -1 : s[stacklen - 1]);
        s[stacklen] = i;
        stacklen++;
    }

    curGas -= stations[0].pos; // move to station 1
    long long cost = 0;
    for (int i = 0; i < n; i++)
    {
        // gas is less than 0 means it is impossible to reach the station
        if (curGas < 0)
        {
            printf("-1\n");
            return 0;
        }
        int gasNeeded = min(maxGas, (nextSmall[i] == -1 ? dist : stations[nextSmall[i]].pos) - stations[i].pos);
        if (gasNeeded > curGas)
        {
            cost += (long long)stations[i].cost;
            curGas = gasNeeded;
        }
        curGas -= (i == n - 1 ? dist : stations[i + 1].pos) - stations[i].pos;
    }

    if (curGas < 0)
    {
        printf("-1\n");
    }
    else
    {
        /* printf("%lld\n", cost); */
    }
}