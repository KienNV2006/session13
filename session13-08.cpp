#include<stdio.h>

int ucln(int a,int b){
	int r;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	int a=100,b=120,c=150;
	int temp=ucln(a,b);
	printf("Uoc chung lon nhat cua 3 so la :%d",ucln(temp,c));
}