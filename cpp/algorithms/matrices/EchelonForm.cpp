#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

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

    void echelon_form()
    {
        int pivot_row = 0;
        for (int col = 0; col < this->cols && pivot_row < this->rows; col++)
        {
            int max_row = pivot_row;
            for (int k = pivot_row + 1; k < this->rows; k++)
            {
                if (std::abs(matrix[k][col]) > 1e-10)
                {
                    max_row = k;
                }
            }

            if (std::abs(matrix[max_row][col]) < 1e-9)
            {
                continue;
            }

            if (max_row != pivot_row)
            {
                this->swap_rows(max_row, pivot_row);
            }

            double pivot_val = matrix[pivot_row][col];

            for (int j = col; j < this->cols; j++)
            {
                matrix[pivot_row][j] /= pivot_val;
            }

            for (int k = pivot_row + 1; k < this->rows; k++)
            {
                if (k != pivot_row && std::abs(matrix[k][col]) > 1e-9)
                {
                    double factor = matrix[k][col];
                    this->other_row_plus_row_times_n(k, pivot_row, factor);
                }
            }

            pivot_row++;
        }
    }
    std::vector<std::vector<double>> createElementaryMatrix()
    {
        std::vector<std::vector<double>> elementaryMatrix(this->rows, std::vector<double>(this->cols));
        // Intialzie the elementary matrix;

        for (int i = 0; i < elementaryMatrix.size(); i++)
        {
            elementaryMatrix[i][i] = 1;
        }

        return elementaryMatrix;
    }

    Matrix inverse()
    {
        if (this->rows != this->cols)
        {
            std::cout << "Inverse doesn't exist because the matrix is not a square matrix " << std::endl;
            return *this;
        }
        // Elementary Matrix to store the inverse
        std::vector<std::vector<double>> elementaryVector = createElementaryMatrix();
        Matrix elementaryMatrix(elementaryVector);

        for (int i = 0; i < this->rows; i++)
        {
            // if the element is zero find the row below to swap with the current row
            if (std::abs(matrix[i][i]) < 1e-9)
            {
                for (int k = i + 1; k < this->rows; k++)
                {
                    if (std::abs(this->matrix[k][i]) > 1e-9)
                    {
                        // Apply on  elementaryMatrix;
                        elementaryMatrix.swap_rows(k, i);
                        this->swap_rows(k, i);
                        break;
                    }
                }
            }
            // End of swapping with non zeros

            if (std::abs(this->matrix[i][i]) < 1e-9)
            {
                std::cout << "Inverse doesn't exit because matrix is sigular" << std::endl;
                return *this;
            }

            // Find the first non-zero in the current row and divide by that number to get 1 in that row
            // Apply on elementaryMatrix;
            double dividing_factor = this->matrix[i][i];
            elementaryMatrix.divide_row_by_number(i, dividing_factor);
            this->divide_row_by_number(i, dividing_factor);

            // Find the the values below in the current row and set that row equal to current row times the factor of the other row
            // Starting from zero to eliminate above and below
            for (int k = 0; k < this->rows; k++)
            {
                if (k != i && matrix[k][i] != 0)
                {
                    double factor = this->matrix[k][i];
                    // Apply on elementary matrix
                    elementaryMatrix.other_row_plus_row_times_n(k, i, factor);
                    this->other_row_plus_row_times_n(k, i, factor);
                }
            }
        }
        return elementaryMatrix;
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
    void other_row_plus_row_times_n(int row2, int row1, double number)
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
        {0, 0, -2, 0, 7, 12},
        {2, 4, -10, 6, 12, 28},
        {2, 4, -5, 6, -5, -1}};

    std::vector<std::vector<double>> matrix2 = {
        {-24, 18, 5},
        {20, -15, -4},
        {-5, 4, 1}};

    Matrix m1(matrix1);
    m1.echelon_form();
    m1.printMatrix();

    Matrix m2(matrix2);
    Matrix inverse_of_m2 = m2.inverse();
    inverse_of_m2.printMatrix();

    return 0;
}