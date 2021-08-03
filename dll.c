#include<stdio.h>
#include<stdlib.h>


/*Node definition*/
struct node{
		int x ; 
		struct node *next; 
		struct node* prev; 	
};
typedef struct node node; 

/*Create a new node given an inter x*/
node* newNode(int x){
		node * tmp = (node*)malloc(sizeof(node)); 
		tmp->x = x; 
		tmp->next = NULL; 
		tmp->prev = NULL; 
		return tmp; 
	}
/*Add a node of a front of the doubly link list*/
node* addNodeFront(node* head, int x){
  /*chech if node list is emptyp8/
  if(head == NULL){
			return newNode(x); 
		}		
    /*Create a node using the functio newNode created in the section right above*/
		node* tmp = newNode(x); 
		tmp->next = head;
		tmp->prev= NULL; 
		head = tmp ;
		return head; 
}

/*Add node at the end of the list */
node* addNodeEnd(node* head, int x){		
		node* tmp = newNode(x);
		/*Check if the list is empty, If yes, we return the element as the head of the list*/
		if(head == NULL){
		   head = tmp ;
		   head->prev = NULL; 
		   return head; 			
		 }
    /*List is not empty. We will traverse the list till is end.*/
		node* dr = head;;
		//tmp = head; 
		/* Traverse the list*/
		while(dr->next != NULL){
			dr = dr->next; 
		}
		/*Here, we are at the end of the list*/
		dr->next = tmp; 
		tmp->prev = dr; 
 		return head; 
	}
 
/*function to search for a node given the list and the number being searched. 
node* nodeSearch(node* head, int x){
        /*Chec if the  list is emply(*/
 	if(head == NULL){
		return NULL;
	}
 	node* n = head; 
	while(n != NULL){
		if(n->x == x){
			return n; 
		}
		n = n->next; 
	}
	if(n == NULL){
		printf("\nElement not found\n"); 
		return NULL; 
 
	}
 	return NULL; 
 
} 
 /*Delete Node*/ 
node* deleteNode(node* head, int x){
	
	/*Check if the list is empty*/
	node* n1 = head; 
  	if(head==NULL){
 		
		return NULL; 
 
	}
  /*check if the first element is the one being deleted.*/
	if(head->x == x){
		head = n1->next; 
		free(n1);             //You may want to free the removed node. If not, memory leak will occur. 
		return head; 
	
	}
	node* tmp = head; i
        node* n ; 
	while(tmp->x != x && tmp->next != NULL){
		n = tmp; 	
		tmp = tmp->next; 
	
	}
 	if(tmp->x != x){
		printf("\nElment is not in the list\n"); 
		return head; 
       	}
	n->next = tmp->next; 
	n->prev = tmp->prev;
	return head; 

}
/*Display list*/ 
void display(node* head){
		if(head==NULL){
			printf("List is empty\n"); 
			exit(1); 
		}
		node* tmp = head ; 
		while(tmp->next != NULL){
			printf("%d->", tmp->x); 	
			tmp = tmp->next; 
		}
		if(tmp->next == NULL){
			printf("%d", tmp->x); 
		}
	}

/*Execution starts here*/
int main(){
		node* head = NULL;
		node* tmp ; 
		head = addNodeEnd(head, 10);
		head = addNodeEnd(head, 20);
		head = addNodeEnd(head, 30); 
		head = addNodeEnd(head, 40); 
		head = addNodeFront(head, 100);
		head = addNodeFront(head, 200);  
		tmp = nodeSearch(head, 4000); 
		if(tmp==NULL){
			printf("\nNode does not exist\n"); 
		}
		else 
			printf("%d is in the list \n", tmp->x); 
		printf("\n");  
		display(head); 

		printf("\nRemove node \n"); 
		head = deleteNode(head, 200); 

		display(head);
		
		head = deleteNode(head, 100); 
		printf("\n"); 
		display(head);  
		 head = deleteNode(head, 40);
		printf("\n"); 
		display(head);
		
		head = deleteNode(head, 30); 
		display(head); 	
		printf("\n"); 

		head = deleteNode(head, 20); 
		 display(head); 
		printf("\n"); 
	
		head = deleteNode(head, 10); 
		display(head); 
		printf("\n"); 
		return 0; 

		
 }
