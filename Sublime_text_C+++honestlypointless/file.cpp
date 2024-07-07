#include <iostream>
#include <string>

void printCube(const std::string cube[3][3][3]) {
    const char* layerNames[3] = {"foreground", "middle", "background"};
    
    for (int x = 0; x < 3; x++) {
        std::cout << "Layer: " << layerNames[x] << std::endl;
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                std::cout << cube[x][y][z] << ", ";
                if (z == 2) std::cout << std::endl;
            }
            if (y == 2) std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}


void rotateWhiteFaceCCW(std::string cube[3][3][3]) {
    std::string rotatedWhiteFace[3][3];

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            rotatedWhiteFace[2 - x][y] = cube[0][y][x];
        }
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cube[0][y][x] = rotatedWhiteFace[y][x];
        }
    }
}

void rotateWhiteFaceCW(std::string cube[3][3][3]) {
    std::string rotatedWhiteFace[3][3];

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            rotatedWhiteFace[x][2 - y] = cube[0][y][x];
        }
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cube[0][y][x] = rotatedWhiteFace[y][x];
        }
    }
}

void rotateRightFaceCCW(std::string cube[3][3][3]) {
    std::string rotatedRightFace[3][3];

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            rotatedRightFace[2 - x][y] = cube[x][y][2];
        }
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cube[x][y][2] = rotatedRightFace[y][x];
        }
    }
}

void rotateRightFaceCW(std::string cube[3][3][3]) {
    std::string rotatedRightFace[3][3];

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            rotatedRightFace[x][2 - y] = cube[x][y][2];
        }
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cube[x][y][2] = rotatedRightFace[y][x];
        }
    }
}


void rotateLeftFaceCW(std::string cube[3][3][3]) {
    std::string rotatedLeftFace[3][3];

    for (int z = 0; z < 3; z++) {
        for (int y = 0; y < 3; y++) {
            rotatedLeftFace[y][2 - z] = cube[z][y][0];
        }
    }

    for (int z = 0; z < 3; z++) {
        for (int y = 0; y < 3; y++) {
            cube[z][y][0] = rotatedLeftFace[z][y];
        }
    }
}


int main() {
    std::string cube[3][3][3] = {
        {{"white_green_orange", "white_orange", "white_orange_blue"},
         {"white_green", "white", "white_blue"},
         {"white_red_green", "white_red", "white_blue_red"}},
        {{"green_orange", "orange", "orange_blue"},
         {"green", "center", "blue"},
         {"green_red", "red", "blue_red"}},
        {{"yellow_orange_green", "orange_yellow", "orange_yellow_blue"},
         {"green_yellow", "yellow", "blue_yellow"},
         {"green_red_yellow", "red_yellow", "blue_red_yellow"}}
    };

    std::string choice;
    do {
        std::cout << "Current state of the cube:" << std::endl;
        std::cout << " " << std::endl;
        printCube(cube);

        std::cout << "Would you like to rotate the cube? use: 'f cw', 'f ccw', 'r cw', 'r ccw', or 'q' to quit: ";
        std::getline(std::cin, choice);

        if (choice == "f ccw") {
            rotateWhiteFaceCCW(cube);
            std::cout << choice << std::endl;
            std::cout << "New state of the cube after rotation:" << std::endl;
            
        } else if (choice == "f cw") {
            rotateWhiteFaceCW(cube);
            std::cout << choice << std::endl;
            std::cout << "New state of the cube after rotation:" << std::endl;
            
        } else if (choice == "r ccw") {
            rotateRightFaceCCW(cube);
            std::cout << choice << std::endl;
            std::cout << "New state of the cube after rotation:" << std::endl;
            
        } else if (choice == "r cw") {
            rotateRightFaceCW(cube);
            std::cout << choice << std::endl;
            std::cout << "New state of the cube after rotation:" << std::endl;
            
        } else if (choice == "l cw") {
            rotateLeftFaceCW(cube);
            std::cout << choice << std::endl;
            std::cout << "New state of the cube after rotation:" << std::endl;
            
        }
        std::cout << " " << std::endl;
        
    } while (!choice.empty() && choice != "q");
        
    std::cout << choice << std::endl;

    return 0;
}

/* 

ASCII artwork example
 _______ _______ _______
|       |       |       |
| white | white | white |
|_______|_______|_______|
|       |       |       |
| white | white | white |
|_______|_______|_______|
|       |       |       |
| white | white | white |
|_______|_______|_______|

*/