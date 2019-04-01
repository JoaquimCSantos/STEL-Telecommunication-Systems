import csv
import matplotlib.pyplot
import numpy as np
from scipy.misc import factorial

scale = []
histogram = []

with open('histograma.csv') as f:
	reader = csv.reader(f, delimiter = ';')
	for row in reader:
		scale.append(float(row[0]))
		histogram.append(int(row[1]))

# poisson
# t = np.arange(0, 20, 1)
# d = np.exp(-5)*np.power(5, t)/factorial(t)

# matplotlib.pyplot.plot(t, d, 'bs')
# matplotlib.pyplot.show()

matplotlib.pyplot.bar(scale, histogram, width = 1, color = 'purple', alpha = 0.75)
matplotlib.pyplot.plot(scale, histogram, 'b--', linewidth = 2.5)
matplotlib.pyplot.xlabel('Int Tempo')
matplotlib.pyplot.ylabel('Late Arrivals')
matplotlib.pyplot.title('Histograma')
matplotlib.pyplot.show()
