//Mei Ye 23459517
#include <vector>
class Student
{
    private:
        string firstName;
        string lastName;
        string idNumber;
        vector<Course>* coursesTaken = new vector<Course>;// make pointer points to the Course address so that it won't have conflict with the method which set to const, when we want to change the data in coursetaken.
        double totalCredits;
        double gpa;
    
    public:
        void setFirstName(string firstName);
        string getFirstName() const;
    
        void setLastName(string lastName);
        string getLastName() const;
    
        void setIdNumber(string idNumber);
        string getIdNumber() const;
    
        void setCoursesTaken(vector<Course> x);
        vector<Course> getCoursesTaken() const;
    
        void setTotalCredits(double credits);
        double getTotalCredits() const;
    
        void setGpa(double gpa);
        double getGpa() const;
    
        void addCourse(Course add_new_course) const;
        vector<Course>::iterator searchCourse(string courseCode) const;
        void deleteCourse(string courseCode) const;
        void gradeCourse();
        //operator overlaoded for comparison based on lastName
        //and equality test based on idNo
    
        friend bool operator==(const Student& a, const Student& b);
        friend bool operator<=(const Student& a, const Student& b);
        friend bool operator<(const Student& a, const Student& b);
        friend bool operator>(const Student& a, const Student& b);
        friend bool operator>=(const Student& a, const Student& b);
    
        string toString() const;
};

/*------------getter and setter method-------------------*/
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
string Student::getFirstName() const
{
    return firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
string Student::getLastName() const
{
    return lastName;
}

void Student::setIdNumber(string idNumber)
{
    this->idNumber = idNumber;
}
string Student::getIdNumber() const
{
    return idNumber;
}

void Student::setCoursesTaken(vector<Course> x)
{
    *coursesTaken = x;
}
vector<Course> Student::getCoursesTaken() const
{
    return *coursesTaken;
}

void Student::setTotalCredits(double credits)
{
    this->totalCredits = credits;
}
double Student::getTotalCredits() const
{
    double totalCredits = 0;
    for(auto course : *coursesTaken)
        {
            totalCredits += course.getNumberOfCredits();
        }
    
    return totalCredits;
}

void Student::setGpa(double gpa)
{
    this->gpa = gpa;
}

double Student::getGpa() const
{
    map<string,double> mymap;
    mymap["A+"] = 4.0;
    mymap["A"] = 4.0;
    mymap["A-"] = 3.7;
    mymap["B+"] = 3.3;
    mymap["B"] = 3.0;
    mymap["B-"] = 2.7;
    mymap["C+"] = 2.3;
    mymap["C"] = 2.0;
    mymap["C-"] = 1.7;
    mymap["D+"] = 1.3;
    mymap["D"] = 1.0;
    mymap["D-"] = 0.7;
    mymap["F"] = 0;
    
    double gpa = 0;
    
    for(auto course : *coursesTaken)
    {
        gpa += (course.getNumberOfCredits()) * mymap[course.getGradeReceived()];
    }
    
    gpa = gpa/(this->getTotalCredits());
    return gpa;
}


/*---------------------------------------------------------*/

/*--------------comparison,equality------------------------*/
bool operator==(const Student& a, const Student& b)
{
    return a.idNumber == b.idNumber;
}
bool operator<=(const Student& a, const Student& b)
{
    if(a.lastName < b.lastName) return true;
    else if(a.lastName == b.lastName)
        {
        if(a.idNumber < b.idNumber) return true;
        else if(a.idNumber == b.idNumber) return true;
        else return false;
        }
    else return false;
}
bool operator<(const Student& a, const Student& b)
{
    return a.lastName < b.lastName;
}
bool operator >(const Student& a, const Student& b)
{
    return a.lastName > b.lastName;
}

bool operator >=(const Student& a, const Student& b)
{
    if(a.lastName > b.lastName) return true;
    else if(a.lastName == b.lastName)
        {
        if(a.idNumber > b.idNumber) return true;
        else if(a.idNumber == b.idNumber) return true;
        else return false;
        
        }
    else return false;
}
/*----------------------------------------------------------*/


//tostring method

string Student::toString() const
{
    stringstream ss;
    ss << "Last Name: " << this->getLastName() << " First Name: " << this->getFirstName() << " ID: " << this->getIdNumber() << "\n";
    for (auto course : this->getCoursesTaken())
    {
        ss << course.toString();
    }
    ss << "Total Credits: "<< this-> getTotalCredits() << " GPA: " << this->getGpa() << endl;//conver to string;
    
    return ss.str();
}

void Student::addCourse(Course add_new_course) const
{
    coursesTaken->push_back(add_new_course);

}
void Student::deleteCourse(string courseCode) const
{
    auto it = searchCourse(courseCode);
    
    coursesTaken->erase(it);
}


vector<Course>::iterator Student::searchCourse(string courseCode) const
{
    vector<Course>::iterator it;
    for(it = coursesTaken->begin(); it != coursesTaken->end(); ++it)
    {
        if(it->getCourseNumber() == courseCode)
        {
            return it;
        }
    }
    return it;
}

/*
    //hash funtion
namespace std
{
    template<> struct hash<Student>
    {
        size_t operator()(const Student& s) const
        {
            string id = s.getIdNumber();
            string last3 = id.substr(id.size() - 3);
            return hash<string>{}(last3);
        }
    };
}*/

