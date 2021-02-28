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

int main()
{
	int ch;
	printf("\n 1-create");
	printf("\n 2-display");
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
	 		default:
	 			exit(0);
		}

	 }
}

void create()
{
	struct node *newnode, *p;
    int data, i;
    start = (struct node *)malloc(sizeof(struct node));
	
	if(start == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
	// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &data);
        start->data = data;      
        start->link = NULL; // links the address field to NULL
        p = start;
	// Creating n nodes and adding to linked list
        while(data!=-1)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if(newnode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &data);
 
                newnode->data = data;      // links the num field of fnNode with num
                newnode->link = NULL; // links the address field of fnNode with NULL
 
                p->link = newnode; // links previous node i.e. tmp to the fnNode
                p = p->link; 
            }
        }
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
    while(p->link!=NULL)
    {
        printf("\n %d",p->data);
        p=p->link;
    }
}

#by Rijushree
