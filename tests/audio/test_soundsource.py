import math

from pysfml11.system import Vector3f
from pysfml11.audio import Sound, SoundSource


def test_construction():
    sound = Sound()

    assert isinstance(sound, SoundSource)
    assert isinstance(sound, Sound)


def test_pitch():
    sound = Sound()

    assert sound.pitch == 1

    sound.pitch = 2
    assert sound.pitch == 2


def test_volume():
    sound = Sound()

    assert sound.volume == 100

    sound.volume = 80
    assert math.isclose(sound.volume, 80, rel_tol=0.1)


def test_position():
    sound = Sound()

    assert isinstance(sound.position, Vector3f)

    sound.position = Vector3f(1, 2, 4)
    assert sound.position == Vector3f(1, 2, 4)


def test_relative_to_listener():
    sound = Sound()

    assert not sound.relative_to_listener

    sound.relative_to_listener = True
    assert sound.relative_to_listener


def test_min_distance():
    sound = Sound()

    assert sound.min_distance == 1

    sound.min_distance = 2
    assert math.isclose(sound.min_distance, 2, rel_tol=0.01)


def test_attenuation():
    sound = Sound()

    assert sound.attenuation == 1

    sound.attenuation = 2
    assert math.isclose(sound.attenuation, 2, rel_tol=0.01)


def test_status():
    sound = Sound()

    assert sound.get_status() == SoundSource.Status.stopped
