import cv2
import requests

url = "http://direccion_IP_ESP32/capture"
response = requests.get(url, stream=True)

with open("imagen.jpg", "wb") as img_file:
    for chunk in response.iter_content(chunk_size=1024):
        img_file.write(chunk)

# Leer la imagen con OpenCV
img = cv2.imread("imagen.jpg")
cv2.imshow("Imagen recibida", img)
cv2.waitKey(0)
