#include <iostream>
using namespace std;

    class MyList{
        int x,count_;
        MyList *First, *Last, *Next, *Prev; //указатели на след и предыдущий элемент
    public:
        MyList(): First(NULL),Last(NULL){};
        void add(int);
        void show();
        void del();
        ~MyList();
    };

   void MyList::add(int x){
        MyList *temp = new MyList;//создание вспомогательного указателя
        temp->x = x;//запоминание нового параметра
        temp->Next = NULL;//след элемент пустой
        if (!First){//если нет первого элемента
            temp->Prev = NULL;//перед добавленным элементом пустота
            First = temp;//первый элемент это
            Last = First;//последний элемент это первый
        } else {
            temp->Prev = Last;//перед добавляемым элементом стоит последний который уже есть
            Last->Next = temp;//следующий за имеющимся элементом будет новый элемент
            Last = temp;//последний элемент это только что добавленный
        }
    }

    void MyList::show(){
        MyList *t = First;//указатель на первый элемент
        while (t){//пока есть этот указатель
            cout << t->x << " ";//выводится добавленный элемент
            t = t->Next;//указателю присваивается новый элемент
        }
        cout << endl;
    }

    void MyList::del(){
            MyList *temp = Last;//указатель на последний элемент
            Last = Last->Prev;//сдвиг последнего элемента на 1 назад
            Last->Next = NULL;//удаление следующего элемента
            delete temp;//удаление вспомогательного указателя
            return;
    }
//очистка памяти
    MyList::~MyList(){
        while (First){//пока есть первый элемент
            Last=First->Next;//последним элементом стает следующий за первым
            delete First;//удаление первого элемента
            First=Last;//первому элементу присваивается последний
        }
    }

int main() {
    MyList lst;
    cout << "Lets fill up ur stack" << endl;
    while(true) {
        cout << "1 - add elem" << endl;
        cout << "2 - delete elem" << endl;
        cout << "3 - exit" << endl;
        string s;
        cin >> s;
        if(s == "1") {
            int newelem;
            cout << "Enter new elem: ";
            cin >> newelem;
            lst.add(newelem);
            lst.show();
        }
        else if(s == "2") {
            lst.del();
            lst.show();
        }
        else if(s == "3") {
            return 0;
        }
        else
        cout << "Er" << endl;
    }
    return 0;
}
