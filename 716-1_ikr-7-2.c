#include <stdio.h>
#include <stdlib.h>

void ShellSort(int n,int mass[]){
        int i,j,step,tmp;
        for(step=n/2;step>0;step/=2){
                for(i=step;i<n;i++){
                        tmp=mass[i];
                        for(j=i;j>=step;j-=step){
                                if(tmp<mass[j-step])mass[j]=mass[j-step];
                                else break;
                        }
                        mass[j]=tmp;
                }
        }
}

int main(){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){scanf("%d",&arr[i]);}
        ShellSort(n,arr);

        for(int i=0;i<n;i++){printf("%d  ",arr[i]);}
        printf("\n");
        return 0;
}
