
#include<string>

class Course
{
    private:
        string courseNumber;
        double numberOfCredits;
        string gradeReceived;
    
    public:
        void setCourseNumber(string courseNumber);
        string getCourseNumber();
    
        void setNumberOfCredits(double numberOfCredits);
        double getNumberOfCredits();
    
        void setGradeReceived(string gradeReceived);
        string getGradeReceived();
    
        friend bool operator==(const Course& a, const Course& b);

          //tostring
        string toString();
};

/*--------------getter and setter method-------------*/
void Course::setCourseNumber(string courseNumber)
{
    this->courseNumber = courseNumber;
}
string Course::getCourseNumber()
{
    return courseNumber;
}

void Course::setNumberOfCredits(double numberOfCredits)
{
    this->numberOfCredits = numberOfCredits;
}
double Course::getNumberOfCredits()
{
    return numberOfCredits;
}

void Course::setGradeReceived(string gradeReceived)
{
    this->gradeReceived = gradeReceived;
}
string Course::getGradeReceived()
{
    return gradeReceived;
}
/*--------------------------------------------------*/

/*----------------operator overloaded---------------*/
bool operator==(const Course& a, const Course& b)
{
    return a.courseNumber == b.courseNumber;
}
/*-------------------------------------------------*/

string Course::toString()
{
    stringstream ss;
    ss << "Course Code: "<< this->getCourseNumber() << " Credits: " << this->getNumberOfCredits() <<" Grade: "<< this->getGradeReceived() << endl;
    return ss.str();
}




