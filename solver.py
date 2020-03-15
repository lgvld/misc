#!/usr/bin/env python3

import sys

import numpy as np

def parse_args():
    # equations = []
    # for line in [l.strip() for l in "".join(sys.argv[1:]).split(";") if l != ""]:
    #     eq = list(map(int, line.split(" ")))
    #     equations.append(eq)
    # return equations
    return [list(map(int, line.split(" "))) for line in [l.strip() for l in "".join(sys.argv[1:]).split(";") if l != ""]]

def solve(equations):
    assert list(map(len, equations)).count(len(equations[0])) == len(equations), "lines/equations must contain the same number of values"
    assert len(equations[0]) - 1 == len(equations), "must be a square matrix"
    # A = np.delete(np.array(equations), -1, axis=1)
    # b = np.array([eq[-1] for eq in equations])
    # return np.matmul(np.linalg.inv(A), b)
    return np.matmul(np.linalg.inv(np.delete(np.array(equations), -1, axis=1)), np.array([eq[-1] for eq in equations]))

if __name__ == '__main__':
    if len(sys.argv) == 1:
        line = "_"
        while line:
            line = input()
            print(line)
    else:
        print(solve(parse_args()))
