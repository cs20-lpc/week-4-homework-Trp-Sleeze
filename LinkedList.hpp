#pragma once
#include <iostream>
#include "Student.hpp"

struct Node {
    Student data;
    Node* next;
    Node(const Student& s) : data(s), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();

    void insertEnd(const Student& s);
    bool deleteById(int id);
    Node* searchById(int id) const;
    void displayAll() const;
    int count() const;
    bool addCourseToStudent(int id, const Course& c);
};
