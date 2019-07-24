import tkinter
import tkinter.messagebox

def main():
    flag = True

    def change_label_text():
        nonlocal flag
        flag = not flag
        color, msg = ('red', 'Hello world!!')\
            if flag else ('blue', 'Goodbye world!!')
        label.config(text=msg, fg=color)

    def confirm_to_quit():
        if tkinter.messagebox.askokcancel('tip','are u sure to quit?'):
            top.quit()

    top = tkinter.Tk()
    top.geometry('240x160')
    top.title('A tiny game')
    label = tkinter.Label(top, text='helllo, world!', font='Arial -32', fg='red')
    label.pack(expand=1)
    panel=tkinter.Frame(top)
    button1 = tkinter.Button(panel, text='change', command=change_label_text)
    button1.pack(side='left')
    button2 = tkinter.Button(panel,text='exit', command=confirm_to_quit)
    button2.pack(side='right')
    panel.pack(side='bottom')
    tkinter.mainloop()


if __name__ == "__main__":
    main()