#include<stdio.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
struct node
{
    int data;
    struct node *next;
};

struct node *start;
void insert_beg();
void insert_end();
void insert_before();
void display();
void deletion();
void destroy();

void main ()
{
    int ch;
    start=NULL;
    do
    {
    pf("\n1:insert_beg\n2:insert_end\n3:insert_before\n4:display\n5:deletion\n6:destroy\n7:exit\nchoice:\n");
    sf("%d",&ch);
    switch(ch)
    {
    case 1:insert_beg();break;
    case 2:insert_end();break;
    case 3:insert_before();break;
    case 4:display();break;
    case 5:deletion();break;
    case 6:destroy();break;
    case 7:pf("program end");break;
    default:pf("wrong choice");break;
    }
    }while(ch!=7);

}

void insert_beg()
{

    struct node *nn;
    nn=(struct node*)malloc(sizeof (struct node));
    pf("enter data to be insert at beg\n");
    sf("%d",&nn->data);
    if(start==NULL)
    {
        start=nn;
        start->next=NULL;
    }
    else
    {
        nn->next=start;
        start=nn;
    }
    pf("%d is entered at the beg\n",start->data);
}

void insert_end()
{
    struct node *nn,*p;
    nn=(struct node*)malloc(sizeof (struct node));
    pf("enter data to be insert at end\n");
    sf("%d",&nn->data);
    nn->next=NULL;
    if(start==NULL)
    {
        start=nn;
    }
   else
   {
       p=start;
    while(p->next!=NULL)
    {
      p=p->next;
    }
    p->next=nn;
   }
    pf("%d is entered at the end\n",start->data);
}

void insert_before()
{
    struct node *nn,*p,*pt;
    int x;

     if(start==NULL)
     {
         pf("SLL is empty\n");
         return ;
     }
     pf("enter a data before which you have to insert\n");
     sf("%d",&x);
     if(x==start->data)
     {
         insert_beg();
         return;
     }
     p=start;
     pt=start->next;
     while(pt->data!=x && pt!=NULL)
     {
        p=pt;
        pt=pt->next;
     }
     if(pt==NULL)
     {
         pf("%d data does not exit\n",x);

     }
     else
     {
         nn=(struct node *)malloc(sizeof(struct node));
         pf("enter data\n");
         sf("%d",&nn->data);
         nn->next=pt;
         p->next=nn;

     }
}



void display()
{
    struct node *p;

    if(start==NULL)
    {
        pf("SLL is empty\n");
        return;
    }
    p=start;
    while(p!=NULL)
    {
    pf("\t\t%d",p->data);
    p=p->next;
    }
}
void deletion ()
{
    struct node *p,*pt;
    int x;
    if(start==NULL)
    {
        pf("SLL is Empty");
        return;
    }
    pf("enter data to bre deleted:");
    sf("%d",&x);
    if(start->data==x)
   {
       p=start;
       start=start->next;
       free(p);
       pf("%d is deleted",x);
       return;
   }
else{
   p=start;
   pt=start->next;
   while(pt->data!=x&&pt!=NULL)
   {
       p=pt;
       pt=pt->next;
   }
   if(pt==NULL)
   {
       pf("%d does not exit",x);
       return ;
   }
   else{
    p->next=pt->next;
    free(pt);
    return;
    pf("%d is deleted",x);
   }
}

}

void destroy ()
{
struct node *t,*tp;

if (start==NULL)
{
    pf("SLL is empty");
    return;
}
tp=start->next;
while(tp!=NULL)
{
 t=tp;
 tp=tp->next;
 free(t);
}
 start=NULL;
}



























