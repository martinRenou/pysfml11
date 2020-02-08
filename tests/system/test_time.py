from pysfml.system import Time, seconds, milliseconds, microseconds


def test_construction():
    time = Time()

    assert time.as_seconds() == 0
    assert time.as_milliseconds() == 0
    assert time.as_microseconds() == 0


def test_seconds():
    time = seconds(3)

    assert isinstance(time, Time)
    assert time.as_seconds() == 3
    assert time.as_milliseconds() == 3000
    assert time.as_microseconds() == 3000000


def test_milliseconds():
    time = milliseconds(4000)

    assert isinstance(time, Time)
    assert time.as_seconds() == 4
    assert time.as_milliseconds() == 4000
    assert time.as_microseconds() == 4000000


def test_microseconds():
    time = microseconds(5000000)

    assert isinstance(time, Time)
    assert time.as_seconds() == 5
    assert time.as_milliseconds() == 5000
    assert time.as_microseconds() == 5000000
