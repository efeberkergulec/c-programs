#include "treeapi.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
	struct file *file;
	struct node *next;
};

void printTree(struct file *tree, struct node *head);
struct file *dequeue(struct node **headPtr);
void enqueue(struct node **headPtr, struct file *newFile);
int isEmpty(struct node *headPtr);

int main(void)
{
	struct file *tree = createTree(); 
	struct node *head = NULL;
	printTree(tree, head); 
	freeTree(tree);
	return 0;
}

void printTree(struct file *tree, struct node *head)
{
	struct file *cursor = tree;
	do
	{
		while(cursor != NULL)
		{	
			enqueue(&head,cursor);
			cursor = cursor->next;
		}
		
		struct file *temp = dequeue(&head);
		printf("%s\n",temp->fileName);
		cursor = temp->subdir;
	
	}while(cursor || !isEmpty(head));
}
struct file *dequeue(struct node **headPtr)
{
    struct node *prev = NULL, *current;
    struct file *retval;
    if(*headPtr == NULL)  return NULL;
    current = *headPtr;
    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    retval = current->file;
    free(current);
    if(prev)    prev->next = NULL;
    else        *headPtr = NULL;
    
    return retval;
}
void enqueue(struct node **headPtr, struct file *newFile)
{       
    struct node *newPtr = malloc(sizeof(struct node));
        
    if(!newPtr) return;
        
    newPtr->file = newFile;
    newPtr->next = *headPtr;
    *headPtr = newPtr;
}
int isEmpty(struct node *headPtr)
{       
        return headPtr == NULL;
}


