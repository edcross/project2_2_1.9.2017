import re
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import cv2

numero_filas = 2389

matriz = []

def make_image(inputname,outputname):
    # data = mpimg.imread(inputname)[:,:,0]
    # data = np.random.rand(288,5)
   data = inputname
   fig = plt.figure()
   fig.set_size_inches(1, 1)
   ax = plt.Axes(fig, [0., 0., 1., 1.])
   ax.set_axis_off()
   fig.add_axes(ax)
   plt.set_cmap('hot')
   ax.imshow(data, aspect = 'auto')
   plt.savefig(outputname, dpi = 228)

clase = []

f = open("/home/ed/Dropbox/shared_ED/categorias/s1.txt",'r')

for line in f.readlines():

    clase.append(line.split())
    
    #print(clase)

#seq = open("/home/ed/Dropbox/shared_ED/categorias/s1.txt",'r')

#ite = 1
#for l in seq:
    
for i in range(numero_filas):
    
    n = 0
    while n < 5:
     
        matriz.append([])
        infile = open("/Documents/VidriloTags/Sequence1/Vidrilo_Sequence1.GoogleCloudVision/sequence1visual"+str(i+1)+".txt", 'r')

   # for j in range(numero_columnas):
        for line in infile:    
        #num = int(255*(re.findall( r'\d+\.*\d*', line )))
 
            num = (line.split('-')[1].split()[0])
       
            num = float(num)
            num = 255*num
            #print num
            num = int(num)
            matriz[i].append(num)
        
        infile.close()
    np.array(matriz).shape
    #cv2.imshow("img",np.array(matriz))
    
    #cv2.waitKey(0)

    #make_image(matriz,'out.png')

            n = n + 1
        
            continue

    name = "out"+str(ite)+".png"
    print name
    make_image(matriz,name)
#ite=ite+1

#print matriz