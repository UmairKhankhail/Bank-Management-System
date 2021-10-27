#include<iostream>
#include<conio.h>
using namespace std;

class Bank{

    private:
        int  total;
        string id;
        struct person{
            string name,ID,address;
            int contact,cash;
        }person[100];

    public:
        Bank(){
        total =0;
        }

        void choice();
        void personData();
        void showData();
        void updateData();

};

int main()
{
    return 0;
}

void Bank :: choice()
{
    char ch;
    while(1){
        cout<<"\n\n Press...!!"<<endl;
        cout<<"1. Create new account"<<endl;
        cout<<"2. View Customers list"<<endl;
        cout<<"3. Update information of existing account"<<endl;
        cout<<"4. Check the details of existing account"<<endl;
        cout<<"5. For transactions"<<endl;
        cout<<"6. Remove existing account"<<endl;
        cout<<"7. Exit."<<endl;
        ch=getch();
        switch(ch)
        {
           case '1':
               Bank :: personData();  // we use this scope resolution operator when we want to access method of any class outside the main function.
               break;
           case '2':
                Bank :: showData();
                break;
           case '3':
                Bank :: updateData();
                break;

        }

    }

}

void Bank :: personData()
{
    cout<<"Enter the data of person "<<total+1<<endl;
    cout<<"Enter name: "<<endl;
    cin>>person[total].name;
    cout<<"Enter ID: "<<endl;
    cin>>person[total].ID;
    cout<<"Enter address: ";
    cin>>person[total].address;
    cout<<"Enter contact: "<<endl;
    cin>>person[total].contact;
    cout<<"Enter total cash: "<<endl;
    cin>>person[total].cash;
    total++;
}

void Bank :: showData()
{
    for (int i=0;i<total;i++)
    {
        cout<<"Data of person "<<i+1<<endl;
        cout<<"ID: "<<person[i].ID<<endl;
        cout<<"Name: "<<person[i].name<<endl;
        cout<<"Address: "<<person[i].address<<endl;
        cout<<"Contact: "<<person[i].contact<<endl;
        cout<<"Total Cash: "<<person[i].cash<<endl;
    }
}

void Bank :: updateData()
{
    cout<<"Enter the ID of person"<<endl;
    cin>>id;
    for (int i=0;i<total;i++)
    {
        if (id==person[i].ID)
        {
          cout<<"Current Data: "<<endl;
          cout<<"ID: "<<person[i].ID<<endl;
          cout<<"Name: "<<person[i].name<<endl;
          cout<<"Address: "<<person[i].address<<endl;
          cout<<"Contact: "<<person[i].contact<<endl;
          cout<<"Total Cash: "<<person[i].cash<<endl;
          cout<<"\n\nEnter new record:"<<endl;
          cout<<"Enter name: "<<endl;
          cin>>person[total].name;
          cout<<"Enter ID: "<<endl;
          cin>>person[total].ID;
          cout<<"Enter address: ";
          cin>>person[total].address;
          cout<<"Enter contact: "<<endl;
          cin>>person[total].contact;
          cout<<"Enter total cash: "<<endl;
          cin>>person[total].cash;

        }
    }

}
