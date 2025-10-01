#include <QDebug>
#include "movie.h"
#include "movies.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Movies movies;
    string filename{"movies.txt"};

    qInfo() << "Welcome to movie tracker!";
    qInfo() << "Menu";
    cout << '\t' << "1. Add Movie" << '\n';

    string title, rating;
    int watched{};

    cout << "Title: ";
    getline(cin, title);

    cout << "Rating: ";
    getline(cin, rating);

    cout << "How many times watched: ";
    cin >> watched;

    movies.add(Movie(title, rating, watched));

    movies.save_to_file(filename);

    qInfo() << "Movie added!";

    return 0;
}
