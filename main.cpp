#include <QDebug>
#include "movie.h"
#include "movies.h"
#include <iostream>
using namespace std;

void add_movie(Movies &);

int main(int argc, char *argv[])
{
    string filename{"watched_movies.txt"};
    Movies movies;

    while (true) {
        qInfo() << "Select option from the menu:";
        qInfo() << "\t1. Add movie";
        qInfo() << "\t2. Check movies";
        qInfo() << "\t3. Save to file";
        qInfo() << "\t4. Load from file";
        qInfo() << "\t5. Exit program";

        int num;
        cin >> num;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (num == 1) {
            add_movie(movies);
        } else if (num == 2) {
            movies.show_movies();
        } else if (num == 3) {
            movies.save_movies(filename);
        } else if (num == 4) {
            movies.load_from_file(filename);
        } else if (num == 5) {
            break;
        } else {
            qInfo() << "Wrong key, try again:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}

void add_movie(Movies &collection)
{
    string title, rating;
    int watched;

    cout << "Movie title: ";
    getline(cin, title);

    cout << "Movie rating: ";
    getline(cin, rating);

    cout << "Watched times: ";

    while (true) {
        cin >> watched;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    collection.to_collection(Movie(title, rating, watched));
}
