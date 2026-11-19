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
    Matrix(std::vector<std::vector<double>> &inputMatrix)
    {

        for (int i = 0; i < inputMatrix.size(); i++)
        {

            this->matrix.push_back(inputMatrix[i]);
        }

        cols = inputMatrix[0].size();
        rows = inputMatrix.size();
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

        for (int col = 0; col < this->cols; col++)
        {
            std::vector<std::vector<double>> minorVector;
            for (int k = 1; k < this->rows; k++)
            {
                std::vector<double> minorRow;
                for (int l = 0; l < this->cols; l++)
                {
                    if (l == col)
                        continue;

                    minorRow.push_back(matrix[k][l]);
                }
                minorVector.push_back(minorRow);
            }

            Matrix minor(minorVector);
            double sign = std::pow(-1, col);
            result += sign * minor.determinant() * this->matrix[0][col];
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
    void appendRow(std::vector<double> row)
    {

        this->matrix.push_back(row);
        this->cols = row.size();
    }

    ~Matrix() {

    };
};

int main()
{

    std::vector<std::vector<double>> matrix1 = {
        {1, 0, 0, 3},
        {2, 7, 0, 6},
        {0, 6, 3, 0},
        {7, 3, 1, -5},
    };

    std::vector<std::vector<double>> matrix2 = {
        {0, 1, 5},
        {3, -6, 9},
        {2, 6, 1}};

    std::vector<std::vector<double>> matrix3 = {
        {1, 0, 0, -1},
        {3, 1, 2, 2},
        {1, 0, -2, 1},
        {2, 0, 0, 1}};

    Matrix m1(matrix1);
    m1.printMatrix();
    std::cout << "The determinant of the matrix is : " << m1.determinant() << std::endl;

    Matrix m2(matrix2);
    m2.printMatrix();
    std::cout << "The determinant of the matrix is : " << m2.determinant() << std::endl;

    Matrix m3(matrix3);
    m3.printMatrix();
    std::cout << "The determinant of the matrix is : " << m3.determinant() << std::endl;

    return 0;
}