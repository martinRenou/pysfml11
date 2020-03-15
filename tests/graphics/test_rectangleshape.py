from pysfml11 import Vector2f, RectangleShape, Color, FloatRect


def test_construction():
    rectangle1 = RectangleShape(Vector2f(2, 3))

    assert rectangle1.size.x == 2
    assert rectangle1.size.y == 3
    assert rectangle1.point_count == 4

    rectangle1.size = Vector2f(5, 6)
    assert rectangle1.size.x == 5
    assert rectangle1.size.y == 6


def test_get_point():
    rectangle = RectangleShape(Vector2f(2, 3))

    assert isinstance(rectangle.get_point(2), Vector2f)

def test_style():
    rectangle = RectangleShape(Vector2f(2, 3))

    assert isinstance(rectangle.fill_color, Color)

    rectangle.fill_color = Color.Yellow
    assert rectangle.fill_color == Color.Yellow

    assert isinstance(rectangle.outline_color, Color)

    rectangle.outline_color = Color.Magenta
    assert rectangle.outline_color == Color.Magenta

    assert rectangle.outline_thickness == 0

    rectangle.outline_thickness = 3
    assert rectangle.outline_thickness == 3

    assert isinstance(rectangle.local_bounds, FloatRect)
    assert isinstance(rectangle.global_bounds, FloatRect)
