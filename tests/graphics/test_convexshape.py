from pysfml11.system import Vector2f

from pysfml11.graphics import ConvexShape, Color


def test_construction():
    shape1 = ConvexShape(3)

    assert shape1.point_count == 3

    shape1.point_count = 40
    assert shape1.point_count == 40

    shape2 = ConvexShape(500)
    assert shape2.point_count == 500


def test_get_point():
    shape = ConvexShape(3)

    assert isinstance(shape.get_point(2), Vector2f)

    shape.set_point(2, Vector2f(34, 6))
    assert shape.get_point(2).x == 34
    assert shape.get_point(2).y == 6

def test_style():
    shape = ConvexShape(3)

    assert isinstance(shape.fill_color, Color)

    shape.fill_color = Color.yellow
    assert shape.fill_color == Color.yellow

    assert isinstance(shape.outline_color, Color)

    shape.outline_color = Color.magenta
    assert shape.outline_color == Color.magenta

    assert shape.outline_thickness == 0

    shape.outline_thickness = 3
    assert shape.outline_thickness == 3


def test_position():
    shape = ConvexShape(3)

    assert isinstance(shape.position, Vector2f)
    assert shape.position.x == 0
    assert shape.position.y == 0

    shape.position = Vector2f(2, 3)
    assert shape.position.x == 2
    assert shape.position.y == 3


def test_rotation():
    shape = ConvexShape(3)

    assert isinstance(shape.rotation, float)
    assert shape.rotation == 0

    shape.rotation = 2
    assert shape.rotation == 2


def test_scale():
    shape = ConvexShape(3)

    assert isinstance(shape.scale, Vector2f)
    assert shape.scale.x == 1
    assert shape.scale.y == 1

    shape.scale = Vector2f(2, 3)
    assert shape.scale.x == 2
    assert shape.scale.y == 3


def test_origin():
    shape = ConvexShape(3)

    assert isinstance(shape.origin, Vector2f)
    assert shape.origin.x == 0
    assert shape.origin.y == 0

    shape.origin = Vector2f(2, 3)
    assert shape.origin.x == 2
    assert shape.origin.y == 3


def test_move():
    shape = ConvexShape(3)

    assert shape.position.x == 0
    assert shape.position.y == 0

    shape.move(2, 3)
    assert shape.position.x == 2
    assert shape.position.y == 3

    shape.move(Vector2f(-2, -3))
    assert shape.position.x == 0
    assert shape.position.y == 0


def test_rotate():
    shape = ConvexShape(3)

    assert shape.rotation == 0

    shape.rotate(2)
    assert shape.rotation == 2
