#include <iostream>
#include <iomanip>


using namespace std;

int RandomeNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FullArrayWithNumber(short array[3][3], short Row, short Cols)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            array[i][j] = RandomeNumber(1, 100);
        }
    }
}

void PrintTheMatrix(short array[3][3], short Row, short Cols)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << array[i][j] << "\t";
        }
        cout << endl;
    }
}

int ColSum(short array[3][3], short Rows, short ColNumber)
{
    short Sum;
    Sum = 0;
    for (short j = 0; j < Rows; j++)
    {
        Sum += array[j][ColNumber];
    }
    return Sum;
}

void PrintEachColSum(short array[3], short Rows)
{

    for (short i = 0; i < Rows; i++)
    {
        printf("Col %d Sum = %d\n", (i + 1), array[i]);
    }
}

void AddTheSumOfRowInOnDim(short array[3][3], short arrSum[3], short Row, short Cols)
{
    for (short i = 0; i < Row; i++)
    {
        arrSum[i] = ColSum(array, Cols, i);
    }
}

void PrintColOfOneDimArray(short array[3][3], short ArrOneDim[3], short Row, short Cols)
{
    AddTheSumOfRowInOnDim(array, ArrOneDim, Row, Cols);
    PrintEachColSum(ArrOneDim, Cols);
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix[3][3],
        arrSum[3],
        Row = 3, Cols = 3;

    FullArrayWithNumber(Matrix, Row, Cols);

    cout << "The following is a 3x3 random matrix:\n";
    PrintTheMatrix(Matrix, Row, Cols);

    cout << "The the following are the sum of each Col in the matrix:\n";
    PrintColOfOneDimArray(Matrix, arrSum, Row, Cols);

    return 0;
}