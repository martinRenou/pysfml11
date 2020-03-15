"""Simple example of a rotating Rectangle."""
from pysfml11 import (
    Vector2f, Clock,
    VideoMode, Event, Color, RenderWindow,
    RectangleShape
)


width = 800
height = 600

mode = VideoMode(width, height)

window = RenderWindow(mode, 'My awesome SFML application!')

clock = Clock()

rectangle = RectangleShape(Vector2f(200, 300))
rectangle.fill_color = Color.Blue
rectangle.position = Vector2f(width / 2., height / 2.)


while (window.is_open()):
    event = Event()

    while window.poll_event(event):
        if event.type == Event.Closed:
            window.close()

    window.clear(Color.White)

    elapsed = clock.elapsed_time.as_seconds() * 40
    rectangle.rotation = elapsed

    window.draw(rectangle)

    window.display()
