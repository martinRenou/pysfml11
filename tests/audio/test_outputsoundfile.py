import pathlib

from pysfml11 import OutputSoundFile, InputSoundFile


def test_construction():
    outputsound = OutputSoundFile()

    assert isinstance(outputsound, OutputSoundFile)


def test_write():
    inputsound = InputSoundFile()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    inputsound.open_from_file(str(resources / 'canary.wav'))

    outputsound = OutputSoundFile()

    sample_rate = inputsound.sample_rate
    channel_count = inputsound.channel_count

    # Read only a subset of the samples
    samples = inputsound.read(1024)

    outputsound.open_from_file(str(resources / 'canary2.ogg'), sample_rate, channel_count)
    outputsound.write(samples)

    # Read the output
    writtensound = InputSoundFile()
    assert writtensound.open_from_file(str(resources / 'canary2.ogg'))
