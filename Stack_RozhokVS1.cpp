#include <iostream>
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
        //cout<<*a<<" "<<*a+1<<" "<<*a+2<<" "<<*a+3<<" "<<*a+4<<" "<<*b<<endl;
    }
    cout<<"}\n"<<endl;
}

int main()
{
    /*cout << "Hello world!" << endl;
    int *a = new int[12];
    int d[16] = { 5, -12, -12, 9, 10, 0, -9, -12, -1, 23, 65, 64, 11, 43, 39, -15 };
    int c = _msize(a)/sizeof(int);
    cout<<c<<endl;
    for (int i = 0; i<4; i++)
    {
        a[i]=i;
        cout<<a[i];
    }
    cout<<endl;
    cout<<a[4]<<endl;
    int b = _msize(a)/sizeof(a[0]);
    cout<<b<<endl;
    int *z = new int[1000];
    z[0]=10;
    int *jk = z;
    cout<<&jk;*/

    /*int a = 15 + 5;
    int *ykazatel = &a;
    cout << ykazatel<<endl;
    int *ykazatel_second;
    ykazatel_second = ykazatel;  // присвоили адрес переменной a
    cout << ykazatel_second<<endl;int abc = 5;*/

    /*int *ab;
    ab = &abc;
    cout <<*ab<<endl;
    *ab = 10;
    cout <<abc<<"\n"<<endl;*/

//int *z = new int[1000];
//z[0]=10;
//cout <<z[0]<<&z[0]<<endl;
//int *zz=&z[0];
//int *zzz=&z[0];
/* *(zzz+1)=20;
zzz++;
cout <<*zzz<<&z[1]<<endl;
push(&zzz);
cout <<*zzz<<&z[2]<<z[2]<<endl;
cout <<zzz<<endl;
cout <<&z[2]<<endl;*/
//cout<<*zz<<" "<<zz<<" "<< z[0] <<" "<< &z[0]<<endl;
/*for(int i = 0; i<5; i++)
{
    push(&zz, 10+10*i);
    cout<<*(zz-1)<<" "<<zz<<" "<< z[i] <<" "<< &z[i]<<endl;
}
*zz=60;
zz++;
for(int i = 0; i<6; i++)
{
    cout<<z[i]<<endl;
}
print(&zzz,&zz);*/
int *arr = new int[1];
//z[0]=10;
//cout <<z[0]<<&z[0]<<endl;
int *arr_start=&arr[0];
int *arr_end=&arr[0];
/*b[0]=1;
b[1]=2;
pop(&bbb);

cout<<*bbb<<endl;
bbb--;
cout<<*bbb<<endl;*/
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
        cout<<last_del<<endl;
        break;
    }
}
    return 0;
}
