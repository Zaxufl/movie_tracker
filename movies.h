#ifndef MOVIES_H
#define MOVIES_H
#include "movie.h"
#include <vector>

class Movies
{
    vector<Movie> movies;

public:
    void save_movies(string) const;
    void to_collection(const Movie &);
    void show_movies() const;
    void load_from_file(const string &);
};

#endif // MOVIES_H
