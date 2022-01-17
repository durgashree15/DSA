#include<stdio.h>
#include<stdlib.h>

int size=0;
struct node{
	int ele;
	struct node* next;
};

struct node *head=NULL, *ptr, *temp, *traverse;

void insert(){
	int n;
	printf("Enter the number of elements to be inserted:");
	scanf("%d",&n);
	size+=n;
	for(int i=0;i<n;i++){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter element to insert:");
		scanf("%d",&temp->ele);
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			temp->next=head;
			ptr=temp;
		}
		else{
			if(temp->ele<head->ele){
				temp->next=head;
				head=temp;
				ptr->next=head;
			}
			else{
				traverse=head;
				while(traverse->next!=head && traverse->next->ele<temp->ele){
					traverse=traverse->next;
				}
				temp->next=traverse->next;
				traverse->next=temp;
			}
		}
	}
}

void remove(){
	int x;
	if(size==0) printf("There are no elements in the list!\n");
	else{
		printf("Enter element to be removed:");
		scanf("%d",&x);
		traverse=head;
		if(head->ele==x){
			while(traverse->next!=head){
				traverse=traverse->next;
			}
			head=head->next;
			traverse->next=head;
			printf("Element removed!\n");
		}
		else{
			while(traverse->next!=head){
				if(traverse->next->ele==x){
					traverse->next=traverse->next->next;
				}
				traverse=traverse->next;
			}
			printf("Element removed!\n");
		}
		size--;
	}
}

void search(){
	int x,c=0;
	printf("Enter element to be searched for:");
	scanf("%d",&x);
	traverse=head;
	int i=0;
	while(i<size){
		if(traverse->ele==x){
			printf("Element available in list\n");
			c++;
			break;
		}
		i++;
		traverse=traverse->next;
	}
	if(c==0) printf("Element not available in list\n");
	
}

void next_ele(){
	int x,c=0;
	printf("Enter element whose next element is to be printed:");
	scanf("%d",&x);
	traverse=head;
	int i=0;
	while(i<=size){
		if(traverse->ele==x){
			printf("Element next to the given element is: %d\n",traverse->next->ele);
			c++;
			break;
		}
		traverse=traverse->next;
		i++;
	}
	if(c==0) printf("Element not available in list\n");
	
}


void display(){
	traverse=head;
	int i=0;
	while(i<20){
		printf("%d ",traverse->ele);
		traverse=traverse->next;
		i++;
	}
	printf("\n");
}

int main(){
	printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Next element\n6.Exit\n");
	int choice;
	scanf("%d",&choice);
	while(choice==1||choice==2||choice==3||choice==4||choice==5){
		if(choice==1) insert();
		else if(choice==2) remove();
		else if(choice==3) display();
		else if(choice==4) search();
		else if(choice==5) next_ele();
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Next element\n6.Exit\n");
		scanf("%d",&choice);
	}
}
