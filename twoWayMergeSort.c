#include<stdio.h>
 
int a [] ={1,99,88,77,55,66};


void merge(int a[],int l,int m,int u) // a 0 0 1
{  
     int i=0,j=0,k=0;
    int SIZE =  m - l + 1   ; //  1 
    int SIZE2 = u - m ;      //   1 

    while (i < SIZE && j < SIZE2)
    {
        if (a[i] > a[j])
        {
            a[k++] = a[j++];
        }
        else
        {
            a[k++] = a[i++]; // a[0] = a[0]; 
        }
    }
    if (i < SIZE)
    {
        while (i < SIZE)
        {
            a[k++] = a[i++];
        }
    }
    else if (j < SIZE2)
    {

        while (j < SIZE2)
        {
            a[k++] =a[j++]; // a[0] = a[0] 
        }
    }
}

void divide(int a[],int l,int u){ //a 0 1 3  
    
    //a -> X 
    //a -> X 

    
    //l = 0
    //u = 1
    // m = 0
    int mid = (l+u)/2; // 10 
    if(l < u){ 
        divide(a,l,mid);// 0,2 [0,1][2,2] 
        divide(a,mid+1,u);//3,5   
        merge(a,l,mid,u);
    }
}

void sort(){
    divide(a,0,SIZE-1);// 0 7 
}



int main()
{
    
    return 0;
}
