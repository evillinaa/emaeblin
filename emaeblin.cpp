#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Human 
{
protected:
    string name_;
    int age_;

public:
    Human(string name, int age) : name_(name), age_(age) {}

    void PrintInformation() 
    {
        cout << "Имя: " << name_ << endl;
        cout << "Возраст: " << age_ << endl;
    }
};

class Resident : public Human
{
private:
    int NumApart_;

public:
    Resident(string name, int age, int NumApart) : Human(name, age), NumApart_(NumApart) {}

    void PrintInformation() 
    {
        Human::PrintInformation();
        cout << "Номер квартиры: " << NumApart_ << endl;
    }

    void toPay() 
    {
        cout << name_ << " оплатил коммунальные услуги" << endl;
    }
};

class Manager : public Human 
{
private:
    int numberOfApart_;

public:
    Manager(string name, int age, int numberOfApart) : Human(name, age), numberOfApart_(numberOfApart) {}


    void PrintInformation() 
    {
        Human::PrintInformation();
        cout << "Количество квартир в доме: " << numberOfApart_ << endl;
    }

    void OrganizeMeeting() 
    {
        cout << name_ << " организовал собрание жильцов." << endl;
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Resident house("Вася", 35, 13);

    Manager admin("Слава", 55, 88);

    cout << "Информация о жителе дома:" << endl;
    house.PrintInformation();

    cout << "\nИнформация об управляющем домом:" << endl;
    admin.PrintInformation();

    house.toPay();

    admin.OrganizeMeeting();

    system("pause");
    return 0;
}
