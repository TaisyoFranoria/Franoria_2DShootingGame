from tkinter import *
from PIL import Image,ImageTk

win = Tk();
cv = Canvas(win,width=600,height=450)
cv.pack();


filename = "cutin.png"
img = Image.open(filename)

img_tk = ImageTk.PhotoImage(img)

cv.create_image(0,0,image=img_tk,anchor=NW)

win.mainloop()
