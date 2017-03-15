# !/usr/bin/env python
# -*- coding: utf-8 -*-

#-----------------------------------------------------------------------------
# Lectura línea a línea del fichero.
#-----------------------------------------------------------------------------
# En primer lugar debemos de abrir el fichero que vamos a leer.
# Usa 'rb' en vez de 'r' si se trata de un fichero binario.
# for i in range(2):

import re
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

numeric_const_pattern = r"""
    
	
     (?:
         (?: \d* \. \d+ ) # .1 .12 .123 etc 9.1 etc 98.1 etc
         |
         (?: \d+ \.? ) # 1. 12. 123. etc 1 12 123 etc
     )
     # followed by optional exponent part if desired
     (?: [Ee] [+-]? \d+ ) ?
     """
rx = re.compile(numeric_const_pattern, re.VERBOSE)
text = ""

matriz = []
num = 0
for i in range(2):
  
	#print "texto"+str(i+1)+".txt"
	infile = open("texto"+str(i+1)+".txt", 'r')

	matriz.append([])

	for line in infile:
		#for line in infile:
		 num = 255*(re.findall(r'\d\.\d+', line)
		 matriz[i].append(num)
		 text += str(matriz)+"\t"
		# Cerramos el fichero.
	infile.close()

def make_image(inputname,outputname):
	#data = mpimg.imread(inputname)[:,:,0]
	data = inputname
    #data = np.random.rand(288,5)
   	fig = plt.figure()
   	fig.set_size_inches(1, 1)
   	ax = plt.Axes(fig, [0., 0., 1., 1.])
   	ax.set_axis_off()
   	fig.add_axes(ax)
   	plt.set_cmap('hot')
   	ax.imshow(data, aspect = 'auto')
   	plt.savefig(outputname, dpi = 228)
   
make_image(matriz,'test.png')

print("la matriz resultante fue:"+str(matriz) )

outfile = open('texto.txt', 'w') # Indicamos el valor 'w'.
outfile.write(text)
outfile.close()

print "fin"

