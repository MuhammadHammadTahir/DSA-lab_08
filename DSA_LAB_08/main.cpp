#include <iostream>
#include <BinaryHeap.h>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
   double sum=0.0;
   double avg;
   int size;
   int value,result;
   vector<int> arry,sorted;
   BinaryHeap<int> heap;
   cout<<"Please enter the size of array=";
   cin>>size;
   arry.resize(size);
   for(int j=0;j<4;j++)
   {
       BinaryHeap<int> heap;
       for(int i=0; i<size; i++)
        {
            arry[i]=std::rand()%10000000;
            heap.insert(arry[i]);
        }
   using std::chrono::high_resolution_clock;
   using std::chrono::duration_cast;
   using std::chrono::duration;
   using std::chrono::milliseconds;
   auto t1= high_resolution_clock::now();
   sorted = heap.getSorted();
   auto t2=high_resolution_clock::now();
   auto ms_int_1 = duration_cast<milliseconds>(t2-t1);
   duration<double, std::milli> ms_double_1=t2-t1;
   cout<<"Heap : "<<endl;
   heap.printHeap();
   cout<<endl;
   cout<<"Heap sort : "<<endl;
   for(int i=0;i<sorted.size();i++)
   {
       cout<<" "<<sorted.at(i);
   }
   cout<<endl;
   std::cout <<ms_int_1.count() <<"ms\n";
   std::cout <<ms_double_1.count() <<"ms"<<endl;
   sum+=ms_double_1.count();
   }
   avg=sum/4;
   cout<<endl<<"Average value : "<<avg<<"ms";
   return 0;
}
