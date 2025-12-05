# Circular Playlist C++ Project
This project implements a circular playlist using a circular singly linked list in C++. The playlist allows songs to be added, removed, shuffled, and played in a continuous loop. It demonstrates understanding of pointer manipulation, dynamic memory, and object-oriented design.

Data Structure Implemented

The core of the project is a circular singly linked list. Each node stores a song title and a pointer to the next node. The final node always connects back to the first, forming a circle.

How the Circular Playlist Works

The CircularPlaylist class provides the main operations:

Add a new song

Remove a song by title

Move to the next or previous song

Shuffle by randomly advancing a number of steps

Display the entire playlist

Reset the current pointer back to the head

Because the list is circular, navigating forward never stops. Once you reach the last song, the next pointer loops back to the first.

Circular Playlist Diagram

[Song 1] → [Song 2] → [Song 3]
     
      ↑                 ↓
      ←←←←← circular loop ←←←←←


This diagram shows that the last node points back to the first, creating a continuous loop.

Files Included

CircularPlaylist.h – class definition

CircularPlaylist.cpp – method implementations

main.cpp – driver program with a menu interface

How to Run the Program
If using Linux / Mac / VS Code terminal:
g++ main.cpp CircularPlaylist.cpp -o playlist
./playlist

On Windows (MinGW or WSL):
g++ main.cpp CircularPlaylist.cpp -o playlist.exe
playlist.exe

What the Program Does

When you run the program, it opens a text-based menu that lets you add songs, remove songs, shuffle the playlist, move forward or backward, and print all songs. You can also reset to the first song. The circular structure ensures playback never reaches a dead end.

Purpose of the Project

I built this project to practice circular linked lists, pointer handling, class design, and dynamic memory management in C++. It also served as a hands-on way to learn how circular structures behave in real applications such as music players.

Instructor Access

The repository is public.
