from pysfml11 import Vector2f, CircleShape, Color


def test_construction():
    circle1 = CircleShape(3)

    assert circle1.radius == 3
    assert circle1.point_count == 30

    circle1.radius = 4
    assert circle1.radius == 4

    circle1.point_count = 40
    assert circle1.point_count == 40

    circle2 = CircleShape(20, 500)
    assert circle2.radius == 20
    assert circle2.point_count == 500


def test_get_point():
    circle = CircleShape(3)

    assert isinstance(circle.get_point(3), Vector2f)


def test_style():
    circle = CircleShape(3)

    assert isinstance(circle.fill_color, Color)

    circle.fill_color = Color.Yellow
    assert circle.fill_color == Color.Yellow

    assert isinstance(circle.outline_color, Color)

    circle.outline_color = Color.Magenta
    assert circle.outline_color == Color.Magenta

    assert circle.outline_thickness == 0

    circle.outline_thickness = 3
    assert circle.outline_thickness == 3
