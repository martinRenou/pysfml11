from pysfml11 import Vector2f, ConvexShape, Color


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

    shape.fill_color = Color.Yellow
    assert shape.fill_color == Color.Yellow

    assert isinstance(shape.outline_color, Color)

    shape.outline_color = Color.Magenta
    assert shape.outline_color == Color.Magenta

    assert shape.outline_thickness == 0

    shape.outline_thickness = 3
    assert shape.outline_thickness == 3
