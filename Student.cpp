#include "Student.hpp"

Student::Student() : id(0), name(""), gpa(0.0), coursesHead(nullptr) {}

Student::Student(int id, const std::string& name, double gpa)
    : id(id), name(name), gpa(gpa), coursesHead(nullptr) {}

void Student::copyFrom(const Student& other) {
    id = other.id;
    name = other.name;
    gpa = other.gpa;
    coursesHead = nullptr;
    CourseNode* cur = other.coursesHead;
    CourseNode* tail = nullptr;
    while (cur) {
        CourseNode* n = new CourseNode(cur->data);
        if (!coursesHead) {
            coursesHead = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        cur = cur->next;
    }
}

void Student::clearCourses() {
    CourseNode* cur = coursesHead;
    while (cur) {
        CourseNode* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    coursesHead = nullptr;
}

Student::Student(const Student& other) : id(0), gpa(0.0), coursesHead(nullptr) {
    copyFrom(other);
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        clearCourses();
        copyFrom(other);
    }
    return *this;
}

Student::~Student() {
    clearCourses();
}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
double Student::getGpa() const { return gpa; }

void Student::setName(const std::string& n) { name = n; }
void Student::setGpa(double g) { gpa = g; }

void Student::addCourse(const Course& c) {
    CourseNode* n = new CourseNode(c);
    if (!coursesHead) {
        coursesHead = n;
    } else {
        CourseNode* cur = coursesHead;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
}

bool Student::hasCourses() const {
    return coursesHead != nullptr;
}

void Student::printCourses(std::ostream& out) const {
    if (!coursesHead) {
        out << "None";
        return;
    }
    CourseNode* cur = coursesHead;
    while (cur) {
        out << "\n  " << cur->data.name << " " << cur->data.location;
        cur = cur->next;
    }
}
