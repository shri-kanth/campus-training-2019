#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* getSubArrayIndices(int l[],int sizeOfL,int s[],int sizeOfS);

int main(int argc, char **argv){
    int longArray[] = {2,5,0,0,2,9,3,0,7,1,1,1,-1,8,1,5,0};
    int shortArray[] = {1, 5, 9};
    int* answer = getSubArrayIndices(longArray,17,shortArray,3);
    if(answer){
        int* cursor = answer;
        while(*cursor >= 0){
            printf(" %d ",*cursor);
            cursor++;
        }
        free(answer);
        printf("\n");
    }else{
        printf("\n NOT POSSIBLE \n");
    }
}

int* getSubArrayIndices(int l[],int sizeOfL,int s[],int sizeOfS){
    
    int* answer = NULL;
    int closestLocation[sizeOfS][sizeOfL];

    int closureIndex[sizeOfL];

    // Find Closest Locations
    for(int i = 0; i < sizeOfS; ++i){
        closestLocation[i][sizeOfL-1] = -1;
        for(int j = sizeOfL-1; j >= 0; --j){
            if(l[j] == s[i]){
                closestLocation[i][j] = j;
            }else if(j+1 < sizeOfL){
                closestLocation[i][j] = closestLocation[i][j+1];
            }
        }
    }
    
/*
    for(int i = 0; i < sizeOfS; ++i){
        for(int j = 0; j < sizeOfL; ++j){
            printf(" %2d  ", closestLocation[i][j]);
        }
        printf("\n");
    }
*/

    // Find Closure Index
    for(int i = 0; i < sizeOfL; ++i){
        int max = INT_MIN;
        for(int j = 0; j < sizeOfS; ++j){
            if(closestLocation[j][i] == -1){
                max = closestLocation[j][i];
                break;
            }else if(max < closestLocation[j][i]){
                max = closestLocation[j][i];
            }
        }
        closureIndex[i] = max;
    }

 
/*
    for(int j = 0; j < sizeOfL; ++j){
        printf(" %2d  ", closureIndex[j]);
    }
    printf("\n");
*/

    int min = INT_MAX;
    int bestStart = -1;

    // Find minimum size array
    for(int i = 0; i < sizeOfL; ++i){
        if( closureIndex[i] >= 0 && min >= (closureIndex[i]-i)){
            min = closureIndex[i]-i;
            bestStart = i;
        }
    }

    if(bestStart >= 0){
        answer =(int *) malloc(3*sizeof(int));
        int* cursor = answer;
        *cursor = bestStart;
        cursor++;
        *cursor = closureIndex[bestStart];
        cursor++;
        *cursor = -1;
        return answer;
    }

    return answer;
}
