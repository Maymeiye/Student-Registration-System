//Mei Ye 23459517
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
#include "Course.h"
#include "Student.h"
#include "Registration.h"

int main()
{
    Registration r;
    char operation;
    Student add_new_student;
    Course add_new_course;
    string lastname,firstname, idnumber, courseCode, astudent,grade;
    double courseCredits;
    set<Student>::iterator student_it;
    vector<Course>::iterator course_it;
    
        //there are two students registed
        //one stduent have one course; the other one have two courses
    
    cout <<"-----------------------------------"<< endl;
    cout <<"Welcome to use registration system!"<< endl;
G:
    cout <<"---------------MENU----------------"<< endl;
    cout <<"L: Load the current registration"<< endl;
    cout <<"A: Add stduent     B: Delete student"<< endl;
    cout <<"C: Add course      D: Delete course "<< endl;
    cout <<"G: Grade           S: Save data"<< endl;
    cout <<"P: Display the current registration"<< endl;
    cout <<"F: Find a stduent"<< endl;
    cout <<"E: Exit the system"<< endl;
    cout <<"-----------------------------------"<< endl;
    
    cin >> operation;
    
    
    switch(operation)
    {
        case 'L':
        case 'l':
                cout << "Loading current registration..."<< endl;
                r.loadData("data.txt");
                break;
    
        case 'A':
        case 'a':
                cout << "Please enter last name: ";
                cin >>lastname;
                add_new_student.setLastName(lastname);
                cout << "Please enter first name: ";
                cin >>firstname;
                add_new_student.setFirstName(firstname);
                cout << "Please enter ID: ";
                cin >>idnumber;
                add_new_student.setIdNumber(idnumber);
                r.addStudent(add_new_student);
                break;
        //addstudent run time is O(n)
    
        case 'B':
        case 'b':
                cout << "Please enter the student's last name you want to delete: ";
                cin >> astudent;
                r.deleteStudent(astudent);
                break;
        //deleteStudent run time is O(n)
        case 'C':
        case 'c':
                cout << "Please enter the student's last name: ";
                cin >> astudent;
                cout << "Please enter course code: ";
                cin >> courseCode;
                add_new_course.setCourseNumber(courseCode);
                cout << "Please enter course Credits: ";
                cin >> courseCredits;
                add_new_course.setNumberOfCredits(courseCredits);
                student_it = r.searchStudent(astudent);
                student_it->addCourse(add_new_course);
                cout << student_it->toString();
                break;
        //addCourse run time is O(n)
    
        case 'D':
        case 'd':
                cout << "Please enter the student's last name: ";
                cin >> astudent;
                cout << r.searchStudent(astudent)->toString();
                cout << "Please enter the course code to delete: ";
                cin >> courseCode;
                r.searchStudent(astudent)->searchCourse(courseCode);
        
                student_it = r.searchStudent(astudent);
                student_it->deleteCourse(courseCode);
                cout << student_it->toString();
                break;
                //deleteCourse run time is O(n)
    
        case 'G':
        case 'g':
    
                cout << "Please enter the student's last name: ";
                cin >> astudent;
                student_it = r.searchStudent(astudent);
                cout << student_it->toString();
                cout << "Please enter the course code to grade: ";
                cin >> courseCode;
                course_it = student_it->searchCourse(courseCode);
                cout << "Please enter the grade: ";
                cin >> grade;
                course_it->setGradeReceived(grade);
                break;
                //grade run time is O(n)
    
        case 'F':
        case 'f':
                cout << "Please enter the student's last name you want to find: ";
                cin >> astudent;
                cout << r.searchStudent(astudent)->toString();
                break;
                //searchStudent run time is O(n)
        case 'S':
        case 's':
                cout << "Saving data..."<< endl;
                r.saveData("data2.txt");
                break;
        
        case 'P':
        case 'p':
                cout << "Displaying the current registration"<< endl;
                r.displayRegistration();
                break;
        
        case 'E':
        case 'e':
                return 0;
        default:
                cout << "ERROR" << endl;
    }
    goto G;
    
    
    
    return 0;
}




