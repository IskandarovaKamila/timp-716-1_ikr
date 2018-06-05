#include <stdio.h>
#include <stdlib.h>

void siftDown(int arr[], int nach, int vybran){
    int max=0,done=0;
    while ((nach*2<=vybran) && (!done)){
        if (nach*2==vybran)
            max=nach*2;
        else if (arr[nach*2]>arr[nach*2+1])max=nach*2;
             else max=nach*2+1;
            if (arr[nach]<arr[max]){
                int temp=arr[nach];
                arr[nach]=arr[max];
                arr[max]=temp;
                nach=max;
            }
            else done=1;
    }
}

void sort(int arr[], int size){
    int temp=0;
    for(int i=(size/2)-1; i>=0; i--) siftDown(arr,i,size);
    for(int i=size-1; i>0; i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        siftDown(arr,0,i-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
