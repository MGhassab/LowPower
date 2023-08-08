import numpy as np
from PIL import Image
Image.fromarray(np.loadtxt('Y_result.txt', dtype=np.uint8)).save('Y_result.png')
Image.fromarray(np.loadtxt('Cb_result.txt', dtype=np.uint8)).save('Cb_result.png')
Image.fromarray(np.loadtxt('Cr_result.txt', dtype=np.uint8)).save('Cr_result.png')