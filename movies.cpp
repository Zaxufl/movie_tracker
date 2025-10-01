#include "movies.h"
#include <fstream>
using namespace std;

void Movies::add(const Movie &m)
{
    collection.push_back(m);
};

void Movies::save_to_file(const string &filename) const
{
    ofstream out(filename);
    for (const auto &m : collection) {
        m.save(out);
    }
}
