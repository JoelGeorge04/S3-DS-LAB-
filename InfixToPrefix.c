#include<stdio.h>
#include<string.h>
#include<math.h>

#define size 10
char infix[size],stack[size],postfix[size],prefix[size];
int n,w;
int top=-1;



int precedence(char el){
 switch(el){
  case '^':
   return 4;
   break;
  case '*':
   return 3;
   break;
  case '/':
   return 3;
   break;
  case '+':
   return 2;
   break;
  case '-':
   return 2;
   break;
  default:
                 return 0;
                 break;
  
 }
}

void infix_prefix(){
 n=strlen(prefix);
 int i,j;
 for(i=0, j=0;i<n;i++){
  if(prefix[i]>='a'&&prefix[i]<='z' ||prefix[i]>='A'&&prefix[i]<='Z'){
   postfix[j++]=prefix[i];
   
  }
  else if(prefix[i]=='('){
   stack[++top]=prefix[i];
  }
  else if(prefix[i]==')'){
   while(stack[top]!='(' && top>-1){
   
     postfix[j++]=stack[top--];
    
    top--;
   }
  }
  else if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='/' || prefix[i]=='*' || prefix[i]=='^' ){
  
    if(stack[top]=='*' && prefix[i]=='*' ||stack[top]=='/' && prefix[i]=='/' || stack[top]=='+' && prefix[i]=='+'||stack[top]=='-' && prefix[i]=='-' ){
     stack[++top]=prefix[i];
    }
    else{
     while(precedence(stack[top])>=precedence(prefix[i])){
     postfix[j++]=stack[top--];
     }
     stack[++top]=prefix[i];
    }
   
   
   
  }
  
  }
  while(top>-1){
   postfix[j++]=stack[top--];
   
  }
  
}
	


void prefixx(){
 w=strlen(infix);
 int j=0;
 for(int i=(w-1);i>=0;i--){
	
  prefix[j]=infix[i];
  j++;

 }
	
 for(int i=0;i<w;i++){
  if(prefix[i]=='('){
   prefix[i]=')';
  }
  else if(prefix[i]==')'){
   prefix[i]='(';
  }
 }
 printf("Reversed:");
 for(int i=0;i<w;i++){
  printf("%c",prefix[i]);
 }
 printf("\n");
	

}


void eval() {
    int k, i = 0, result = 0, op1, op2;
    top = -1;
    k = strlen(postfix);
    for (i = 0; i < k; i++) {
        if (postfix[i] >= 'a' && postfix[i] <= 'z' || postfix[i] >= 'A' && postfix[i] <= 'Z') {
            printf("Enter the value of %c: ", postfix[i]);
            scanf("%d", &stack[++top]);
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            op1 = stack[top--];
            op2 = stack[top--];
            if (postfix[i] == '+') {
                stack[++top] = op1 + op2;
            } else if (postfix[i] == '-') {
                stack[++top] = op1 - op2;
            } else if (postfix[i] == '*') {
                stack[++top] = op1 * op2;
            } else if (postfix[i] == '/') {
                stack[++top] = op1 / op2;
            } else if (postfix[i] == '^') {
                stack[++top] = (int)pow(op1, op2);
            }
        }
    }
    printf("The result of prefix evaluation is %d\n", stack[top]);
}




void main(){
 int m,k;
 printf("Enter Expression:");
 scanf("%s",infix);
 prefixx();
 infix_prefix();
 m=strlen(postfix);
 printf("Prefix:");
 for(k=0;k<=m;k++){
  printf("%c",postfix[k]);
  
 }
 printf("\n");
	
 printf("Reversed prefix:");
 for(k=m-1;k>=0;k--){
  printf("%c",postfix[k]);
  
 }
 eval();
}


    
