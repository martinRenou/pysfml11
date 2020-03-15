# pysfml11


A Python binding for the [SFML](https://www.sfml-dev.org) library, based on [pybind11](https://github.com/pybind/pybind11).

## Usage

```python
import pysfml11 as sf


width = 800
height = 600

# Create your window
window = sf.RenderWindow(sf.VideoMode(width, height), 'My awesome SFML application!')

clock = sf.Clock()

rectangle = sf.RectangleShape(sf.Vector2f(200, 300))
rectangle.fill_color = sf.Color.Blue
rectangle.position = sf.Vector2f(width / 2., height / 2.)

# Simple rendering loop: poll events/clear/draw/display
while (window.is_open()):
    event = sf.Event()

    while window.poll_event(event):
        if event.type == sf.Event.Closed:
            window.close()
        # Do something with the event (mouse event/keyboard event/resize event...)

    window.clear(sf.Color.White)

    elapsed = clock.elapsed_time.as_seconds() * 40
    rectangle.rotation = elapsed

    window.draw(rectangle)

    window.display()
```

## API differences

Most of the C++ API has been ported to Python using [pybind11](https://github.com/pybind/pybind11), except features that did not make sense to implement because already available in Python (Threading features are available through the built-in [threading](https://docs.python.org/3/library/threading.html) module. String features are already supported by Python).

There are some API differences:

### camelCase to snake_case

All method/function names are renamed using snake_case.

### Setters/Getters

Those are replaced by properties (read-only properties if there is not getter available). So for example with the RectangleShape, this C++ code:

```cpp
sf::RectangleShape rectangle;

rectangle.setPosition(10, 20);
sf::Vector2f position = rectangle.getPosition();
```

Becomes the following in Python:
```python
rectangle = RectangleShape()

rectangle.position = Vector2f(10, 20)
position = rectangle.position
```

### C-like functions

C-like functions are made simpler. For example with the InputSoundFile's read method, the samples buffer is the returned value (no need to allocate it before calling the method), and the samples counts actually read can be computed getting the length of the returned value.

This C++ code:
```cpp
sf::InputSoundFile file;
file.openFromFile("music.ogg");

sf::Int16 samples[1024];
sf::Uint64 count = file.read(samples, 1024);
```

Becomes the following in Python:
```python
file = InputSoundFile()
file.open_from_file("music.ogg")

samples = file.read(1024)
count = len(samples)
```

## Status

`pysfml11` is under development and not yet usable. Contributions are very welcome!

## License

`pysfml11` is provided under a BSD-style license that can be found in the LICENSE
file. By using, distributing, or contributing to this project, you agree to the
terms and conditions of this license.
