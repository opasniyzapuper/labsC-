#include <iostream>
using namespace std;

    class MyList{
        int x,count_;
        MyList *First, *Last, *Next, *Prev; //��������� �� ���� � ���������� �������
    public:
        MyList(): First(NULL),Last(NULL){};
        void add(int);
        void show();
        void del();
        ~MyList();
    };

   void MyList::add(int x){
        MyList *temp = new MyList;//�������� ���������������� ���������
        temp->x = x;//����������� ������ ���������
        temp->Next = NULL;//���� ������� ������
        if (!First){//���� ��� ������� ��������
            temp->Prev = NULL;//����� ����������� ��������� �������
            First = temp;//������ ������� ���
            Last = First;//��������� ������� ��� ������
        } else {
            temp->Prev = Last;//����� ����������� ��������� ����� ��������� ������� ��� ����
            Last->Next = temp;//��������� �� ��������� ��������� ����� ����� �������
            Last = temp;//��������� ������� ��� ������ ��� �����������
        }
    }

    void MyList::show(){
        MyList *t = First;//��������� �� ������ �������
        while (t){//���� ���� ���� ���������
            cout << t->x << " ";//��������� ����������� �������
            t = t->Next;//��������� ������������� ����� �������
        }
        cout << endl;
    }

    void MyList::del(){
            MyList *temp = Last;//��������� �� ��������� �������
            Last = Last->Prev;//����� ���������� �������� �� 1 �����
            Last->Next = NULL;//�������� ���������� ��������
            delete temp;//�������� ���������������� ���������
            return;
    }
//������� ������
    MyList::~MyList(){
        while (First){//���� ���� ������ �������
            Last=First->Next;//��������� ��������� ����� ��������� �� ������
            delete First;//�������� ������� ��������
            First=Last;//������� �������� ������������� ���������
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
