import pytest

from pysfml11 import Window, Vector2i


def test_open_close(ci):
    if ci:
        pytest.skip("skipping Window tests on CI (no display available)")

    window = Window()

    assert not window.is_open()

    window.close()


def test_position(ci):
    if ci:
        pytest.skip("skipping Window tests on CI (no display available)")

    window = Window()

    assert isinstance(window.position, Vector2i)

    position = Vector2i(50, 70)

    window.position = position

    window.close()
