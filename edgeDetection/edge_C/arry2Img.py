import numpy as np
from PIL import Image
Image.fromarray(np.loadtxt('elaine_512.txt', dtype=np.uint8)).save('elaine_512.png')