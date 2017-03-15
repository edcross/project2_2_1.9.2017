import matplotlib.pyplot as plt

import numpy as np
def make_image(inputname,outputname):
   # data = mpimg.imread(inputname)[:,:,0]
   data = np.random.rand(288,5)
   fig = plt.figure()
   fig.set_size_inches(1, 1)
   ax = plt.Axes(fig, [0., 0., 1., 1.])
   ax.set_axis_off()
   fig.add_axes(ax)
   plt.set_cmap('hot')
   ax.imshow(data, aspect = 'auto')
   plt.savefig(outputname, dpi = 228)
   
make_image(None,'out.png')