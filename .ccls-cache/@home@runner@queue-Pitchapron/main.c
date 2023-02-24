#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
 
  struct Queue;
  Queue  q;
   q.headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;

   int i,x,cash,change,p;

  /*printf("List of Order Number  :  \n");
  printf("1. Salmon Sushi Roll    100 bath.\n");
  printf("2. Tuna Sushi Roll      150 bath.\n");
  printf("3. Pandaa Leaf Tea      40  bath.\n");*/
   

 for(i=1,p=1;i<argc;i++){
  if(strcmp(argv[i],"x")==0){
    
    x=dequeue_struct(&q,p);
    p++;
    if(x){
      printf("->You have to pay   %4d bath\n",x);
      do{
        printf("Cash : ");
        scanf("%d",&cash);
      }while(cash<x);
      change=cash-x;
      if(change!=0) printf("->Change is %4d bath\n",change);
      printf("Thank You\n\n");
      }
    }
  else {
    if(atoi(argv[i])>3||atoi(argv[i])<1)
    {
      printf("No food please choose again.\n");
      i++;
      goto r;
    }
    else{
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
      i++;
    }
  }
   r:
 }
  if(q.size>0){
    printf("==============================================\n");
    printf("%d orders left in queue\n",q.size);
    printf("Clearing queue\n");
    while(q.headPtr){
      NodePtr tmp;
      tmp = q.headPtr;
      q.headPtr=q.headPtr->nextPtr;
      free(tmp);
      printf("Clear left order.\n");
    };
    }
  
  return 0;
}
