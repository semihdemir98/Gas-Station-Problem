//greedy.h
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int greedy_solve(vector<int> &mlist, vector<int> &plist, int k, int f, int distance)
{
    int curr_refil = 0;
    int limit = f;
    int n = plist.size();
    int price_refill = 0;

    while (limit < distance)
    {
        int temp = curr_refil;
        if (curr_refil >= n || mlist[curr_refil] > limit)
        {
            return -1;
        }
        while (curr_refil < n - 1 && mlist[curr_refil + 1] <= limit)
        {
            curr_refil += 1;
        }
        limit = mlist[curr_refil] + f;
        if ((mlist[curr_refil] - mlist[temp]) >= k)
        {
            price_refill += plist[curr_refil];
        }
    }
    return price_refill;
}