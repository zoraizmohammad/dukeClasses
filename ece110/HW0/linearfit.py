import numpy as np
import pandas as pd
from tabulate import tabulate

# Initialize arrays for slopes and intercepts
slopes = []
intercepts = []

# List of data files
data_files = ['file1.dat', 'file2.dat', 'file3.dat']

for file in data_files:
    # Load data from a file
    data = pd.read_csv(file)  # replace with your file name
    voltage = data['voltage']  # replace with your column name
    current = data['current']  # replace with your column name

    # Determine the line of best fit
    P = np.polyfit(voltage, current, 1)  # 1 for linear fit

    # Store the slope and intercept into arrays
    slopes.append(P[0])
    intercepts.append(P[1])

# Create a table with results
table = list(zip(data_files, slopes, intercepts))

# Print the table with scientific notation with four significant figures
print(tabulate(table, headers=['Data File', 'Slope', 'Intercept'], floatfmt=".3e"))