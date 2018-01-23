
class Student
{
    private:
        string firstName;
        string lastName;
        string idNumber;
        vector<Course> coursesTaken;
        double totalCredits;
        double gpa;
    
    public:
        void setFirstName(string firstName);
        string getFirstName();
    
        void setLastName(string lastName);
        string getLastName();
    
        void setIdNumber(string idNumber);
        string getIdNumber();
    
        void setCoursesTaken(vector<Course> x);
        vector<Course> getCoursesTaken();
    
        void setTotalCredits(double credits);
        double getTotalCredits();
    
        void setGpa(double gpa);
        double getGpa();
    
        //operator overlaoded for comparison based on lastName
        //and equality test based on idNo
        friend bool operator==(const Student& a, const Student& b);
        friend bool operator<=(const Student& a, const Student& b);
        friend bool operator<(const Student& a, const Student& b);
        friend bool operator>(const Student& a, const Student& b);
        friend bool operator>=(const Student& a, const Student& b);
    
        string toString();
};

/*------------getter and setter method-------------------*/
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
string Student::getFirstName()
{
    return firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
string Student::getLastName()
{
    return lastName;
}

void Student::setIdNumber(string idNumber)
{
    this->idNumber = idNumber;
}
string Student::getIdNumber()
{
    return idNumber;
}

void Student::setCoursesTaken(vector<Course> x)
{
    this->coursesTaken = x;
}
vector<Course> Student::getCoursesTaken()
{
    return coursesTaken;
}

void Student::setTotalCredits(double credits)
{
    this->totalCredits = credits;
}
double Student::getTotalCredits()
{
    double totalCredits = 0;
    for(auto course : coursesTaken)
        {
            totalCredits += course.getNumberOfCredits();
        }
    
    return totalCredits;
}

void Student::setGpa(double gpa)
{
    this->gpa = gpa;
}

double Student::getGpa()
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
    
    for(auto course : coursesTaken)
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

string Student::toString()
{
    stringstream ss;
    ss << "Last Name: " << this->getLastName() << " First Name: " << this->getFirstName() << " ID: " << this -> getIdNumber() << "\n";
    for (auto course : this->getCoursesTaken())
    {
        ss << course.toString();
    }
    ss << "Total Credits: "<< this-> getTotalCredits() << " GPA: " << this->getGpa() << endl;//conver to string;
    
    return ss.str();
}

