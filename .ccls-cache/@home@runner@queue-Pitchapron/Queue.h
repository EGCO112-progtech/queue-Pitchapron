#include<stdlib.h>

typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x, int y){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){ 
  new_node->order_number=x;
  new_node->qty=y;
  new_node->nextPtr=NULL;
  switch(x)
      {
        case 1 : {  printf("My Order is 1\n"); 
                    break;  }
        case 2 : {  printf("My Order is 2\n");
                    break;  }
        case 3 : {  printf("My Order is 3\n");
                    break;  }
      }
  
  if(q->headPtr==NULL) q->headPtr=new_node;
  else (q->tailPtr)->nextPtr=new_node;
  q->tailPtr=new_node;
  q->size++;
  
  /*Finish enqueue */
 }
}


int dequeue_struct(Queue *q, int p){
  NodePtr t=q->headPtr;
  int price=0;
  if(q->size>0){
    int value= t->qty;
    printf("Customer NO. : %d\n",p);
    switch(t->order_number)
      {
        case 1 : {  printf("Salmon Sushi Roll\t %d\n",value); 
                    price = 100*t->qty;
                    break;  }
        case 2 : {  printf("Tuna Sushi Roll\t\t %d\n",value);
                    price = 120*t->qty;
                    break;  }
        case 3 : {  printf("Pandan Leaf Tea\t\t %d\n",value);
                    price = 40*t->qty;
                    break;  }
      }
   
    q->headPtr= t->nextPtr;
    if(q->headPtr==NULL) q->tailPtr=NULL;
    free(t);
    q->size--;
     
       /*Finish dequeue */
   return price;
   }
   printf("Empty queue\n");
   return 0;
}

