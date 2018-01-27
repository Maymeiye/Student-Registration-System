//Mei Ye 23459517

#include<vector>
#include<algorithm>
#include <unordered_set>

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
}


class Registration
{
    public:
    /*  I use unordered_set to maintain the registration,the elements in the unordered_set are not sorted in any particular order, but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their values (with a constant average time complexity on average).
        
        The most impotant things I need to do is to add hash fuction into Registration class, so than the student ID can be use as a value to store in hash table.
     
         */
    
        unordered_set<Student> registStudents;// use Sets instesd of vector
        void loadData(string x);
        void displayRegistration();
        void saveData(string x);
        void addStudent(Student add_new_student);
        void deleteStudent(string x);
        unordered_set<Student>::iterator searchStudent(string x);//use Sets instesd of vector
};

/*---------------------------------------------------------*/

void Registration::loadData(string x)
{
        ifstream readin_data(x.c_str(), ifstream::in);
    
        while(!readin_data.eof())
        {
            Student student;
            string line;
            size_t begin = 0, end;
            getline(readin_data, line);
        
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
        
            getline(readin_data, line);
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
            
                getline(readin_data, line);
            }
        
            student.setCoursesTaken(courses);
        
            getline(readin_data, line);
        
            begin = 0;
            end = line.find(',', begin);
            string totalcredits = line.substr(begin, end);
            double dbltotalcredits = atof(totalcredits.c_str());//  convert string to double type
            student.setTotalCredits(dbltotalcredits);
        
            begin = end + 1;
            end = line.find(',', begin);
            string GPA = line.substr(begin, end - begin);
            double dblgpa = atof(GPA.c_str());//convert string to double type
            student.setGpa(dblgpa);
        
            registStudents.insert(student);
        }
    
        readin_data.close();
    
        // sort(registStudents.begin(), registStudents.end());
}

void Registration::displayRegistration()
{
    for (auto student : registStudents)
    {
        cout << student.toString();
        cout << endl;
    }
}


/*-------------------------------------------------------------------*/

void Registration::addStudent(Student add_new_student)
{
        // since Sets are implemented as binary search trees which has been already ordered, I don't need to use compare method to insert a new student.
    registStudents.insert(add_new_student);
    
    
    /*<Student>::iterator it;
    for(it = registStudents.begin(); it != registStudents.end(); ++it)
    {
        if(*it > add_new_student)
        {
            registStudents.insert(it, add_new_student);
            return;
        }
    }
    registStudents.push_back(add_new_student);*/
   
    
}

void Registration::deleteStudent(string x)
{
    auto it = searchStudent(x);
 
          registStudents.erase(it);
}

unordered_set<Student>::iterator Registration::searchStudent(string x)
{
    unordered_set<Student>::iterator it;
    for(it = registStudents.begin(); it != registStudents.end(); ++it)
    {
    if(it->getLastName() == x)
        {
        return it;
        }
    }
    return it;
}

/*-------------------------------------------------------------------*/
void Registration :: saveData(string x)
{
    ofstream output_data;
    output_data.open(x);
    for(auto student : registStudents)
    {
        output_data << student.getLastName()<<","<< student.getFirstName() <<","<< student.getIdNumber() <<endl;
    
        for(auto course : student.getCoursesTaken())
        {
            output_data << course.getCourseNumber() <<","<< course.getNumberOfCredits() <<","<< course.getGradeReceived() << endl;
        
        }
    
        output_data << "-999"<< endl;
        output_data << student.getTotalCredits()<<","<< student.getGpa() << endl;
    }
    
    output_data.close();
}







