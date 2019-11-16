#!/usr/bin/python3
"""Provides a function to compute the perimeter of an island"""


def island_perimeter(grid):
    """Compute the perimeter of an island"""
    perim = 0
    for y, row in enumerate(grid):
        for x, item in enumerate(row):
            if item == 1:
                try:
                    perim += grid[y][x - 1] == 0
                except IndexError:
                    perim += 1
                try:
                    perim += grid[y][x + 1] == 0
                except IndexError:
                    perim += 1
                try:
                    perim += grid[y - 1][x] == 0
                except IndexError:
                    perim += 1
                try:
                    perim += grid[y + 1][x] == 0
                except IndexError:
                    perim += 1
    return perim
