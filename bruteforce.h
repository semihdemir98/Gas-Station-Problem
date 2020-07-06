//bruteforce.h
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int brute_solve(vector<int> &mlist, vector<int> &plist, int k, int f, vector<int>&mlist_temp, 
                int begin, int finish, int point, int count,vector<int>& stop, vector<int>&costs)
{
    int add_cost = 0;

    if(point == count){
        if(mlist_temp[0] > f){
            return 1;
        }
        for(int i=0; i<count; i++){
            add_cost += stop[i];
        }
        costs.push_back(add_cost);
    }
    for(int i=begin; count-point <= (finish-i)+1 && i<=finish; i++){
        mlist_temp[point] = mlist[i];
        stop[point] = plist[i];
        brute_solve(mlist,plist,k, f, mlist_temp, begin+1, finish,
                    point+1, count--,stop,costs);  
        if(mlist_temp[i+1] - mlist_temp[i] > f || mlist_temp[i+1] - mlist_temp[i] <= k ){
                break;
        }
        sort(costs.begin(),costs.end());
        cout << "brute cozum benzin fiyati = " << costs.front() << endl;  
    }
    return 18;
}