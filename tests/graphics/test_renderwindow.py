import pytest

from pysfml11 import VideoMode, RenderWindow


def test_construction(ci):
    if ci:
        pytest.skip("skipping RenderWindow tests on CI (no display available)")

    mode = VideoMode(800, 600)

    window = RenderWindow(mode, 'test')

    assert window.is_open()
