#include<stdio.h>
#include<stdlib.h>
struct poly1{
	int ele;
	int pow;
	struct poly1 *next;
};

struct poly2{
	int ele;
	int pow;
	struct poly2 *next;
};

struct poly3{
	int ele;
	int pow;
	struct poly3 *next;
};

struct poly1 *head1=NULL, *ptr1, *temp1, *traverse1;
struct poly2 *head2=NULL, *ptr2, *temp2, *traverse2;
struct poly3 *head3=NULL, *ptr3, *temp3, *traverse3, *check;

int insert(int p){
	int d;
	if(p==1){
		printf("Insert data for first polynomial!\n");
		printf("Enter the order of the polynomial:");
		scanf("%d",&d);
		for(int i=d;i>-1;i--){
			printf("Enter the coefficient of %d-order term:",i);
			temp1=(struct poly1*)malloc(sizeof(struct poly1));
			scanf("%d",&temp1->ele);
			temp1->pow=i;
			temp1->next=NULL;
			if(head1==NULL){
				head1=temp1;
				ptr1=head1;
			}
			else{
				ptr1->next=temp1;
				ptr1=temp1;
			}
		}	
	}
	else{
		printf("Insert data for second polynomial!\n");
		printf("Enter the order of the polynomial:");
		scanf("%d",&d);
		for(int i=d;i>-1;i--){
			printf("Enter the coefficient of %d-order term:",i);
			temp2=(struct poly2*)malloc(sizeof(struct poly2));
			scanf("%d",&temp2->ele);
			temp2->pow=i;
			temp2->next=NULL;
			if(head2==NULL){
				head2=temp2;
				ptr2=head2;
			}
			else{
				ptr2->next=temp2;
				ptr2=temp2;
			}
		}	
	}
	return d;	
}
 void comp(int p,char s){
 	traverse1=head1;
 	traverse2=head2;
 	for(int i=p;i>-1;i--){
 		temp3=(struct poly3*)malloc(sizeof(struct poly3));
 		if(traverse1->pow >traverse2->pow){
 			temp3->ele=traverse1->ele;
 			temp3->pow=traverse1->pow;
 			temp3->next=NULL;
			traverse1=traverse1->next;
		}
		else if(traverse1->pow==traverse2->pow){
			if(s=='+') temp3->ele=traverse1->ele+traverse2->ele;
			else temp3->ele=traverse1->ele-traverse2->ele;
 			temp3->pow=traverse1->pow;
 			temp3->next=NULL;
 			traverse1=traverse1->next;	
 			traverse2=traverse2->next;
		}
		else{
 			temp3->ele=traverse2->ele;
 			temp3->pow=traverse2->pow;
 			temp3->next=NULL;
 			traverse2=traverse2->next;
		}
		if(head3==NULL){
			head3=temp3;
			ptr3=head3;
		}
		else{
			ptr3->next=temp3;
			ptr3=temp3;
		}
	}
 }
 
 void mul(int p1, int p2){
 	traverse1=head1;
 	int power,element,count;
 	for(int i=0;i<=p1;i++){
 		traverse2=head2;
 		for(int j=0;j<=p2;j++){
 			count=0;
 			check=head3;
 			power=traverse1->pow+traverse2->pow;
 			while(check!=NULL){
 				if(check->pow==power){
 					element=traverse1->ele*traverse2->ele;
 					check->ele=check->ele+element;
 					count++;
 					break;
				}
				check=check->next;
			}
			if(count==0){
				temp3=(struct poly3*)malloc(sizeof(struct poly3));
 				temp3->ele=traverse1->ele*traverse2->ele;
 				temp3->pow=traverse1->pow+traverse2->pow;
 				temp3->next=NULL;
 				//printf("%d\n",temp3->pow);
 				if(head3==NULL){
					head3=temp3;
					ptr3=head3;
				}
				else{
					ptr3->next=temp3;
					ptr3=temp3;
				}
			}
			traverse2=traverse2->next;
		}
		traverse1=traverse1->next;
	}
}

void display(int p){
	if(p==1){
		printf("First polynomial\n");
		traverse1=head1;
		while(traverse1!=NULL){
			printf("power:%d, coefficient:%d\n",traverse1->pow,traverse1->ele);
			traverse1=traverse1->next;
		}
	}
	else if(p==2){
		printf("Second polynomial\n");
		traverse2=head2;
		while(traverse2!=NULL){
			printf("power:%d, coefficient:%d\n",traverse2->pow,traverse2->ele);
			traverse2=traverse2->next;
		}
	}
	else if(p==3){
		traverse3=head3;
		while(traverse3!=NULL){
			printf("power:%d, coefficient:%d\n",traverse3->pow,traverse3->ele);
			traverse3=traverse3->next;
		}
		head3=NULL;
	}
	printf("\n");
}

int main(){
	int d1,d2;
	d1=insert(1);
	d2=insert(2);
	display(1);
	display(2);
	if(d1>d2) comp(d1,'+');
	else comp(d2,'+');
	printf("Addition:\n");
	printf("\n");
	display(3);
	if(d1>d2) comp(d1,'-');
	else comp(d2,'-');
	printf("Subtraction:\n");
	printf("\n");
	display(3);
	mul(d1,d2);
	printf("Multiplication:\n");
	printf("\n");
	display(3);
}
