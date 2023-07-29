def isValid(x, y, n, maze):
    return 0 <= x < n and 0 <= y < n and maze[x][y] == 1

def solve(maze, x, y, n, path, visited):
    if x == n - 1 and y == n - 1:
        path.append((x, y))
        return True

    if isValid(x, y, n, maze) and not visited[x][y]:
        visited[x][y] = True
        path.append((x, y))

        if solve(maze, x + 1, y, n, path, visited):
            return True

        if solve(maze, x, y + 1, n, path, visited):
            return True

        if solve(maze, x - 1, y, n, path, visited):
            return True

        if solve(maze, x, y - 1, n, path, visited):
            return True

        # If none of the above paths lead to the destination, backtrack
        path.pop()
        visited[x][y] = False
        return False


def ratInAMaze(maze, n):
    path = []
    visited = [[False for _ in range(n)] for _ in range(n)]

    if solve(maze, 0, 0, n, path, visited):
        for x, y in path:
            print(f"({x}, {y}) -> ", end="")
        print("Destination Reached!")
    else:
        print("No path to reach the destination!")


# Main.
n = int(input())
maze = []

for i in range(n):
    row = input().split()
    maze.append([int(j) for j in row])

ratInAMaze(maze, n)
