#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;

void create();
void display();
void insert_beg();
void insert_end();
void insert_any();
void delete_beg();
void delete_end();
void delete_any();

int main()
{
	int ch;
	printf("\n 1-create");
	printf("\n 2-display");
	printf("\n 3-insert_beginning");
	printf("\n 4-insert_end");
	printf("\n 5-insert_any");
	printf("\n 6-delete_beg");
	printf("\n 7-delete_end");
	printf("\n 8-delete_any");
	 while(1)
	 {
	 	printf("\n Enter choice :");
	 	scanf("%d",&ch);
	 	switch(ch)
	 	{
	 		case 1:
	 			create();
	 			break;
	 		case 2:
	 			display();
	 			break;
	 		case 3:
	 			insert_beg();
	 			break;
	 		case 4:
	 			insert_end();
	 			break;
	 		case 5:
	 			insert_any();
	 			break;
	 		case 6:
	 			delete_beg();
	 			break;
	 		case 7:
	 			delete_end();
	 			break;
	 		case 8:
	 			delete_any();
	 			break;
	 		
	 		default:
	 			exit(0);
		}

	 }
}

void create()
{
	struct node *newnode, *p;
    int n;
    printf("Enter data");
    scanf("%d",&n);
	
    while(n!=-1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
    	newnode->data = n;     
        newnode->link = NULL;
		   	if(start==NULL)
        	{
        		start=newnode;
			}
			else
		    {
		 	  p = start;
		  	  while(p->link!=NULL)
			   	p=p->link;
			   	p->link=newnode;
			}
			printf("\nEnter data");
			scanf("%d",&n);
	}
}

void display()
{
    struct node *p;
    p=start;
    if(start==NULL)
    {
    	printf("List is empty\n");
    	return;
	}
    while(p!=NULL)
    {
        printf("\n %d",p->data);
        p=p->link;
    }
}
void insert_beg()
{
	struct node *newnode;
	int n;
	if(newnode==NULL)
	{
		printf("Unable to allocate memory");
	}
	else{
		printf("Enter data");
		scanf("%d",&n);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=n;
		newnode->link=start;
		start=newnode;
	}
}
void insert_end()
{
	struct node *newnode,*p;
	int n;
	printf("\nEnter data");
	scanf("%d",&n);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n;
	newnode->link=NULL;
	p=start;
	while(p->link!=NULL)
	{
		p=p->link;
	}
	p->link=newnode;
}
void insert_any()
{
	struct node *newnode,*p,*q;
	int n,m;
	printf("\nEnter data to insert");
	scanf("%d",&n);
	printf("\nEnter number after which you want to insert");
	scanf("%d",&m);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n;
	p=start;
	while(p!=NULL)
	{
		if(p->data==m)
		{
			q=p->link;
			p->link=newnode;
			newnode->link=q;
		}
		p=p->link;
	}
	
}
void delete_beg()
{
	struct node *p;
	if(start==NULL)
	{
		printf("\nNo list");
	}
	else
	{
		p=start;
		start=start->link;
	}
	free(p);
}

void delete_end()
{
	struct node *p,*q;
	p=start;
	q=p;
	while(p->link!=NULL)
	{
		q=p;
		p=p->link;
	}
	q->link=NULL;
	free(p);
}
void delete_any()
{
	struct node *p,*q;
	int n;
	printf("Enter the node value you want to delete");
	scanf("%d",&n);
	p=start;
	q=p;
	while(p->data!=n)
	{
		q=p;
		p=p->link;
	}
	q->link=p->link;
	free(p);
}

