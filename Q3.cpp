#include<iostream>
using namespace std;

class Student
{
    public:
    int CGPI;
    string name;
    int semester;
    int roll;

    Student()
    {

    }

    Student(string name, int roll, int semester, int CGPI)
    {
        this->name = name;
        this->roll = roll;
        this->semester = semester;
        this->CGPI = CGPI;
    }

    void setDetails()
    {
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Roll No: ";
        cin>>roll;
        cout<<"Enter Semester: ";
        cin>>semester;
        cout<<"Enter CGPA: ";
        cin>>CGPI;
        cout<<endl;
    }

    int getCGPI()
    {
        return CGPI;
    }

    void getDetails()
    {
        cout<<"Name: "<<name<<"    Roll: "<<roll<<"    Semester: "<<semester<<"    CGPI: "<<CGPI<<endl;
    }
};

void insertObj(Student s[],Student s1, int index)
{
    int i = 5;
    while(i>=0)
    {
        s[i+1] = s[i];
        i--;
    }
    s[index] = s1;
}


int main()
{
    Student s[10];
    for(int i = 0; i<5; i++)
    {
        cout<<"Enter details of student "<<i+1<<":"<<endl;
        s[i].setDetails();
    }
    for(int i = 0; i<5; i++)
    {
        s[i].getDetails();
    }

    cout<<endl;
    int k;
    cout<<"Enter the value of base CGPI"<<endl;
    cin>>k;
    cout<<"List of record of students having CGPI greater than "<<k<<endl;
    for(int i = 0; i<5; i++)
    {
        if(s[i].getCGPI() > k)
        {
            s[i].getDetails();
        }
    }

    int index;
    cout<<endl<<"Enter the index at which you want to insert the new record"<<endl;
    cin>>index;
    Student s1;
    s1.setDetails();

    insertObj(s,s1,index);
    cout<<endl;
    for(int i = 0; i<6; i++)
    {
        s[i].getDetails();
    }

    return 0;
}
