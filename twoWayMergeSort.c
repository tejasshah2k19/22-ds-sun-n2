#include<stdio.h>
#define SIZE 6 
int a [] ={1,99,88,77,55,66};


void divide(int a[],int l,int u){
    //l = 3
    //u = 5
    // m = 4
    int mid = (l+u)/2;
    if(l < u){ 
        divide(a,l,mid);//0 1 2 -> 0 1  
        divide(a,mid+1,u);//3 4 5  -> 2 3 
    }
}

void sort(){
    divide(a,0,SIZE-1);
}



int main()
{
    
    return 0;
}
