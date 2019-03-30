/*
 
**Campus Training 2019 Quiz Question 3 Solution**

**Author** : Koraveni Srikanth

**Problem Statement**

A 'majority element' is an element that makes up half or more than half of the items in an array. 
Write a C function which takes a positive integer array as argument and returns the majority element.
If there is no majority element return -1. 
Do this in O(N) time complexity and O(1) space complexity. 
Example : Input : {1,2,5,9,5,9,5,5,5}
OutPut : 5

*/

#include <stdio.h>

int getMajorityElement(int a[], int sizeA);
int getMajorityElementCandidate(int a[], int sizeA);
int isValidMajorityElement(int a[], int sizeA, int candidate);

int main(int argc, char **argv)
{

    // Input array for Testing
    int a[14] = {1, 2, 23, 9, 23, 9, 23, 23, 23, 0, 0, 23, 4, 23};

    int ans = getMajorityElement(a, 14);

    printf("\n %d \n", ans);

    return 0;
}

int getMajorityElement(int a[], int sizeA)
{
    int candidate = getMajorityElementCandidate(a, sizeA);
    return isValidMajorityElement(a, sizeA, candidate) ? candidate : -1;
}

int getMajorityElementCandidate(int a[], int sizeA)
{
    int candidate = -1;
    int count = 0;
    for (int i = 0; i < sizeA; ++i)
    {
        if (count == 0)
        {
            candidate = a[i];
        }
        if (a[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int isValidMajorityElement(int a[], int sizeA, int candidate)
{
    int count = 0;
    for (int i = 0; i < sizeA; ++i)
    {
        if (a[i] == candidate)
        {
            count++;
        }
    }
    return (2 * count) >= (sizeA);
}
