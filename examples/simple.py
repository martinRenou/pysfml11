"""Simple example of a rotating Rectangle."""
from pysfml11.system import Vector2f, Clock
from pysfml11.window import VideoMode
from pysfml11.graphics import Color, RenderWindow, RectangleShape


width = 800
height = 600

mode = VideoMode(width, height)

window = RenderWindow(mode, 'My awesome SFML application!')

clock = Clock()

rectangle = RectangleShape(Vector2f(200, 300))
rectangle.fill_color = Color.blue
rectangle.position = Vector2f(width / 2., height / 2.)


while (window.is_open()):
    while window.poll_event():
        pass

    window.clear(Color.white)

    elapsed = clock.get_elapsed_time().as_seconds() * 40
    rectangle.rotation = elapsed

    window.draw(rectangle)

    window.display()