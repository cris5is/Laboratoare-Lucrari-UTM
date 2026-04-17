import cv2

file_in = "monkey-rizz.gif"
file_out = "C:/Users/culac/Desktop/labs/li_tp/7/miscare_simpla.avi"
varThreshold = 30
history= 300

cap = cv2.VideoCapture(file_in)
if not cap.isOpened():
    print("Eroare")
    exit(1)

w = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
h = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = cap.get(cv2.CAP_PROP_FPS)
if fps == 0:
    fps = 10.0

fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter(file_out, fourcc, fps, (w, h), isColor=False)

fgbg = cv2.createBackgroundSubtractorMOG2(history=history, varThreshold=varThreshold, detectShadows=False)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (15, 15), 0)
    fgmask = fgbg.apply(gray)
    _, fgmask = cv2.threshold(fgmask, 127, 255, cv2.THRESH_BINARY)
    fgmask = cv2.dilate(fgmask, None, iterations=2)
    out.write(fgmask)

cap.release()
out.release()
cv2.destroyAllWindows()
