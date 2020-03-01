from pysfml11.window import Window, VideoMode, ContextSettings, Style
from pysfml11.system import Vector2i


def test_open_close():
    window = Window()

    assert not window.is_open()

    window.close()


def test_position():
    window = Window()

    assert isinstance(window.position, Vector2i)

    position = Vector2i(50, 70)

    window.position = position

    window.close()
