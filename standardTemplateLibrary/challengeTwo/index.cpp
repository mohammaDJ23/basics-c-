#include <iostream>
#include <list>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <limits>
#include <string>
#include <sstream>

class Song
{
    friend std::ostream& operator<<(std::ostream& os, const Song& s);

private:
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name(name), artist(artist), rating(rating) {}

    std::string get_name() const { return this->name; }
    std::string get_artist() const { return this->artist; }
    int get_rating() const { return this->rating; }

    bool operator<(const Song& rhs) const { return this->name < rhs.name; }
    bool operator==(const Song& rhs) const { return this->name == rhs.name; }
};

std::ostream& operator<<(std::ostream& os, const Song& s)
{
    os << std::setw(25) << std::left << s.name
        << std::setw(30) << std::left << s.artist
        << std::setw(5) << std::left << s.rating
        << std::endl;
    return os;
}

class Songs
{
private:
    std::list<Song> songs;
    std::list<Song>::const_iterator current_song_it;

public:
    Songs()
        : songs({
            {"God's Plan", "Drake", 5},
            {"Never Be The Same", "Camila Cabello", 5},
            {"Pray For Me", "The Weekend and K. Lamar", 4},
            {"The Middle", "Zedd, maren Morris & Grey", 5},
            {"Wait", "Maroone 5", 4},
            {"Whatever It Takes", "Imagine Dragons", 3}}),
        current_song_it(songs.begin()) {}

    bool is_currnet_song_it_exist(const std::list<Song>::const_iterator& it) const
    {
        return it != this->songs.cend();
    }

    void display_song(const Song& song) const
    {
        std::cout << song;
    }

    void play_first_song()
    {
        this->current_song_it = songs.cbegin();
        this->display_song(*this->current_song_it);
    }

    void play_next_song()
    {
        this->current_song_it++;
        if (!this->is_currnet_song_it_exist(this->current_song_it))
            this->current_song_it = songs.cbegin();
        this->display_song(*this->current_song_it);
    }

    void play_previous_song()
    {
        this->current_song_it--;
        if (!this->is_currnet_song_it_exist(this->current_song_it))
            this->current_song_it = --songs.cend();
        this->display_song(*this->current_song_it);
    }

    void add_song()
    {
        auto it = std::find(this->songs.cbegin(), this->songs.cend(), *this->current_song_it);
        if (!this->is_currnet_song_it_exist(it))
            std::cout << "Not found the song" << std::endl;
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string str;
            std::istringstream iss;
            std::string name;
            std::string artist;
            int rating;

            do
            {
                std::cin.clear();
                iss.clear();
                std::cout << "Enter a name, artist and rating seperated by an space: ";
                std::getline(std::cin, str);
                iss.str(str);
            } while (!(iss >> name >> artist >> rating));

            this->songs.insert(it, Song {name, artist, rating});
            std::cout << "A new song inserted." << std::endl;
            this->current_song_it--;
        }
    }

    void display_playlist() const
    {
        std::for_each(this->songs.cbegin(),
            this->songs.cend(),
            [this] (const Song& song) { this->display_song(song); });
        std::cout << std::endl;
        std::cout << "Current song: " << std::endl;
        this->display_song(*this->current_song_it);
    }
};

void display_menu()
{
    std::cout << std::endl;
    std::cout << "F - play first song" << std::endl;
    std::cout << "N - play next song" << std::endl;
    std::cout << "P - play previous song" << std::endl;
    std::cout << "A - add and play a new song at current location" << std::endl;
    std::cout << "L - list the current playlist" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

int main()
{
    Songs songs;
    char option {0};

    do
    {
        display_menu();
        std::cin >> option;
        option = std::tolower(option);
        std::cout << std::endl;

        switch (option)
        {
            case 'f': songs.play_first_song(); break;
            case 'n': songs.play_next_song(); break;
            case 'a': songs.add_song(); break;
            case 'p': songs.play_previous_song(); break;
            case 'l': songs.display_playlist(); break;
            default: break;
        }
    } while (option != 'q');
    
    return 0;
}
