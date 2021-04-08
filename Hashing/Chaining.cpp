#include "Chains.h"
#include<iostream>
using namespace std;

int hash1(int key){
    return key%10;
}

void Insert(struct Node *H[],int key){

    int index = hash1(key);
    SortedInsert(&H[index],key);
}
int main(){

    struct Node *HT[10];
    struct Node *temp;
    int i;

    for(int i=0;i<10;i++){
        HT[i]=NULL;
    }

    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);

    temp = Search(HT[hash1(22)],22);

    cout<<temp->data;

    return 0;
}