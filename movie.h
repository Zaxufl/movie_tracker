#ifndef MOVIE_H
#define MOVIE_H

#include <fstream>
#include <string>
using std::string;

class Movie
{
    string title, rating;
    int watched;

public:
    Movie(string t, string r, int w)
        : title{t}
        , rating{r}
        , watched{w} {};
    void save_in_file(std::ofstream &);
    void show();
    static Movie load_from_file(const string &);
    void increment_watch();
    bool check_title(string);
};

#endif // MOVIE_H
