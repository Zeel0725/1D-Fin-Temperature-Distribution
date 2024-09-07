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
- [References](#references)

## Overview
This project simulates the temperature distribution in a 1D fin under different heating scenarios. The model was built using C++ for numerical computation and GNUplot for visualizing the results. The purpose of the project is to analyze how temperature varies over time and distance when subjected to volumetric heating.

## Project Structure
The repository is structured as follows:

- [src/](src/)  
  - [temperature_model.cpp](src/temperature_model.cpp): C++ code for modeling the temperature distribution.
  - [plot.gnu](src/plot.gnu): Gnuplot script for plotting the results.
- [docs/](docs/)  
  - [report.pdf](docs/report.pdf): PDF report detailing the methodology and results.
  - [presentation.pptx](docs/presentation.pptx): PowerPoint presentation summarizing the project.
- [README.md](README.md): This file.

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
4. Compile the C++ code:(for example)
   ```bash
   g++ gnuplot plot_script.gp.cpp -o temp_model
6. Run the compiled program:
   ```bash
   ./temp_model

## Visualization

To visualize the temperature distribution over time:
1. Navigate to the folder:
   ```bash
   cd 1D-Fin-Temperature-Distribution/src/plot_script
4. Run the following code in terminal:
   ```bash
   gnuplot plot_script.gp
6. Open the compiled program:
   ```bash
   open temperature_plots.png


This will generate plots showing the temperature distribution under different heating conditions for each scenario.

## Results

The results demonstrate how the heating rate (constant, length-dependent, or time-dependent) affects the temperature distribution along the fin. The visualizations generated using GNUplot help illustrate the temperature variation over time and space, providing insights into thermal behavior under each heating condition.


## References
- [GNUplot Documentation](http://www.gnuplot.info/documentation.html)
- [TDMA Algorithm (Wikipedia)](https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm)
- [C++ Standard Library Documentation](https://en.cppreference.com/w/)
- [C# Documentation (Microsoft)](https://learn.microsoft.com/en-us/dotnet/csharp/)



