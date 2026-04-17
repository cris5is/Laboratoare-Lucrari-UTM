import tkinter as tk
from tkinter import filedialog, ttk, messagebox
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
import csv
import statistics

root = tk.Tk()
data = []
def load_file():
    global data
    path = filedialog.askopenfilename(filetypes=[("csv", "*.csv"), ("txt", "*.txt")])
    if not path:
        return

    data = []
    try:
        with open(path, "r") as file:
            reader = csv.reader(file)
            for row in reader:
                for item in row:
                    try:
                        data.append(float(item))
                    except ValueError:
                        pass

        file_label.config(text=f"{path}")
        update_stats()
    except Exception as e:
        messagebox.showerror(f"Eroare {e}")

def update_stats():
    if not data:
        stats_label.config()
        return

    medie = statistics.mean(data)
    minim = min(data)
    maxim = max(data)
    stats_label.config(text=f"medie = {medie}, min = {minim}, max = {maxim}")

def draw_plot():
    if not data:
        messagebox.showwarning("nu s date incarcate")
        return

    gtype = graph_type.get()
    figure.clear()
    ax = figure.add_subplot(111)
    if gtype == "linie":
        ax.plot(data)
    elif gtype == "bara":
        ax.bar(range(len(data)), data)
    elif gtype == "histograma":
        ax.hist(data, bins=10)
    ax.set_title(f"{gtype}")
    canvas.draw()
def save_plot():
    filepath = filedialog.asksaveasfilename(defaultextension=".png", filetypes=[("png", "*.png")])
    if not filepath:
        return
    try:
        figure.savefig(filepath)
        save_label.config(text=f"{filepath}")
    except Exception as e:
        messagebox.showerror("Eroare {e}")
file_frame = tk.Frame(root)
file_frame.pack(pady=10)

tk.Button(file_frame, text="incarca fisier", command=load_file).pack(side=tk.LEFT, padx=5)
file_label = tk.Label(file_frame, text="niciun fisier incarcat")
file_label.pack(side=tk.LEFT)
graph_frame = tk.Frame(root)
graph_frame.pack(pady=10)
graph_type = ttk.Combobox(graph_frame, values=["linie", "bara", "histograma"])
graph_type.current(0)
graph_type.pack(side=tk.LEFT, padx=5)

tk.Button(root, text="deseneaza", command=draw_plot).pack(pady=10)

figure = Figure(figsize=(5, 4), dpi=100)
canvas = FigureCanvasTkAgg(figure, master=root)
canvas.get_tk_widget().pack()

stats_label = tk.Label(root)
stats_label.pack(pady=10)

save_frame = tk.Frame(root)
save_frame.pack(pady=10)
tk.Button(save_frame, text="export", command=save_plot).pack(side=tk.LEFT)
save_label = tk.Label(save_frame, text="nu s-a salvat")
save_label.pack(side=tk.LEFT, padx=5)

tk.Button(root, text="exit", command=root.quit).pack(pady=10)

root.mainloop()
