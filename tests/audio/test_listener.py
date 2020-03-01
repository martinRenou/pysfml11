import math

from pysfml11 import Vector3f, Listener


def test_global_volume():
    assert Listener.global_volume == 100

    Listener.global_volume = 80
    assert math.isclose(Listener.global_volume, 80, rel_tol=0.1)


def test_position():
    assert isinstance(Listener.position, Vector3f)

    assert Listener.position == Vector3f(0, 0, 0)

    Listener.position = Vector3f(1, 2, 4)
    assert Listener.position == Vector3f(1, 2, 4)


def test_direction():
    assert isinstance(Listener.direction, Vector3f)

    assert Listener.direction == Vector3f(0, 0, -1)

    Listener.direction = Vector3f(1, 2, 4)
    assert Listener.direction == Vector3f(1, 2, 4)


def test_up_vector():
    assert isinstance(Listener.up_vector, Vector3f)

    assert Listener.up_vector == Vector3f(0, 1, 0)

    Listener.up_vector = Vector3f(1, 2, 4)
    assert Listener.up_vector == Vector3f(1, 2, 4)
