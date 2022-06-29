#include <stdio.h>
#include <stdlib.h>


struct N {

    int data;
   struct N* next;
};

  void sortlistinsert(struct N** start,struct N* cur)
{
    struct N* current;
    //if start is end
    if (*start == NULL || (*start)->data >= cur->data) {
        cur->next = *start;
        *start = cur;
    }
    else {
        //locate node before adding
        current = *start;
        while (current->next != NULL && current->next->data < cur->data) {
            current = current->next;
        }
        cur->next = current->next;
        current->next = cur;
    }
}

void printorderd(struct N* head)
{
   struct N* temp = head;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


struct nodeS
{
    int val;
    struct nodeS *next;
};
 struct nodeS *head;

void push ()
{
    int val;
    struct nodeS *ptr = malloc(sizeof(struct nodeS*));



        printf("Enter the value ");
        scanf("%d",&val);
        if(head==NULL)
        {
            ptr->val = val;
            ptr -> next = NULL;
            head=ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = head;
            head=ptr;

        }


}

void pop()
{
    int item;
    struct nodeS *ptr;

        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);


}
void display()
{
    int i;
    struct nodeS *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("\nPrinting Stack elements \n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->val);
            ptr = ptr->next;
        }
    }
}


struct queueN
{
    int data;
    struct queueN *next;
    struct queueN*prev;
};
struct MyQueue
{
    struct queueN *front;
    struct queueN *rear;
    int size;
};

void enqueue(struct MyQueue *q, int data)
{
    struct queueN *node =  malloc(sizeof(struct queueN*));


    // declariton
    node->data = data;
    node->next = NULL;
    node->prev = q->rear;
    if (q->front == NULL)
    {
        // if add to first
        q->front = node;
        q->size = 1;
    }
    else
    {
        q->rear->next = node;
        q->size = q->size + 1;
    }
    q->rear = node;

}
int isEmpty(struct MyQueue *q)
{
    if (q->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek(struct MyQueue *q)
{
    if (isEmpty(q) == 1)
    {
        return ;
    }
    else
    {
        return q->front->data;
    }
}

int dequeue(struct MyQueue *q)
{
    if (isEmpty(q) == 1)
    {
        //empty
        return ;
    }
    else
    {
        int data = peek(q);
        struct QNode *temp = q->front;
        if (q->front == q->rear)
        {
            // When queue contains only one node
            q->rear = NULL;
            q->front = NULL;
        }
        else
        {
            q->front = q->front->next;
            q->front->prev = NULL;
        }
        q->size--;
        return data;
    }
}

void printQdata(struct MyQueue *q)
{
    struct queueN *node = q->front;
    printf("\n Queue Element \n");
    while (node != NULL)
    {
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node
{
    int id;
    struct Node* next;
    struct Node* prev;
};

void sortlist(struct Node *start)
{
    int swapped, i;
    struct Node *cur;
    struct Node *end = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        cur = start;

        while (cur->next != end)
        {
            if (cur->id > cur->next->id)
            {
                int temp = cur->id;
                cur->id = cur->next->id;
                cur->next->id = temp;
                swapped = 1;
            }
            cur = cur->next;
        }
        end = cur;
    }
    while (swapped);
}
void printlinked(struct Node* node)
{
    struct Node* cur;
    printf("\n******PRINTING******\n");
    sortlist(node);
    //WHIILE node doesnt equal null
    while (node != NULL)
    {
        printf(" %d ", node->id);
        //cur equal node
        cur = node;
        //node ->next
        node = node->next;
    }
}
void removeBeg(struct Node** Start)
{
    if (*Start == NULL)
    {
        printf("List Is empty\n");
        return;
    }
    else
    {
        struct Node* Cur = *Start;
        //clear prev of next to make firstt
        Cur->next->prev = NULL;
        //make the new struct the next cur
        *Start = Cur->next;
    }
}

void removend(struct Node** Start)
{
    if (*Start == NULL )
    {
        printf("List Is empty\n");
        return;
    }
    else
    {

        struct Node* cur;
        while (cur->next != NULL)
            cur = cur->next;

        cur->prev->next = NULL;

    }
}

void addfront (struct Node** start, int id)
{
    //create a new node
    struct Node* new_node = malloc(sizeof(struct Node*));

    //add id
    new_node->id = id;

    //point new node next to start and prev to null
    new_node->next = (*start);
    new_node->prev = NULL;

    //if prev diidnt equal null then make prev eq new node loc
    if ((*start) != NULL)
        (*start)->prev = new_node;

    //and change the value address of start
    (*start) = new_node;
}
void insertAfter(struct Node* oldNode, int id)
{
    // check if oldN exists
    if (oldNode == NULL)
    {
        printf("Something went wrong ERROR404 lol");
        return;
    }

    struct Node* new_node = malloc(sizeof(struct Node*));
    new_node->id = id;

    //allocate new node next is next of old
    new_node->next = oldNode->next;

    //and next of old equal new
    oldNode->next = new_node;

    //make prev of new is old
    new_node->prev = oldNode;

    //if new node next isnt at the end then the preev of the next is the new node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void addEnd(struct Node** Start, int id)
{

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));



    new_node->id = id;

    //since its last the next is null
    new_node->next = NULL;

    //If the list is empty, then make the newnode the start
    if (*Start == NULL)
    {
        new_node->prev = NULL;
        *Start = new_node;
        return;
    }
     struct Node* cur = *Start;
    //loop until end
    while (cur->next != NULL)
        cur = cur->next;

    //the next after current is new node and the prev of new node is cur
    cur->next = new_node;
    new_node->prev = cur;

}


int binarysearch (int arr[],int size)
{
    int first, last, middle, search;
    printf("Enter value to find\n");
    scanf("%d", &search);

    first = 0;
    last = size - 1;
    middle = (first+last)/2;

    while (first <= last)
    {
        if (arr[middle] < search)
            first = middle + 1;
        else if (arr[middle] == search)
        {
            printf("%d found at location %d.\n", search, middle+1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last)/2;
    }
    if (first > last)
        printf("Not found! %d isn't present in the list.\n", search);

    return 0;
}

void bubblerec (int arr[], int size)
{
    //base
    if (size == 1)
    {
        return;
    };
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] >= arr[i+1])
        {
            int temp = arr[i];
            arr[i]= arr[i+1];
            arr[i+1]=temp;
        }
    }
    bubblerec(arr,size-1);
}


