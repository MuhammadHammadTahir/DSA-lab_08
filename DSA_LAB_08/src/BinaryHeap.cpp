#include "BinaryHeap.h"
#include <iostream>
#include <vector>

using namespace std;

template <class comparable>
BinaryHeap<comparable>::BinaryHeap(int capacity)
{
    currentSize = 0; //initilizes the current size =0 (for no element)
    arry.resize(capacity+1);
}

template <class comparable>
BinaryHeap<comparable>::BinaryHeap(const vector<comparable> &item)
{
    currentSize=item.size();
    //arry.reserve(currentSize+1);      //reserve the space to avoid the resizing as we know the number of elements
    arry.resize(item.size()+1);
    for(int i=0;i<item.size();i++)
    {
        arry[i+1]=item[i];
        //this->arry.push_back(item[i]);  //add item at the end of arry
    }
    buildHeap();
}

template <class comparable>
BinaryHeap<comparable>::~BinaryHeap()
{
    //destructor
}

template <class comparable>
bool BinaryHeap<comparable>:: isEmpty() const
{
    if(currentSize==0)
        return true;
    else
        return false;
}

template <class comparable>
void BinaryHeap<comparable>:: insert(const comparable &x)       //by dig hole methode
{
    if(currentSize==arry.size()-1)
    {
        arry.resize(arry.size()*2);
    }
    if(currentSize==arry.size()/4)
    {
        arry.resize(arry.size()/2);
    }
    int hole=++currentSize; //create hole at last + increase the currentsize counter
    for(;hole>1 && x<arry[hole/2];hole/=2)  //check the position of inserted element
    {
        arry[hole]=arry[hole / 2];
    }
    arry[hole]=x;    //insert element
}

template <class comparable>
void BinaryHeap<comparable>:: deleteMin()
{
    if (isEmpty())
        return;
    arry[1]=arry[currentSize--];
    percolateDown(1);
}

template <class comparable>
void BinaryHeap<comparable>:: deleteMin(comparable &minItem)
{
     if (isEmpty())
        return;
    minItem=arry[1];
    arry[1]=arry[currentSize--];
    percolateDown(1);
}

template <class comparable>
void BinaryHeap<comparable>:: makeEmpty()
{
    arry.clear();
    arry.resize(1);
    currentSize = 0;
}

template <class comparable>
void BinaryHeap<comparable>:: buildHeap()
{
    for( int i = currentSize / 2; i > 0; --i )                      //start from mid and move backward
    percolateDown( i );
}

template <class comparable>
void BinaryHeap<comparable>:: percolateDown(int hole)
{
    int child;
    comparable tmp=arry[hole];
    for(;hole*2<=currentSize; hole=child)
    {
        //left child
        child=hole*2;
        if(child != currentSize && arry[child+1]<arry[child])       //find minimum of childs
            child++;
        if(arry[child]<tmp)                                         //minimum of child and temp
            arry[hole]=arry[child];
        else
            break;
    }
    arry[hole]=tmp;         //add value
}

template <class comparable>
vector<comparable> BinaryHeap<comparable>:: getSorted()
{
    //silicing to remove the extra spaces
    auto first = arry.cbegin() + 1;
    auto last = arry.cbegin() + currentSize;
    vector <comparable> new_vector (first, last);
    BinaryHeap<comparable> copy_heap(new_vector);      //to keep original heap same
    vector<comparable> sorted;
    for(int i=0;i<copy_heap.arry.size();i++)
    {
        comparable temp;
        copy_heap.deleteMin(temp);
        sorted.push_back(temp);
    }
    return sorted;
}

template <typename comparable>
void BinaryHeap <comparable> :: printHeap()
{
    for (int i = 0; i < currentSize; i++)
        cout << arry[i] << " ";
}
