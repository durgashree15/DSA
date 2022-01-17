#include<stdio.h>
int stack1[20],stack2[20],n;
int top1=-1,top2=-1;
int isfull(){
	if(top1==n-1) return 1;
	else return 0;
}
void push(int x){
	int j=0,k=0;
	if (!isfull()){
		while(j<=top1){
			if (stack1[j]==x){
				stack2[++top2]=x;
				k+=1;
				break;
			}
			j++;
		}
		if(k==0) stack1[++top1]=x;
	}
}
void pop(int y){
	int ind;
	for(int j=0;j<=top1;j++){
		if (stack1[j]==y){
			ind=j;
			break;
		}
		
	}
	for(int l=ind;l<top1;l++){
		stack1[l]=stack1[l+1];
	}
	top1--;
}

int main(){
	printf("No. of elements:");
	scanf("%d",&n);
	int p;
	for(int i=0;i<n;i++){
		printf("Element:");
		scanf("%d",&p);
		push(p);
	}
	p=0;
	while(p<=top2){
		pop(stack2[p]);
		p++;
	}
	printf("Non-duplicate elements:\n");
	for(int i=0;i<=top1;i++){
		printf("%d\n",stack1[i]);
	}
		
}

