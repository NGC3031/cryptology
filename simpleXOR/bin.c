#include <stdio.h>


int bToD(int n, int base){
	int a[20],i,k, l,temp;
	for(i=0;n>0;i++){
		a[i]=n%base;
		n=n/base;
	}
        l=k-1;
    	k=0;
    	while(k<l)
    	{
        	temp=a[k];
        	a[k]=a[l];
        	a[l]=temp;
        	k++;
        	l--;
    	}
        return *a;
}

int main(){
       printf("%d", bToD(232345,2));
}
