
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
#include "Course.h"
#include "Student.h"

vector<Student> read_file()
{
    vector<Student> students;
    ifstream readmyfile("data.txt");
    
    while(!readmyfile.eof())
    {
        Student student;
        string line;
        size_t begin = 0, end;
        getline(readmyfile, line);
    
        end = line.find(',', begin);
        string lastname = line.substr(begin, end);
        student.setLastName(lastname);
    
        begin = end + 1;
        end = line.find(',', begin);
        string firstname = line.substr(begin, end - begin);
        student.setFirstName(firstname);
    
        begin = end + 1;
        end = line.find(',', begin);
        string idnumber = line.substr(begin, end - begin);
        student.setIdNumber(idnumber);
    
        vector<Course> courses;

        getline(readmyfile, line);
        while(line.find("-999", 0) == string::npos)
        {
                Course course;//new a course vector
            
                begin = 0;
                end = line.find(',', begin);
                string coursecode = line.substr(begin, end);
                course.setCourseNumber(coursecode);
    
                begin = end + 1;
                end = line.find(',', begin);
                string credits = line.substr(begin, end - begin);
                double dblCredit = atof(credits.c_str()); // get c string from string class
                course.setNumberOfCredits(dblCredit);
    
                begin = end + 1;
                end = line.find(',', begin);
                string grade = line.substr(begin, end - begin);
                course.setGradeReceived(grade);
        
                courses.push_back(course);
        
                getline(readmyfile, line);
        }
   
        student.setCoursesTaken(courses);
    
        getline(readmyfile, line);
    
        begin = 0;
        end = line.find(',', begin);
        string totalcredits = line.substr(begin, end);
        double dbltotalcredits = atof(totalcredits.c_str());//convert string to double type
        student.setTotalCredits(dbltotalcredits);
    
        begin = end + 1;
        end = line.find(',', begin);
        string GPA = line.substr(begin, end - begin);
        double dblgpa = atof(GPA.c_str());//convert string to double type
        student.setGpa(dblgpa);
    
        students.push_back(student);
    }
    
    return students;
}

int main()
{
   auto students = read_file();

    for (auto student : students)
    {
        cout << student.toString();
        cout << endl;
    }
    
    
        //writing a data into file and store data
    ofstream inputmyfile;
    inputmyfile.open("data.txt", ios::app);
    string lastname,firstname;
    
    
    cout << "Please enter last name: ";
    getline(cin, lastname);
    
    cout << "Please enter first name: ";
    getline(cin, firstname);
    
    inputmyfile << endl << lastname << "," << firstname << endl;
    
    inputmyfile.close();
    
    return 0;
}




