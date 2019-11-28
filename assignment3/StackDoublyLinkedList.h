template <class T>
class StackDoublyLinkedList : public DoublyLinkedList<T>
{
  public:
    StackDoublyLinkedList();
    void displayStack() const; //Display a stack
    T getTop() const; //return element at the top of a stack
};
