#include <stdio.h>
#include <stdlib.h>

int* getSubArrayIndices(int l[],int sizeOfL,int s[],int sizeOfS);

int main(int argc, char **argv){
    int longArray[] = {2,5,0,0,2,0,3,-1,7,1,1,1,-1,8,0,4,5};
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

    // Choose size of search array
    for(int i = sizeOfS; i <= sizeOfL; ++i){
        
        // Choose start index of search array
        for(int j = 0; i+j <= (sizeOfL); ++j){

            int foundAnswer = 1;
            
            // Search for every element in short array
            for(int x = 0; x < sizeOfS; ++x){
                int found = 0;
                
                // Searching in the selected subArray
                for(int k = j; k < i+j; ++k){
                    if(s[x] == l[k]){
                        found = 1;
                        break;
                    }
                } 

                // One of the elelment not found move to next sub array selection
                if(!found){
                    foundAnswer = 0;
                    break;
                }
            }

            if(foundAnswer){
                answer =(int *) malloc(3*sizeof(int));
                int* cursor = answer;
                *cursor = j;
                cursor++;
                *cursor = i+j-1;
                cursor++;
                *cursor = -1;
                return answer;
            }

        }
    }

    return answer;
}
