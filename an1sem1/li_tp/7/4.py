import tkinter as tk

import combinatorica as comb

def use_fact():
    numar = int(entry.get())
    if numar:
        result.config(text=f"{comb.factorial(numar)}")
    else:
        result.config(text="introduceti un numar natural")

def use_subfact():
    numar = int(entry.get())
    if numar:
        result.config(text=f"{comb.sub_factorial(numar)}")
    else:
        result.config(text="introduceti un numar natural")


root=tk.Tk()
root.title("test")
root.geometry("200x200")

entry = tk.Entry(root, width=25)
entry.pack()

btn_fact = tk.Button(root, text="factorial", command=use_fact)
btn_fact.pack(pady=10)
btn_subfact = tk.Button(root, text="subfactorial", command=use_subfact)
btn_subfact.pack(pady=10)

result = tk.Label(root, text="", font=("Arial", 14), fg="blue")
result.pack(pady=10)
root.mainloop()