from pysfml11.system import Vector2f

from pysfml11.graphics import CircleShape, Color


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

    circle.fill_color = Color.yellow
    assert circle.fill_color == Color.yellow

    assert isinstance(circle.outline_color, Color)

    circle.outline_color = Color.magenta
    assert circle.outline_color == Color.magenta

    assert circle.outline_thickness == 0

    circle.outline_thickness = 3
    assert circle.outline_thickness == 3


def test_position():
    circle = CircleShape(3)

    assert isinstance(circle.position, Vector2f)
    assert circle.position.x == 0
    assert circle.position.y == 0

    circle.position = Vector2f(2, 3)
    assert circle.position.x == 2
    assert circle.position.y == 3


def test_rotation():
    circle = CircleShape(3)

    assert isinstance(circle.rotation, float)
    assert circle.rotation == 0

    circle.rotation = 2
    assert circle.rotation == 2


def test_scale():
    circle = CircleShape(3)

    assert isinstance(circle.scale, Vector2f)
    assert circle.scale.x == 1
    assert circle.scale.y == 1

    circle.scale = Vector2f(2, 3)
    assert circle.scale.x == 2
    assert circle.scale.y == 3


def test_origin():
    circle = CircleShape(3)

    assert isinstance(circle.origin, Vector2f)
    assert circle.origin.x == 0
    assert circle.origin.y == 0

    circle.origin = Vector2f(2, 3)
    assert circle.origin.x == 2
    assert circle.origin.y == 3


def test_move():
    circle = CircleShape(3)

    assert circle.position.x == 0
    assert circle.position.y == 0

    circle.move(2, 3)
    assert circle.position.x == 2
    assert circle.position.y == 3

    circle.move(Vector2f(-2, -3))
    assert circle.position.x == 0
    assert circle.position.y == 0


def test_rotate():
    circle = CircleShape(3)

    assert circle.rotation == 0

    circle.rotate(2)
    assert circle.rotation == 2
