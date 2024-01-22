#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <vector>

using namespace std;

template <class comparable>
class BinaryHeap
{
    public:
        //constructors
        BinaryHeap(int capacity=100);
        BinaryHeap(const vector<comparable> &item);
        //destructor
        virtual ~BinaryHeap();

        bool isEmpty() const;

        void insert(const comparable &x);
        //delete the minimum element
        void deleteMin();
        //delete the minimum element but that value is stored in the another place
        void deleteMin(comparable &minItem);
        void makeEmpty();
        void printHeap();
        vector<comparable> getSorted();

    private:
        int currentSize;       //number of elements in heap
        vector<comparable> arry;  //the heap arry

        void buildHeap();
        void percolateDown(int hole);
};

#endif // BINARYHEAP_H
