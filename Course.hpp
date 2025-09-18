#pragma once
#include <string>

class Course {
public:
    std::string name;
    int location;
    Course();
    Course(const std::string& n, int loc);
};
