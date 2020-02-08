from pysfml.system import Clock, Time


def test_construction():
    clock = Clock()

    assert isinstance(clock.get_elapsed_time(), Time)
