#include<stdio.h>
#include<stdlib.h>
void matrix(int *row,int *col,int ***a){
	printf("Nhap vao so hang:");
	scanf("%d",row);
	printf("Nhap vao so cot :");
	scanf("%d",col);
	*a=(int **)malloc(*row*sizeof(int*));
	for(int i=0;i<*row;i++){
		(*a)[i]=(int *)malloc(*col*sizeof(int));
	}
	for(int i=0;i<*row;i++){
		for(int j=0;j<*col;j++){
			printf("Nhap vao phan tu o hang %d cot %d :",i+1,j+1);
			scanf("%d",&(*a)[i][j]);
		}
	}
}

int main(){
	int **a;
	int row,col;
	matrix(&row,&col,&a);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<row;i++){
		free(a[i]);
	}
	free(a);
}