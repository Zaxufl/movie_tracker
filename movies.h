#ifndef MOVIES_H
#define MOVIES_H
#include "movie.h"
using namespace std;

class Movies
{
private:
    vector<Movie> collection;

public:
    void add(const Movie &);
    void save_to_file(const string &) const;
};

#endif // MOVIES_H
