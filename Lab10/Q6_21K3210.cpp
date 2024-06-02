//Lab 10
//Qasim Hasan
//Question 6
//21K-3210
//BCS-3J
#include<iostream>
using namespace std;

class priority_queue{
public:
    int *array;
    int MaxCapacity;
    int Capacity;
    int front;
    int back;
    priority_queue(){}
    priority_queue(int size){
     array= new int[size];
     back=0;
     front=0;
     MaxCapacity = size;
    }
    void Enqueue(int val){
        if (MaxCapacity== Capacity){
            cout<<"FULL Queue"<<endl;
        }
        array[back++]=val;
        int i =back-1;
       while (i>0 && val < array[i/2 ]){
          array[i]=array[i/2];
          i = i/2;
       }
       array[i]=val;
    }
    bool empty(){
        if(back==0)
        return true;
        return false;
    }
    int dequeue(){
         int i,j,x;
         int temp,val;
         i=0;
         j=1;
         val = array[0];
         x = array[back-1];
         array[0]=array[back-1];
         while (j<back){
            if (array[j+1]>=array[j])
                j = j+1;
            if (array[i]<=array[j]){
                temp =array[i];
                array[i]=array[j];
                array[j]=temp;
                i= j;
                j =j*2+1;
            }else{
            break;
            }
         }
         array[back-1]=val;
         back--;
        return val;
    }
    int top(){
        return array[front];
    }
    void Display(){
        for (int i = 0; i < back; i++){
            cout<<array[i]<<" ";
        }
    }
};
int Dec_Arr(int arr[], int size){
    int Sum = 0;
    int Diff = 0;
    priority_queue obj;
    for (int i=0;i<size;i++){
        if (!obj.empty()&&obj.top()<arr[i]) {
        Diff = arr[i] - obj.top();
        Sum += Diff;
            obj.dequeue();
            obj.Enqueue(arr[i]);
        }
        obj.Enqueue(arr[i]);
       cout<<obj.top();
    }
    return Sum;
}
int main(){
    int array[]={3, 1, 2, 1 };
    int size =sizeof(array)/sizeof(array[0]);
    priority_queue H(size);
    for(int i=0;i<size;i++){
        H.Enqueue(array[i]);
    }
   H.Display();
   cout<<Dec_Arr(H.array,size);
   
}