#ifndef CIRCULAR_PLAYLIST_H
#define CIRCULAR_PLAYLIST_H

#include <string>
#include <cstddef>
#include <vector>

class CircularPlaylist {
private:
    struct Node {
        std::string title;
        Node* next;
        Node* prev;

        Node(const std::string& t) : title(t), next(nullptr), prev(nullptr) {}
    };

    Node* head;         // logical start of playlist
    Node* current;      // “now playing”
    std::size_t count;  // number of songs

    Node* getNodeAt(std::size_t index) const;

public:
    CircularPlaylist();
    ~CircularPlaylist();

    // Basic info
    bool empty() const;
    std::size_t size() const;

    // Insertions
    void pushFront(const std::string& title);
    void pushBack(const std::string& title);
    bool insertAt(std::size_t index, const std::string& title);

    // Removals
    bool removeAt(std::size_t index);
    bool removeByTitle(const std::string& title);
    void clear();

    // Search
    int find(const std::string& title) const;

    // Traversal
    void printForward() const;
    void printBackward() const;

    // Player-like movement
    const std::string* getCurrent() const;
    void nextSong();
    void prevSong();
    void resetToHead();


    void shuffle();  // jump to a random song
};

#endif
