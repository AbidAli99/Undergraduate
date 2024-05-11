/*
 *Operation on the Sparse Matrix
 *dse_assign05
 *Student Name :ABID ALI
 *Student ID   :2019380141
 *E-Mail       :abiduu354@gmail.com
 */
#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class sparse_matrix
{

    // Maximum number of Elementss in this matrix
    const static int MAX = 20000;

    // Initialized double-pointer to store
    // the triple-represented form
    int **Elements;

    // This will be our Matrix dimension
    int row, column;

    // Total number of Elements in the matrix
    //We are making a length of int type
    int l;

public:
    sparse_matrix(int r, int c)
    {

        // initializing the row inputs
        row = r;

        // initializing the column inputs
        column = c;

        // initialize l to 0,So that our length start from first index.
        l = 0;

        //Array of Pointer to make a matrix
        Elements = new int *[MAX];

        // Representation of the Array of Sparse matrix

        for (int i = 0; i < MAX; i++)
            Elements[i] = new int[3];
    }

    // Insert the elements into sparse matrix
    void insert(int r, int c, int value)
    {

        // When there is a invalid entry
        if (r > row || c > column)
        {
            cout << "An invalid entry";
        }
        else
        {

            // inserting the row value
            Elements[l][0] = r;

            // inserting the column value
            Elements[l][1] = c;

            // insert the following Element's value
            Elements[l][2] = value;

            // Increment number of Elements in matrix,So,that we can move to next elements.
            l++;
        }
    }

    void AddTSMatrix(sparse_matrix b)
    {

        // If the matrices doesn't have same dimensions
        if (row != b.row || column != b.column)
        {
            cout << "Matrix addition cannot be done.";
        }
        else
        {
            int mat1_position = 0, mat2_position = 0;
            sparse_matrix result(row, column);

            while (mat1_position < l && mat2_position < b.l)
            {

                // If 2nd matrix row and column is smaller
                if(Elements[mat1_position][0] > b.Elements[mat2_position][0] || (Elements[mat1_position][0] == b.Elements[mat2_position][0] &&
                    Elements[mat1_position][1] > b.Elements[mat2_position][1]))
                {

                    // Insert smaller value into result
                    result.insert(b.Elements[mat2_position][0],
                                  b.Elements[mat2_position][1],
                                  b.Elements[mat2_position][2]);

                    mat2_position++;
                }
                else if (Elements[mat1_position][0] < b.Elements[mat2_position][0] ||         // if a's row and column is smaller
                         (Elements[mat1_position][0] == b.Elements[mat2_position][0] &&
                          Elements[mat1_position][1] < b.Elements[mat2_position][1]))

                {

                    // Insert smaller values into result
                    result.insert(Elements[mat1_position][0],
                                  Elements[mat1_position][1],
                                  Elements[mat1_position][2]);

                    mat1_position++;
                }

                else
                {

                    // AddSTMatrix the values as row and column is same
                    int AddTSMatrixedvalue = Elements[mat1_position][2] +
                                   b.Elements[mat2_position][2];

                    if (AddTSMatrixedvalue != 0)
                        result.insert(Elements[mat1_position][0],
                                      Elements[mat1_position][1],
                                      AddTSMatrixedvalue);
                    // then insert
                    mat1_position++;
                    mat2_position++;
                }
            }

            // insert remaining Elements
            while (mat1_position < l)
                result.insert(Elements[mat1_position][0],
                              Elements[mat1_position][1],
                              Elements[mat1_position++][2]);

            while (mat2_position < b.l)
                result.insert(b.Elements[mat2_position][0],
                              b.Elements[mat2_position][1],
                              b.Elements[mat2_position++][2]);

            // print result
            result.print();
        }
    }

    sparse_matrix TransposeTSMatrix()
    {

        // new matrix with inversed row X column
        sparse_matrix result(column, row);

        // same number of Elements
        result.l = l;

        // to count number of Elements in each column
        int *count = new int[column + 1];

        // initialize all to 0
        for (int i = 1; i <= column; i++)
            count[i] = 0;

        for (int i = 0; i < l; i++)
            count[Elements[i][1]]++;

        int *index = new int[column + 1];

        // to count number of Elements having
        // column smaller than particular i

        // as there is no column with value < 0
        index[0] = 0;

        // initialize rest of the indice
        for (int i = 1; i <= column; i++)

            index[i] = index[i - 1] + count[i - 1];

        for (int i = 0; i < l; i++)
        {

            // insert a Elements at rpos and
            // increment its value
            int rpos = index[Elements[i][1]]++;

            // TransposeSMatrix row=column
            result.Elements[rpos][0] = Elements[i][1];

            // TransposeSMatrix column=row
            result.Elements[rpos][1] = Elements[i][0];

            // same value
            result.Elements[rpos][2] = Elements[i][2];
        }

        // the above method ensures
        // sorting of Transpose SMatrix matrix
        // according to row-column value
        return result;
    }

    void MultiplySMatrix(sparse_matrix b)
    {
        if (column != b.row)
        {

            // Invalid multiplication
            cout << "Error...Invalid dimensions";
            return;
        }

        // Transpose SMatrix b to compare row and column value and to AddSMatrix them at the end

        b = b.TransposeTSMatrix();
        int matrix1_position, matrix2_position;

        // result matrix of dimension row X b.column
        // However b has been TransposeSMatrix,
        // Hence row X b.row
        sparse_matrix result(row, b.row);

        // iterate over all Elements of A
        for (matrix1_position = 0; matrix1_position < l;)
        {

            // Current row of result matrix
            int r = Elements[matrix1_position][0];

            // Iterate over all Elements of B
            for (matrix2_position = 0; matrix2_position < b.l;)
            {

                // current column of result matrix
                // Elements[,0] used as b is Transpose SMatrix
                int c = b.Elements[matrix2_position][0];

                // temporary pointers created to AddSMatrix all
                // Multiplied value to obtain current value
                // Elements of result matrix
                int tempa = matrix1_position;
                int tempb = matrix2_position;

                int sum = 0;

                // Iterating over all Elements with
                // Same row and column value then we are going calculate result[r]

                while (tempa < l && Elements[tempa][0] == r &&
                        tempb < b.l && b.Elements[tempb][0] == c)
                {
                    if (Elements[tempa][1] < b.Elements[tempb][1])
                        // Skipped a
                        tempa++;
                    else if (Elements[tempa][1] > b.Elements[tempb][1])
                        // Skipped b
                        tempb++;
                    else
                        // Same column, therfore Multiply TSMatrix and increment
                        sum += Elements[tempa++][2] *
                               b.Elements[tempb++][2];
                }

                if (sum != 0)
                    result.insert(r, c, sum);

                while (matrix2_position < b.l &&
                        b.Elements[matrix2_position][0] == c)
                    // Jump to next column
                    matrix2_position++;
            }
            while (matrix1_position < l && Elements[matrix1_position][0] == r)
                // Jump to next row
                matrix1_position++;
        }
        result.print();
    }

    // Printing the matrix
    void print()
    {
        cout <<"(" << row << "x" << column<<")"<<endl;


        for (int i = 0; i < l; i++)
        {
            cout << Elements[i][0] << " " << Elements[i][1]
                 << " " << Elements[i][2] << endl;
        }
    }
};


int main()
{
    int p,q,n1,n2,x,y,z,i,j,k;
    cin>>p>>n1;

    // Creating 1st sparse matrices and insert value
    sparse_matrix a(p, n1);
    while(1)
    {
        cin>>x>>y>>z;
        if(x==0 && y==0 && z==0) break;
        a.insert(x, y, z);
    }

    cin>>q>>n2;
     // Creating 2nd sparse matrices and insert value
    sparse_matrix b(q, n2);
    while(1)
    {
        cin>>i>>j>>k;
        if(i==0 && j==0 && k==0) break;
        b.insert(i, j, k);
    }



    cout << "Result of the Addition:";
    a.AddTSMatrix(b);
    cout << "Result of the Multiplication:";
    a.MultiplySMatrix(b);
    cout << "Result of Transpose on the first matrix:";
    sparse_matrix aTransposeTSMatrix = a.TransposeTSMatrix();
    aTransposeTSMatrix.print();
}
