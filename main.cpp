#include <iostream>
#include <string>
#include "CircularPlaylist.h"

int main() {
    CircularPlaylist playlist;

    playlist.pushBack("Song A");
    playlist.pushBack("Song B");
    playlist.pushBack("Song C");
    playlist.pushBack("Song D");

    std::cout << "Initial playlist:\n";
    playlist.printForward();

    std::cout << "\nCurrent song: " << *playlist.getCurrent() << "\n";

    playlist.nextSong();
    std::cout << "After next(): " << *playlist.getCurrent() << "\n";

    playlist.prevSong();
    std::cout << "After prev(): " << *playlist.getCurrent() << "\n";

    std::cout << "\nShuffle!\n";
    playlist.shuffle();
    std::cout << "Shuffled to: " << *playlist.getCurrent() << "\n";

    return 0;
}
