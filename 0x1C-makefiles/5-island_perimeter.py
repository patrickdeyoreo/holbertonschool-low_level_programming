#!/usr/bin/python3


def island_perimeter(grid):
    """Compute the perimeter of an island"""
    perimeter = 0
    for y, row in enumerate(grid):
        for x, value in enumerate(row):
            if value == 1:
                for i, j in ((x - 1, y), (x + 1, y)):
                    if 0 < x < len(row):
                        if grid[j][i] == 0:
                            perimeter += 1
                for i, j in ((x, y - 1), (x, y + 1)):
                    if 0 < y < len(grid):
                        if grid[j][i] == 0:
                            perimeter += 1
    return perimeter
