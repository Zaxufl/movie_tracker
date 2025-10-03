#include "movie.h"
#include <QDebug>
#include <fstream>
using std::ofstream;

void Movie::save_to_file(ofstream &out) const
{
    out << title << ';' << rating << ';' << watched << '\n';
}

void Movie::show() const
{
    qInfo() << "Title: " << title << "; " << "Rating: " << "; " << "Watched: " << watched
            << " times";
}

Movie Movie::load(const string &line)
{
    size_t p1{line.find(';')};
    size_t p2{line.find(';', p1 + 1)};

    string t{line.substr(0, p1)};
    string r{line.substr(p1 + 1, p2 - p1 - 1)};
    int w{std::stoi(line.substr(p2 + 1))};

    return Movie(t, r, w);
}
