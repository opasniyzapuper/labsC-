#include <iostream>
#include <malloc.h>
#include <vector>
using namespace std;

void push(int **arr_end, int value)
{
    **arr_end=value;
    *arr_end=*arr_end+1;
}
int pop(int **arr_end)
{
    int *last_elem = *arr_end-1;
    *arr_end=*arr_end-1;
    cout<<"Deleted element with value = "<<**arr_end<<endl;
    return *last_elem;
}
void print(int **arr_start, int **arr_end)
{
    cout<<"Current stack - {";
    for (int *arr_index = *arr_start; arr_index<*arr_end; *arr_index++)
    {
        if(arr_index+1==*arr_end) cout<<*arr_index;
        else cout<<*arr_index<<", ";
    }
    cout<<"}\n"<<endl;
}

int main()
{
int *arr = new int[1];
int *arr_start=&arr[0];
int *arr_end=&arr[0];

int action=5;
int last_del=5;
int new_value;

while(action!=0)
{
    int arr_len=(arr_end-arr_start);
    cout<<"Current stack consists "<<arr_len<<" elements"<<endl;
    cout<<"Enter a value that determines further action:\n   ";
    cout<<"1 - Show stack's elements\n   2 - Add int element\n   ";
    cout<<"3 - Delete last element\n   4 - Finish the program"<<endl;
    cin>>action;
    if (action==1)
    {
        if(arr_len==0) cout<<"Current stack is empty - enter 2 to add element"<<endl;
        else print(&arr_start,&arr_end);
    }
    if (action==2)
    {
        cout<<"Enter new element: ";
        cin>>new_value;
        push(&arr_end, new_value);
    }
    if (action==3)
    {
        if (arr_len==0) cout<<"Nothing to delete, try adding new values to the stack"<<endl;
        else last_del=pop(&arr_end);
    }
    if (action==4)
    {
        delete [] arr;
        cout<<"Last deleted element - "<<last_del<<endl;
        break;
    }
}
    return 0;
}
