package dsaqueue;


class QueueNode{
    int data;
    QueueNode next;

    QueueNode(int data){
        this.data = data;
        next = null;
    }
}

class Queue {
    QueueNode front;
    QueueNode rear;

    Queue(){
        front = null;
        rear = null;
    }
    public void enqueue(int element){
        QueueNode temp = new QueueNode(element);
        if(this.isEmpty()){
            front = temp;
        }else{
            rear.next= temp;
        }
        rear = temp;
        System.out.println("Element added!");
    }

    public boolean isEmpty(){
        return (front==null);
    }

    public void deque(){
        if(this.isEmpty()){
            System.out.println("Queue is empty");

        }
        front = front.next;
        System.out.println("Element removed!");
    }

    public int peek(){
        if(this.isEmpty()){
            System.out.println("Queue is empty");
            return -1;
        }

        return front.data;
    }

    public void printQueue(){
        System.out.print("Queue :");
        QueueNode temp = front;
        while(temp!=null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class QueueImpl{
    public static void main(String[] args){
        Queue queue = new Queue();
        queue.enqueue(1);
        queue.enqueue(50);
        queue.enqueue(100);
        queue.enqueue(150);
        queue.printQueue();
        queue.deque();
        System.out.println(queue.peek());
        queue.printQueue();
    }
}

