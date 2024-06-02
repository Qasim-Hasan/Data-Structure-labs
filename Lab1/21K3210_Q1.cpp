//Question 1
//Qasim Hasan
//BCS-3J
//21K-3210
#include<iostream>
using namespace std;

const int size = 100;
 
bool IdentityMatrix(int Matrix[][size], int N)
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (row == col && Matrix[row][col] != 1)
                return false;
            else if (row != col && Matrix[row][col] != 0)
                return false;
        }
    }
    return true;
}
 
// Driver Code
int main()
{
    int N = 4;
    int Matrix[][size] = {{1, 0, 0, 0},{0, 1, 0, 0}, {0, 0, 1, 0},{0, 0, 0, 1}};
    if (IdentityMatrix(Matrix, N))
       cout << "Yes identity matrix";
    else
       cout << "NO  identity matrix ";
    return 0;
}
