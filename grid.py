#!/bin/env python3

import hashlib

import colorama

N = 16
COLORS = "nbre"
CCOLORS = [colorama.Back.BLACK, colorama.Back.BLUE, colorama.Back.RED, colorama.Back.WHITE]

grid = [None for i in range(N ** 2)]

def print_grid(g):
    for i in range(N ** 2):
        if i % N == 0:
            print()
        if g[i] == None:
            print(".", end=" ")
        else:
            print(CCOLORS[g[i]] + COLORS[g[i]], end=" ")
        print(colorama.Style.RESET_ALL, end="")
    print()

def grid2str(g):
    return "".join([str(g[i]) for i in range(N ** 2) if g[i] is not None])

def int_from_grid(g, max):
    return int.from_bytes(hashlib.sha256(grid2str(g).encode()).hexdigest().encode(), byteorder="big") % max

def fill_next_cell(g):
    empty_cells = [i for i in range(N ** 2) if g[i] == None]
    if len(empty_cells) > 0:
        pos = empty_cells[int_from_grid(grid, len(empty_cells))]
        color = int_from_grid(grid, len(COLORS))
        g[pos] = color
        return pos
    return -1

if __name__ == "__main__":
    grid[0] = COLORS.index("r")
    pos = 0
    # print("[0]")
    print_grid(grid)
    for i in range(N ** 2):
        print("[" + str(i + 1) + "] ↓ (" + str(pos // N + 1) + ";" + str(pos % N + 1) + ")", end="")
        print_grid(grid)
        input("")
        pos = fill_next_cell(grid)
    # print_grid(grid)
