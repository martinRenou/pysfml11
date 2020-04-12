import math

from pysfml11 import Vector3f, Sound, SoundSource


def test_construction():
    sound = Sound()

    assert isinstance(sound, SoundSource)
    assert isinstance(sound, Sound)


def test_pitch():
    sound = Sound()

    assert type(sound.pitch) is float
    sound.pitch = 2


def test_volume():
    sound = Sound()

    assert type(sound.volume) is float
    sound.volume = 80


def test_position():
    sound = Sound()

    assert type(sound.position) is Vector3f
    sound.position = Vector3f(1, 2, 4)


def test_relative_to_listener():
    sound = Sound()

    assert type(sound.relative_to_listener) is bool
    sound.relative_to_listener = True


def test_min_distance():
    sound = Sound()

    assert type(sound.min_distance) is float
    sound.min_distance = 2


def test_attenuation():
    sound = Sound()

    assert type(sound.attenuation) is float
    sound.attenuation = 2


def test_status():
    sound = Sound()

    assert sound.status == SoundSource.Status.Stopped
