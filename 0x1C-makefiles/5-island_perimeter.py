#!/usr/bin/python3
"""Provides a function to compute the perimeter of an island"""


def island_perimeter(grid):
    """Compute the perimeter of an island"""
    perim = 0
    for y, row in enumerate(grid):
        for x, item in enumerate(row):
            if item == 1:
                if x == 0 or grid[y][x - 1] == 0:
                    perim += 1
                if x == len(row) - 1 or grid[y][x + 1] == 0:
                    perim += 1
                if y == 0 or grid[y - 1][x] == 0:
                    perim += 1
                if y == len(grid) - 1 or grid[y + 1][x] == 0:
                    perim += 1
    return perim
