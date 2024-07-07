#include <iostream>

int main() {
    // Initialize a 3D array with the first 3x3 slice set to 1
    double prices[3][3][3] = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
                              {{1, 1, 1}, {1,0,1}, {1, 1, 1}},
                              {{1,1,1}, {1,1,1}, {1,1,1}}};
    double summation = 0;
   
    // Iterate through each element in the 3D array
    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 3; y++) {
            for(int z = 0; z < 3; z++) {
                // Add the current element to summation
                summation += prices[x][y][z];
               
                // Print the current element
                std::cout << prices[x][y][z] << std::endl;
               
                // If we are at the last element, print the summation
                if ((x == 2) && (y == 2) && (z == 2)) {
                    std::cout << summation << std::endl;
                }       
            }
        }
    }

    return 0;
}