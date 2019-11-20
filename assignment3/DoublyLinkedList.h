template <class T>
class DoublyLinkedList
{
    protected:
        Node<T>* head; //pointer to the first node of a doubly linked list
        Node<T>* tail; //pointer to the last node of a doubly linked list
        int size;
