import tkinter as tk
from sympy import *
from sympy.parsing.sympy_parser import (
    parse_expr, standard_transformations, implicit_multiplication_application)


class LaplaceTransformGUI:
    def __init__(self, master):
        self.master = master
        master.title("Laplace Transform Calculator")

        self.label = tk.Label(master, text="Enter the function to transform:")
        self.label.pack()

        self.entry = tk.Entry(master)
        self.entry.pack()

        self.button = tk.Button(
            master, text="Calculate", command=self.calculate)
        self.button.pack()

        self.result_label = tk.Label(master, text="")
        self.result_label.pack()

    def calculate(self):
        transformations = (standard_transformations +
                           (implicit_multiplication_application,))
        function = parse_expr(
            self.entry.get(), transformations=transformations)

        laplace_transform = laplace_transform(function, t, s)[0]
        inverse_laplace_transform = inverse_laplace_transform(
            laplace_transform, s, t)

        result = f"Laplace Transform: {laplace_transform}\nInverse Laplace Transform: {inverse_laplace_transform}"
        self.result_label.config(text=result)


root = tk.Tk()
gui = LaplaceTransformGUI(root)
root.mainloop()
