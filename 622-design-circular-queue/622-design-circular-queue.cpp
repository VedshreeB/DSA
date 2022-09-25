class MyCircularQueue {
    int size;
    int *a;
    int front,rear;
public:
    MyCircularQueue(int k) {
        size = k;
        a = new int[k];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(front == -1){
            front = rear = 0;
            a[rear] = value;
        }
        else
        {    
            rear = (rear+1)%size;
            a[rear] = value;  
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%size;
        }
        return true;
    }
    
    int Front() {
      if(isEmpty()) return -1;
    
      return a[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return a[rear];
    }
    
    bool isEmpty() {
        return (rear == -1);
    }
    
    bool isFull() {
        return ((rear+1)%size == front);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */