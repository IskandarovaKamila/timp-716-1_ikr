#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n, i=1,x,summ=0;
	scanf("%d",&n);
	while(i<=n){
		scanf("%d",&x);
		summ=summ+((i+1) % 2)*pow(x,3);
		i++;
}
	printf("\n%d\n",summ);
	return 0;
}