void removeindex(struct Node** start, int n)
{
    if (*start == NULL || n <= 0)
        return;

    struct Node* current = *start;
    int i;

    //iterate until end or n
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;

    //if its the end then n is greater so return
    if (current == NULL)
        return;


    //printf("HERE");
    if (*start == NULL || current == NULL)
        return;

    //if head is to be deleted
    if (*start == current)
        *start = current->next;

    //if its last node
    if (current->next != NULL)
        current->next->prev = current->prev;

    //its its first node
    if (current->prev != NULL)
        current->prev->next = current->next;

}


void selectionrec(int arr[],int size,int start)
{
    if ( start >= size - 1 ) return;

    int minIndex = start;

    for ( int index = start + 1; index < size; index++ )
    {
        if (arr[index] < arr[minIndex] )
            minIndex = index;
    }
    int temp = arr[start];
    arr[start] = arr[minIndex];
    arr[minIndex] = temp;
    selectionrec(arr, size,start + 1);
}

void insertionsort(int arr[],int size)
{

    for(int i =1; i<size-1; i++)
    {
        int value = arr[i];
        int hole = i;

        while (hole > 0  && arr[hole-1] >= value)
        {
            arr[hole] = arr[hole-1];
            hole--;

        }
        arr[hole]= value;
    }
}

void insertionrec(int arr[], int n)
{
    if (n <= 1)
        return;
    insertionrec( arr, n-1 );
    int hole = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > hole)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = hole;
}

void printarr (int arr[], int size)
{
    for(int i =0 ; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    // int arrSize;

    // printf("enter array size\n");
    //scanf("%d",&arrSize);

    //int *arr = malloc(sizeof(int)*arrSize);

    // printf("enter numbers\n");
    /* for(int i= 0; i<arrSize; i++)
     {
         scanf("%d",&arr[i]);
     } */

    //bubblerecursion
    //bubblerec(arr,arrSize);

    //selectionrec
    //selectionrec(arr,arrSize,0);

    //insertionsort
    //insertionsort(arr,arrSize);

    //insertionreec
    //insertionrec(arr,arrSize);

    //binarysearch
    //binarysearch(arr,arrSize);
    //printarr(arr,arrSize);
//free (arr);

    //linked list employee
    //struct Node* emp = NULL;
    //addEnd(&emp, 6);
    //addfront(&emp, 7);
    //addfront(&emp, 1);
    //addEnd(&emp, 4);
    //insertAfter(emp->next, 8);
    //removeBeg(&emp);
    //removend(&emp);
    //removeindex(&emp,2);
    //printlinked(emp);


    //insert employes in sorted linked list
    //struct N* head = NULL;

//  struct N* emp1 = malloc(sizeof(struct N*));
   // struct N* emp2 = malloc(sizeof(struct N*));
 // struct N* emp3 = malloc(sizeof(struct N*));

    /* put in the data */
   // emp1->data = 10;
    //emp1->next = NULL;
   // emp2->data = 5;
   // emp2->next = NULL;
    // emp3->data = 4;
    //emp3->next = NULL;

//sortlistinsert(&head, emp1);
//sortlistinsert(&head, emp2);
//sortlistinsert(&head, emp3);
//printorderd(head);


    //queue
    //struct MyQueue *q =  malloc(sizeof(struct MyQueue*));
    // q->front = NULL;
    //q->rear = NULL;
    //q->size = 0;
    //enqueue(q,1);
    //enqueue(q,2);
    //enqueue(q,3);
    //printQdata(q);
    //dequeue(q);
    //printQdata(q);

    //stack
    //push();
    //push();
    //push();
    //display();
    //pop();
    //display();

}
