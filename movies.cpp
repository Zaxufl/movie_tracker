#include "movies.h"
#include <QDebug>
#include <fstream>
using namespace std;

void Movies::to_collection(const Movie &movie)
{
    movies.push_back(movie);
    qInfo() << "Movie added to collection";
}

void Movies::show_movies() const
{
    if (movies.empty()) {
        qInfo() << "Movies not found!";
    } else {
        for (auto &m : movies) {
            m.show();
        }
    }
}

void Movies::save_movies(string filename) const
{
    ofstream out(filename);
    for (auto &m : movies) {
        m.save_to_file(out);
    }
    qInfo() << "Colection saved!";
}

void Movies::load_from_file(const string &filename)
{
    movies.clear();
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (!line.empty()) {
            movies.push_back(Movie::load(line));
        }
    }
    qInfo() << "File loaded successfully";
}
