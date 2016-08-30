//
//  main.cpp
//  A257_lab_1
//
//  Created by Sammy Roberts on 8/30/16.
//  Copyright © 2016 Sammy Roberts. All rights reserved.
//

#include <iostream>
//inits and returns a character array. requires a length and width
char** initArray(int length, int width);
//creates the quilt, uses "Private" function initArray to also build the array. requires a length, width, and even/odd characters. We will use these characters to fill the quilt.
char** buildQuilt(int length, int width, char even, char odd);
//this function will output the quilt to cout
void printQuilt(char** quilt, int width, int length);

int main() {
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
    std::cout << "Enter the length of the quilt block: ";
    std::cin >> length;
    
    std::cout << "Enter the width of the quilt block: ";
    std::cin >> width;
    
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
    printQuilt(quilt,width, length);

    return 0;
}
char** initArray(int length, int width) {
    char **arr = new char*[width];
    for (int i = 0; i < width; i++) {
        arr[i] = new char[length];
    }
    
    return arr;
}
char** buildQuilt(int length, int width, char even, char odd) {
    char **quilt;
    quilt = initArray(length, width);
    
    for(int lcv = 0; lcv < width; lcv++) {
        for (int lcv2 = 0; lcv2 < length; lcv2++){
            char temp;
            if(lcv2 % 2 == 0) {
                temp = even;
            }
            else {
                temp = odd;
            }
            quilt[lcv][lcv2] = temp;
        }
    }
    return quilt;
}
void printQuilt(char** quilt, int width, int length) {
    for(int lcv = 0; lcv < width; lcv++) {
        for(int lcv2 = 0; lcv2 < length; lcv2++) {
            std::cout << quilt[lcv][lcv2] << " ";
        }
        std::cout << std::endl;
    }
}