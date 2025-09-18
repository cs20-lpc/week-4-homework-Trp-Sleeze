#pragma once
#include <string>
#include <iostream>
#include "Course.hpp"

struct CourseNode {
    Course data;
    CourseNode* next;
    CourseNode(const Course& c) : data(c), next(nullptr) {}
};

class Student {
private:
    int id;
    std::string name;
    double gpa;
    CourseNode* coursesHead;

    void copyFrom(const Student& other);
    void clearCourses();
public:
    Student();
    Student(int id, const std::string& name, double gpa);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    int getId() const;
    std::string getName() const;
    double getGpa() const;

    void setName(const std::string& n);
    void setGpa(double g);

    void addCourse(const Course& c);
    bool hasCourses() const;
    void printCourses(std::ostream& out = std::cout) const;
};
