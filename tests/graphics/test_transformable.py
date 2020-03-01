from pysfml11 import Vector2f, ConvexShape, Color


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
