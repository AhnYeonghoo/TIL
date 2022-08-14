import cv2

path = "C:/Users/Ahn_YeongHoo/Desktop/TIL/Python/dog.jpg"
image = cv2.imread(path, cv2.IMREAD_UNCHANGED)

cv2.imshow("image",image)
cv2.waitKey(0)
cv2.destroyAllWindows()

video = cv2.VideoCapture("cat2.mp4")

while video.isOpened():
    check, frame = video.read()
    if not check:
        print("Frame is done")
        break
    
    cv2.imshow("cute cats", frame)
    if cv2.waitKey(25) == ord('q'):
        print("exit video")
        break

video.release()
cv2.destroyAllWindows()
    