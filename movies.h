#ifndef MOVIES_H
#define MOVIES_H
#include "movie.h"
#include <vector>

class Movies
{
    std::vector<Movie> collection;

public:
    void add_to_collection(const Movie);
    void show_movies();
    void save_to_file(string) const;
    void load(string &);
    void increment_watch();
    bool if_title_exist(string);
};

#endif // MOVIES_H
