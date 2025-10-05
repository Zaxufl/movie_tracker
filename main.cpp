#include <QDebug>
#include "movies.h"
#include <iostream>
using namespace std;
void cin_clear();
bool add_movie(Movies &);

int main()
{
    Movies movies;
    string filename{"my_movies.txt"};

    while (true) {
        qInfo() << "Movie tracker menu: ";
        qInfo() << "\t1. Add movie";
        qInfo() << "\t2. Show movies";
        qInfo() << "\t3. Save to file";
        qInfo() << "\t4. Load from file";
        qInfo() << "\t5. Increment watch time by 1";
        qInfo() << "\t6. Quit";

        int choice{};
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            if (add_movie(movies)) {
                continue;
            }
        } else if (choice == 2) {
            movies.show_movies();
        } else if (choice == 3) {
            movies.save_to_file(filename);
        } else if (choice == 4) {
            movies.load(filename);
        } else if (choice == 5) {
            movies.increment_watch();
        } else if (choice == 6) {
            break;
        } else {
            cout << "Wrong key! try again: ";
            cin_clear();
        }
    }

    return 0;
}

bool add_movie(Movies &collection)
{
    string title, rating;
    int watched{};

    cout << "Title: ";
    getline(cin, title);

    if (collection.if_title_exist(title)) {
        return true;
    }

    cout << "Rating: ";
    getline(cin, rating);

    cout << "How many times watched: ";
    cin >> watched;

    collection.add_to_collection(Movie(title, rating, watched));

    return false;
}

void cin_clear()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
