#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

void push(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
    new_node->value  = new_data;
  
    new_node->next = (*head);
  
    (*head)    = new_node;
}

void endPush(struct Node** last, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    new_node->value = new_data;
    new_node->next = NULL;
    
    (*last)->next = new_node;
}

void inBetweenPush(struct Node** inBN, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    new_node->value = new_data;
    
    new_node->next = (*inBN)->next;
    (*inBN)->next = new_node;
}

void deleteNode(struct Node** head, int valTBDel){
    struct Node *temp = (*head), *prev;
    if(temp != NULL && temp->value == valTBDel){
        *head = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->value != valTBDel){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
    
}

void  delAtPos(struct Node** head, int pos){
    struct Node *temp = *head;
    
    if(pos == 0){
        (*head) = temp->next;
        free(temp);
    }
    
    for(int i = 0; temp!=NULL && i < pos-1; i++){
        temp = temp->next;
    }
    
    if(temp == NULL || temp->next == NULL){
        return;
    }
    
    struct Node* after = temp->next->next;
    free(temp->next);
    temp->next = after;
}

void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->value);
        n = n->next;
    }
    printf("\n");
}

int main(){

    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    
    first->value = 10; 
    first->next = second; 
 
    second->value = 287; 
    second->next = third;
 
    third->value = 351;
    third->next = NULL;
    

    push(&first, 209);
    endPush(&third, 510);
    
    inBetweenPush(&third, 90);
    printList(first);
    deleteNode(&first, 510);
    delAtPos(&first, 5);

    printList(first);
}
