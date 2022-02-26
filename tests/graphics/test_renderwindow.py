import pytest

from pysfml11 import (
    VideoMode, RenderWindow, View, Color, IntRect,
    Vector2f, Vector2i
)


def test_construction(ci):
    if ci:
        pytest.skip("skipping RenderWindow tests on CI (no display available)")

    mode = VideoMode(800, 600)

    window = RenderWindow(mode, 'test')

    assert window.is_open()
    assert isinstance(window.default_view, View)
    assert isinstance(window.get_viewport(window.default_view), IntRect)
    assert isinstance(window.map_pixel_to_coords(Vector2i(1, 2)), Vector2f)
    assert isinstance(window.map_pixel_to_coords(Vector2i(1, 2), window.default_view), Vector2f)
    assert isinstance(window.map_coords_to_pixel(Vector2f(1., 2.)), Vector2i)
    assert isinstance(window.map_coords_to_pixel(Vector2f(1., 2.), window.default_view), Vector2i)

    window.clear(Color())
