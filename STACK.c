#include<stdio.h>
#define pf printf
#define sf scanf
#define size 3
int stack[size];
int top;
void push ();
void pop ();
void display ();
void main ()
{
top = -1;
int ch;
do
{
pf("\n1:push\n2:pop\n3:display\n4:exit\nchoice:");
sf("%d",&ch);
switch(ch)
{
case 1: push();break;
case 2: pop();break;
case 3: display();break;
case 4: pf("Program End");break;
default: pf("Does Not Exit");break;
}
}while(ch!=4);
}

void push ()
{
int x;
if(top==size-1)
{
pf("stack is full");
return;
}
pf("enter data");
sf("%d",&x);
top++;
stack[top]=x;
pf("%d is pushed",x);
}

void pop ()
{
int x;
if(top==-1)
{
pf("stack is empty");
return ;
}
x=stack[top];
stack[top]=0;
top--;
pf("%d is poped",x);
}

void display()
{
int i;
if(top==-1)
{
pf("stack is empty");
return;
}

for(i=top;i>=0;i--)
{
pf("%d\n",stack[i]);
}
}
