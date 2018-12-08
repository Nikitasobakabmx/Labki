template <typename T>
class Node
{
    public:
        Node<T> *next;
        T data;

        Node(){};
        Node(const T &item):data(item){};
    /*    //add next
        void InsertAfter(Node<T> *p);
        //delete next
        Node<T> *DeleteAfter();
        //move to next node
        Node<T> *NextNode() const;

        // geter/seter
        void setData(const T &item):deta(item);
        T getData();*/
        //~Node();
};

