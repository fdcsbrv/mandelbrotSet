// mandelbrotSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// (0) Libraries and preamble



// Libraries
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

// Declarations
double mandelbrot_set(std::complex<double>& z0, int maxIterations);
void print_set(const int& nIterations, double& x, double& y, std::complex<double>& z0);
void save_set(std::ofstream& fileData, const int& nIterations, double& x, double& y, std::complex<double>& z0);


// Main code
int main(){
    // Local variables
    std::string extensionOut = ".dat";
    // File variables 
    std::ofstream fileData;
    std::string nameFile = "./mandelbrot";
    std::string fileDataName;



    // Logical
    bool isSaveToFile = true;
    bool isPrintToTerminal = false;

    // Numerical 
    int i = 0,
        j = 0,
        nX = 1000, //
        nY = 1000; //
    int nIterations = 20;
    double x = 0.0,
        y = 0.0;
    std::complex<double> z0(0, 0);


    //
    if (isSaveToFile == true) {
        fileDataName = nameFile + "_" + "nIterations" + "_" + std::to_string(nIterations) + "_" + "nX" + "_" + std::to_string(nX) + "_" + "nY" + "_" + std::to_string(nY) + extensionOut;
        fileData.open(fileDataName.c_str(), std::ios::app);
    }

    //
    for (i = 0; i < nX; ++i) {
        for(j = 0; j < nY; ++j) {

            // Coordinates of Mandelbrot set
            x = -2.0 + (3.0 * static_cast<double>(i)) / (static_cast<double>(nX) - 1.0);
            y = -1.0 + (2.0 * static_cast<double>(j)) / (static_cast<double>(nY) - 1.0);


            // Assign the real and imaginary coordinates to the complex variable
            z0.real(x);
            z0.imag(y);

            // Print out result
            if (isSaveToFile == false && isPrintToTerminal == true) {
                print_set(nIterations, x, y, z0);
            }
            if (isSaveToFile == true) {
                save_set(fileData, nIterations, x, y, z0);
            }
        }

    }


    // Close
    if (isSaveToFile == true) {
        fileData.close();
    }


    return 0;

}

// Definitions
double mandelbrot_set(std::complex<double>& z0, int maxIterations) {
    
    // Local variables
    int i = 0;
    std::complex<double> z = 0;

    // Iterate through the Mandelbrot Set
    for (i = 0; i < maxIterations; ++i) {
        
        // If the point is not an element of the set
        if (norm(z) > 4.0) {
            return i;
        }

        // 
        z = z * z + z0;
    }

    return maxIterations;
}

void print_set(const int& nIterations, double& x, double& y, std::complex<double>& z0){

    // (1) Print out result
    std::cout << x << " " << y << " " << 1 / mandelbrot_set(z0, nIterations) << std::endl;
}

void save_set(std::ofstream& fileData, const int& nIterations, double& x, double& y, std::complex<double>& z0) {

    // (1) Save to out file the result
    fileData << x << " " << y << " " << 1 / mandelbrot_set(z0, nIterations) << std::endl;

}