import pathlib
import math

from pysfml11.system import Time
from pysfml11.audio import Music


def test_construction():
    music = Music()

    assert isinstance(music, Music)


def test_open_file():
    music = Music()

    resources = pathlib.Path(__file__).parent.parent.absolute().joinpath('resources')

    assert not music.open_from_file('this_file_does_not_exist.ogg')

    assert music.open_from_file(str(resources.joinpath('canary.wav')))
    assert music.open_from_file(str(resources.joinpath('ding.flac')))
    assert music.open_from_file(str(resources.joinpath('orchestral.ogg')))


def test_methods():
    music = Music()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    music.open_from_file(str(resources / 'canary.wav'))

    assert music.channel_count == 1
    assert music.sample_rate == 11025
    assert isinstance(music.duration, Time)
    assert math.isclose(music.duration.as_seconds(), 5.75, rel_tol=0.01)
    assert isinstance(music.playing_offset, Time)
    assert music.playing_offset.as_seconds() == 0
    assert not music.loop
