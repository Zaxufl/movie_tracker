#include "movie.h"
#include <fstream>
using namespace std;

void Movie::save(ofstream &out) const
{
    out << name << " " << movie_rating << " " << watched << '\n';
}
