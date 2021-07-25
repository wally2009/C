#include<stdio.h>



#include<stdlib.h>

/*Create Node*/
struct node 
	{
		int x ;
		struct node *next; 


	};
/*Node definition*/
typedef struct node node_t; 
typedef node_t* list; 


/*Create a new node */
node_t* newNode(int x){
	node_t* tmp = malloc(sizeof(node_t)); 
	tmp->x = x; 
	tmp->next = NULL; 
	return tmp;
}

/*Add node at the end */
node_t* addNodeAtTheEnd(node_t* head, int x){

	node_t* tmp;
	node_t* n = newNode(x); 
	if(head == NULL) {
		head = n;
		return head; 
	}


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
node_t* addNodeAtTheHead(node_t* head, int x)
	{

		node_t* tmp = newNode(x);
		tmp->next = head;
		head = tmp;  
		return head; 


	}

node_t * deleteNode(node_t* head, int x){
		node_t* n = newNode(x);
		node_t* tmp = head; 
		node_t* driver = head; 
		node_t* prev ;// = NULL; 
		while(tmp->x != x)
			{

				prev = tmp; 	
				tmp = tmp->next; 
				
			
			}
			//tmp = tmp->next;
			prev->next = tmp->next; 
		/*
		while(driver  != NULL); 
			{
				if(driver->x == x){
					prev->next = driver->next ; 
					free(driver); 
				}

				driver = driver->next; 
			} */
		return head; 

	}

void   insertNodeAfter( node_t* after, node_t* mynode){

			
		mynode->next = after->next;
		after->next = mynode; 		



	}
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


int main(){

	node_t* head; 
	node_t* tmp; 	
	head = addNodeAtTheEnd(head, 10);
	head = addNodeAtTheEnd(head, 20);
	 
	head = addNodeAtTheEnd(head, 30);
	head = addNodeAtTheEnd(head, 40);
	head = addNodeAtTheEnd(head, 50);
	head = addNodeAtTheEnd(head, 60);
	/*
	head = addNodeAtTheHead(head, 100);
	head = addNodeAtTheHead(head, 150);
	head = addNodeAtTheHead(head, 200);
	*/
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
