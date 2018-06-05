#include<stdio.h>
int main() 
{
	int n, i=0,a,y=1;
	scanf("%d",&n);
	while(y<=n){
		scanf("%d",&a);
		if(a<=0)i++;
		y++;
	}
	printf("\n%d\n",i);
	return 0;
}

