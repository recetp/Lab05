//
// Created by awonu on 2/19/2024.
//
#include <iostream>
#include <chrono>
#include "StringData.h"

using namespace std;

int binarySearch(string element, vector<string> data){
    int start = 0, mid = 0, end = data.size();
    while(end >= start)
    {
        mid = (start + end)/2;
        if(data[mid] > element) end = mid - 1;
        else if (data[mid] < element) start = mid + 1;
        else return mid;
    }
    return -1;

}

int linearSearch(vector<string> data, string element)
{
    for(int i = 0; i < data.size(); i ++)
    {
        if(data[i] == element)
            return i;
    }
    return -1;
}

long long* runTime(string searchTerm, vector<string> data)
{
    long long* times = new long long[3];
    long long nowTime = systemTimeNanoseconds();
    int index = binarySearch(searchTerm, data);
    long long endTime = systemTimeNanoseconds();
    *times = endTime - nowTime;

    nowTime = systemTimeNanoseconds();
    index = linearSearch(data, searchTerm);
    endTime = systemTimeNanoseconds();
    times ++;
    *times = endTime - nowTime;
    times ++;
    *times = index;
    times -= 2;

    return times;



}
int main() {
    vector<string> data = getStringData();
    long long* arrPtr = runTime("not_here", data);
    printf("Binary Search: %ld Linear Search: %ld Index: %d\n", *arrPtr, *(arrPtr + 1), (*(arrPtr +2)));
    arrPtr = runTime("mzzzz", data);
    printf("Binary Search: %ld Linear Search: %ld Index: %d\n", *arrPtr, *(arrPtr + 1), (*(arrPtr +2)));
    arrPtr = runTime("aaaaa", data);
    printf("Binary Search: %ld Linear Search: %ld Index: %d\n", *arrPtr, *(arrPtr + 1), (*(arrPtr +2)));

    delete[] arrPtr;
    return 0;
}
