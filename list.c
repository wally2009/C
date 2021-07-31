#include<stdio.h>
#include<stdlib.h>

/*A data structure called node with two members : int and a pointer to a another node*/
struct node 
	{
		int x ;
		struct node *next; 
	};

/*Type defintion */
typedef struct node node_t; 
typedef node_t* list; 

/*Create a new node : We expect to receive a node_t* type*/
node_t* newNode(int x){
	node_t* tmp = malloc(sizeof(node_t)); 
	tmp->x = x; 
	tmp->next = NULL; 
	return tmp;
}

/*Add node at the end */
node_t* addNodeAtTheEnd(node_t* head, int x){
	//Check if the list is empty
	if(head == NULL) {
		head = n;
		return head; 
	}
	
	node_t* tmp;
	node_t* n = newNode(x);
	tmp = head; 
	while(tmp->next != NULL){	
		tmp = tmp->next; 
	}
	tmp->next = n; 
	return head; 
}

/*Find node*/
node_t* findNode(node_t* head, int x){
	node_t* tmp = head; 
	while(tmp->next != NULL){
		if(tmp->x == x){
			return tmp;
		}
		tmp = tmp->next; 
	}
	return NULL; 
}

/*add node at the head of hte list. */
node_t* addNodeAtTheHead(node_t* head, int x){
		node_t* tmp = newNode(x);
		tmp->next = head;
		head = tmp;  
		return head; 
	}

/*Delete a node*/
node_t * deleteNode(node_t* head, int x){
	
	/*Check if the list is empty*/
	if(head == NULL){
		return NULL; 
	}
	
	/*This will check if  removing the first element of the list */ 
	node_t* n = head; 
	if(head->x == x){
		head = n->next;
		free(n); 
		return head; 
	}

	node_t* tmp = head; 	  //Here tmp is initialzed to the head of the list
	node_t* prev ; 
	//This loop will check till the node before the one to be deleted
	while(tmp->x != x){
		prev = tmp; 	
		tmp = tmp->next; 
	}	
	//This meant we are at the end of the list and the element to delete there. 
	if(tmp->x == x){
		printf("\nNumber is not the list\n"); 
		return head; 
	}
	//The next of the previous node will now pont to where the node to remove is pointing to. 
	prev->next = tmp->next;
	free(tmp); 			//This is a very important command to run. If not, memory leak will occurs. 
	return head; 
}

/*Insert a node after a given node*/ 
void   insertNodeAfter( node_t* after, node_t* mynode){
		mynode->next = after->next;
		after->next = mynode; 		
	}


/*Display a a linklist*/
void display(node_t* head){
		
	node_t* tmp = head; 
	while(tmp->next != NULL){
		printf("%d->", tmp->x);
		tmp = tmp->next; 
	}
	
	if(tmp->next == NULL){
		printf("%d->NULL", tmp->x); 
	}

	printf("\n"); 

	}

/*EXECUTION Start here/*
int main(){

	node_t* head; 
	node_t* tmp; 	
	/*For simplicity, we could use a loop to create a list. I chose to add the node manually*/
	head = addNodeAtTheEnd(head, 10);
	head = addNodeAtTheEnd(head, 20); 
	head = addNodeAtTheEnd(head, 30);
	head = addNodeAtTheEnd(head, 40);
	head = addNodeAtTheEnd(head, 50);
	head = addNodeAtTheEnd(head, 60);
	
	/*I want to insert a node at the end of my list*/
	head = addNodeAtTheHead(head, 100);
	head = addNodeAtTheHead(head, 150);
	head = addNodeAtTheHead(head, 200);
	
	//the list is displayed. 
	display(head); 
	
	tmp = findNode(head, 20); 
	insertNodeAfter(tmp , newNode(2));
	printf("After inserting a node :\n"); 
	display(head);
	printf("After deleting a node : \n");  
	head = deleteNode(head, 60); 
	display(head);
	return 0; 
}
