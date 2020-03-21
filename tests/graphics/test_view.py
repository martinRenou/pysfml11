import math

import pysfml11 as sf


def test_construction():
    sf.View()

    sf.View(sf.FloatRect())

    sf.View(sf.Vector2f(), sf.Vector2f())


def test_center():
    center = sf.Vector2f(0.3, 7.8)

    view = sf.View(center, sf.Vector2f())

    assert math.isclose(view.center.x, 0.3, rel_tol=0.01)
    assert math.isclose(view.center.y, 7.8, rel_tol=0.01)

    view.center = sf.Vector2f(2, 3)

    assert math.isclose(view.center.x, 2, rel_tol=0.01)
    assert math.isclose(view.center.y, 3, rel_tol=0.01)


def test_size():
    size = sf.Vector2f(0.3, 7.8)

    view = sf.View(sf.Vector2f(), size)

    assert math.isclose(view.size.x, 0.3, rel_tol=0.01)
    assert math.isclose(view.size.y, 7.8, rel_tol=0.01)

    view.size = sf.Vector2f(2, 3)

    assert math.isclose(view.size.x, 2, rel_tol=0.01)
    assert math.isclose(view.size.y, 3, rel_tol=0.01)


def test_rotation():
    view = sf.View()

    assert math.isclose(view.rotation, 0, rel_tol=0.01)

    view.rotation = 3

    assert math.isclose(view.rotation, 3, rel_tol=0.01)


def test_viewport():
    viewport = sf.FloatRect(0, 0, 0.7, 1)
    viewport2 = sf.FloatRect(0, 0, 0.5, 1)

    view = sf.View()
    view.viewport = viewport

    assert view.viewport == viewport
    assert view.viewport != viewport2

    view.viewport = viewport2

    assert view.viewport == viewport2
    assert view.viewport != viewport


def test_move():
    center = sf.Vector2f(1, 1)

    view = sf.View(center, sf.Vector2f())

    assert view.center == sf.Vector2f(1, 1)

    view.move(2, 3)

    assert view.center == sf.Vector2f(3, 4)

    view.move(sf.Vector2f(-2, 3))

    assert view.center == sf.Vector2f(1, 7)


def test_rotate():
    view = sf.View()

    assert math.isclose(view.rotation, 0, rel_tol=0.01)

    view.rotate(3)

    assert math.isclose(view.rotation, 3, rel_tol=0.01)
