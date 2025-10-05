#include "movies.h"
#include <QDebug>
#include <fstream>
#include <iostream>
using namespace std;

void Movies::add_to_collection(const Movie movie)
{
    collection.push_back(movie);
    qInfo() << "Movie added to library";
}

void Movies::show_movies()
{
    if (collection.empty()) {
        qInfo() << "Movies not found!\n";
    }
    for (auto m : collection) {
        m.show();
    }
}

void Movies::save_to_file(string filename) const
{
    std::ofstream out(filename);
    for (auto m : collection) {
        m.save_in_file(out);
    }
    qInfo() << "Collection saved!\n";
}

void Movies::load(string &filename)
{
    collection.clear();
    std::ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (!line.empty()) {
            collection.push_back(Movie::load_from_file(line));
        }
    }

    qInfo() << "Collection loaded!\n";
}

void Movies::increment_watch()

{
    if (collection.empty()) {
        qInfo() << "Collection is empty!";
    } else {
        qInfo() << "Select movie:'\n";

        while (true) {
            int i{1};
            for (auto &m : collection) {
                cout << i << ". ";
                m.show();
                ++i;
            }

            int choice{};
            cin >> choice;

            if (choice <= i - 1 && choice > 0) {
                collection[choice - 1].increment_watch();
                break;
            } else {
                qInfo() << "Movie not found, try again: \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}

bool Movies::if_title_exist(string t)
{
    for (auto m : collection) {
        if (m.check_title(t)) {
            return true;
        }
    }

    return false;
}
