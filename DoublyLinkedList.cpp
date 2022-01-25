#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};

void bignInsert(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}

void insertAftNode(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout<<"previous node cannot be NULL";
        return;
    }
 
    Node* new_node = new Node();
 
    new_node->data = new_data;
 
    new_node->next = prev_node->next;
 
    prev_node->next = new_node;
 
    new_node->prev = prev_node;
 
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void delElement(int value)
{
    struct node *tmp, *q;
    if (start->data == value)
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
        if (q->next->data == value)  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
    if (q->next->data == value)    
    { 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}


void displayList(struct Node* node) {
   struct Node* last;
  
   while (node != NULL) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == NULL)
   cout<<"NULL";
}


int main(){
  //Define Oprations here
}
