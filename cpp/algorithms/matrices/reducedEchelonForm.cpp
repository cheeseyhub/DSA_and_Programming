#include <iostream>
#include <vector>
#include <math.h>

class Matrix
{
private:
    std::vector<std::vector<double>> matrix;
    int rows;
    int cols;

public:
    // Turns a vector into a matrix object.
    Matrix(std::vector<std::vector<double>> &inputMatrix)
    {

        for (int i = 0; i < inputMatrix.size(); i++)
        {

            this->matrix.push_back(inputMatrix[i]);
        }

        rows = inputMatrix[0].size();
        cols = inputMatrix.size();
    };

    double determinant()
    {
        double result = 0;
        if (this->rows != this->cols)
        {
            std::cout << " The Determinent doesn't exist for matrix with dimensions : " << this->rows << " X " << this->cols << std::endl;
            return result;
        }

        if (this->rows == 2 && this->cols == 2)
        {
            return this->matrix[0][0] * this->matrix[1][1] - this->matrix[0][1] * this->matrix[1][0];
        }

        // Go through the first row

        for (int i = 0; i < this->rows; i++)
        {
            // Get the cofactor adding one to get the acutally mathematical numbering ;

            double cofactor = std::pow(-1, i);
            double minorResult = 0;

            int j;

            for (j = 0; j < this->cols; j++)
            {
                std::vector<std::vector<double>> minorVector;

                // Inner loop for minor row and column;
                for (int k = 0; k < this->matrix[i].size(); k++)
                {
                    // skip the same row ;
                    if (k == i)
                        continue;
                    std::vector<double> minorRow;
                    for (int l = 0; l < this->matrix.size(); l++)
                    {

                        // skip the same column;
                        if (l == j)
                            continue;
                        minorRow.push_back(this->matrix[k][l]);
                    }
                    minorVector.push_back(minorRow);
                }
                Matrix minor(minorVector);
                minorResult = minor.determinant();
            }

            result += cofactor * this->matrix[i][j - 1] * minorResult;
        }

        return result;
    }

    void printMatrix()
    {

        for (int i = 0; i < this->matrix.size(); i++)
        {
            std::cout << " { ";
            for (int j = 0; j < this->matrix[i].size(); j++)
            {
                std::cout << matrix[i][j] << ", ";
            }

            std::cout << "}" << std::endl;
        }
    }

    void reduced_echelon_form()
    {

        for (int i = 0; i < this->rows; i++)
        {
            // Divide the current row by the first element to get 1 there;
            this->divide_row_by_number(i, this->matrix[i][0]);
        }
    }

    void swap_rows(int i, int j)
    {
        std::vector<double> temp = this->matrix[i];
        this->matrix[i] = this->matrix[j];
        this->matrix[j] = temp;
    }
    void divide_row_by_number(int row_number, double number)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (number != 0 && this->matrix[row_number][j] != 0)
                this->matrix[row_number][j] /= number;
        }
    }
    void multiply_and_subtract_row_from_other_row_and_store_in_other_row(int row1, int row2, double number)
    {

        for (int j = 0; j < this->cols; j++)
        {
            this->matrix[row2][j] -= (number * this->matrix[row1][j]);
        }
    }

    ~Matrix() {

    };
};

int main()
{

    // 10 matrices in the same format as above:
    std::vector<std::vector<double>> matrix1 = {
        {2, 3, 4},
        {0, 1, 7},
        {8, 9, 10}};

    // Testing of swapping rows
    Matrix m(matrix1);
    m.multiply_and_subtract_row_from_other_row_and_store_in_other_row(0, 2, 4);
    m.printMatrix();

    // std::vector<std::vector<double>> matrix2 = {
    //     {-1, -2, -3},
    //     {-4, -5, -6},
    //     {-7, -8, -9}};

    // std::vector<std::vector<double>> matrix3 = {
    //     {0, 0, 0},
    //     {0, 0, 0},
    //     {0, 0, 0}};

    // std::vector<std::vector<double>> matrix4 = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}};

    // std::vector<std::vector<double>> matrix5 = {
    //     {3, 5, 7},
    //     {11, 13, 15},
    //     {19, 21, 23}};

    // std::vector<std::vector<double>> matrix6 = {
    //     {-2, -4, -6},
    //     {-8, -10, -12},
    //     {-14, -16, -18}};

    // std::vector<std::vector<double>> matrix7 = {
    //     {1, 3, 5},
    //     {7, 9, 11},
    //     {13, 15, 17}};

    // std::vector<std::vector<double>> matrix8 = {
    //     {-1, -3, -5},
    //     {-7, -9, -11},
    //     {-13, -15, -17}};

    // std::vector<std::vector<double>> matrix9 = {
    //     {0, 0, 1},
    //     {0, 1, 0},
    //     {1, 0, 0}};

    // std::vector<std::vector<double>> matrix10 = {
    //     {-1, -1, 1},
    //     {1, -1, 0},
    //     {-1, 1, 0}};

    // Matrix m1(matrix1);
    // m1.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m1.determinant() << std::endl;

    // Matrix m2(matrix2);
    // m2.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m2.determinant() << std::endl;

    // Matrix m3(matrix3);
    // m3.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m3.determinant() << std::endl;

    // Matrix m4(matrix4);
    // m4.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m4.determinant() << std::endl;

    // Matrix m5(matrix5);
    // m5.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m5.determinant() << std::endl;

    // Matrix m6(matrix6);
    // m6.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m6.determinant() << std::endl;

    // Matrix m7(matrix7);
    // m7.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m7.determinant() << std::endl;

    // Matrix m8(matrix8);
    // m8.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m8.determinant() << std::endl;

    // Matrix m9(matrix9);
    // m9.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m9.determinant() << std::endl;

    // Matrix m10(matrix10);
    // m10.printMatrix();
    // std::cout << "The determinant of the matrix is : " << m10.determinant() << std::endl;

    return 0;
}