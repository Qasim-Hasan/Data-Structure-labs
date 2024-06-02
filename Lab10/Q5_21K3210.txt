//Lab 10
//Qasim Hasan
//Question 5
//21K-3210
//BCS-3J
#include<iostream>
using namespace std;

class priority_queue{
public:
    int *array;
    int Capacity;
    int front;
    int back;
    int MaxCapacity;
    priority_queue(){}
    priority_queue(int size){
     array=new int[size];
     MaxCapacity=size;
     back=0;
     front=0;
    }
    void Enqueue(int val){
        if(MaxCapacity==Capacity){
            cout<<" FULL Queue"<<endl;
        }
        array[back++]=val;
        int i =back-1;
       while(i>0&&val>array[i/2]){
          array[i]=array[i/2];
          i = i/2;
       }
       array[i]=val;
    }
    int dequeue(){
         int i,j,x;
         int temp,val;
         i=0;
         j=1;
         val = array[0];
         x = array[back-1];
         array[0]=array[back-1];
         while(j<back){
            if (array[j+1]>array[j])
                j=j+1;
            if (array[i]<array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
                i=j;
                j=j*2+1;
            }
            else{
            break;
            }
         }
         array[back-1]=val;
         back--;
        return val;
    }
    void Display(){
        for (int i=0;i<back;i++){
            cout<<array[i]<<" ";
        }      
    }
};
int main(){
    int arr[]={13,7,5,3,2,1};
    int size =sizeof(arr)/sizeof(arr[0]);
    priority_queue obj(size);
    for (int i=0;i<size;i++){
        obj.Enqueue(arr[i]);
    }
    cout<<"Dequeue: "<<obj.dequeue()<<endl;
    obj.Display();
    cout << endl;
    cout<<"Dequeue: "<<obj.dequeue()<<endl;
    obj.Display();
    cout << endl;
}