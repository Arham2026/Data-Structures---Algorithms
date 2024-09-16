#include<stdio.h>

// linear search 
int linearSearch(int arr[],int size,int number){

    for(int i=0;i<=size-1;i++){
            
        if(arr[i]== number){
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[],int size,int number){
    int mid,high,low;
    low = 0;
    high = size-1;

    while(low<=high){
        mid = (low+high)/2;
    if(arr[mid] == number){
        return mid;
    }

    else if(arr[mid]<number){
        low = mid + 1;
    }

    else if(arr[mid]>number){
        high = mid-1;
    }
}  
    
    return -1;
}

int main(){
    
    int arr[] = {3,44,55,67,98,99};
    int number,size;
    size = sizeof(arr)/sizeof(int);
    scanf("%d",&number);
    int answer = linearSearch(arr,size,number);
    printf("The index of the %d will be %d ",number,answer);

    return 0;
}