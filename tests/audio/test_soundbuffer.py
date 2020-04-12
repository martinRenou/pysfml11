import pathlib

from pysfml11 import Time, SoundBuffer


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

    assert type(sound_buffer.sample_count) is int
    assert type(sound_buffer.channel_count) is int
    assert type(sound_buffer.sample_rate) is int
    assert len(sound_buffer.samples) == sound_buffer.sample_count
    assert isinstance(sound_buffer.duration, Time)
