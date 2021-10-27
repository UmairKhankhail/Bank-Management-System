#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
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
        void searchPerson();
        void transactions();
        void del();
};

int main()
{
    Bank b;
    b.choice();
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
           case '4':
                Bank :: searchPerson();
                break;
           case '5':
                Bank :: transactions();
                break;

           case '6':
                Bank :: del();
                break;
           case '7':
                exit(0);
        }

    }

}

void Bank :: personData()
{
    cout<<"\nEnter the data of person "<<total+1<<endl;
    cout<<"Enter name: ";
    cin>>person[total].name;
    cout<<"Enter ID: ";
    cin>>person[total].ID;
    cout<<"Enter address: ";
    cin>>person[total].address;
    cout<<"Enter contact: ";
    cin>>person[total].contact;
    cout<<"Enter total cash: ";
    cin>>person[total].cash;
    total++;
}

void Bank :: showData()
{
    for (int i=0;i<total;i++)
    {
        cout<<"\nData of person "<<i+1<<endl;
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
          cout<<"Current Data of person "<<i+1<<endl;
          cout<<"ID: "<<person[i].ID<<endl;
          cout<<"Name: "<<person[i].name<<endl;
          cout<<"Address: "<<person[i].address<<endl;
          cout<<"Contact: "<<person[i].contact<<endl;
          cout<<"Total Cash: "<<person[i].cash<<endl;
          cout<<"\n\nEnter new record:"<<endl;
          cout<<"Enter name: ";
          cin>>person[i].name;
          cout<<"Enter ID: ";
          cin>>person[i].ID;
          cout<<"Enter address: ";
          cin>>person[i].address;
          cout<<"Enter contact: ";
          cin>>person[i].contact;
          cout<<"Enter total cash: ";
          cin>>person[i].cash;
          break;
        }
         if (i==total-1)
        {
            cout<<"No such record found."<<endl;

        }
    }

}

void Bank :: searchPerson()
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
          break;
        }
         if (i==total-1)
        {
            cout<<"No such record found."<<endl;

        }
    }
}

void Bank :: transactions()
{
    char ch;
    int amount;
    cout<<"Enter the ID: "<<endl;
    cin>>id;
    for (int i=0;i<total;i++)
    {
        if (id==person[i].ID)
        {
          cout<<"ID: "<<person[i].ID<<endl;
          cout<<"Name: "<<person[i].name<<endl;
          cout<<"Address: "<<person[i].address<<endl;

          cout<<"Current amount: "<<person[i].cash<<endl;
          cout<<"Press 1 for Deposit: "<<endl;
          cout<<"Press 2 for Withdraw: "<<endl;
          ch=getch();
          switch(ch)
          {
              case '1':
                  {cout<<"Enter the amount to deposit: "<<endl;
                  cin>>amount;
                  person[i].cash=person[i].cash+amount;
                  cout<<"Your new amount is: "<<person[i].cash<<endl;
                  break;}
              case '2':
                  {back:
                  cout<<"Enter the amount to withdraw: "<<endl;
                  cin>>amount;
                  if (amount>person[i].cash)
                  {
                      cout<<"Your current amount is just: "<<person[i].cash<<endl;
                      Sleep(3000);
                       goto back;
                  }
                  person[i].cash=person[i].cash-amount;
                  cout<<"Your new amount is: "<<person[i].cash<<endl;
                  break;}
              default:
                  {cout<<"Invalid Input."<<endl;
                  break;}
          }
          break;

        }

        if (i==total-1)
        {
            cout<<"No such record found."<<endl;

        }
    }

}

void Bank :: del()
{
    char ch;
    cout<<"Enter the ID: "<<endl;
    cin>>id;
    cout<<"Press 1 for specific record deletion."<<endl;
    cout<<"Press 2 for complete records deletion."<<endl;
    cin>>ch;
    switch(ch)
    {
        case '1':
            for (int i=0;i<total;i++)
              {
                    if (id==person[i].ID)
                        {
                            for (int j=i;j<total;j++)
                                {
                                        person[j].ID=person[j+1].ID;
                                        person[j].name=person[j+1].name;
                                        person[j].contact=person[j+1].contact;
                                        person[j].address=person[j+1].address;
                                        person[j].cash=person[j+1].cash;

                                }
                                total--;
                                break;
                        }
                    if (i==total-1)
                      {
                    cout<<"No such record found."<<endl;

                      }
              }


            break;
        case '2':
            total=0;
            cout<<"All the records have been deleted."<<endl;
            break;


    }

}
