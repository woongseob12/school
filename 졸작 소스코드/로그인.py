from tkinter import * 
from PIL import Image, ImageTk
import 기능 as cam

class MyLabel(Label):
    def __init__(self, master, filename):
        im = Image.open(filename)
        seq =  []
        try:
            while 1:
                seq.append(im.copy())
                im.seek(len(seq))
        except EOFError:
            pass
        try:
            self.delay = im.info['duration']
        except KeyError:
            self.delay = 100

        first = seq[0].convert('RGBA')
        self.frames = [ImageTk.PhotoImage(first)]

        Label.__init__(self, master, image=self.frames[0])

        temp = seq[0]
        for image in seq[1:]:
            temp.paste(image)
            frame = temp.convert('RGBA')
            self.frames.append(ImageTk.PhotoImage(frame))

        self.idx = 0

        self.cancel = self.after(self.delay, self.play)

    def play(self):
        self.config(image=self.frames[self.idx])
        self.idx += 1
        if self.idx == len(self.frames):
            self.idx = 0
        self.cancel = self.after(self.delay, self.play)        


gui = Tk()
gui.title("20142140 심웅섭")
gui.resizable(False, False)
anim = MyLabel(gui, 'sample2.gif')
anim.pack()

# id
logo_id = Label(gui, text="ID", bg = "black", fg = "white")
logo_id.place(x =140, y = 330)
test_id = Entry(gui, bg = "black", fg = "white")
test_id.insert(0, "학번/ 수험번호")
def clear_id(event):
    if test_id.get() == "학번/ 수험번호":
        test_id.delete(0,len(test_id.get()))
test_id.bind("<Button-1>", clear_id)
test_id.place(x =170, y = 330)

# pw
logo_pw = Label(gui, text="PW", bg = "black", fg = "white")
logo_pw.place(x =140, y = 360)
test_pw = Entry(gui, bg = "black", fg = "white")
test_pw.insert(0, "초기비밀번호")
def clear_pw(event):
    if test_pw.get() == "초기비밀번호":
        test_pw.delete(0,len(test_pw.get()))
test_pw.bind("<Button-1>", clear_pw)
test_pw.config(show = "*")
test_pw.place(x =170, y = 360)

# login btn
test_login = Button(gui)
def login():
    my_id = test_id.get()
    my_pw = test_pw.get()
    if (my_id == '20142140' and my_pw == '1234'):
        login_msg = Label(gui, text="            로그인 성공!                        ", fg = "blue", bg = "black")
        login_msg.place(x = 140, y = 390)
        cam.test()

    else:
        login_msg = Label(gui, text="ID 또는 Password가 일치하지 않습니다.", fg = "red", bg = "black")
        login_msg.place(x = 140, y = 390)
        
test_login.config(text = 'login', command = login, bg = "black", fg= "white", bd = 2)
test_login.place(x =345, y = 340)
