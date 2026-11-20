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

        for (int i = 0; i < this->rows; i++)
        {
            int pivot_col = -1;
            for (int j = pivot_col + 1; j < this->cols; j++)
            {
                // if the element is zero find the row below to swap with the current row
                if (matrix[i][j] == 0)
                {
                    for (int k = i + 1; k < this->rows; k++)
                    {
                        if (matrix[k][j] != 0)
                        {
                            this->swap_rows(k, i);
                            break;
                        }
                    }
                }
                // End of swapping with non zeros

                // Find the first non-zero in the current row and divide by that number to get 1 in that row
                if (matrix[i][j] != 0)
                {
                    this->divide_row_by_number(i, this->matrix[i][j]);
                    pivot_col = j;
                    break;
                }
            }

            // Find the the values below in the current row and set that row equal to current row times the factor of the other row
            for (int k = i + 1; k < this->rows; k++)
            {
                if (pivot_col != -1 && matrix[k][pivot_col] != 0)
                {
                    this->other_row_plus_row_times_n(k, i, matrix[k][pivot_col]);
                }
            }
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

    void inverse()
    {
        // Elementary Matrix to store the inverse
        std::vector<std::vector<double>> elementaryVector = createElementaryMatrix();
        Matrix elementaryMatrix(elementaryVector);

        for (int i = 0; i < this->rows; i++)
        {
            int pivot_col = -1;
            for (int j = pivot_col + 1; j < this->cols; j++)
            {
                // if the element is zero find the row below to swap with the current row
                if (matrix[i][j] == 0)
                {
                    for (int k = i + 1; k < this->rows; k++)
                    {
                        if (matrix[k][j] != 0)
                        {
                            this->swap_rows(k, i);
                            break;
                        }
                    }
                }
                // End of swapping with non zeros

                // Find the first non-zero in the current row and divide by that number to get 1 in that row
                if (matrix[i][j] != 0)
                {
                    this->divide_row_by_number(i, this->matrix[i][j]);
                    pivot_col = j;
                    break;
                }
            }

            // Find the the values below in the current row and set that row equal to current row times the factor of the other row
            // Starting from zero to eliminate above and below
            for (int k = 0; k < this->rows; k++)
            {
                if (k != pivot_col && pivot_col != -1 && matrix[k][pivot_col] != 0)
                {
                    this->other_row_plus_row_times_n(k, i, matrix[k][pivot_col]);
                }
            }
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
        {1, 0, 2},
        {2, -1, 3},
        {4, 1, 8}};

    Matrix m1(matrix1);
    m1.echelon_form();
    m1.printMatrix();

    Matrix m2(matrix2);
    m2.inverse();
    m2.printMatrix();

    return 0;
}