#ifndef MOVIE_H
#define MOVIE_H

#include <fstream>
#include <string>
using namespace std;

class Movie
{
    string title, rating;
    int watched{};

public:
    Movie(string t, string r, int w)
        : title{t}
        , rating{r}
        , watched{w} {};
    void save_to_file(ofstream &out) const;
    void show() const;
    static Movie load(const string &);
};

#endif // MOVIE_H
