//
//  QueueADT.h
//  CIS22C_HW2
//
//  Created by 古谷駿 on 4/17/21.
//  Copyright © 2021 Shun Furuya. All rights reserved.
//

#ifndef QueueADT_h
#define QueueADT_h

using namespace std;

template <class T>
class Queue
{
private:
    struct QueueNode
    {
      T value;
      QueueNode *next;
    };

    QueueNode *front;
    QueueNode *rear;
    int length;

public:
    Queue(){ front = rear = NULL; length = 0;}// Constructor
    ~Queue();// Destructor

    bool push(T);
    
    T pop();
    
    T peek(){ return front->value;};
    
    T peekRear(){return rear->value;}; //get the end of value
    
    bool isEmpty(){
        if(length == 0)
           return true;
        else
           return false;
    };
    
    int getLength(){ return length;};
};

//push function sets value into the queue
template <class T>
bool Queue<T>::push(T item){
    QueueNode *newNode; // Pointer to a new node

    // Allocate a new node and store num there.
    newNode = new QueueNode;
    if (!newNode)
        return false;
    newNode->value = item;
    newNode->next = NULL;
    
    // Update links and counter
    if (!front) // front is NULL: empty queue
        front = newNode;
    else
        rear->next = newNode;
        
    rear = newNode;
    length++;

    return true;
}

//pop function returns front value

template <class T>
T Queue<T>::pop(){
    QueueNode *temp;

    T item = front->value;
    temp = front->next;
    delete front;
    front = temp;
    length--;

    return item;
}



//destructor function release the memory
template <class T>
Queue<T>::~Queue(){
    QueueNode *currNode;
    
    while (front != NULL)
    {
       currNode = front;
       front = front->next;
       delete currNode;
    }
    //cout << "delete" << endl;
}
#endif /* QueueADT_h */
