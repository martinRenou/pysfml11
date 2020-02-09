from pysfml11.system import Clock, Time, sleep, seconds


def test_construction():
    clock = Clock()

    assert isinstance(clock.get_elapsed_time(), Time)
    assert isinstance(clock.restart(), Time)


def test_elapsed_time():
    clock = Clock()

    sleep(seconds(1))

    assert clock.get_elapsed_time().as_seconds() >= 1
