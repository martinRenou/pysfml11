import math
import pathlib

from pysfml11.system import Time
from pysfml11.audio import InputSoundFile


def test_construction():
    inputsound = InputSoundFile()

    assert isinstance(inputsound, InputSoundFile)


def test_open_file():
    inputsound = InputSoundFile()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    assert not inputsound.open_from_file('this_file_does_not_exist.ogg')

    assert inputsound.open_from_file(str(resources / 'canary.wav'))
    assert inputsound.open_from_file(str(resources / 'ding.flac'))
    assert inputsound.open_from_file(str(resources / 'orchestral.ogg'))


def test_methods():
    inputsound = InputSoundFile()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    inputsound.open_from_file(str(resources / 'canary.wav'))

    assert inputsound.sample_count == 63460
    assert inputsound.channel_count == 1
    assert inputsound.sample_rate == 11025
    assert isinstance(inputsound.duration, Time)
    assert math.isclose(inputsound.duration.as_seconds(), 5.75, rel_tol=0.01)
    assert isinstance(inputsound.time_offset, Time)
    assert inputsound.time_offset.as_seconds() == 0
    assert inputsound.sample_offset == 0


def test_read():
    inputsound = InputSoundFile()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    inputsound.open_from_file(str(resources / 'canary.wav'))

    samples = inputsound.read(640)
    assert len(samples) == 640
    assert inputsound.sample_offset == 640

    samples = inputsound.read(1024)
    assert len(samples) == 1024
    assert inputsound.sample_offset == 1024 + 640

    samples = inputsound.read(2048)
    assert len(samples) == 2048
    assert inputsound.sample_offset == 2048 + 1024 + 640

    # Read remaining samples minus 1
    remaining_samples = 63460 - 640 - 1024 - 2048 - 1
    samples = inputsound.read(remaining_samples)
    assert inputsound.sample_offset == 63460 - 1

    # Read two samples, there is only one remaining though
    samples = inputsound.read(2)
    assert len(samples) == 1

    # Test seek
    inputsound.seek(63460 - 2)
    samples = inputsound.read(3)
    assert len(samples) == 2
