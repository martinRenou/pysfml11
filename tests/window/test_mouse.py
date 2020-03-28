import pytest

from pysfml11 import Mouse, Vector2i


def test_mouse_pressed(ci):
    if ci:
        pytest.skip("skipping Mouse tests on CI (no display available)")

    assert not Mouse.is_button_pressed(Mouse.Button.Left)


def test_mouse_position(ci):
    if ci:
        pytest.skip("skipping Mouse tests on CI (no display available)")

    assert isinstance(Mouse.position, Vector2i)

    old_position = Mouse.position

    Mouse.position = Vector2i(50, 50)
    assert Mouse.position.x == 50
    assert Mouse.position.y == 50

    Mouse.position = old_position
