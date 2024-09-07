
maxIterations=4000
# Specify the output file format and name
set terminal pngcairo
set output "temperature_plots.png"

# Define plot style and labels
set xlabel "X"
set ylabel "Temperature"

set title "Temperature Variation over Iterations S(x)"


# Set a smaller legend size
#set key samplen 1 spacing 1

# Plot data from multiple files using a loop
#plot for [i=0:maxIterations] 'TEST/'.i.'.dat' using 1:2 with lines title 'S=0.0'.i
plot for [i=1:maxIterations:100] 'ST/'.i.'.dat' using 1:2 with lines notitle 
