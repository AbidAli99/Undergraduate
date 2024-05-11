#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>

using namespace std;

/*
 * IMPORTANT NOTE:
 *
 * For this assignment, you might need to add state to the
 * class and/or augment existing methods, and/or create helper
 * methods, but you shold not delare new public methods
 */

const bool INFECTED = true;
const bool NOT_INFECTED = false;

class grid;

class grid {

  private:
    int rows;
    int cols;
    vector<bool> *area;
    vector<string> *visited;
    int indexof (int row, int col) const;
	bool infected(int row, int col) const;

  public:
    grid (string file);
    ~grid ();
    int count (int row, int col);
    friend ostream &operator<<(ostream &stream, const grid& ob);
};

#endif
