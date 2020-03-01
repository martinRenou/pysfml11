from pysfml11 import Mouse, Vector2i


def test_mouse_pressed():
    assert not Mouse.is_button_pressed(Mouse.Button.Left)


def test_mouse_position():
    assert isinstance(Mouse.position, Vector2i)

    old_position = Mouse.position

    Mouse.position = Vector2i(50, 50)
    assert Mouse.position.x == 50
    assert Mouse.position.y == 50

    Mouse.position = old_position
