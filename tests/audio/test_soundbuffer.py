import math
import pathlib

from pysfml11.system import Time
from pysfml11.audio import SoundBuffer


def test_construction():
    sound_buffer = SoundBuffer()

    assert isinstance(sound_buffer, SoundBuffer)


def test_load_from_file():
    sound_buffer = SoundBuffer()

    resources = pathlib.Path(__file__).parent.parent.absolute().joinpath('resources')

    assert not sound_buffer.load_from_file('this_file_does_not_exist.ogg')

    assert sound_buffer.load_from_file(str(resources.joinpath('canary.wav')))


def test_methods():
    sound_buffer = SoundBuffer()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    sound_buffer.load_from_file(str(resources / 'canary.wav'))

    assert sound_buffer.sample_count == 63460
    assert sound_buffer.channel_count == 1
    assert sound_buffer.sample_rate == 11025
    assert len(sound_buffer.samples) == sound_buffer.sample_count
    assert isinstance(sound_buffer.duration, Time)
    assert math.isclose(sound_buffer.duration.as_seconds(), 5.75, rel_tol=0.01)
