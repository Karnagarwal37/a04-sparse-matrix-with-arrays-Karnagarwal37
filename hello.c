#include <stdio.h>
#include <stdbool.h>

#define MAX_NON_ZERO_ELEMENTS 100  // Maximum number of non-zero elements in the sparse matrix
#define NUM_COLUMNS 4              // Number of columns in the original matrix (modifiable)

// Function prototypes
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][NUM_COLUMNS], int rows, int cols);
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount);
bool testCreateSparseMatrix();
bool testPrintSparseMatrix();

int main() {
    // Run test cases
    if (testCreateSparseMatrix()) {
        printf("testCreateSparseMatrix PASSED\n");
    } else {
        printf("testCreateSparseMatrix FAILED\n");
    }

    if (testPrintSparseMatrix()) {
        printf("testPrintSparseMatrix PASSED\n");
    } else {
        printf("testPrintSparseMatrix FAILED\n");
    }

    return 0;
}

// Function to convert a matrix into sparse matrix format
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][NUM_COLUMNS], int rows, int cols) {
    // Initialize the sparse matrix with the dimensions and number of non-zero elements
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = 0;  // Initially, no non-zero elements found

    // Iterate through the original matrix and populate the sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (originalMatrix[i][j] != 0) {
                sparseMatrix[sparseMatrix[0][2] + 1][0] = i;
                sparseMatrix[sparseMatrix[0][2] + 1][1] = j;
                sparseMatrix[sparseMatrix[0][2] + 1][2] = originalMatrix[i][j];
                sparseMatrix[0][2]++;  // Increment the count of non-zero elements
            }
        }
    }
}

// Function to print sparse matrix representation
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount) {
    // Print the header row containing dimensions and number of non-zero elements
    printf("Row  Column  Value\n");
    printf("----------------\n");

    // Print the non-zero elements of the sparse matrix
    for (int i = 1; i <= nonZeroCount; i++) {
        printf("%3d  %5d  %5d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

//--------------------------------------------------------
// DON'T CHANGE THE CODE BELOW THIS!
//--------------------------------------------------------
// TEST CASES

// Test function for createSparseMatrix
bool testCreateSparseMatrix() {
    int originalMatrix[4][NUM_COLUMNS] = {
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {0, 0, 0, 5},
        {0, 2, 0, 6}
    };

    int expectedSparseMatrix[MAX_NON_ZERO_ELEMENTS][3] = {
        {4, 4, 5},  // 4x4 matrix with 5 non-zero elements
        {0, 2, 3},  // Original matrix[0][2] = 3
        {1, 1, 4},  // Original matrix[1][1] = 4
        {2, 3, 5},  // Original matrix[2][3] = 5
        {3, 1, 2},  // Original matrix[3][1] = 2
        {3, 3, 6}  // Original matrix[3][3] = 6
    };

    int sparseMatrix[MAX_NON_ZERO_ELEMENTS][3];
    createSparseMatrix(sparseMatrix, originalMatrix, 4, NUM_COLUMNS);

    // Compare the sparseMatrix with the expectedSparseMatrix
    for (int i = 0; i <= expectedSparseMatrix[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            if (sparseMatrix[i][j] != expectedSparseMatrix[i][j]) {
                return false;  // If any value doesn't match, test fails
            }
        }
    }

    return true;  // Test passes if all values match
}

// Test function for printSparseMatrix
bool testPrintSparseMatrix() {
    // Define a sparse matrix with 5 non-zero elements
    int sparseMatrix[MAX_NON_ZERO_ELEMENTS][3] = {
        {4, 4, 5},  // 4x4 matrix with 5 non-zero elements
        {0, 2, 3},  // Original matrix[0][2] = 3
        {1, 1, 4},  // Original matrix[1][1] = 4
        {2, 3, 5},  // Original matrix[2][3] = 5
        {3, 1, 2},  // Original matrix[3][1] = 2
        {3, 3, 6}  // Original matrix[3][3] = 6
    };

    // Simulate a successful print (visual inspection may be needed for testing this)
    printf("Expected Sparse Matrix Output:\n");
    printSparseMatrix(sparseMatrix, sparseMatrix[0][2]);

    // Since printSparseMatrix only prints the output, we assume it passes if the format is correct
    return true;
}
