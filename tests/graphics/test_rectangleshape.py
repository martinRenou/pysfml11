from pysfml.system import Vector2f

from pysfml.graphics import RectangleShape, Color


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

    rectangle.fill_color = Color.yellow
    assert rectangle.fill_color == Color.yellow

    assert isinstance(rectangle.outline_color, Color)

    rectangle.outline_color = Color.magenta
    assert rectangle.outline_color == Color.magenta

    assert rectangle.outline_thickness == 0

    rectangle.outline_thickness = 3
    assert rectangle.outline_thickness == 3


def test_position():
    rectangle = RectangleShape(Vector2f(2, 3))

    assert isinstance(rectangle.position, Vector2f)
    assert rectangle.position.x == 0
    assert rectangle.position.y == 0

    rectangle.position = Vector2f(2, 3)
    assert rectangle.position.x == 2
    assert rectangle.position.y == 3


def test_rotation():
    rectangle = RectangleShape(Vector2f(2, 3))

    assert isinstance(rectangle.rotation, float)
    assert rectangle.rotation == 0

    rectangle.rotation = 2
    assert rectangle.rotation == 2


def test_scale():
    rectangle = RectangleShape(Vector2f(2, 3))

    assert isinstance(rectangle.scale, Vector2f)
    assert rectangle.scale.x == 1
    assert rectangle.scale.y == 1

    rectangle.scale = Vector2f(2, 3)
    assert rectangle.scale.x == 2
    assert rectangle.scale.y == 3


def test_origin():
    rectangle = RectangleShape(Vector2f(2, 3))

    assert isinstance(rectangle.origin, Vector2f)
    assert rectangle.origin.x == 0
    assert rectangle.origin.y == 0

    rectangle.origin = Vector2f(2, 3)
    assert rectangle.origin.x == 2
    assert rectangle.origin.y == 3


def test_move():
    rectangle = RectangleShape(Vector2f(2, 3))

    assert rectangle.position.x == 0
    assert rectangle.position.y == 0

    rectangle.move(2, 3)
    assert rectangle.position.x == 2
    assert rectangle.position.y == 3

    rectangle.move(Vector2f(-2, -3))
    assert rectangle.position.x == 0
    assert rectangle.position.y == 0


def test_rotate():
    rectangle = RectangleShape(Vector2f(2, 3))

    assert rectangle.rotation == 0

    rectangle.rotate(2)
    assert rectangle.rotation == 2
