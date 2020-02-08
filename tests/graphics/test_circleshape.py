from pysfml.system import Vector2f

from pysfml.graphics import CircleShape, Color


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


def test_fill_color():
    circle1 = CircleShape(3)

    assert isinstance(circle1.fill_color, Color)

    circle1.fill_color = Color.yellow
    assert circle1.fill_color == Color.yellow
