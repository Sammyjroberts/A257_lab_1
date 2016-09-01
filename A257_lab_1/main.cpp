/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   main.cpp                                                                                          *
 *   A257_lab_1: Quilting                                                                              *
 *                                                                                                     *
 *   You will create a program that prints out a quilt pattern. The pattern will be a basic vertical   *
 *   stripe pattern. To represent the quilt block, use a 2D character array filled with two different  *
 *   characters. Each column will be a stripe. The first column is column 0.                           *
 *   REQUIREMENTS:                                                                                     *
 *   1. Ask for the dimensions of the quilt block. You may assume that the dimensions are              *
 *   no greater than 25 so that you can use a static array. Feel free to use dynamic arrays.           *
 *   Do not accept negative dimensions or dimensions greater than 25.                                  *
 *   2. Ask the user for the character to use in the even column stripes. Then ask the user for        *
 *   the character to use in the odd column stripes.                                                   *
 *   3. Print the final quilt block                                                                    *
 *   You must use:                                                                                     *
 *   • At least one for loop                                                                           *
 *   • At least one while/dowhile loop                                                                 *
 *   • A 2D array                                                                                      *
 *                                                                                                     *
 *                                                                                                     *
 *   Created by Sammy Roberts on 8/30/16.                                                              *
 *   Copyright © 2016 Sammy Roberts. All rights reserved.                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdexcept>

//inits and returns a character array. requires a length and width
char** initArray(const int length, const int width);
//creates the quilt, uses "Private" function initArray to also build the array. requires a length, width, and even/odd characters. We will use these characters to fill the quilt.
char** buildQuilt(const int length, const int width, const char even, const char odd);
//this function will output the quilt to cout
void printQuilt(char** quilt, const int width, const int length);

int main() {
    //Title
    std::cout << "---A257_lab_1: Quilting---" << std::endl;
    //intro to the program
    std::cout << "This program will create a quilt pattern. "
    << "The pattern will be a basic vertical stripe pattern. To represent the quilt block, we will use two different characters you will need to enter."
    <<"You will also be prompted to enter a length and width." << std::endl << std::endl;
    
    //char we will use in the even columns
    char even;
    //char used in odd columns
    char odd;
    //length of the quilt
    int length;
    //width of the quilt
    int width;
    //the dynamic array holding the quilt
    char **quilt;
    
    //INPUT
    //TODO these dos could be moved into a function to facilitate code reuse / testing
    //Think of a solution for duplicating the <=1 check
    do {
        try {
            std::cout << "Enter the length of the quilt block: ";
            std::cin >> length;
            if(length <= 1) {
                throw std::invalid_argument("Please enter a number larger than 1.");
            }
        }
        catch(std::invalid_argument e){
            std::cout << e.what() << std::endl;
        }
    }while(length <= 1);

    do {
        try {
            std::cout << "Enter the width of the quilt block: ";
            std::cin >> width;
            if(width <= 1) {
                throw std::invalid_argument("Please enter a number larger than 1.");
            }
        }
        catch(std::invalid_argument e){
            std::cout << e.what() << std::endl;
        }
    }while(width <= 1);

    
    //we must ignore leftover endls in the buffer
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "What character should the even columns be filled with? ";
    std::cin.get(even);
    
    //we must ignore leftover endls in the buffer
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "What character should the odd columns be filled with? ";
    std::cin.get(odd);
    
    //PROCESSING
    quilt = buildQuilt(length, width, even, odd);
    
    //OUTPUT
    printQuilt(quilt, width, length);

    return 0;
}
char** initArray(const int length, const int width) {
    //init the width of the array by creating a pointer to a array of pointers
    char **arr = new char*[length];
    //for each array in the array of pointers, point to a new array of size length
    for (int i = 0; i < length; i++) {
        arr[i] = new char[width];
    }
    
    return arr;
}
char** buildQuilt(const int length, const int width, const char even, const char odd) {
    
    char **quilt;
    
    //dynamically allocate memory for the quilt
    quilt = initArray(length, width);
    
    //put the characters in the correct spt
    for(int lcv = 0; lcv < length; lcv++) {
        for (int lcv2 = 0; lcv2 < width; lcv2++){
            //temporarily hold the character value we are going to use
            char temp;
            
            //if is even use even, else use odd
            if(lcv2 % 2 == 0) {
                temp = even;
            }
            else {
                temp = odd;
            }
            //put the character at the correct index
            quilt[lcv][lcv2] = temp;
        }
    }
    return quilt;
}
void printQuilt(char** quilt, const int width, const int length) {
    for(int lcv = 0; lcv < length; lcv++) {
        for(int lcv2 = 0; lcv2 < width; lcv2++) {
            std::cout << quilt[lcv][lcv2];
        }
        //end line at end of width
        std::cout << std::endl;
    }
}