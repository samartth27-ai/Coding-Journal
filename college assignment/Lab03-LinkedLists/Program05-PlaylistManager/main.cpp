/**
 * @file main.cpp
 * @brief Interactive Music Playlist Manager using Circular Doubly Linked List
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <string>

struct Song {
    std::string title;
    std::string artist;
    double durationMinutes;
    Song* next;
    Song* prev;

    Song(std::string t, std::string a, double d)
        : title(std::move(t)), artist(std::move(a)), durationMinutes(d), next(nullptr), prev(nullptr) {}
};

class MusicPlaylistManager {
private:
    Song* currentSong;
    int songCount;

public:
    MusicPlaylistManager() : currentSong(nullptr), songCount(0) {}

    ~MusicPlaylistManager() {
        if (!currentSong) return;
        Song* curr = currentSong;
        for (int i = 0; i < songCount; ++i) {
            Song* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void addSong(const std::string& title, const std::string& artist, double duration) {
        Song* newSong = new Song(title, artist, duration);
        if (!currentSong) {
            currentSong = newSong;
            currentSong->next = currentSong;
            currentSong->prev = currentSong;
        } else {
            Song* tail = currentSong->prev;
            tail->next = newSong;
            newSong->prev = tail;
            newSong->next = currentSong;
            currentSong->prev = newSong;
        }
        songCount++;
        std::cout << "[Playlist] Added: \"" << title << "\" by " << artist << "\n";
    }

    void playCurrent() const {
        if (!currentSong) {
            std::cout << "[Player] Playlist is currently empty.\n";
            return;
        }
        std::cout << "\n>>> NOW PLAYING: \"" << currentSong->title 
                  << "\" by " << currentSong->artist 
                  << " (" << currentSong->durationMinutes << " mins) <<<\n";
    }

    void playNext() {
        if (!currentSong) return;
        currentSong = currentSong->next;
        std::cout << "\n[Action] Skipped to Next Song >>";
        playCurrent();
    }

    void playPrevious() {
        if (!currentSong) return;
        currentSong = currentSong->prev;
        std::cout << "\n[Action] << Went Back to Previous Song";
        playCurrent();
    }

    void displayPlaylist() const {
        if (!currentSong) {
            std::cout << "[Playlist] No tracks available.\n";
            return;
        }
        std::cout << "\n=======================================================\n";
        std::cout << "           MUSIC PLAYLIST (Total: " << songCount << " songs)\n";
        std::cout << "=======================================================\n";
        Song* temp = currentSong;
        for (int i = 1; i <= songCount; ++i) {
            std::cout << (temp == currentSong ? " -> [CURRENT] " : "    [TRACK " + std::to_string(i) + "] ");
            std::cout << temp->title << " - " << temp->artist 
                      << " (" << temp->durationMinutes << " min)\n";
            temp = temp->next;
        }
        std::cout << "=======================================================\n";
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Music Playlist Manager\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n";

    MusicPlaylistManager playlist;
    playlist.addSong("Tum Hi Ho", "Arijit Singh", 4.22);
    playlist.addSong("Kesariya", "Arijit Singh", 4.28);
    playlist.addSong("Chaiyya Chaiyya", "Sukhwinder Singh", 5.40);
    playlist.addSong("Kun Faya Kun", "A.R. Rahman", 7.53);

    playlist.displayPlaylist();
    playlist.playCurrent();

    // Demonstrate circular next navigation
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();
    playlist.playNext(); // Loops back seamlessly to the start!

    // Demonstrate circular backward navigation
    playlist.playPrevious();

    return 0;
}
