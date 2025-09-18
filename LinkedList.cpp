#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

void LinkedList::insertEnd(const Student& s) {
    Node* n = new Node(s);
    if (!head) {
        head = n;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

bool LinkedList::deleteById(int id) {
    if (!head) return false;
    if (head->data.getId() == id) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }
    Node* cur = head;
    while (cur->next && cur->next->data.getId() != id) {
        cur = cur->next;
    }
    if (cur->next) {
        Node* toDel = cur->next;
        cur->next = cur->next->next;
        delete toDel;
        return true;
    }
    return false;
}

Node* LinkedList::searchById(int id) const {
    Node* cur = head;
    while (cur) {
        if (cur->data.getId() == id) return cur;
        cur = cur->next;
    }
    return nullptr;
}

void LinkedList::displayAll() const {
    std::cout << "Students in List:\n";
    Node* cur = head;
    if (!cur) {
        std::cout << "(empty)\n";
        return;
    }
    while (cur) {
        std::cout << cur->data.getId() << " "
                  << cur->data.getName() << " "
                  << cur->data.getGpa() << " ";
        cur->data.printCourses(std::cout);
        std::cout << "\n";
        cur = cur->next;
    }
}

int LinkedList::count() const {
    int c = 0;
    Node* cur = head;
    while (cur) { c++; cur = cur->next; }
    return c;
}

bool LinkedList::addCourseToStudent(int id, const Course& c) {
    Node* found = searchById(id);
    if (!found) return false;
    found->data.addCourse(c);
    return true;
}
