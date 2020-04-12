import pathlib

from pysfml11 import Time, seconds, Sound, SoundBuffer


def test_construction():
    sound = Sound()

    assert isinstance(sound, Sound)


def test_buffer():
    sound = Sound()

    assert sound.buffer is None

    sound_buffer = SoundBuffer()
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'
    sound_buffer.load_from_file(str(resources / 'canary.wav'))

    sound.buffer = sound_buffer
    assert sound.buffer is sound_buffer


def test_loop():
    sound = Sound()

    assert type(sound.loop) is bool
    sound.loop = True


def test_playing_offset():
    sound = Sound()

    assert isinstance(sound.playing_offset, Time)
    assert sound.playing_offset.as_seconds() == 0

    sound_buffer = SoundBuffer()
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'
    sound_buffer.load_from_file(str(resources / 'canary.wav'))
    sound.buffer = sound_buffer

    sound.loop = True
    sound.play()
    sound.playing_offset = seconds(0.5)
    assert type(sound.playing_offset) is Time
