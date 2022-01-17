#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int ele;
	struct node *next;
};

struct node *head=NULL,*ptr,*traverse, *check,*store;

void push(int x){
	if(head==NULL){
		head=(struct node*)malloc(sizeof(struct node));
		head->prev=NULL;
		head->ele=x;
		head->next=NULL;
		ptr=head;	
	}
	else{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->ele=x;
		traverse=head;
		if(head->ele>x){
			temp->next=head;
			temp->prev=NULL;
			temp->next->prev=temp;
			head=temp;
		}
		else{
			while(traverse->next!=NULL && x>traverse->next->ele){
				traverse=traverse->next;
			}
			if(traverse->next==NULL){
				temp->next=NULL;
				temp->prev=traverse;
				traverse->next=temp;	
			}
			else{
				temp->next=traverse->next;
				temp->prev=traverse;
				traverse->next=temp;
			}
		}
		
	}
	
}

void delete_ele(int y){
	check=head;
	if(y==head->ele){
		if(head->next==NULL){
			head=NULL;
		}
		else{
			check=check->next;
			check->prev=NULL;
			head=check;	
		}
	}
	else{
		while(y!=check->ele){
			check=check->next;
		}
		if(check->next==NULL){
			check->prev->next=NULL;
			check->prev=NULL;
			
		}
		else{
			store=check->prev;
			check=check->next;
			check->prev=store;
			store->next=check;
			
		}
			
	}
	
}


void display(){
	traverse=head;
	if(head==NULL){
		printf("List is empty\n");
	}
	else{
		while(traverse!=NULL){
			printf("%d\n",traverse->ele);
			traverse=traverse->next;
		}
	}
	
}


int main(){
	int n,x,con,y;
	printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	scanf("%d",&con);
	while(con==1||con==2||con==3){
		if(con==1){
			printf("Enter the number of elements:");
			scanf("%d",&n);
			ptr=head;
			for(int i=0;i<n;i++){
				printf("Enter the element:");
				scanf("%d",&x);
				push(x);
			}	
		}
		else if(con==2){
			if(head==NULL){
				printf("List is empty! Can't delete element!\n");
			}
			else{
				printf("Enter element to be deleted:");
				scanf("%d",&y);
				delete_ele(y);
			}
			
		}
		else{
			display();
		}
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&con);	
	}	
}
