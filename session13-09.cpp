#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int prime_is(int n){
	if(n<2){
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void enter_matrix(int *n,int *m,int ***a){
	printf("Nhap n:");
	scanf("%d",n);
	printf("Nhap m:");
	scanf("%d",m);
	*a=(int **)malloc((*n)*sizeof(int *));
	for(int i=0;i<*n;i++){
		(*a)[i]=(int*)malloc(*m*sizeof(int));
	}
	for(int i=0;i<*n;i++){
		for(int j=0;j<*m;j++){
			printf("Nhap phan tu tai hang thu %d cot thu %d:",i+1,j+1);
			scanf("%d",&(*a)[i][j]);
		}
	}
}
void print_matrix(int n,int m,int **a){
	printf("In ra cac phan tu trong ma tran :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}
void elements_at_the_corner_of_matrix(int n,int m,int**a){
	printf("In ra cac phan tu o goc theo ma tran :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0||i==0&&j==m-1||j==0&&i==n-1||i==n-1&&j==m-1){	
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}
		}
		printf("\n");	
	}
}
void elements_on_the_border_of_matrix(int n,int m,int **a){
	printf("In ra cac phan tu o bien ma tran :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0||j==0||i==n-1||j==m-1){
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}						
		}
		printf("\n");
	}
}

void diagonals_of_matrix(int n,int m,int **a){
	if(m!=n){
		printf("So hang va so cot khong bang nhau, vui long nhap ma tran vuong!");
		return;
	}
	printf("In ra duong cheo chinh cua ma tran :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j==i){
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}						
		}
		printf("\n");
	}
	printf("In ra duong cheo phu cua ma tran :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j==n-i-1){
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}						
		}
		printf("\n");
	}
}
void print_prime_number_in_the_matrix(int n,int m,int **a){
	printf("In ra cac phan tu la so nguyen to trong ma tran :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(prime_is(a[i][j])==1){
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}						
		}
		printf("\n");
	}
}
int main() {
	int **a;
	int n,m;
	do{
		printf("1.Nhap n va m.\n");
		printf("2.In ra ma tran.\n");
		printf("3.In ra cac phan tu o goc theo ma tran.\n");
		printf("4.In ra cac phan tu o bien ma tran.\n");
		printf("5.In ra duong cheo chinh cua ma tran.\n");
		printf("6.In ra duong cheo phu cua ma tran.\n");
		printf("7.Thoat.\n");
		int choice;
		printf("Nhap lua chon cua ban :");
		scanf("%d",&choice);
		if(choice==1){
			enter_matrix(&n,&m,&a);
		}
		else if(choice==2){
			print_matrix(n,m,a);	
		}
		else if(choice==3){
			elements_at_the_corner_of_matrix(n,m,a);	
		}
		else if(choice==4){
			elements_on_the_border_of_matrix(n,m,a);	
		}
		else if(choice==5){
			diagonals_of_matrix(n,m,a);	
		}
		else if(choice==6){
			print_prime_number_in_the_matrix(n,m,a);
		}
		else if(choice==7){
			printf("Thoat.");
			return 0;
		}
		else {
			printf("Lua chon khong hop le !\n");
		}
	}while(true);
	for(int i=0;i<n;i++){
		free(a[i]);
	}
	free(a);
}


