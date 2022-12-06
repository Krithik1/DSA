#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"

int main() {
    Queue q = Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    cout<<q.dequeue()<<endl;
    q.print();
    return 0;
}