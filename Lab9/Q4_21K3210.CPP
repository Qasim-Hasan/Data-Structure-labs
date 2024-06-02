//LAB 9
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 4
#include <iostream>
using namespace std;
#define MAX 10
class EntireQueueUsingArray{
    private:
      int front,rear;
      int array[MAX];   //MAking a Queue with the help of Array
      static int count; //Elements present after every Push or Pop
      public:
    EntireQueueUsingArray(){
    front=-1;
    rear=-1;
    }
    bool QueueCapacity(){
        if(rear==MAX-1){
            return true;
        }else{
            return false;
        }
    }
    bool QueueEmpty(){
        if(rear==-1){
            return true;
        }else{
            return false;
        }
    }
    void ADDMEMBER(int data){
    if(QueueCapacity()){
    cout<<"\n Queue Elements are OverFlowing";
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        array[rear]=data;
        count++;
    }else{
        rear++;
        array[rear]=data;
        count++;
    }
    }
    void PeekFront(){
        cout << "\nFront Element:"<< array[front]<< endl;
    }
    void PeekRear(){
        cout << "Rear Element: "<< array[rear] << endl;
    }
    void REMOVEMEMBER(){
    if(QueueEmpty()){
    cout<<"\nQueue Elements are Underflowing";
    }else if(front==0 && rear==0){
        front=rear=-1;
        count--;
    }else{
        front++;
        count--;
       }
    }
 
void PrintQueue(){
     if(front==-1){
      cout<<"\nQUEUE IS EMPTY\n";
     }
     else{
    cout<<"\nQUEUE ELEMENTS:";
    for(int i=front;i<=rear;i++){
    cout<<array[i]<<" ";
    }
    cout<<endl;
    }
}
void QueueSize(){
    cout << "Queue Size:" <<count;
}
};
int EntireQueueUsingArray::count=0;
int main(){
      EntireQueueUsingArray q;
 
      q.PrintQueue();// No elements Present
      q.ADDMEMBER(10);
      q.ADDMEMBER(20);
      q.ADDMEMBER(231);
      q.PrintQueue();  
      q.QueueSize();    //Size should be 3 
      q.PeekFront();
      q.PeekRear();

      q.REMOVEMEMBER();
      q.REMOVEMEMBER();
      q.PrintQueue();
      q.QueueSize();   //Size should be 1
      q.PeekFront();
      q.PeekRear();
      return 0;
}