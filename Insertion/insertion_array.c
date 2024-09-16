#include<stdio.h>

int display(int array[],int size,int index,int number,int capacity ){

    for(int i=0;i<=size-1;i++){
        printf("%d ",array[i]); 
    }
    printf("\n");
    return 0;
}

int insert(int array[],int size,int index,int number,int capacity){
    
    for(int i=size-1;i>=index;i--){
        array[i+1] = array[i];
    }
    array[index] = number;
    return 1;
}


int main(){

    // inserting a element in an array
    int arr[100] = {2,4,5,6,50};
    int size = 5;
    int index = 1;
    int number = 3;

    display(arr,size,index,number,100);
    insert(arr,size,index,number,100);
    size+=1;
    display(arr,size,index,number,100);

    return 0;
}