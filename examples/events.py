"""Dumps the events in the console."""
from pysfml11.window import VideoMode, Event
from pysfml11.graphics import Color, RenderWindow


width = 800
height = 600

mode = VideoMode(width, height)

window = RenderWindow(mode, 'My awesome SFML application!')


while (window.is_open()):
    event = Event()

    while window.poll_event(event):
        print('\n{}!'.format(event.type))

        if event.type == Event.EventType.Resized:
            print(event.size.width, event.size.height)

        if event.type == Event.EventType.TextEntered:
            print(event.text.unicode)

        if event.type == Event.EventType.KeyPressed or event.type == Event.EventType.KeyReleased:
            # print(event.key.code, event.key.alt, event.key.control, event.key.shift, event.key.system)
            print(event.key.alt, event.key.control, event.key.shift, event.key.system)

        if event.type == Event.EventType.MouseMoved:
            print(event.mouse_move.x, event.mouse_move.y)

        if event.type == Event.EventType.MouseButtonPressed or event.type == Event.EventType.MouseButtonReleased:
            # print(event.mouse_button.button, event.mouse_button.x, event.mouse_button.y)
            print(event.mouse_button.x, event.mouse_button.y)

        if event.type == Event.EventType.MouseWheelMoved:
            print(event.mouse_wheel.delta, event.mouse_wheel.x, event.mouse_wheel.y)

        if event.type == Event.EventType.MouseWheelScrolled:
            # print(event.mouse_wheel_scroll.wheel, event.mouse_wheel_scroll.delta, event.mouse_wheel_scroll.x, event.mouse_wheel_scroll.y)
            print(event.mouse_wheel_scroll.delta, event.mouse_wheel_scroll.x, event.mouse_wheel_scroll.y)

    window.clear(Color.white)

    window.display()
