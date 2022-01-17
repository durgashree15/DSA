#include<stdio.h>
#include<stdlib.h>

struct node{
	char n;
	struct node *next;
};

struct node *head=NULL, *temp, *ptr, *traverse;

void create(){
	char flames[]={'f','l','a','m','e','s'};
	for(int i=0;i<6;i++){
		temp=(struct node *)malloc(sizeof(struct node));
		temp->n=flames[i];
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			ptr=head;
		}
		else{
			ptr->next=temp;
			ptr=temp;
		}
	}
}

int count(){
	traverse=head;
	int c=0;
	while(traverse!=NULL){
		c++;
		traverse=traverse->next;
	}
	return c;
}

void find(){
	int p,c;
	ptr=head;
	printf("Enter the number of beats per round:");
	scanf("%d",&p);
	c=count();
	while(c>1){
		for(int i=0;i<p-2;i++){
			if(ptr->next==NULL) ptr=head;
			else ptr=ptr->next;
		}
		if(ptr->next==NULL){
			ptr=head->next;
			head=ptr;
			c=count();
		}
		else{
			ptr->next=ptr->next->next;
			c=count();
			if(c>1){
				if(ptr->next!=NULL) ptr=ptr->next;
				else ptr=head;
			}
		}	
	}
	printf("Final:%c",ptr->n);
}
int main(){
	create();
	find();
}
