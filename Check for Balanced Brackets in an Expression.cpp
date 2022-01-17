#include<stdio.h>
#include<string.h>
char str[100],stack[50];
int top=-1;
int isempty(){
	if(top==-1) return 1;
	else return 0;
}
void push(int x){
	stack[++top]=x;
}
void pop(){
	top--;
}
int check_balance(){
	char s;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='{'||str[i]=='('||str[i]=='['||str[i]==')'||str[i]=='}'||str[i]==']'){
			if (str[i]=='{'||str[i]=='('||str[i]=='['){
				push(str[i]);
				continue;
			}
			if (isempty()) return 0;
			switch(str[i]){
				case ')':
					s=stack[top];
					pop();
					if (s=='{'||s=='[') return 0;
					break;
				case '}':
					s=stack[top];
					pop();
					if (s=='('||s=='[') return 0;
					break;
				case ']':
					s=stack[top];
					pop();
					if (s=='{'||s=='(') return 0;
					break;		
			}
			}
			
		}
	return isempty();
}
int main(){
	printf("Enter your expression:");
	scanf("%[^\n]%*c",str);
	if (check_balance()) {
		printf("The expression is BALANCED");
	}
	else {
		printf("The expression is NOT BALANCED");
	}
}

