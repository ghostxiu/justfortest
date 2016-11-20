#include<iostream>

using namespace std;
int ** CreatArr(int r , int c );
void Display(int ** arr,int l,int w);
int main()
{
    int r,c;//r is rows ,c is cols
    r = 5 ;
    c = 5 ;
    int ** arr;
    arr = CreatArr(r,c);
    Display(arr,r,c);

    for(int i = 0 ; i < r ; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}
int ** CreatArr(int r , int c )
{
        //method 1 to initialize a dynamic-planar arr
    int ** arr = new int*[r];
    for(int i = 0 ; i < c ; i ++)
    {
        arr[i] = new int[c];
    }
    for(int i = 1; i < r; i++)
    {
        arr[i] = arr[i-1] + c;
    }
    //using std::fill to fill 0
    std::fill( &arr[0][0], &arr[0][0]+r*c, 0);
    return arr;
}
void Display(int ** arr,int l,int w)
{
        for(int i = 0 ; i < l ; i++)
        {
            for(int j = 0 ; j < w ; j++ )
            {
                cout << arr[i][j] << " ";
            }
            cout << endl ;
        }
}
