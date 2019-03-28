/*
 
**Campus Training 2019 Quiz Question 2 Solution**

**Author** : Koraveni Srikanth

**Problem Statement**

Write a c function, which takes two integer arrays as arguments. 
From these two arrays find a pair of values (one from each array) that you can swap to give the two arrays the same sum. 
Print these two values separated by a comma to output on a new line. 
If no such pair exists print "Not Possible". 
(You could have more than one valid pair for given input, in such cases printing any one valid pair is acceptable) 
Example : Input : {4,1,2,1,1,2} and {3,6,3,3}
OutPut : {1,3}

*/

#include <stdio.h>
#include <stdlib.h>

void findSameSumPair(int a[], int sizeA, int b[], int sizeB);

int main(int argc, char **argv)
{

    // Input arrays
    int a[6] = {4, 1, 2, 1, 1, 2};
    int b[4] = {3, 6, 3, 3};

    findSameSumPair(a, 6, b, 4);

    return 0;
}

void findSameSumPair(int a[], int sizeA, int b[], int sizeB)
{
    int sumA = 0, sumB = 0;

    for (int i = 0; i < sizeA; ++i)
    {
        sumA += a[i];
    }

    for (int i = 0; i < sizeB; ++i)
    {
        sumB += b[i];
    }

    int totalSum = sumA + sumB;

    if (totalSum % 2 == 1)
    {
        printf("\n NOT POSSIBLE \n");
    }

    int finalSum = totalSum / 2;

    // use hashmap (O(m+n)) or
    // binary search after soting (O(m+n)logm)
    // to reduce computational complexity.
    for (int i = 0; i < sizeA; ++i)
    {
        int y = a[i] + finalSum - sumA;
        for (int j = 0; j < sizeB; ++j)
        {
            if (b[j] == y)
            {
                printf("\n Solution : %d %d \n", a[i], b[j]);
                return;
            }
        }
    }

    printf("\n NOT POSSIBLE \n");
}
