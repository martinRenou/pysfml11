from pysfml.window import VideoMode

from pysfml.graphics import RenderWindow


def test_construction():
    mode = VideoMode(800, 600)

    window = RenderWindow(mode, 'test')

    assert window.is_open()
