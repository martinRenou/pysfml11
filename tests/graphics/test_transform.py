from pysfml11.system import Vector2f

from pysfml11.graphics import Transform, CircleShape


def test_construction():
    transform = Transform()

    assert transform == Transform.identity

    transform = Transform(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    )

    assert transform == Transform.identity

    shape = CircleShape(3)

    assert isinstance(shape.transform, Transform)


def test_methods():
    transform = Transform()

    assert transform.matrix == [
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    ]
