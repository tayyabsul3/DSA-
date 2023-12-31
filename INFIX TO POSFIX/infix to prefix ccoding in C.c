#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
};
int precedence(char a)
{
    if(a == '+' || a == '-')
    {
       return 2;
    }
    else
    {
        if(a == '*' || a == '/')
        {
                return 3;
        }
    }
    return 0;
}
int isoperator(char a)
{
    if(a == '+' || a == '-' || a == '*' || a == '/')
    {return 1;}
    else
    {return 0;}
}
int stacktop(struct stack * sp)
{
    return sp->arr[sp->top];
};
int isEmpty(struct stack * ptr)
{
    if (ptr->top < 0)
        {
        return 1;
        }
    else
      {
        return 0;
      }
}
int isFull(struct stack * ptr)
{
    if (ptr->top == ptr->size-1)
       {
        return 1;
       }
    else
       {
        return 0;
       }
}
char push(char element,struct stack * ptr )
{
    if(isFull(ptr))
    {
        return 0;
    }
    else
    {
       ptr->top++;
       ptr->arr[ptr->top] = element;
    }
    return 1;
}
char pop(struct stack * ptr)
{
   if(isEmpty(ptr))
   {
       return 0;
   }
   else
   {
       char val = ptr->arr[ptr->top];
       ptr->top--;
       return val;
   }
}
char* infixtopostfix(char * infix)
{
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size=20;
    sp->top=-1;
    sp->arr=(char * )malloc(sp->size * sizeof(char ));
    char * postfix = (char *)malloc((strlen(infix)+1) * sizeof(char ));
    int i=0;
    int j=0;
   while(infix[i]!='\0')
    {
       if(!isoperator(infix[i]))
       {
           postfix[j]=infix[i];
           i++;
           j++;
       }
       else
       {if(precedence(infix[i])>precedence(stacktop(sp)))
       {
           push(infix[i],sp);
           i++;

       }
       else
       {
           postfix[j]=pop(sp);
           j++;
       }}
    }
    while(!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
  char * infix = "3+4*5/8";
  printf(" POSTFIX expression  %s ",infixtopostfix(infix));




    return 0;
}
