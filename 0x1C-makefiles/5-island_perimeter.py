#!/usr/bin/python3
"""Provides a function to compute the perimeter of an island"""


def island_perimeter(grid):
    """Compute the perimeter of an island"""
    perimeter = 0
    for y, row in enumerate(grid):
        for x, item in enumerate(row):
            if item == 1:
                if 0 < x:
                    perimeter += grid[y][x - 1] == 0
                if x < len(row) - 1:
                    perimeter += grid[y][x + 1] == 0
                if 0 < y:
                    perimeter += grid[y - 1][x] == 0
                if y < len(grid) - 1:
                    perimeter += grid[y + 1][x] == 0
    return perimeter
