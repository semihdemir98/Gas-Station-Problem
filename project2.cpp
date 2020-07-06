// Proje 2
// Semih Demir
//18120205005

#include "bruteforce.h"
#include "greedy.h"
#include "dynamic.h"
#include "time.h"

int main()
{
    vector <int> costs;
    vector <int> mlist_temp = {1,2,3,4,5,6,7,8,9,10};
    vector <int> stop = {0};
    int begin , finish , point , count;
    vector<int> mList = {10, 40, 50, 80, 100, 140, 158, 215, 270, 300}; // benzinliklerin baslangic noktasina uzakliklari
    vector<int> pList = {6, 8, 4, 3, 7, 9, 10, 5, 2, 1};                // benzinliklerdeki depo benzin fiyati
    const int Limit = 15;                                               // refillden sonraki minimum gitmesi gereken km
    const int F = 80;                                                   // 1 depo benzin ile maks yol
    const int distance = 350;                                           // toplam yol uzunlugu


    clock_t start, end; 
  
    /* Recording the starting clock tick.*/
    start = clock(); 
  
    cout << "brute cozum benzin fiyati = " << brute_solve(mList, pList, Limit, F, mlist_temp, 0, mList.size(), 0, 9, stop, costs) << endl; 
    cout << "greedy cozum benzin fiyati = " << greedy_solve(mList, pList, Limit, F, distance) << endl; 
    cout << "dinamik cozum benzin fiyati = " << dynamic_solve(mList, pList, Limit, F, distance) << endl;
    // Recording the end clock tick. 
    end = clock(); 
  
    // Calculating total time taken by the program. 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken; 
    cout << " sec " << endl; 
    return 0;
}