#include<stdio.h>
#include<stdlib.h>


typedef struct nodeL
{
	int data;
	struct nodeL *next;
}node;

//Insertion at the beginning of the list
int insertFirst (node **head, int value)
{
	node *newNode;
	newNode = (node*)malloc(sizeof(node));
	if (!newNode)
	{
		return 0;
	}
	newNode->data = value;
	newNode->next = (*head);
	(*head) = newNode;
	return 1;
}


void printList(node **head)
{
	node *temp=*head;
	while(temp)
	{
		printf("Node Element:%d \n", temp->data);
		temp=temp->next;
	}

}
int delete(node **head, int value)
{
	node *temp = *head;
	if ((*head)->data == value)
	{// first element to be deleted.
		*head = (*head)->next;
		free(temp);
		return 1;
	}
	while (temp)
	{
		if (temp->next->data ==value)
		{
			node *temp1 = temp->next;
			temp->next = temp->next->next;
			free (temp1);
			return 1; 
		}
		temp=temp->next;
	}
	return 0;
}

int main ()
{
	node *headInit = NULL;
	int res=0;
	res = insertFirst(&headInit,1);
	res = insertFirst(&headInit,2);
	res = insertFirst(&headInit,3);
	res = insertFirst(&headInit,4);
	res = insertFirst(&headInit,5);
	res = insertFirst(&headInit,6);
	res = insertFirst(&headInit,7);
	printList(&headInit);
}
