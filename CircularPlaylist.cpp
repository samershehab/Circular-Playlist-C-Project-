#include "CircularPlaylist.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

CircularPlaylist::CircularPlaylist() : head(nullptr), current(nullptr), count(0) {
    std::srand(std::time(nullptr)); // used for shuffle feature
}

CircularPlaylist::~CircularPlaylist() {
    clear();
}

bool CircularPlaylist::empty() const {
    return count == 0;
}

std::size_t CircularPlaylist::size() const {
    return count;
}

void CircularPlaylist::clear() {
    if (!head) return;

    Node* node = head;
    for (std::size_t i = 0; i < count; i++) {
        Node* nxt = node->next;
        delete node;
        node = nxt;
    }

    head = nullptr;
    current = nullptr;
    count = 0;
}

CircularPlaylist::Node* CircularPlaylist::getNodeAt(std::size_t index) const {
    if (!head || index >= count) return nullptr;

    Node* node = head;
    for (std::size_t i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

void CircularPlaylist::pushFront(const std::string& title) {
    Node* node = new Node(title);

    if (!head) {
        node->next = node;
        node->prev = node;
        head = node;
        current = node;
    } else {
        Node* tail = head->prev;
        node->next = head;
        node->prev = tail;
        head->prev = node;
        tail->next = node;
        head = node;
    }

    count++;
}

void CircularPlaylist::pushBack(const std::string& title) {
    if (!head) {
        pushFront(title);
        return;
    }

    Node* node = new Node(title);
    Node* tail = head->prev;

    node->next = head;
    node->prev = tail;
    tail->next = node;
    head->prev = node;

    count++;
}

bool CircularPlaylist::insertAt(std::size_t index, const std::string& title) {
    if (index > count) return false;
    if (index == 0) { pushFront(title); return true; }
    if (index == count) { pushBack(title); return true; }

    Node* before = getNodeAt(index - 1);
    Node* after = before->next;

    Node* node = new Node(title);
    node->next = after;
    node->prev = before;
    before->next = node;
    after->prev = node;

    count++;
    return true;
}

bool CircularPlaylist::removeAt(std::size_t index) {
    if (!head || index >= count) return false;

    Node* node = getNodeAt(index);

    if (count == 1) {
        delete node;
        head = nullptr;
        current = nullptr;
        count = 0;
        return true;
    }

    Node* a = node->prev;
    Node* b = node->next;

    a->next = b;
    b->prev = a;

    if (node == head) head = b;
    if (node == current) current = b;

    delete node;
    count--;
    return true;
}

bool CircularPlaylist::removeByTitle(const std::string& title) {
    for (std::size_t i = 0; i < count; i++) {
        if (getNodeAt(i)->title == title) {
            return removeAt(i);
        }
    }
    return false;
}

int CircularPlaylist::find(const std::string& title) const {
    for (std::size_t i = 0; i < count; i++) {
        if (getNodeAt(i)->title == title) return static_cast<int>(i);
    }
    return -1;
}

void CircularPlaylist::printForward() const {
    if (!head) {
        std::cout << "[empty playlist]\n";
        return;
    }

    Node* node = head;
    for (std::size_t i = 0; i < count; i++) {
        std::cout << i << ". " << node->title << "\n";
        node = node->next;
    }
}

void CircularPlaylist::printBackward() const {
    if (!head) {
        std::cout << "[empty playlist]\n";
        return;
    }

    Node* node = head->prev;
    for (std::size_t i = 0; i < count; i++) {
        std::cout << i << ". " << node->title << "\n";
        node = node->prev;
    }
}

const std::string* CircularPlaylist::getCurrent() const {
    return current ? &current->title : nullptr;
}

void CircularPlaylist::nextSong() {
    if (current) current = current->next;
}

void CircularPlaylist::prevSong() {
    if (current) current = current->prev;
}

void CircularPlaylist::resetToHead() {
    current = head;
}

void CircularPlaylist::shuffle() {
    if (!head) return;
    int steps = std::rand() % count;
    for (int i = 0; i < steps; i++) current = current->next;
}
