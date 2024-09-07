# 1D Fin Temperature Distribution with Volumetric Heating

This project models the unsteady temperature distribution in a 1D fin subjected to volumetric heating. The simulation considers three different scenarios:
1. Constant heating rate
2. Heating rate varying with length
3. Heating rate varying with time

The project uses **C++** for numerical modeling and the **TDMA (Tri-Diagonal Matrix Algorithm)** for solving the temperature distribution iteratively. Results are visualized using **GNUplot**.

## Table of Contents
- [Overview](#overview)
- [Project Structure](#project-structure)
- [Setup and Execution](#setup-and-execution)
- [Visualization](#visualization)
- [Results](#results)
- [Files](#files)
- [References](#references)

## Overview
This project simulates the temperature distribution in a 1D fin under different heating scenarios. The model was built using C++ for numerical computation and GNUplot for visualizing the results. The purpose of the project is to analyze how temperature varies over time and distance when subjected to volumetric heating.

## Project Structure
The repository is structured as follows:

1D-Fin-Temperature-Distribution/
│
├── src/
│   ├── temperature_model.cpp      # C++ code for modeling the temperature distribution
│   ├── plot.gnu                   # GNUplot script for plotting results
│
├── ST/                            # Directory containing the generated .dat files (temperature data)
│
├── docs/
│   ├── report.pdf                 # Report detailing the methodology and results
│   ├── presentation.pptx          # PowerPoint presentation summarizing the assignment
│
├── README.md                      # This README file


## Setup and Execution
### Requirements:
- A C++ compiler (e.g., GCC)
- GNUplot for visualization

### Steps to run the simulation:
1. Clone the repository:
   ```bash
   git clone https://github.com/zeel0725/1D-Fin-Temperature-Distribution.git
2. Navigate to the src folder:
   ```bash
   cd 1D-Fin-Temperature-Distribution/src
4. Compile the C++ code:
   ```bash
   g++ temperature_model.cpp -o temp_model
6. Run the compiled program:
   ```bash
   ./temp_model

## Visualization

To visualize the temperature distribution over time:
Open the plot.gnu file with GNUplot:
gnuplot plot.gnu


This will generate plots showing the temperature distribution under different heating conditions for each scenario.

## Results

The results demonstrate how the heating rate (constant, length-dependent, or time-dependent) affects the temperature distribution along the fin. The visualizations generated using GNUplot help illustrate the temperature variation over time and space, providing insights into thermal behavior under each heating condition.


## Files

src/temperature_model.cpp: C++ code that implements the TDMA algorithm to compute the temperature distribution.
src/plot.gnu: GNUplot script for visualizing the results.
docs/report.pdf: Detailed report explaining the methodology and findings.
docs/presentation.pptx: PowerPoint presentation summarizing the key aspects of the project.

## References
- [GNUplot Documentation](http://www.gnuplot.info/documentation.html)
- [TDMA Algorithm (Wikipedia)](https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm)
- [C++ Standard Library Documentation](https://en.cppreference.com/w/)
- [C# Documentation (Microsoft)](https://learn.microsoft.com/en-us/dotnet/csharp/)



