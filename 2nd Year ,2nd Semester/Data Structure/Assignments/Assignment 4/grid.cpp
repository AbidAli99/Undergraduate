#include <iostream>
#include <fstream>

using namespace std;

#include "grid.h"


int grid::indexof (int row, int col) const
{
  return row*cols+col;
}


bool grid::infected(int row, int col) const
{
  return (area->operator[](indexof(row, col)) == INFECTED);
}


grid::grid (string file)
{
  ifstream grid_file;

  grid_file.open (file.c_str());

  grid_file >> rows;
  grid_file >> cols;

  area = new vector<bool>(rows*cols, NOT_INFECTED);
  visited = new vector<string>(rows*cols, "0 ");

  while (true)
  {

    int blob_row;
    int blob_col;

    grid_file >> blob_row;
    grid_file >> blob_col;

    if (grid_file.eof())
	{
        break;
    }

    area->operator[](indexof(blob_row,blob_col)) = INFECTED;
    visited->operator[](indexof(blob_row,blob_col)) = "1 ";
  }

  grid_file.close();
}


grid::~grid ()
{
  delete area;
  delete visited;
}


ostream &operator<<(ostream &stream, const grid& ob)
{

  for (int row=0; row < ob.rows; row++)
  {

    for (int col=0; col < ob.cols; col++)
	{
      stream << ob.visited->operator[](ob.indexof(row, col));
    }

    stream << endl;
  }
  stream << endl;
  return stream;
}

int grid::count (int row, int col)
{
    if(0<=row&&row < rows&&0<=col&&col < cols)
    {
        if(infected( row, col)&&visited->operator[](indexof(row,col)) =="1 ")
        {
            visited->operator[](indexof( row,col)) ="1+ ";
            return 1+count (row+1, col+1)+count (row+1, col)+
                   count (row+1, col-1)+count (row, col-1)+
                   count (row , col+1)+count (row-1, col+1)+
                   count (row-1, col )+count (row-1, col-1);
        }

    }
    else return 0;
}
