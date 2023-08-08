import numpy as np
from PIL import Image
Image.fromarray(np.loadtxt('R_img.txt', dtype=np.uint8)).save('elaine_512.png')