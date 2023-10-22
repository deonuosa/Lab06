#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

static const int Max_Size = 100;

void Read_File(int matrix_A[Max_Size][Max_Size], int matrix_B[Max_Size][Max_Size], int& size, const char* file_name);
void printMatrices(const int matrix[Max_Size][Max_Size], int size);
void Addition_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int m_result[Max_Size][Max_Size], int size);
void Product_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int m_result[Max_Size][Max_Size], int size);
void Subtraction_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int m_result[Max_Size][Max_Size], int size);

int main() {
  int size;
  int matrix_A[Max_Size][Max_Size];
  int matrix_B[Max_Size][Max_Size];
  int m_result[Max_Size][Max_Size];

  Read_File(matrix_A, matrix_B, size, "matrix_input.txt");

  cout << "Deborah Onuosa" << endl;
  cout << "Lab #6: Matrix manipulation" << endl;

  cout << "Matrix A:" << endl;
  printMatrices(matrix_A, size);

  cout << "Matrix B:" << endl;
  printMatrices(matrix_B, size);

  Addition_matrix(matrix_A, matrix_B, m_result, size);
  cout << "Matrix Sum (A + B):" << endl;
  printMatrices(m_result, size);

  Product_matrix(matrix_A, matrix_B, m_result, size);
  cout << "Matrix Product (A * B):" << endl;
  printMatrices(m_result, size);

  Subtraction_matrix(matrix_A, matrix_B, m_result, size);
  cout << "Matrix Difference (A - B):" << endl;
  printMatrices(m_result, size);

  return 0;
}

void Read_File(int matrix_A[Max_Size][Max_Size], int matrix_B[Max_Size][Max_Size], int& size, const char* filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Cannot Open File." << endl;
    exit(1);
  }
  file >> size;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      file >> matrix_A[i][j];
    }
  }

  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      file >> matrix_B[i][j];
    }
  }

  file.close();
}

void printMatrices(const int matrix[Max_Size][Max_Size], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << setw(4) << matrix[i][j];
    }
    cout << endl;
  }
}

void Addition_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int m_result[Max_Size][Max_Size], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
       m_result[i][j] = matrix_1[i][j] + matrix_2[i][j];
    }
  }
}

void Product_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int m_result[Max_Size][Max_Size], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      m_result[i][j] = 0;
      for (int x = 0; x < size; x++) {
        m_result[i][j] += matrix_1[i][x] * matrix_2[x][j];
      }
    }
  }
}

void Subtraction_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int m_result[Max_Size][Max_Size], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      m_result[i][j] = matrix_1[i][j] - matrix_2[i][j];
    }
  }
}
