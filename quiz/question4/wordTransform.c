#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

#define DICTIONARY "dictionaries/small"

typedef struct Node
{
    char word[LENGTH + 1];
    struct Node *next;
}
Node;

void printWordTranformation(char *source,char *target);
Node* getWordTranformation(char *source,char *target);
void freeMemory(Node* head);

int main(int argc, char** argv){
    char *source = "DAMP";
    char *target = "LIKE";
    printWordTranformation(source,target);
    return 0;
}

void printWordTranformation(char *source,char *target){
    Node* head = getWordTranformation(source,target);
    if(head){
        Node* node = head;
        printf("\n");
        while(node->next){
            printf("%s -> ",node->word);
            node = node->next;
        }
        printf("%s\n",node->word);
        freeMemory(head);
    }else{
        printf("\n Not Possible \n");
    }

}

Node* getWordTranformation(char *source,char *target){
    
    load(DICTIONARY);

    Node* head;
    
    // TODO
    if(check(source) && check(target)){
        head = (Node*) malloc(sizeof(Node));
        strcpy(head->word,source);

        Node* node = (Node*) malloc(sizeof(Node));
        strcpy(node->word,target);
        
        head-> next = node;
    }

    return head;
}

void freeMemory(Node* head){
    Node* node = head;
    while(node){
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}