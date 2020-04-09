/*
 * @Description: 
 * @Autor: GengchenXu
 * @Date: 2020-03-16 09:25:50
 * @LastEditTime: 2020-04-09 23:47:04
 */
#include <iostream>
#include <string>
using namespace std;
class student
{
    private:
        char name[30];
        int age;
        char ID[30];
        int  grade1, grade2, grade3, grade4;
    public:
        void Int();
        float average();
        void print();
};
void student::Int()
{
    char d;
    cin.getline(name, 30, ',');
    cin >> age >>d;
    cin.getline(ID, 30, ',');
    cin >> grade1 >> d >> grade2 >> d >> grade3 >> d >> grade4;
}
float student::average()
{
    return (float) (grade1 + grade2 + grade3 + grade4)/4;
    
}
void student::print()
{
    cout << name << "," << age << "," <<ID << "," << average() << endl;
}
int main()
{
    student student;
    student.Int();
    student.print();
    return 0;
}