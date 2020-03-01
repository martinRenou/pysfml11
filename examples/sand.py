"""Sand simulation example.

This was inspired by https://github.com/seanballais/sand-sim-2d, which was
itself inspired by the following talk: https://www.youtube.com/watch?v=prXuyMCgbTc.
"""

from random import choice

import numpy as np

from pysfml11.system import Vector2f, Clock
from pysfml11.window import VideoMode, Event, Mouse, Style
from pysfml11.graphics import Color, RenderWindow, RectangleShape


physics_accumulator = 0.
grain_spawner_accumulator = 0.

WIDTH = 640
HEIGHT = 640
SAND_SIZE = 8

GRID_WIDTH = WIDTH // SAND_SIZE
GRID_HEIGHT = HEIGHT // SAND_SIZE

PHYSICS_TIME_STEP = 1. / 30.

grid = np.ndarray((GRID_WIDTH, GRID_HEIGHT), dtype=np.bool)
grid.fill(False)

window = RenderWindow(VideoMode(WIDTH, HEIGHT), 'Sand Simulation!', Style.Titlebar | Style.Close)

clock = Clock()

sand_shape = RectangleShape(Vector2f(SAND_SIZE, SAND_SIZE))
sand_shape.fill_color = Color(255, 255, 153)


def simulate_physics(grid, grains_indices, delta_time):
    """Simulate the physics."""
    global physics_accumulator

    physics_accumulator += delta_time

    while physics_accumulator >= PHYSICS_TIME_STEP:
        for location in grains_indices:
            x = location[0]
            y = location[1]

            if y == GRID_HEIGHT - 1:
                continue

            # Is there a grain under this location?
            if grid[x][y + 1]:
                # Move the grain either to the left or right
                move_right = choice([True, False])

                if move_right:
                    # Is there an empty spot at the bottom right?
                    if x != GRID_WIDTH - 1 and not grid[x + 1][y + 1]:
                        grid[x][y] = False
                        grid[x + 1][y] = True
                else:
                    # Is there an empty spot at the bottom left?
                    if x != 0 and not grid[x - 1][y + 1]:
                        grid[x][y] = False
                        grid[x - 1][y] = True
            else:
                # Move down
                grid[x][y] = False
                grid[x][y + 1] = True

        physics_accumulator -= PHYSICS_TIME_STEP


while (window.is_open()):
    event = Event()

    while window.poll_event(event):
        if event.type == Event.EventType.Closed:
            window.close()

    elapsed_time = clock.restart()
    delta_time = elapsed_time.as_seconds()

    # If the mouse left button is pressed, add a new sand grain in the world
    if Mouse.is_button_pressed(Mouse.Button.Left) and grain_spawner_accumulator >= 0.04:
        mouse_position = Mouse.get_position(window)

        grid_x = mouse_position.x // SAND_SIZE
        grid_y = mouse_position.y // SAND_SIZE

        if 0 <= grid_x < GRID_WIDTH and 0 <= grid_y < GRID_HEIGHT:
            grid[grid_x][grid_y] = True

        grain_spawner_accumulator = 0.

    grain_spawner_accumulator += delta_time

    window.clear(Color.Black)

    sand_indices = np.argwhere(grid)

    # Sort them from bottom to top (this improves the simulation slightly)
    sand_indices = sand_indices[np.argsort(sand_indices[..., 1])[::-1]]

    # Draw sand grains
    for location in sand_indices:
        sand_shape.set_position(location[0] * SAND_SIZE, location[1] * SAND_SIZE)
        window.draw(sand_shape)

    window.display()

    simulate_physics(grid, sand_indices, delta_time)
