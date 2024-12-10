#include<stdio.h>
#include<stdlib.h>
void Enter_array(int *n,int**a){
	printf("Nhap vao so luong phan tu :");
	scanf("%d",n);
	*a=(int *)malloc(*n*sizeof(int));
	for(int i=0;i<*n;i++){
		printf("Nhap vao phan tu thu %d :",i+1);
		scanf("%d",&(*a)[i]);
	}
}

void Print_array(int n,int *a){
	printf("In ra mang dang quan ly :\n");
	for(int i=0;i<n;i++){
		printf("%3d",a[i]);
	}
	printf("\n");
}
void Add_element(int *n,int *a){
	printf("Nhap vao vi tri muon them (0-%d):",*n+1);
	int pos;
	scanf("%d",&pos);
	if(pos==0){
		pos=1;
	}
	if(pos<1||pos>*n+1){
		printf("Vi tri khong hop le !\n");
		return;
	}
	printf("Nhap vao gia tri :");
	int value;
	scanf("%d",&value);
	for(int i=*n;i>=pos;i--){
		a[i]=a[i-1];
	}
	a[pos-1]=value;
	*n+=1;
	printf("Them phan tu thanh cong!\n");
}
void Fix_element(int n,int *a){
	printf("Nhap vao vi tri muon sua (1-%d) :",n);
	int pos;
	scanf("%d",&pos);
	if(pos<1||pos>n){
		printf("Vi tri khong hop le!\n");
		return;
	}
	printf("Nhap vao gia tri muon sua :");
	int value;
	scanf("%d",&value);
	a[pos-1]=value;
	printf("Sua phan tu thanh cong!\n");
}
void Delete_element(int *n,int *a){
	printf("Nhap vao vi tri muon xoa (1-%d):",*n);
	int pos;
	scanf("%d",&pos);
	if(pos==0){
		pos=1;
	}
	if(pos<1||pos>*n){
		printf("Vi tri khong hop le !\n");
		return;
	}
	for(int i=pos-1;i<*n;i++){
		a[i]=a[i+1];
	}
	*n-=1;
	printf("Delete elements successfull!\n");
}
void Arrange_elements(int n,int *a){
	printf("a.Sap xep giam dan\n");
	printf("b.Sap xep tang dan\n");
	char option;
	do{
		printf("Nhap vao lua chon a hoac b :");
		scanf(" %c",&option);	
	}while(option!='a'&&option!='b');
	if(option=='a'){
		printf("Dang sap xep giam dan... \n");
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]<a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	if(option=='b'){
		printf("Dang sap xep tang dan...\n");
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	printf("Sap xep thanh cong!\n");
}
void Search_element(int n,int *a){
	int is_descending=1;
	int is_ascending =1;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			is_ascending=0;
		}
		if(a[i]<a[i+1]){
			is_descending=0;
		}
	}
	if(is_ascending==1){
		printf("Mang duoc sap xep tang dan.\n");
	}
	else if(is_descending==1){
		printf("Mang duoc sap xep giam dan.\n");
	}
	else{
		printf("Mang chua duoc sap xep.\n");
	}
	printf("Nhap phan tu muon tim :");
	int number;
	int pos=-1;
	scanf("%d",&number);
	if(is_ascending==1){
		int l=0;
		int r=n-1;
		while(l<=r){
			int m=(l+r)/2;
			if(a[m]==number){
				pos=m;
				break;
			}
			else if(a[m]<number){
				l=m+1;
			}
			else{
				r=m-1;
			}
		}
	}
	else if(is_descending==1){
		int l=0;
		int r=n-1;
		while(l<=r){
			int m=(l+r)/2;
			if(a[m]==number){
				pos=m;
				break;
			}
			else if(a[m]<number){
				r=m-1;
			}
			else{
				l=m+1;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i]==number){
				pos=i;
				break;
			}
		}	
	}
	if(pos==-1){
		printf("Phan tu khong duoc tim thay !\n");
	}
	else{
		printf("Phan tu %d o vi tri %d.\n",number,pos);
	}
}



int main(){
	int *a;
	int n=0;
	do{
		printf("1.Nhap mang.\n");
		printf("2.In ra mang.\n");
		printf("3.Them phan tu.\n");
		printf("4.Sua phan tu.\n");
		printf("5.Xoa phan tu.\n");
		printf("6.Sap xep mang.\n");
		printf("7.Tim kiem mot phan tu.\n");
		printf("8.Thoat.\n");
		int choice;
		printf("Nhap lua chon cua ban :");
		scanf("%d",&choice);
		if(choice==1){
			Enter_array(&n,&a);
		}
		else if(choice==2){
			Print_array(n,a);	
		}
		else if(choice==3){
			Add_element(&n,a);	
		}
		else if(choice==4){
			Fix_element(n,a);	
		}
		else if(choice==5){
			Delete_element(&n,a);		
		}
		else if(choice==6){
			Arrange_elements(n,a);
		}
		else if(choice==7){
			Search_element(n,a);
		}
		else if(choice==8){
			return 0;
		}
		else {
			printf("Lua chon khong hop le !\n");
		}
	}while(true);
	free(a);
}