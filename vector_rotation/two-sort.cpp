#include "two-sort.h"
#include <iostream>

int Sort::sort(vector<int> input, int start, int end, int value) {
    if(start > end)
        return -1;
    int mid = start + (end-start)/2;
    if(input[mid] < value)
        return sort(input, mid+1, end, value);
    else if (input[mid] > value)
        return sort(input, start, mid-1, value);
    else 
        return mid;
}

