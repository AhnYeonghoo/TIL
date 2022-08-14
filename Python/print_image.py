import cv2

path = "C:/Users/Ahn_YeongHoo/Desktop/TIL/Python/dog.jpg"
image = cv2.imread(path, cv2.IMREAD_UNCHANGED)

cv2.imshow("image",image)
cv2.waitKey(0)
cv2.destroyAllWindows()
