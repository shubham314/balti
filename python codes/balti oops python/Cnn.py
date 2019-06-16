# Import Libraries
from keras.preprocessing.image import load_img
from keras.preprocessing.image import img_to_array
from keras.applications.vgg16 import preprocess_input
from keras.applications.vgg16 import decode_predictions
from keras.applications.vgg16 import VGG16
from keras import backend as K
import matplotlib.pyplot as plt
import numpy as np
import cv2


# Process Model
class imageClassifier:

    def __init__(self):
        pass


    def imageInput(ima):
        image_file = ima
        model = VGG16()
        image = load_img(image_file, target_size=(224, 224))
        image = img_to_array(image)
        image = image.reshape((1, image.shape[0], image.shape[1], image.shape[2]))
        image = preprocess_input(image)

        # Generate predictions
        pred = model.predict(image)
        print('Predicted:', decode_predictions(pred, top=3)[0])
        np.argmax(pred[0])

i = cv2.VideoCapture(0)

#i = 'c.jpg'
#j = 'b.jpg'
print("------------------------------")


#imageClassifier.imageInput(j)
print("------------------------------")
imageClassifier.imageInput(i)