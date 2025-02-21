#include <iostream>

struct StudentBook {
    char* name;
    int facultyNumber;
    int gradeCount;
    double* grades;
};

void addGrade(StudentBook* book, double grade) {
    book->grades[book->gradeCount++] = grade;
}

void sortGrades(StudentBook* book) {
    for (int i = 0; i < book->gradeCount - 1; i++) {
        for (int j = 0; j < book->gradeCount - i - 1; j++) {
            if (book->grades[j] < book->grades[j + 1]) {
                std::swap(book->grades[j], book->grades[j + 1]);
            }
        }
    }
}

double calculateAverage(StudentBook* book, bool excludeFailed) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < book->gradeCount; i++) {
        if (!excludeFailed || book->grades[i] >= 3.0) {
            sum += book->grades[i];
            count++;
        }
    }
    return count > 0 ? sum / count : 0;
}

bool canAdvanceToNextYear(StudentBook* book) {
    int failedExams = 0;
    for (int i = 0; i < book->gradeCount; i++) {
        if (book->grades[i] < 3.0) {
            failedExams++;
        }
    }
    if (failedExams < 4) return true;
    if (failedExams > 4) return false;
    return calculateAverage(book, true) >= 4.0;
}

bool qualifiesForScholarship(StudentBook* book) {
    return calculateAverage(book, true) >= 5.0 && canAdvanceToNextYear(book);
}

int main() {
    StudentBook student;
    student.name = new char[50]{"John Doe"};
    student.facultyNumber = 12345;
    student.gradeCount = 0;
    student.grades = new double[10];

    addGrade(&student, 5.5);
    addGrade(&student, 6.0);
    addGrade(&student, 4.2);
    addGrade(&student, 2.9);
    
    sortGrades(&student);
    
    std::cout << "Average grade: " << calculateAverage(&student, true) << std::endl;
    std::cout << "Can advance to next year: " << (canAdvanceToNextYear(&student) ? "Yes" : "No") << std::endl;
    std::cout << "Qualifies for scholarship: " << (qualifiesForScholarship(&student) ? "Yes" : "No") << std::endl;
    
    delete[] student.name;
    delete[] student.grades;
    return 0;
}
