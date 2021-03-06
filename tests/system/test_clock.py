from pysfml11 import Clock, Time, sleep, seconds


def test_construction():
    clock = Clock()

    assert isinstance(clock.elapsed_time, Time)
    assert isinstance(clock.restart(), Time)


def test_elapsed_time():
    clock = Clock()

    sleep(seconds(1))

    assert clock.elapsed_time.as_seconds() >= 1
