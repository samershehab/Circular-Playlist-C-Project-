# Circular Playlist C++ Project
Circular Playlist C++ Project
Project Overview

This project implements a simple music playlist system using a circular linked list in C++. The goal was to build a playlist where songs loop continuously, allowing forward navigation, backward navigation, and a shuffle feature. The project demonstrates understanding of dynamic memory, pointers, node structures, and modular program design.

Data Structure Implemented

A circular singly linked list is used to store and navigate through songs.
Each song is represented as a node containing:

A song title

A pointer to the next node
Because the last song points back to the first song, the playlist loops forever.

How the Data Structure Works 


[Song 1] → [Song 2] → [Song 3]
   
      ↑                 ↓
      
←←←←←← circular loop ←←←←←←


And the structure of each node:

+-----------+
|  title    |
|  next ----|---->
+-----------+

File Structure
CircularPlaylist.h      → Class definition and node structure
CircularPlaylist.cpp    → Method implementations (add, remove, next, prev, shuffle)
main.cpp                → Driver program that runs the playlist

Description of the Data Structure

The circular playlist behaves like a normal list, except it never stops.
When the program reaches the last song and you call nextSong(), it loops back to the first.
This makes it ideal for media queues, where continuous looping is required.

Key features implemented:

Add a new song

Display all songs

Move to the next or previous song

Reset to the head

Shuffle to a random song

Automatically loop back to the beginning

How to Run the Program

If you want to build and run the program locally:

1. Compile
g++ CircularPlaylist.cpp main.cpp -o playlist

2. Run
./playlist

If running in VS Code or Jupyter

Just run the file normally using the terminal you have already set up.

If the Instructor Wants to See the Program Running

If compiling is not possible on their end, I recommend either:

Uploading a short video demo to Google Drive/YouTube, or

Adding screenshots of the program running in your terminal

Both are acceptable based on the assignment instructions.

Why This Project Matters

This project shows practical use of:

Pointers

Dynamic memory

Structs and classes

Linked data structures

Modular programming

It also demonstrates the ability to design a functional system rather than just isolated functions.
I built this project to practice circular linked lists, pointer handling, class design, and dynamic memory management in C++. It also served as a hands-on way to learn how circular structures behave in real applications such as music players.

Instructor Access

The repository is public.
