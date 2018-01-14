#include<stdio.h>

void main(){
	int *p,a[4]={1,2,4,6};
	p=a;
	printf("%u\n",p);
	printf("%u\n",a);
	/* a=&p;
	printf("%u\n",p);
	printf("%u\n",a); */
	
}