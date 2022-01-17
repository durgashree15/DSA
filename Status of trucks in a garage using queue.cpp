#include<stdio.h>

int front=-1, rear=-1, n;

bool full(){
	if((rear+1)%n==front) return true;
	else return false;
}

bool empty(int queue[]){
	if (front==-1) return true;
	else return false;
}
void push(int queue[],int n){
	int m;
	if(!full()){
		printf("Enter the number of trucks entering the garage:");
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			if(!full()){
				printf("Enter truck number:");
				rear=(rear+1)%n;
				scanf("%d",&queue[rear]);
				if(front==-1) front++;
			}
			else{
				printf("Garage is full!\nRemove a truck to continue addition!\n");
				break;
			}
		}
	}
	else{
		printf("Garage is full!\nRemove a truck to continue addition!");
	}	
}

void pop(int queue[], int n){
	if(!empty(queue)){
		front=(front+1)%n;
		//printf("%d %d\n",front,rear);
		if(empty(queue)){
			front=-1;
			rear=-1;
		}
		printf("A truck has left the garage!\n");
	}
	else{
		printf("Garage is empty!\nInsert trucks to continue\n");
	}
}

void display(int queue[],int n){
	if(!empty(queue)){
		printf("Truck numbers available in the garage:\n");
        int i = front;
        do {
            printf("%d\n",queue[i]);
            i = (++i)%n;
        }while (i != rear);
        printf("%d",queue[rear]);
		printf("\n");
	}
	else{
		printf("The garage is empty!\n");
	}
	
}
int main(){
	printf("Enter the number of spaces in the garage:");
	int con;
	scanf("%d",&n);
	int queue[n];
	printf("\n1.Enter the garage\n2.Leave the garage\n3.Display trucks in garage\n4.Exit\n");
	printf("Enter operation of your choice:");
	scanf("%d",&con);
	while(con==1||con==2||con==3){
		if(con==1) push(queue,n);
		else if(con==2) pop(queue,n);
		else display(queue,n);
		printf("\n1.Enter the garage\n2.Leave the garage\n3.Display trucks in garage\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&con);	
	}
}
