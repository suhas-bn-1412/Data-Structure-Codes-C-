#include<stdio.h>
int input_prec(char);
int stack_prec(char);
char peep(char *,int);
void convert_postfix(char*,char*);
void push(char *, int *, char);
char pop(char *, int *);
int main()
{
  char infix[10],postfix[10];
  printf("\nEnter valid Infix Expression\n");
  scanf("%s",infix);
  convert_postfix(infix,postfix);
  printf("\nThe postfix equivalent=%s\n",postfix);
}

  void convert_postfix(char * infix, char *postfix)
  {
     char s[10],ch;
     int i,j,top;
     i=0;
     top=-1;
     j=0;
     push(s,&top,'#');
     while(infix[i]!='\0')
     {
        ch=infix[i];
        while(stack_prec(peep(s,top))>input_prec(ch))
             postfix[j++]=pop(s,&top);
        if(input_prec(ch)!=stack_prec(peep(s,top)))
             push(s,&top,ch);
          else
             pop(s,&top);
       i++;
    }
     while(peep(s,top)!='#')
        postfix[j++]=pop(s,&top);
    postfix[j]='\0';
  }

   
 //function to return the input precedence

  int input_prec(char ch)
  {
    switch(ch)
    {
      case '+':
      case '-':return 1;
      case '*':
      case '/':return 3;
      case '$':return 6;
      case '(':return 9;
      case ')':return 0;
      default:return 7;
    }
 }
  //function to return the stack precedence
  int stack_prec(char ch)
  {
    switch(ch)
    {
      case '+':
      case '-':return 2;
      case '*':
      case '/':return 4;
      case '$':return 5;
      case '(':return 0;
      case '#':return -1;
      default:return 8;
    }
 }

  char peep(char * s, int t)
  {
    return s[t];
  }
    
  void push(char *s, int *t, char x)
  {
    ++*t;
    s[*t]=x;
  }
  
   char pop(char *s, int *t)
   {
     char x;
      x=s[*t];
     --*t;
    return x;
  }

  









  
