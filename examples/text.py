"""Simple example of rotating Text."""
import pathlib
from pysfml11 import (
    Vector2f, Clock,
    VideoMode, Event, Color, RenderWindow,
    Text, Font
)


FONT = (
    pathlib.Path(__file__).parent / 'resources' / 'Manrope-ExtraLight.ttf'
    ).resolve()

width = 800
height = 600

mode = VideoMode(width, height)

window = RenderWindow(mode, 'My awesome SFML application!')

clock = Clock()

font = Font()
font.load_from_file(str(FONT))

text = Text('Hello World!', font)
text.fill_color = Color.Blue
text.position = Vector2f(width / 2., height / 2.)


while (window.is_open()):
    event = Event()

    while window.poll_event(event):
        if event.type == Event.Closed:
            window.close()

    window.clear(Color.White)

    elapsed = clock.elapsed_time.as_seconds() * 40
    text.rotation = elapsed

    window.draw(text)

    window.display()
