
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;              // Data part
	struct node *next;     // Link part

} Node_t;

Node_t *head;
void init_list()
{
	
	head = NULL;
}

void insert_first(int data)
{
	
	Node_t *newnode;

	newnode = (Node_t *)malloc(sizeof(Node_t));

	
	newnode->data = data;
	newnode->next = NULL;

	
	if(head == NULL)
	{
           	head = newnode;
		newnode->next = head;
		return;
	}

	
	Node_t *trav = head;
	while(trav->next != head)
	{
		trav = trav->next;
	}

	
	trav->next = newnode;
	newnode->next = head;
	head = newnode;
}

void insert_last(int data)
{
	
	Node_t *newnode;

	newnode = (Node_t *)malloc(sizeof(Node_t));
	

	newnode->data = data;
	newnode->next = NULL;

	
	if(head == NULL)
	{
		
		head = newnode;
		newnode->next = head;
		return;
	}

	Node_t *trav = head;
	while(trav->next != head)
	{
		trav = trav->next;
	}

	
	trav->next = newnode;
	newnode->next = head;
}

void traverse_list()
{
	
	if(head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	
	Node_t *trav = head;

	
	do
	{
		printf("%d -> ", trav->data); // Display data of the current node.
		trav = trav->next;            // Move to the next node.

	}while(trav != head); //traversal pointer again reaches the head node.

	printf("(HEAD)\n");
}

int count_list()
{
	
	int cnt = 0;

	
	if(head == NULL)
	{
		return 0;
	}
	
	Node_t *trav = head;
	do
	{
		cnt++;              
		trav = trav->next;  
	}while(trav != head);   

	
	return cnt;
}

void insert_pos(int data, int pos)
{
	

	int cnt = count_list();
        if(pos == 1) 
	{
		insert_first(data);
		return;
	}

	
	else if(pos == cnt + 1)  
	{
		insert_last(data);
		return;
	}

	
	else if(pos > 1 && pos <= cnt)
	{
		
		Node_t *newnode;

		newnode = (Node_t *)malloc(sizeof(Node_t));
		newnode->data = data;
		newnode->next = NULL;

		
		Node_t *trav = head;
		int i = 1;
		while(i < pos - 1)
		{
			trav = trav->next;
			i++;
		}
		
		newnode->next = trav->next;
		trav->next = newnode;
		return;
	}

	
    else
    {
	    printf("Invalid Position.\n");
    }
}

void delete_first()
{
	
	if(head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	else if(head == head->next)
	{
		free(head);
		head = NULL;
		return;
	}

    else
    {
      
        Node_t *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
       
        Node_t *temp = head;

        head = head->next;

       
        trav->next = head;

      
        free(temp);
    }   
}

void delete_last()
{
	
	if(head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	
	if(head == head->next)
	{
		free(head);
		head = NULL;
		return;
	}
    else
    {
        
        Node_t *trav = head;
        while(trav->next->next != head)
        {
            trav = trav->next;
        }
        
        Node_t *temp = trav->next;
        trav->next = head;
        free(temp);
    }
}

void delete_pos(int pos)
{
	
	int cnt = count_list();

	
	if(pos == 1)
	{
		delete_first();
		return;
	}

	
	if(pos == cnt)
	{
		delete_last();
		return;
	}

	

	if(pos > 1 && pos < cnt)
	{
		Node_t *trav = head;
		Node_t *temp;
		int i = 1;
		
		while(i < pos - 1)
		{
			trav = trav->next;
			i++;
		}
		
		temp = trav->next;
		trav->next = temp->next;
		free(temp);
		return;
	}

	
	printf("Invalid Position.\n");
}


void delete_all()
{
	// Step 1: Check whether the list is empty.
	if(head == NULL)
	{
		printf("List is empty.\n");

		return;
	}

	// Step 2: Delete first node repeatedly until the list becomes empty.
	while(head != NULL)
	{
		delete_first();
	}
}


int main()
{
	int ch;
	int data;
	int pos;

	init_list();

	do
	{
        printf("----------------------------------------\n");
		printf(" Singly Circular Linked List (SCLL)\n");
        printf("----------------------------------------\n");
		printf("0. Exit\n");
		printf("1. Insert First\n");
		printf("2. Insert Last\n");
		printf("3. Insert At Position\n");
		printf("4. Delete First\n");
		printf("5. Delete Last\n");
		printf("6. Delete At Position\n");
		printf("7. Traverse List\n");
		printf("8. Count Nodes\n");
		printf("9. Delete All\n");
		printf("----------------------------------------\n");
		printf("Enter Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 0:
				printf("Thank You...\n");
				break;

			case 1:
				printf("Enter Data : ");
				scanf("%d",&data);

				insert_first(data);
				break;

			case 2:
				printf("Enter Data : ");
				scanf("%d",&data);

				insert_last(data);
				break;

			case 3:
				printf("Enter Position : ");
				scanf("%d",&pos);

				printf("Enter Data : ");
				scanf("%d",&data);

				insert_pos(data,pos);
				break;

			case 4:
				delete_first();
				break;

			case 5:
				delete_last();
				break;

			case 6:
				printf("Enter Position : ");
				scanf("%d",&pos);

				delete_pos(pos);
				break;

			case 7:
				printf("\nLinked List :\n");
				traverse_list();
				break;

			case 8:
				printf("Total Nodes : %d\n",count_list());
				break;

			case 9:
				delete_all();
				printf("All nodes deleted successfully.\n");
				break;

			default:
				printf("Invalid Choice...\n");
		}

	}while(ch != 0);

	return 0;
}