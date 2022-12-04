#include<stdio.h>

//int count = 0;
//calling itself -> break 

void printName(int count){//1  2  3 4 
    
    printf("\nRoyal");//1  2  3  4 
    count++;//2 3 4 5 
    if(count != 5){
        printName(count);//2 3  4 
    }  

}
void printNum(int count){//5
   
    if(count != 1){ 
        printNum(--count);//4
    }
    printf(" %d",count);//5 
}


int fact(int num){ //5 4 

    if(num == 1){
        return 1;
    }
    return num*fact(num-1); // return 5 * 4 * 3 * 2 * 1;
}

/*
   5
        4
                   3
                        2
                              1      
*/
 
 void divide(int a[],int low,int up){//0 7   4 7 
    if(low < up){ 
        int mid = (low + up ) / 2; //  3 
        divide(a,low,mid); //a 0 3 
        divide(a,mid+1,up);//a 4 7 
    }
 }
 
int main(){
    // printName(0);
    //printNum(5);
    int a[]={11,22,1,33,4,29,6,8};
    divide(a,0,7);
    printf("\n%d",fact(5)); //==>120 
    return 0;
}



//printNum(5);

//5 4 3 2 1 

//1 2 3 4 5 

