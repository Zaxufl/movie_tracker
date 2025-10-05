#include "movie.h"
#include <QDebug>
#include <fstream>
#include <iostream>
using namespace std;

void Movie::save_in_file(std::ofstream &out)
{
    out << title << ';' << rating << ';' << watched << '\n';
}

void Movie::show()
{
    cout << "Title: " << title << " ; Rating: " << rating << " ; Watched " << watched << " times\n";
}

Movie Movie::load_from_file(const string &line)
{
    size_t p1{line.find(';')};
    size_t p2{line.find(';', p1 + 1)};

    string t{line.substr(0, p1)};
    string r{line.substr(p1 + 1, p2 - p1 - 1)};
    int w{stoi(line.substr(p2 + 1))};

    return Movie(t, r, w);
}

void Movie::increment_watch()
{
    ++watched;
}

bool Movie::check_title(string t)
{
    if (title == t) {
        qInfo() << "That title already exist\n";
        return true;
    }
    return false;
}
