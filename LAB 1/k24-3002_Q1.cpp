#include <iostream>
#include <cstring>

using namespace std;
class Student {
private:
    char* name;      
    double* marks;

public:
	
    Student(const char* student_name = "Unknown") {
        name = new char[strlen(student_name) + 1]; 
        strcpy(name, student_name); 
        marks = new double[3]; 
        cout << "Student created: " << name << endl;
    }

    ~Student() {
        delete[] name;  
        delete[] marks;
        cout << "Student destroyed: " << name << endl;
    }

    void setMarks(double mark1, double mark2, double mark3) {
        marks[0] = mark1;
        marks[1] = mark2;
        marks[2] = mark3;
    }

    void displayAverage() const {
        double average = (marks[0] + marks[1] + marks[2]) / 3;
        cout << name << "'s Average Marks: " << average << endl;
    }

    Student(const Student& other) {
        name = other.name;        
        marks = other.marks;      
        cout << "Shallow copy created for: " << name << endl;
    }

    void display() const {
		cout << "Name: " << name << "\nMarks: " 
                  << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
    }
};

int main() {
	
    Student student1("John Doe");
    student1.setMarks(85.5, 90.0, 78.0);
    student1.displayAverage(); 

    Student student2 = student1;

    student2.setMarks(88.0, 92.5, 79.5);
    student2.displayAverage(); 

    cout << "\nStudent1 details after copying:\n";
    student1.display();

    cout << "\nStudent2 details after copying:\n";
    student2.display();

    cout << "\nDestroying student1...\n";

    return 0;  
}
