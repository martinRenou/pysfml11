import math
import pathlib

from pysfml11.system import Time
from pysfml11.audio import InputSoundFile


def test_construction():
    inputsound = InputSoundFile()

    assert isinstance(inputsound, InputSoundFile)


def test_open_file():
    inputsound = InputSoundFile()

    resources = pathlib.Path(__file__).parent.parent.absolute().joinpath('resources')

    assert not inputsound.open_from_file('this_file_does_not_exist.ogg')

    assert inputsound.open_from_file(str(resources.joinpath('canary.wav')))
    assert inputsound.open_from_file(str(resources.joinpath('ding.flac')))
    assert inputsound.open_from_file(str(resources.joinpath('orchestral.ogg')))


def test_methods():
    inputsound = InputSoundFile()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    inputsound.open_from_file(str(resources / 'canary.wav'))

    assert inputsound.get_sample_count() == 63460
    assert inputsound.get_channel_count() == 1
    assert inputsound.get_sample_rate() == 11025
    assert isinstance(inputsound.get_duration(), Time)
    assert math.isclose(inputsound.get_duration().as_seconds(), 5.75, rel_tol=0.01)
    assert isinstance(inputsound.get_time_offset(), Time)
    assert inputsound.get_time_offset().as_seconds() == 0
    assert inputsound.get_sample_offset() == 0
