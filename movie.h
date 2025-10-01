#include <QDebug>
#include <fstream>
#include <string>
using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie
{
private:
    string name;
    string movie_rating;
    int watched{};

public:
    Movie(string n, string r, int w)
        : name{n}
        , movie_rating{r}
        , watched{w} {};
    void save(ofstream &out) const;
};

#endif // MOVIE_H
