from pysfml11 import Time, seconds, milliseconds, microseconds


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


def test_operators():
    time1 = seconds(3)
    time2 = seconds(5)

    assert not time1 == time2
    assert time1 != time2
    assert time1 < time2
    assert not time1 > time2
    assert time1 <= time2
    assert not time1 >= time2
    assert (- time1).as_seconds() == -3
    assert (time1 + time2).as_seconds() == 8

    time1 += time1
    assert time1.as_seconds() == 6

    assert (time2 - time2).as_seconds() == 0

    time1 -= time1 / 2
    assert time1.as_seconds() == 3

    assert (time1 * 3).as_seconds() == 9
    assert (3 * time1).as_seconds() == 9

    assert (time1 / 3).as_seconds() == 1


def test_repr():
    time = seconds(3)

    assert str(time) == '<sfml.Time seconds=3>'
