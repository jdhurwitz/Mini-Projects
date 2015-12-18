#include <stdio.h>
#include <string.h>
#include <iostream>


using namespace std;

int NUMPRINTS = 0;

//swap pointers
void swap(char *a, char* b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void findPermutations(char *first, int begin, int end){
    //Base case is when all letters are fixed
    if(begin == end){
        cout<<first<<endl;
        NUMPRINTS++;
    }
    else{
        //Call swap function on each subset
        for(int i = begin; i<=end; i++){
            swap(first+begin, first+i);
            findPermutations(first, begin+1, end);
            swap(first+begin, first+i);
        }
    }
}

int main(){
    char s[] = "Hello";
    int len = strlen(s);
    findPermutations(s, 0, len-1);
    cout<<NUMPRINTS<<endl;
    return 0;
}
