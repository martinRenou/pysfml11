"""Sand simulation example.

This was inspired by https://github.com/seanballais/sand-sim-2d, which was
itself inspired by the following talk: https://www.youtube.com/watch?v=prXuyMCgbTc.
"""

from random import choice

from pysfml11.system import Vector2f, Vector2i, Clock, sleep, milliseconds
from pysfml11.window import VideoMode, Event, Mouse
from pysfml11.graphics import Color, RenderWindow, RectangleShape


physics_accumulator = 0.
grain_spawner_accumulator = 0.

WIDTH = 640
HEIGHT = 640
SAND_SIZE = 8
PHYSICS_TIME_STEP = 1. / 30.

window = RenderWindow(VideoMode(WIDTH, HEIGHT), 'Sand Simulation!')

clock = Clock()

sand_shape = RectangleShape(Vector2f(SAND_SIZE, SAND_SIZE))
sand_shape.fill_color = Color(255, 255, 153)

sand_locations = []


def get_cell_grid_position(pixel_coord):
    """Get position in the sand grid, given the pixel coordinate."""
    return Vector2i(pixel_coord.x - pixel_coord.x % SAND_SIZE, pixel_coord.y - pixel_coord.y % SAND_SIZE)


def simulate_physics(sand_locations, delta_time):
    """Simulate the physics."""
    global physics_accumulator

    physics_accumulator += delta_time

    while physics_accumulator >= PHYSICS_TIME_STEP:
        for location in sand_locations:
            # Is there a grain under this location?
            if Vector2i(location.x, location.y + SAND_SIZE) in sand_locations:
                # Move the grain either to the left or right
                move_right = choice([True, False])

                if move_right:
                    # Is there an empty spot at the bottom right?
                    if Vector2i(location.x + SAND_SIZE, location.y + SAND_SIZE) not in sand_locations:
                        location.x += SAND_SIZE
                else:
                    # Is there an empty spot at the bottom left?
                    if Vector2i(location.x - SAND_SIZE, location.y + SAND_SIZE) not in sand_locations:
                        location.x -= SAND_SIZE
            else:
                location.y = min(location.y + SAND_SIZE, int(HEIGHT * 0.75))

        physics_accumulator -= PHYSICS_TIME_STEP


while (window.is_open()):
    event = Event()

    while window.poll_event(event):
        if event.type == Event.EventType.Closed:
            window.close()

    elapsed_time = clock.restart()
    delta_time = elapsed_time.as_seconds()

    # If the mouse left button is pressed, add a new sand grain in the world
    if Mouse.is_button_pressed(Mouse.Button.Left) and grain_spawner_accumulator >= 0.02:
        mouse_position = Mouse.get_position(window)
        sand_locations.append(get_cell_grid_position(mouse_position))

        grain_spawner_accumulator = 0.

    grain_spawner_accumulator += delta_time

    window.clear(Color.black)

    # Draw sand grains
    for location in sand_locations:
        sand_shape.position = Vector2f(location.x, location.y)
        window.draw(sand_shape)

    window.display()

    simulate_physics(sand_locations, delta_time)

    sleep(milliseconds(16))
