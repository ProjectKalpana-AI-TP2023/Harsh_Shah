import cv2 as cv
import numpy as np

prevcircle = None
dist = lambda x1,x2,y1,y2: (x1-x2)**2+(y1-y2)**2

vid = cv.VideoCapture(0)
while True:
    ret, frame = vid.read()

    if not ret: break

    grey = cv.cvtColor(frame, cv.COLOR_GRAY2RGB)
    blur = cv.GaussianBlur(grey,(17,17),0)
    
    circles = cv.HoughCircles(grey, cv.HOUGH_GRADIENT ,1.2,100,param1 = 100, param2=40,minRadius=10,maxRadius=200)

    if circles is None: 
        circles = np.uint16(np.arround(circles))
        chose = None
        for i in circles[0:]:
            if chosen is None: chosen = i
            if prevcircle is not None:
                if dist(chosen[0],chosen[1],prevcircle[0],prevcircle[1]) <= dist(i[0],i[1],prevcircle[0],prevcircle[1]):
                    chosen = i
        
        cv.circle(frame,(chosen[0],chosen[1]),1,(0,0,255),3)
        cv.circle(frame,(chosen[0],chosen[1]),chosen[2],(0,0,255),3)
        prevcircle = chosen
    
    cv.imshow("circle",frame)

    if cv.waitKey(1) & 0xFf == ord("q"): break

vid.release()
cv.destroyAllWindows()
