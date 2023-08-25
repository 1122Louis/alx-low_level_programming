#!/usr/bin/python3

"""
Module 5-island_perimeter
Find the perimeter of an island.
The island is one block where the island (1)
is surrounded by water (0) and each side of the (1)
is a unit length
"""


def island_perimeter(grid):
    """Return the perimeter of an island

    Args:
        grid (list): 2d array bitmap

    Returns:
        perimeter (int)
    """
    max_y = len(grid)
    max_x = len(grid[0])
    perimeter = 0

    def neighbours(grid, x, y, max_x, max_y):
        """Return number of neighbours of a cell in a grid

        Args:
            grid (list): the 2d array bitmap of the island
            x: the current cell's x position
            x: the current cell's y position
            max_x: the extent of the island's "width"
            max_y: the extent of the island's "height"

        Returns:
            n (int): number of neighbours (non-zero neighbours)
        """

        n = 0

        # left neighbour
        n += x > 0 and grid[y][x - 1]

        # top neighbour
        n += y > 0 and grid[y - 1][x]

        # right neighbour
        n += x + 1 < max_x and grid[y][x + 1]

        # bottom neighbour
        n += y + 1 < max_y and grid[y + 1][x]

        return n

    for i in range(max_y):
        for j in range(max_x):
            if grid[i][j]:
                perimeter += 4 - neighbours(grid, j, i, max_x, max_y)

    return perimeter
