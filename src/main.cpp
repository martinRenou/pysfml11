#include <array>
#include <sstream>
#include <vector>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>


namespace py = pybind11;

#define PYSFML_CONCATENATE(A, B) PYSFML_CONCATENATE_IMPL(A, B)
#define PYSFML_CONCATENATE_IMPL(A, B) A##B
#define PYSFML_STRINGIFY(a) PYSFML_STRINGIFY_IMPL(a)
#define PYSFML_STRINGIFY_IMPL(a) #a
#define PYSFML_CONCAT_STRING(A, B) PYSFML_STRINGIFY(PYSFML_CONCATENATE(A, B))


// Return the Python repr of a boolean value
std::string bool_repr(bool value)
{
    return value ? "True" : "False";
}


PYBIND11_MODULE(pysfml11, sfml)
{
    sfml.doc() = R"pbdoc(
        pysfml11
        --------

        .. currentmodule:: pysfml11
    )pbdoc";

    /*****************
     * SYSTEM MODULE *
     *****************/

    /* Time class */
    py::class_<sf::Time>(sfml, "Time")
        .def(py::init<>())
        .def("as_seconds", &sf::Time::asSeconds)
        .def("as_milliseconds", &sf::Time::asMilliseconds)
        .def("as_microseconds", &sf::Time::asMicroseconds)
        .def_readonly_static("zero", &sf::Time::Zero)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self < py::self)
        .def(py::self > py::self)
        .def(py::self <= py::self)
        .def(py::self >= py::self)
        .def(-py::self)
        .def(py::self + py::self)
        .def(py::self += py::self)
        .def(py::self - py::self)
        .def(py::self -= py::self)
        .def(float() * py::self)
        .def(py::self * float())
        .def(py::self *= float())
        .def(py::self / float())
        .def(py::self /= float())
        .def(py::self / py::self)
        .def(py::self % py::self)
        .def(py::self %= py::self)
        .def("__repr__", [](const sf::Time& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Time seconds=" << self.asSeconds() << ">";
            return stream.str();
        });

    /* Timing free functions */
    sfml.def("seconds", &sf::seconds, py::arg("amount"));
    sfml.def("milliseconds", &sf::milliseconds, py::arg("amount"));
    sfml.def("microseconds", &sf::microseconds, py::arg("amount"));
    sfml.def("sleep", &sf::sleep, py::arg("duration"));

    /* Clock class */
    py::class_<sf::Clock>(sfml, "Clock")
        .def(py::init<>())
        .def_property_readonly("elapsed_time", &sf::Clock::getElapsedTime)
        .def("restart", &sf::Clock::restart);

    #define PYSFML_IMPLEMENT_VECTOR2(T, TS)                                \
    py::class_<sf::Vector2<T>>(sfml, PYSFML_CONCAT_STRING(Vector2, TS))    \
        .def(py::init<T, T>(), py::arg("x") = (T)0, py::arg("y") = (T)0)   \
        .def(py::init<sf::Vector2<T>>(), py::arg("vector"))                \
        .def_readwrite("x", &sf::Vector2<T>::x)                            \
        .def_readwrite("y", &sf::Vector2<T>::y)                            \
        .def(-py::self)                                                    \
        .def(py::self += py::self)                                         \
        .def(py::self -= py::self)                                         \
        .def(py::self + py::self)                                          \
        .def(py::self - py::self)                                          \
        .def((T)0 * py::self)                                              \
        .def(py::self * (T)0)                                              \
        .def(py::self *= (T)0)                                             \
        .def(py::self / (T)0)                                              \
        .def(py::self /= (T)0)                                             \
        .def(py::self == py::self)                                         \
        .def(py::self != py::self)                                         \
        .def("__repr__", [](const sf::Vector2<T>& self) {                  \
            std::ostringstream stream;                                     \
            stream << "<pysfml11." << PYSFML_CONCAT_STRING(Vector2, TS) << \
                " x=" << self.x <<                                         \
                " y=" << self.y << ">";                                    \
            return stream.str();                                           \
        });

    /* Vector2f class */
    PYSFML_IMPLEMENT_VECTOR2(float, f)
    /* Vector2i class */
    PYSFML_IMPLEMENT_VECTOR2(int, i)
    /* Vector2u class */
    PYSFML_IMPLEMENT_VECTOR2(unsigned int, u)
    /* Vector2b class */
    PYSFML_IMPLEMENT_VECTOR2(bool, b)

    #undef PYSFML_IMPLEMENT_VECTOR2

    #define PYSFML_IMPLEMENT_VECTOR3(T, TS)                                                      \
    py::class_<sf::Vector3<T>>(sfml, PYSFML_CONCAT_STRING(Vector3, TS))                          \
        .def(py::init<T, T, T>(), py::arg("x") = (T)0, py::arg("y") = (T)0, py::arg("z") = (T)0) \
        .def(py::init<sf::Vector3<T>>(), py::arg("vector"))                                      \
        .def_readwrite("x", &sf::Vector3<T>::x)                                                  \
        .def_readwrite("y", &sf::Vector3<T>::y)                                                  \
        .def_readwrite("z", &sf::Vector3<T>::z)                                                  \
        .def(-py::self)                                                                          \
        .def(py::self += py::self)                                                               \
        .def(py::self -= py::self)                                                               \
        .def(py::self + py::self)                                                                \
        .def(py::self - py::self)                                                                \
        .def((T)0 * py::self)                                                                    \
        .def(py::self * (T)0)                                                                    \
        .def(py::self *= (T)0)                                                                   \
        .def(py::self / (T)0)                                                                    \
        .def(py::self /= (T)0)                                                                   \
        .def(py::self == py::self)                                                               \
        .def(py::self != py::self)                                                               \
        .def("__repr__", [](const sf::Vector3<T>& self) {                                        \
            std::ostringstream stream;                                                           \
            stream << "<pysfml11." << PYSFML_CONCAT_STRING(Vector3, TS) <<                       \
                " x=" << self.x <<                                                               \
                " y=" << self.y <<                                                               \
                " z=" << self.z << ">";                                                          \
            return stream.str();                                                                 \
        });

    /* Vector3f class */
    PYSFML_IMPLEMENT_VECTOR3(float, f)
    /* Vector3i class */
    PYSFML_IMPLEMENT_VECTOR3(int, i)
    /* Vector3u class */
    PYSFML_IMPLEMENT_VECTOR3(unsigned int, u)
    /* Vector3b class */
    PYSFML_IMPLEMENT_VECTOR3(bool, b)

    #undef PYSFML_IMPLEMENT_VECTOR3

    /* InputStream class */
    py::class_<sf::InputStream>(sfml, "InputStream")
        .def("read", [](sf::InputStream& self, std::size_t count) {
            sf::Int64* samples = new sf::Int64[count];

            sf::Uint64 readcount = self.read(samples, count);
            // TODO: Raise if readcount is -1
            return std::vector<int64_t>(samples, samples + readcount);
        }, py::arg("size"))
        .def("seek", &sf::InputStream::seek, py::arg("position"))
        .def("tell", &sf::InputStream::tell)
        .def_property_readonly("size", &sf::InputStream::getSize);

    /* FileInputStream class */
    py::class_<sf::FileInputStream, sf::InputStream>(sfml, "FileInputStream")
        .def(py::init<>())
        .def("open", &sf::FileInputStream::open, py::arg("filename"));

    /*****************
     * WINDOW MODULE *
     *****************/

    // TODO
    // class   sf::Joystick
    // class   sf::Sensor
    // class   sf::Touch
    // class   sf::Window

    /* ContextSettings class */
    py::class_<sf::ContextSettings> context_settings(sfml, "ContextSettings");

    py::enum_<sf::ContextSettings::Attribute>(context_settings, "Attribute", py::arithmetic())
        .value("Default", sf::ContextSettings::Attribute::Default)
        .value("Core", sf::ContextSettings::Attribute::Core)
        .value("Debug", sf::ContextSettings::Attribute::Debug)
        .export_values();

    context_settings.def(
            py::init<std::size_t, std::size_t, std::size_t, std::size_t, sf::ContextSettings::Attribute, bool>(),
            py::arg("depth_bits") = 0, py::arg("stencil_bits") = 0, py::arg("major_version") = 1, py::arg("minor_version") = 1, py::arg("attribute_flags") = sf::ContextSettings::Attribute::Default, py::arg("s_rgb_capable") = false
        )
        .def_readwrite("depth_bits", &sf::ContextSettings::depthBits)
        .def_readwrite("stencil_bits", &sf::ContextSettings::stencilBits)
        .def_readwrite("antialiasing_level", &sf::ContextSettings::antialiasingLevel)
        .def_readwrite("major_version", &sf::ContextSettings::majorVersion)
        .def_readwrite("minor_version", &sf::ContextSettings::minorVersion)
        .def_readwrite("attribute_flags", &sf::ContextSettings::attributeFlags)
        .def_readwrite("s_rgb_capable", &sf::ContextSettings::sRgbCapable);

    /* Context class */
    py::class_<sf::Context>(sfml, "Context")
        .def(py::init<>())
        .def(py::init<const sf::ContextSettings&, std::size_t, std::size_t>(), py::arg("settings"), py::arg("width"), py::arg("height"))
        .def("set_active", &sf::Context::setActive, py::arg("active"))
        .def_property_readonly("settings", &sf::Context::getSettings)
        .def_static("is_extension_available", &sf::Context::isExtensionAvailable, py::arg("name"))
        // .def_static("get_function", &sf::Context::getFunction)
        .def_static("get_active_context", &sf::Context::getActiveContext)
        .def_static("get_active_context_id", &sf::Context::getActiveContextId);

    /* VideoMode class */
    py::class_<sf::VideoMode>(sfml, "VideoMode")
        .def(py::init<std::size_t, std::size_t, std::size_t>(), py::arg("width"), py::arg("height"), py::arg("bits_per_pixel") = 32)
        .def("is_valid", &sf::VideoMode::isValid)
        .def_static("get_desktop_mode", &sf::VideoMode::getDesktopMode)
        .def_static("get_fullscreen_modes", &sf::VideoMode::getFullscreenModes)
        .def_readwrite("width", &sf::VideoMode::width)
        .def_readwrite("height", &sf::VideoMode::height)
        .def_readwrite("bits_per_pixel", &sf::VideoMode::bitsPerPixel)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self < py::self)
        .def(py::self > py::self)
        .def(py::self <= py::self)
        .def(py::self >= py::self);

    /* Clipboard class */
    py::class_<sf::Clipboard>(sfml, "Clipboard")
        .def_property_static("string", [](py::object) {
            std::string str = sf::Clipboard::getString();
            return str;
        }, [](py::object, const std::string& str) {
            sf::Clipboard::setString(str);
        });

    /* Cursor class */
    py::class_<sf::Cursor> cursor(sfml, "Cursor");

    py::enum_<sf::Cursor::Type>(cursor, "Type")
        .value("Arrow", sf::Cursor::Arrow)
        .value("ArrowWait", sf::Cursor::ArrowWait)
        .value("Wait", sf::Cursor::Wait)
        .value("Text", sf::Cursor::Text)
        .value("Hand", sf::Cursor::Hand)
        .value("SizeHorizontal", sf::Cursor::SizeHorizontal)
        .value("SizeVertical", sf::Cursor::SizeVertical)
        .value("SizeTopLeftBottomRight", sf::Cursor::SizeTopLeftBottomRight)
        .value("SizeBottomLeftTopRight", sf::Cursor::SizeBottomLeftTopRight)
        .value("SizeAll", sf::Cursor::SizeAll)
        .value("Cross", sf::Cursor::Cross)
        .value("Help", sf::Cursor::Help)
        .value("NotAllowed", sf::Cursor::NotAllowed)
        .export_values();

    cursor.def(py::init<>())
        .def("load_from_pixels", [](sf::Cursor& self, const std::vector<uint8_t>& pixels, const sf::Vector2u& size, const sf::Vector2u& hotspot) {
            return self.loadFromPixels(pixels.data(), size, hotspot);
        }, py::arg("pixels"), py::arg("size"), py::arg("hotspot"))
        // TODO for convenience?
        // .def("load_from_file", &sf::Cursor::loadFromFile)
        .def("load_from_system", &sf::Cursor::loadFromSystem, py::arg("type"));

    /* Event class */
    py::class_<sf::Event> event(sfml, "Event");

    py::class_<sf::Event::SizeEvent>(event, "SizeEvent")
        .def_readonly("width", &sf::Event::SizeEvent::width)
        .def_readonly("height", &sf::Event::SizeEvent::height)
        .def("__repr__", [](const sf::Event::SizeEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.SizeEvent width=" << self.width << " height=" << self.height << ">";
            return stream.str();
        });

    py::class_<sf::Event::KeyEvent>(event, "KeyEvent")
        .def_readonly("code", &sf::Event::KeyEvent::code)
        .def_readonly("alt", &sf::Event::KeyEvent::alt)
        .def_readonly("control", &sf::Event::KeyEvent::control)
        .def_readonly("shift", &sf::Event::KeyEvent::shift)
        .def_readonly("system", &sf::Event::KeyEvent::system)
        .def("__repr__", [](const sf::Event::KeyEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.KeyEvent code=" << self.code << " alt=" << self.alt <<
                " control=" << self.control << " shift=" << self.shift <<
                " system=" << self.system << ">";
            return stream.str();
        });

    py::class_<sf::Event::TextEvent>(event, "TextEvent")
        .def_readonly("unicode", &sf::Event::TextEvent::unicode)
        .def("__repr__", [](const sf::Event::TextEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.TextEvent unicode=" << self.unicode << ">";
            return stream.str();
        });

    py::class_<sf::Event::MouseMoveEvent>(event, "MouseMoveEvent")
        .def_readonly("x", &sf::Event::MouseMoveEvent::x)
        .def_readonly("y", &sf::Event::MouseMoveEvent::y)
        .def("__repr__", [](const sf::Event::MouseMoveEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.MouseMoveEvent x=" << self.x << " y=" << self.y << ">";
            return stream.str();
        });

    py::class_<sf::Event::MouseButtonEvent>(event, "MouseButtonEvent")
        .def_readonly("button", &sf::Event::MouseButtonEvent::button)
        .def_readonly("x", &sf::Event::MouseButtonEvent::x)
        .def_readonly("y", &sf::Event::MouseButtonEvent::y)
        .def("__repr__", [](const sf::Event::MouseButtonEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.MouseButtonEvent button=" << self.button << " x=" << self.x << " y=" << self.y << ">";
            return stream.str();
        });

    py::class_<sf::Event::MouseWheelEvent>(event, "MouseWheelEvent")
        .def_readonly("delta", &sf::Event::MouseWheelEvent::delta)
        .def_readonly("x", &sf::Event::MouseWheelEvent::x)
        .def_readonly("y", &sf::Event::MouseWheelEvent::y)
        .def("__repr__", [](const sf::Event::MouseWheelEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.MouseWheelEvent delta=" << self.delta << " x=" << self.x << " y=" << self.y << ">";
            return stream.str();
        });

    py::class_<sf::Event::MouseWheelScrollEvent>(event, "MouseWheelScrollEvent")
        .def_readonly("wheel", &sf::Event::MouseWheelScrollEvent::wheel)
        .def_readonly("delta", &sf::Event::MouseWheelScrollEvent::delta)
        .def_readonly("x", &sf::Event::MouseWheelScrollEvent::x)
        .def_readonly("y", &sf::Event::MouseWheelScrollEvent::y)
        .def("__repr__", [](const sf::Event::MouseWheelScrollEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.MouseWheelScrollEvent wheel=" << self.wheel << " delta=" << self.delta << " x=" << self.x << " y=" << self.y << ">";
            return stream.str();
        });

    py::class_<sf::Event::JoystickConnectEvent>(event, "JoystickConnectEvent")
        .def_readonly("joystick_id", &sf::Event::JoystickConnectEvent::joystickId)
        .def("__repr__", [](const sf::Event::JoystickConnectEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.JoystickConnectEvent joystick_id=" << self.joystickId << ">";
            return stream.str();
        });

    py::class_<sf::Event::JoystickMoveEvent>(event, "JoystickMoveEvent")
        .def_readonly("joystick_id", &sf::Event::JoystickMoveEvent::joystickId)
        .def_readonly("axis", &sf::Event::JoystickMoveEvent::axis)
        .def_readonly("position", &sf::Event::JoystickMoveEvent::position)
        .def("__repr__", [](const sf::Event::JoystickMoveEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.JoystickMoveEvent joystick_id=" << self.joystickId << " axis=" << self.axis << " position=" << self.position << ">";
            return stream.str();
        });

    py::class_<sf::Event::JoystickButtonEvent>(event, "JoystickButtonEvent")
        .def_readonly("joystick_id", &sf::Event::JoystickButtonEvent::joystickId)
        .def_readonly("button", &sf::Event::JoystickButtonEvent::button)
        .def("__repr__", [](const sf::Event::JoystickButtonEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.JoystickButtonEvent joystick_id=" << self.joystickId << " button=" << self.button << ">";
            return stream.str();
        });

    py::class_<sf::Event::TouchEvent>(event, "TouchEvent")
        .def_readonly("finger", &sf::Event::TouchEvent::finger)
        .def_readonly("x", &sf::Event::TouchEvent::x)
        .def_readonly("y", &sf::Event::TouchEvent::y)
        .def("__repr__", [](const sf::Event::TouchEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.TouchEvent finger=" << self.finger << " x=" << self.x << " y=" << self.y << ">";
            return stream.str();
        });

    py::class_<sf::Event::SensorEvent>(event, "SensorEvent")
        .def_readonly("type", &sf::Event::SensorEvent::type)
        .def_readonly("x", &sf::Event::SensorEvent::x)
        .def_readonly("y", &sf::Event::SensorEvent::y)
        .def_readonly("z", &sf::Event::SensorEvent::z)
        .def("__repr__", [](const sf::Event::SensorEvent& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Event.SensorEvent type=" << self.type << " x=" << self.x << " y=" << self.y << " z=" << self.z << ">";
            return stream.str();
        });

    py::enum_<sf::Event::EventType>(event, "EventType")
        .value("Closed", sf::Event::Closed)
        .value("Resized", sf::Event::Resized)
        .value("LostFocus", sf::Event::LostFocus)
        .value("GainedFocus", sf::Event::GainedFocus)
        .value("TextEntered", sf::Event::TextEntered)
        .value("KeyPressed", sf::Event::KeyPressed)
        .value("KeyReleased", sf::Event::KeyReleased)
        .value("MouseWheelMoved", sf::Event::MouseWheelMoved)
        .value("MouseWheelScrolled", sf::Event::MouseWheelScrolled)
        .value("MouseButtonPressed", sf::Event::MouseButtonPressed)
        .value("MouseButtonReleased", sf::Event::MouseButtonReleased)
        .value("MouseMoved", sf::Event::MouseMoved)
        .value("MouseEntered", sf::Event::MouseEntered)
        .value("MouseLeft", sf::Event::MouseLeft)
        .value("JoystickButtonPressed", sf::Event::JoystickButtonPressed)
        .value("JoystickButtonReleased", sf::Event::JoystickButtonReleased)
        .value("JoystickMoved", sf::Event::JoystickMoved)
        .value("JoystickConnected", sf::Event::JoystickConnected)
        .value("JoystickDisconnected", sf::Event::JoystickDisconnected)
        .value("TouchBegan", sf::Event::TouchBegan)
        .value("TouchMoved", sf::Event::TouchMoved)
        .value("TouchEnded", sf::Event::TouchEnded)
        .value("SensorChanged", sf::Event::SensorChanged)
        .value("Count", sf::Event::Count)
        .export_values();

    event.def(py::init<>())
        .def_readonly("type", &sf::Event::type)
        .def_readonly("size", &sf::Event::size)
        .def_readonly("key", &sf::Event::key)
        .def_readonly("text", &sf::Event::text)
        .def_readonly("mouse_move", &sf::Event::mouseMove)
        .def_readonly("mouse_button", &sf::Event::mouseButton)
        .def_readonly("mouse_wheel", &sf::Event::mouseWheel)
        .def_readonly("mouse_wheel_scroll", &sf::Event::mouseWheelScroll)
        .def_readonly("joystick_move", &sf::Event::joystickMove)
        .def_readonly("joystick_button", &sf::Event::joystickButton)
        .def_readonly("joystick_connect", &sf::Event::joystickConnect)
        .def_readonly("touch", &sf::Event::touch)
        .def_readonly("sensor", &sf::Event::sensor);

    /* Mouse class */
    py::class_<sf::Mouse> mouse(sfml, "Mouse");

    py::enum_<sf::Mouse::Button>(mouse, "Button")
        .value("Left", sf::Mouse::Left)
        .value("Right", sf::Mouse::Right)
        .value("Middle", sf::Mouse::Middle)
        .value("XButton1", sf::Mouse::XButton1)
        .value("XButton2", sf::Mouse::XButton2)
        .value("ButtonCount", sf::Mouse::ButtonCount);

    py::enum_<sf::Mouse::Wheel>(mouse, "Wheel")
        .value("VerticalWheel", sf::Mouse::VerticalWheel)
        .value("HorizontalWheel", sf::Mouse::HorizontalWheel);

    mouse.def_static("is_button_pressed", &sf::Mouse::isButtonPressed)
        .def_property_static("position",
            [](py::object) {
                return sf::Mouse::getPosition();
            },
            [](py::object, const sf::Vector2i& position) {
                sf::Mouse::setPosition(position);
            }
        )
        .def_static("get_position",
            [](const sf::Window& relative_to) {
                return sf::Mouse::getPosition(relative_to);
            }, py::arg("relative_to")
        )
        .def_static("set_position",
            [](const sf::Vector2i& position, const sf::Window& relative_to) {
                return sf::Mouse::setPosition(position, relative_to);
            }, py::arg("position"), py::arg("relative_to")
        );

    /* Keyboard class */
    py::class_<sf::Keyboard> keyboard(sfml, "Keyboard");

    py::enum_<sf::Keyboard::Key>(keyboard, "Key")
        .value("Unknown", sf::Keyboard::Unknown).value("A", sf::Keyboard::A).value("B", sf::Keyboard::B).value("C", sf::Keyboard::C)
        .value("D", sf::Keyboard::D).value("E", sf::Keyboard::E).value("F", sf::Keyboard::F).value("G", sf::Keyboard::G)
        .value("H", sf::Keyboard::H).value("I", sf::Keyboard::I).value("J", sf::Keyboard::J).value("K", sf::Keyboard::K)
        .value("L", sf::Keyboard::L).value("M", sf::Keyboard::M).value("N", sf::Keyboard::N).value("O", sf::Keyboard::O)
        .value("P", sf::Keyboard::P).value("Q", sf::Keyboard::Q).value("R", sf::Keyboard::R).value("S", sf::Keyboard::S)
        .value("T", sf::Keyboard::T).value("U", sf::Keyboard::U).value("V", sf::Keyboard::V).value("W", sf::Keyboard::W)
        .value("X", sf::Keyboard::X).value("Y", sf::Keyboard::Y).value("Z", sf::Keyboard::Z).value("Num0", sf::Keyboard::Num0)
        .value("Num1", sf::Keyboard::Num1).value("Num2", sf::Keyboard::Num2).value("Num3", sf::Keyboard::Num3).value("Num4", sf::Keyboard::Num4)
        .value("Num5", sf::Keyboard::Num5).value("Num6", sf::Keyboard::Num6).value("Num7", sf::Keyboard::Num7).value("Num8", sf::Keyboard::Num8)
        .value("Num9", sf::Keyboard::Num9).value("Escape", sf::Keyboard::Escape).value("LControl", sf::Keyboard::LControl).value("LShift", sf::Keyboard::LShift)
        .value("LAlt", sf::Keyboard::LAlt).value("LSystem", sf::Keyboard::LSystem).value("RControl", sf::Keyboard::RControl).value("RShift", sf::Keyboard::RShift)
        .value("RAlt", sf::Keyboard::RAlt).value("RSystem", sf::Keyboard::RSystem).value("Menu", sf::Keyboard::Menu).value("LBracket", sf::Keyboard::LBracket)
        .value("RBracket", sf::Keyboard::RBracket).value("Semicolon", sf::Keyboard::Semicolon).value("Comma", sf::Keyboard::Comma).value("Period", sf::Keyboard::Period)
        .value("Quote", sf::Keyboard::Quote).value("Slash", sf::Keyboard::Slash).value("Backslash", sf::Keyboard::Backslash).value("Tilde", sf::Keyboard::Tilde)
        .value("Equal", sf::Keyboard::Equal).value("Hyphen", sf::Keyboard::Hyphen).value("Space", sf::Keyboard::Space).value("Enter", sf::Keyboard::Enter)
        .value("Backspace", sf::Keyboard::Backspace).value("Tab", sf::Keyboard::Tab).value("PageUp", sf::Keyboard::PageUp).value("PageDown", sf::Keyboard::PageDown)
        .value("End", sf::Keyboard::End).value("Home", sf::Keyboard::Home).value("Insert", sf::Keyboard::Insert).value("Delete", sf::Keyboard::Delete)
        .value("Add", sf::Keyboard::Add).value("Subtract", sf::Keyboard::Subtract).value("Multiply", sf::Keyboard::Multiply).value("Divide", sf::Keyboard::Divide)
        .value("Left", sf::Keyboard::Left).value("Right", sf::Keyboard::Right).value("Up", sf::Keyboard::Up).value("Down", sf::Keyboard::Down)
        .value("Numpad0", sf::Keyboard::Numpad0).value("Numpad1", sf::Keyboard::Numpad1).value("Numpad2", sf::Keyboard::Numpad2).value("Numpad3", sf::Keyboard::Numpad3)
        .value("Numpad4", sf::Keyboard::Numpad4).value("Numpad5", sf::Keyboard::Numpad5).value("Numpad6", sf::Keyboard::Numpad6).value("Numpad7", sf::Keyboard::Numpad7)
        .value("Numpad8", sf::Keyboard::Numpad8).value("Numpad9", sf::Keyboard::Numpad9).value("F1", sf::Keyboard::F1).value("F2", sf::Keyboard::F2)
        .value("F3", sf::Keyboard::F3).value("F4", sf::Keyboard::F4).value("F5", sf::Keyboard::F5).value("F6", sf::Keyboard::F6)
        .value("F7", sf::Keyboard::F7).value("F8", sf::Keyboard::F8).value("F9", sf::Keyboard::F9).value("F10", sf::Keyboard::F10)
        .value("F11", sf::Keyboard::F11).value("F12", sf::Keyboard::F12).value("F13", sf::Keyboard::F13).value("F14", sf::Keyboard::F14)
        .value("F15", sf::Keyboard::F15).value("Pause", sf::Keyboard::Pause).value("KeyCount", sf::Keyboard::KeyCount).value("Dash", sf::Keyboard::Dash)
        .value("BackSpace", sf::Keyboard::BackSpace).value("BackSlash", sf::Keyboard::BackSlash).value("SemiColon", sf::Keyboard::SemiColon).value("Return", sf::Keyboard::Return);

    keyboard.def_static("is_key_pressed", &sf::Keyboard::isKeyPressed);

    // Workaround for sf::Style being a namespace instead of an enum
    enum Style
    {
        None = sf::Style::None,
        Titlebar = sf::Style::Titlebar,
        Resize = sf::Style::Resize,
        Close = sf::Style::Close,
        Fullscreen = sf::Style::Fullscreen,
        Default = sf::Style::Default
    };

    /* Style enum */
    py::enum_<Style>(sfml, "Style", py::arithmetic())
        .value("None", Style::None)
        .value("Titlebar", Style::Titlebar)
        .value("Resize", Style::Resize)
        .value("Close", Style::Close)
        .value("Fullscreen", Style::Fullscreen)
        .value("Default", Style::Default)
        .export_values();

    /* Window class */
    py::class_<sf::Window>(sfml, "Window")
        .def(py::init<>())
        .def(py::init<sf::VideoMode, const std::string&, uint32_t, const sf::ContextSettings&>(),
            py::arg("mode"), py::arg("title"), py::arg("style") = Style::Default, py::arg("settings") = sf::ContextSettings()
        )
        .def("create", [](sf::Window& self, const sf::VideoMode& mode, const std::string& title, uint32_t style, const sf::ContextSettings& settings) {
            return self.create(mode, title, style, settings);
        }, py::arg("mode"), py::arg("title"), py::arg("style") = Style::Default, py::arg("settings") = sf::ContextSettings())
        .def("close", &sf::Window::close)
        .def("is_open", &sf::Window::isOpen)
        .def_property_readonly("settings", &sf::Window::getSettings)
        .def("poll_event", &sf::Window::pollEvent, py::arg("event"))
        .def("wait_event", &sf::Window::waitEvent, py::arg("event"))
        .def_property("position", &sf::Window::getPosition, &sf::Window::setPosition)
        .def_property("size", &sf::Window::getSize, &sf::Window::setSize)
        .def("set_title", [](sf::Window& self, const std::string& title) {
            self.setTitle(title);
        }, py::arg("title"))
        .def("set_icon", [](sf::Window& self, unsigned int width, unsigned int height, const std::vector<uint8_t>& pixels) {
            self.setIcon(width, height, pixels.data());
        }, py::arg("width"), py::arg("height"), py::arg("pixels"))
        .def("set_visible", &sf::Window::setVisible, py::arg("visible"))
        .def("set_vertical_sync_enabled", &sf::Window::setVerticalSyncEnabled, py::arg("enabled"))
        .def("set_mouse_cursor_visible", &sf::Window::setMouseCursorVisible, py::arg("visible"))
        .def("set_mouse_cursor_grabbed", &sf::Window::setMouseCursorGrabbed, py::arg("grabbed"))
        .def("set_mouse_cursor", &sf::Window::setMouseCursor, py::arg("cursor"))
        .def("set_key_repeat_enabled", &sf::Window::setKeyRepeatEnabled, py::arg("enabled"))
        .def("set_framerate_limit", &sf::Window::setFramerateLimit, py::arg("limit"))
        .def("set_joystick_threshold", &sf::Window::setJoystickThreshold, py::arg("threshold"))
        .def("set_active", &sf::Window::setActive, py::arg("active") = true)
        .def("request_focus", &sf::Window::requestFocus)
        .def("has_focus", &sf::Window::hasFocus)
        .def("display", &sf::Window::display);
        // .def_property_readonly("system_handle", &sf::Window::getSystemHandle);


    /*******************
     * GRAPHICS MODULE *
     *******************/

    // TODO
    // class   sf::BlendMode
    // class   sf::Font
    // class   sf::RenderStates
    // class   sf::RenderTarget
    // class   sf::RenderTexture
    // class   sf::RenderWindow
    // class   sf::Sprite
    // class   sf::Text
    // class   sf::Texture
    // class   sf::Transform
    // class   sf::Vertex
    // class   sf::VertexArray
    // class   sf::VertexBuffer
    // class   sf::View

    /* Rect class */
    #define PYSFML_IMPLEMENT_RECT(T, TS)                                                                    \
    py::class_<sf::Rect<T>>(sfml, PYSFML_CONCAT_STRING(TS, Rect))                                           \
        .def(py::init<T, T, T, T>(),                                                                        \
            py::arg("left") = T(0), py::arg("top") = T(0),                                                  \
            py::arg("width") = T(0), py::arg("height") = T(0)                                               \
        )                                                                                                   \
        .def(py::init<const sf::Vector2<T>&, const sf::Vector2<T>&>(),                                      \
            py::arg("position") = sf::Vector2<T>(),                                                         \
            py::arg("size") = sf::Vector2<T>()                                                              \
        )                                                                                                   \
        .def_readwrite("left", &sf::Rect<T>::left)                                                          \
        .def_readwrite("top", &sf::Rect<T>::top)                                                            \
        .def_readwrite("width", &sf::Rect<T>::width)                                                        \
        .def_readwrite("height", &sf::Rect<T>::height)                                                      \
        .def("contains", [](sf::Rect<T>& self, T x, T y) {                                                  \
            return self.contains(x, y);                                                                     \
        })                                                                                                  \
        .def("contains", [](sf::Rect<T>& self, const sf::Vector2<T>& point) {                               \
            return self.contains(point);                                                                    \
        }, py::arg("point"))                                                                                \
        .def("intersects", [](sf::Rect<T>& self, const sf::Rect<T>& rectangle) {                            \
            return self.intersects(rectangle);                                                              \
        }, py::arg("rectangle"))                                                                            \
        .def("intersects", [](sf::Rect<T>& self, const sf::Rect<T>& rectangle, sf::Rect<T>& intersection) { \
            return self.intersects(rectangle, intersection);                                                \
        }, py::arg("rectangle"), py::arg("intersection"))                                                   \
        .def(py::self == py::self)                                                                          \
        .def(py::self != py::self)                                                                          \
        .def("__repr__", [](const sf::Rect<T>& self) {                                                      \
            std::ostringstream stream;                                                                      \
            stream << "<pysfml11." << PYSFML_CONCAT_STRING(TS, Rect) <<                                     \
                " left=" << self.left << " top=" << self.top <<                                             \
                " width=" << self.width << " height=" << self.height << ">";                                \
            return stream.str();                                                                            \
        });

    /* IntRect class */
    PYSFML_IMPLEMENT_RECT(int, Int)
    /* FloatRect class */
    PYSFML_IMPLEMENT_RECT(float, Float)

    #undef PYSFML_IMPLEMENT_RECT

    /* Color class */
    py::class_<sf::Color>(sfml, "Color")
        .def(py::init<uint8_t, uint8_t, uint8_t, uint8_t>(), py::arg("r") = 255, py::arg("g") = 255, py::arg("b") = 255, py::arg("a") = 255)
        .def(py::init<uint32_t>(), py::arg("color"))
        .def("to_integer", &sf::Color::toInteger)
        .def_readwrite("r", &sf::Color::r)
        .def_readwrite("g", &sf::Color::g)
        .def_readwrite("b", &sf::Color::b)
        .def_readwrite("a", &sf::Color::a)
        .def_readonly_static("Black", &sf::Color::Black)
        .def_readonly_static("White", &sf::Color::White)
        .def_readonly_static("Red", &sf::Color::Red)
        .def_readonly_static("Green", &sf::Color::Green)
        .def_readonly_static("Blue", &sf::Color::Blue)
        .def_readonly_static("Yellow", &sf::Color::Yellow)
        .def_readonly_static("Magenta", &sf::Color::Magenta)
        .def_readonly_static("Cyan", &sf::Color::Cyan)
        .def_readonly_static("Transparent", &sf::Color::Transparent)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self * py::self)
        .def(py::self += py::self)
        .def(py::self -= py::self)
        .def(py::self *= py::self)
        .def("__repr__", [](const sf::Color& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Color r=" << int(self.r) << " g=" << int(self.g) << " b=" << int(self.b) << " a=" << int(self.a) << ">";
            return stream.str();
        });

    /* Glsl types */
    py::module glsl = sfml.def_submodule("Glsl");

    glsl.attr("Vec2") = sfml.attr("Vector2f");
    glsl.attr("Ivec2") = sfml.attr("Vector2i");
    glsl.attr("Bvec2") = sfml.attr("Vector2b");

    glsl.attr("Vec3") = sfml.attr("Vector3f");
    glsl.attr("Ivec3") = sfml.attr("Vector3i");
    glsl.attr("Bvec3") = sfml.attr("Vector3b");

    #define PYSFML_IMPLEMENT_VEC4(T, TS)                                                       \
    py::class_<sf::Glsl::TS>(glsl, PYSFML_STRINGIFY(TS))                                       \
        .def(                                                                                  \
            py::init<T, T, T, T>(),                                                            \
            py::arg("x") = T(0), py::arg("y") = T(0), py::arg("z") = T(0), py::arg("w") = T(0) \
        )                                                                                      \
        .def(py::init<sf::Glsl::TS>(), py::arg("vector"))                                      \
        .def(py::init<sf::Color>(), py::arg("color"))                                          \
        .def_readonly("x", &sf::Glsl::TS::x)                                                   \
        .def_readonly("y", &sf::Glsl::TS::y)                                                   \
        .def_readonly("z", &sf::Glsl::TS::z)                                                   \
        .def_readonly("w", &sf::Glsl::TS::w)                                                   \
        .def("__repr__", [](const sf::Glsl::TS& self) {                                        \
            std::ostringstream stream;                                                         \
            stream << "<pysfml11.Glsl." << PYSFML_STRINGIFY(TS) <<                             \
                " x=" << self.x <<                                                             \
                " y=" << self.y <<                                                             \
                " z=" << self.z <<                                                             \
                " w=" << self.w << ">";                                                        \
            return stream.str();                                                               \
        });

    PYSFML_IMPLEMENT_VEC4(float, Vec4);
    PYSFML_IMPLEMENT_VEC4(int, Ivec4);

    #undef PYSFML_IMPLEMENT_VEC4

    py::class_<sf::Glsl::Bvec4>(glsl, "Bvec4")
        .def(
            py::init<bool, bool, bool, bool>(),
            py::arg("x") = false, py::arg("y") = false, py::arg("z") = false, py::arg("w") = false
        )
        .def(py::init<sf::Glsl::Bvec4>(), py::arg("vector"))
        .def_readonly("x", &sf::Glsl::Bvec4::x)
        .def_readonly("y", &sf::Glsl::Bvec4::y)
        .def_readonly("z", &sf::Glsl::Bvec4::z)
        .def_readonly("w", &sf::Glsl::Bvec4::w)
        .def("__repr__", [](const sf::Glsl::Bvec4& self) {
            std::ostringstream stream;
            stream << "<pysfml11.Glsl.Bvec4" <<
                " x=" << bool_repr(self.x) <<
                " y=" << bool_repr(self.y) <<
                " z=" << bool_repr(self.z) <<
                " w=" << bool_repr(self.w) << ">";
            return stream.str();
        });

    py::class_<sf::Glsl::Mat3>(glsl, "Mat3")
        .def(py::init([](const std::array<float, 9>& array) {
            return sf::Glsl::Mat3(array.data());
        }), py::arg("array"))
        .def(py::init([](const sf::Transform& transform) {
            return sf::Glsl::Mat3(transform);
        }), py::arg("transform"));

    py::class_<sf::Glsl::Mat4>(glsl, "Mat4")
        .def(py::init([](const std::array<float, 16>& array) {
            return sf::Glsl::Mat4(array.data());
        }), py::arg("array"))
        .def(py::init([](const sf::Transform& transform) {
            return sf::Glsl::Mat4(transform);
        }), py::arg("transform"));

    /* Drawable class */
    py::class_<sf::Drawable>(sfml, "Drawable");

    /* Transform class */
    py::class_<sf::Transform>(sfml, "Transform")
        .def(py::init<>())
        .def(py::init<float, float, float, float, float, float, float, float, float>())
        .def_property_readonly("matrix", [](const sf::Transform& self) {
            const float* matrix = self.getMatrix();

            return std::vector<float>(matrix, matrix + 16);
        })
        .def_property_readonly("inverse", &sf::Transform::getInverse)
        .def("transform_point", [](sf::Transform& self, float x, float y) {
            return self.transformPoint(x, y);
        }, py::arg("x"), py::arg("y"))
        .def("transform_point", [](sf::Transform& self, const sf::Vector2f& point) {
            return self.transformPoint(point);
        }, py::arg("point"))
        .def("transform_rect", &sf::Transform::transformRect, py::arg("rectangle"))
        .def("combine", &sf::Transform::combine, py::arg("transform"))
        .def("translate", [](sf::Transform& self, float x, float y) {
            return self.translate(x, y);
        }, py::arg("x"), py::arg("y"))
        .def("translate", [](sf::Transform& self, const sf::Vector2f& offset) {
            return self.translate(offset);
        }, py::arg("offset"))
        .def("rotate", [](sf::Transform& self, float angle) {
            return self.rotate(angle);
        }, py::arg("angle"))
        .def("rotate", [](sf::Transform& self, float angle, float centerx, float centery) {
            return self.rotate(angle, centerx, centery);
        }, py::arg("angle"), py::arg("center_x"), py::arg("center_y"))
        .def("rotate", [](sf::Transform& self, float angle, const sf::Vector2f& center) {
            return self.rotate(angle, center);
        }, py::arg("angle"), py::arg("center"))
        .def("scale", [](sf::Transform& self, float scalex, float scaley) {
            return self.scale(scalex, scaley);
        }, py::arg("scale_x"), py::arg("scale_y"))
        .def("scale", [](sf::Transform& self, float scalex, float scaley, float centerx, float centery) {
            return self.scale(scalex, scaley, centerx, centery);
        }, py::arg("scale_x"), py::arg("scale_y"), py::arg("center_x"), py::arg("center_y"))
        .def("scale", [](sf::Transform& self, const sf::Vector2f& factors) {
            return self.scale(factors);
        }, py::arg("factors"))
        .def("scale", [](sf::Transform& self, const sf::Vector2f& factors, const sf::Vector2f& center) {
            return self.scale(factors, center);
        }, py::arg("factors"), py::arg("center"))
        .def_readonly_static("identity", &sf::Transform::Identity)
        .def(py::self * py::self)
        .def(py::self *= py::self)
        .def(py::self * sf::Vector2f())
        .def(py::self == py::self)
        .def(py::self != py::self);

    /* Transformable class */
    py::class_<sf::Transformable>(sfml, "Transformable")
        .def_property("position", &sf::Transformable::getPosition, [](sf::Transformable& self, const sf::Vector2f& position) { self.setPosition(position); })
        .def("set_position", [](sf::Transformable& self, float x, float y) {
            self.setPosition(x, y);
        }, py::arg("x"), py::arg("y"))
        .def_property("rotation", &sf::Transformable::getRotation, &sf::Transformable::setRotation)
        .def_property("scale", &sf::Transformable::getScale, [](sf::Transformable& self, const sf::Vector2f& scale) { self.setScale(scale); })
        .def("set_scale", [](sf::Transformable& self, float x, float y) {
            self.setScale(x, y);
        }, py::arg("x"), py::arg("y"))
        .def_property("origin", &sf::Transformable::getOrigin, [](sf::Transformable& self, const sf::Vector2f& origin) { self.setOrigin(origin); })
        .def("set_origin", [](sf::Transformable& self, float x, float y) {
            self.setOrigin(x, y);
        }, py::arg("x"), py::arg("y"))
        .def("move", [](sf::Transformable& self, float offsetx, float offsety) {
            return self.move(offsetx, offsety);
        }, py::arg("offset_x"), py::arg("offset_y"))
        .def("move", [](sf::Transformable& self, const sf::Vector2f& offset) {
            return self.move(offset);
        }, py::arg("offset"))
        .def("rotate", &sf::Transformable::rotate, py::arg("angle"))
        .def_property_readonly("transform", &sf::Shape::getTransform)
        .def_property_readonly("inverse_transform", &sf::Shape::getInverseTransform);

    /* Shape class */
    py::class_<sf::Shape, sf::Drawable, sf::Transformable>(sfml, "Shape")
        // .def_property("texture", &sf::Shape::setTexture, &sf::Shape::getTexture)
        .def_property("texture_rect", &sf::Shape::setTextureRect, &sf::Shape::getTextureRect)
        .def_property("fill_color", &sf::Shape::getFillColor, &sf::Shape::setFillColor)
        .def_property("outline_color", &sf::Shape::getOutlineColor, &sf::Shape::setOutlineColor)
        .def_property("outline_thickness", &sf::Shape::getOutlineThickness, &sf::Shape::setOutlineThickness)
        .def_property_readonly("point_count", &sf::Shape::getPointCount)
        .def_property_readonly("local_bounds", &sf::Shape::getLocalBounds)
        .def_property_readonly("global_bounds", &sf::Shape::getGlobalBounds)
        .def("get_point", &sf::Shape::getPoint, py::arg("index"));

    /* CircleShape class */
    py::class_<sf::CircleShape, sf::Shape>(sfml, "CircleShape")
        .def(py::init<float, std::size_t>(), py::arg("radius"), py::arg("point_count") = 30)
        .def_property("radius", &sf::CircleShape::getRadius, &sf::CircleShape::setRadius)
        .def_property("point_count", &sf::CircleShape::getPointCount, &sf::CircleShape::setPointCount);

    /* ConvexShape class */
    py::class_<sf::ConvexShape, sf::Shape>(sfml, "ConvexShape")
        .def(py::init<std::size_t>(), py::arg("point_count") = 0)
        .def_property("point_count", &sf::ConvexShape::getPointCount, &sf::ConvexShape::setPointCount)
        .def("set_point", &sf::ConvexShape::setPoint, py::arg("index"), py::arg("point"));

    /* RectangleShape class */
    py::class_<sf::RectangleShape, sf::Shape>(sfml, "RectangleShape")
        .def(py::init<const sf::Vector2f&>(), py::arg("size") = sf::Vector2f(0, 0))
        .def_property("size", &sf::RectangleShape::getSize, &sf::RectangleShape::setSize)
        .def_property_readonly("point_count", &sf::RectangleShape::getPointCount);

    /* RenderWindow class */
    py::class_<sf::RenderWindow, sf::Window>(sfml, "RenderWindow")
        .def(py::init<>())
        .def(py::init<sf::VideoMode, const std::string&, uint32_t, const sf::ContextSettings&>(),
            py::arg("mode"), py::arg("title"), py::arg("style") = Style::Default, py::arg("settings") = sf::ContextSettings()
        )
        .def("clear", &sf::RenderWindow::clear, py::arg("color") = sf::Color::Black)
        .def("draw", [](sf::RenderWindow& self, const sf::Drawable& drawable) {
            self.draw(drawable);
        }, py::arg("drawable"));

    /* Image class */
    py::class_<sf::Image>(sfml, "Image")
        .def(py::init<>())
        .def("create", [](sf::Image& self, unsigned int width, unsigned int height, const sf::Color& color) {
            self.create(width, height, color);
        }, py::arg("width"), py::arg("height"), py::arg("color") = sf::Color::Black)
        // TODO Create from bytes
        .def("load_from_file", &sf::Image::loadFromFile, py::arg("filename"))
        .def("load_from_stream", &sf::Image::loadFromStream, py::arg("stream"))
        .def("save_to_file", &sf::Image::saveToFile, py::arg("filename"))
        .def_property_readonly("size", &sf::Image::getSize)
        .def("create_mask_from_color", &sf::Image::createMaskFromColor, py::arg("color"), py::arg("alpha") = 0)
        .def("copy", &sf::Image::copy, py::arg("source"), py::arg("dest_x"), py::arg("dest_y"), py::arg("source_rect") = sf::IntRect(0, 0, 0, 0), py::arg("apply_alpha") = false)
        .def("set_pixel", &sf::Image::setPixel, py::arg("x"), py::arg("y"), py::arg("color"))
        .def("get_pixel", &sf::Image::getPixel, py::arg("x"), py::arg("y"))
        .def("flip_horizontally", &sf::Image::flipHorizontally)
        .def("flip_vertically", &sf::Image::flipVertically);

    /* Glyph class */
    py::class_<sf::Glyph>(sfml, "Glyph")
        .def(py::init<>())
        .def_readonly("advance", &sf::Glyph::advance)
        .def_readonly("bounds", &sf::Glyph::bounds)
        .def_readonly("texture_rect", &sf::Glyph::textureRect);

    /* View class */
    py::class_<sf::View>(sfml, "View")
        .def(py::init<>())
        .def(py::init<const sf::FloatRect&>(), py::arg("rectangle"))
        .def(py::init<const sf::Vector2f&, const sf::Vector2f&>(), py::arg("center"), py::arg("size"))
        .def_property("center", &sf::View::getCenter, [](sf::View& self, const sf::Vector2f& center) {
            self.setCenter(center);
        })
        .def_property("size", &sf::View::getSize, [](sf::View& self, const sf::Vector2f& size) {
            self.setSize(size);
        })
        .def_property("rotation", &sf::View::getRotation, [](sf::View& self, float rotation) {
            self.setRotation(rotation);
        })
        .def_property("viewport", &sf::View::getViewport, [](sf::View& self, const sf::FloatRect& viewport) {
            self.setViewport(viewport);
        })
        .def("reset", &sf::View::reset, py::arg("rectangle"))
        .def("move", [](sf::View& self, float offsetx, float offsety) {
            self.move(offsetx, offsety);
        }, py::arg("offset_x"), py::arg("offset_y"))
        .def("move", [](sf::View& self, const sf::Vector2f offset) {
            self.move(offset);
        }, py::arg("offset"))
        .def("rotate", &sf::View::rotate, py::arg("angle"))
        .def("zoom", &sf::View::zoom, py::arg("factor"))
        .def_property_readonly("transform", &sf::View::getTransform)
        .def_property_readonly("inverse_transform", &sf::View::getInverseTransform);

    /* Shader class */
    py::class_<sf::Shader> shader(sfml, "Shader");

    py::enum_<sf::Shader::Type>(shader, "Type")
        .value("Vertex", sf::Shader::Vertex)
        .value("Fragment", sf::Shader::Fragment)
        .value("Geometry", sf::Shader::Geometry)
        .export_values();

    shader
        .def(py::init<>())
        .def("load_from_file", [](sf::Shader& self, const std::string& filename, sf::Shader::Type type) {
            return self.loadFromFile(filename, type);
        }, py::arg("filename"), py::arg("type"))
        .def("load_from_file", [](sf::Shader& self, const std::string& vertexfilename, const std::string& fragmentfilename) {
            return self.loadFromFile(vertexfilename, fragmentfilename);
        }, py::arg("vertex_filename"), py::arg("fragment_filename"))
        .def("load_from_file", [](sf::Shader& self, const std::string& vertexfilename, const std::string& geometryfilename, const std::string& fragmentfilename) {
            return self.loadFromFile(vertexfilename, geometryfilename, fragmentfilename);
        }, py::arg("vertex_filename"), py::arg("geometry_filename"), py::arg("fragment_filename"))
        .def("load_from_memory", [](sf::Shader& self, const std::string& shader, sf::Shader::Type type) {
            return self.loadFromMemory(shader, type);
        }, py::arg("shader"), py::arg("type"))
        .def("load_from_memory", [](sf::Shader& self, const std::string& vertexshader, const std::string& fragmentshader) {
            return self.loadFromMemory(vertexshader, fragmentshader);
        }, py::arg("vertex_shader"), py::arg("fragment_shader"))
        .def("load_from_memory", [](sf::Shader& self, const std::string& vertexshader, const std::string& geometryshader, const std::string& fragmentshader) {
            return self.loadFromMemory(vertexshader, geometryshader, fragmentshader);
        }, py::arg("vertex_shader"), py::arg("geometry_shader"), py::arg("fragment_shader"))
        .def("load_from_stream", [](sf::Shader& self, sf::InputStream& shader, sf::Shader::Type type) {
            return self.loadFromStream(shader, type);
        }, py::arg("shader"), py::arg("type"))
        .def("load_from_stream", [](sf::Shader& self, sf::InputStream& vertexshader, sf::InputStream& fragmentshader) {
            return self.loadFromStream(vertexshader, fragmentshader);
        }, py::arg("vertex_shader"), py::arg("fragment_shader"))
        .def("load_from_stream", [](sf::Shader& self, sf::InputStream& vertexshader, sf::InputStream& geometryshader, sf::InputStream& fragmentshader) {
            return self.loadFromStream(vertexshader, geometryshader, fragmentshader);
        }, py::arg("vertex_shader"), py::arg("geometry_shader"), py::arg("fragment_shader"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, float x) {
            self.setUniform(name, x);
        }, py::arg("name"), py::arg("x"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Vec2& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Vec3& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Vec4& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, int x) {
            self.setUniform(name, x);
        }, py::arg("name"), py::arg("x"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Ivec2& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Ivec3& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Ivec4& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, bool x) {
            self.setUniform(name, x);
        }, py::arg("name"), py::arg("x"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Bvec2& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Bvec3& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Bvec4& vector) {
            self.setUniform(name, vector);
        }, py::arg("name"), py::arg("vector"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Mat3& matrix) {
            self.setUniform(name, matrix);
        }, py::arg("name"), py::arg("matrix"))
        .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Glsl::Mat4& matrix) {
            self.setUniform(name, matrix);
        }, py::arg("name"), py::arg("matrix"))
        // .def("set_uniform", [](sf::Shader& self, const std::string& name, const sf::Texture& texture) { self.setUniform(name, texture); })
        // .def("set_uniform", [](sf::Shader& self, const std::string& name, sf::CurrentTextureType) { self.setUniform(name, sf::CurrentTextureType); })
        // TODO set_uniform_array
        // TODO set_parameter
        // TODO get_native_handle
        .def_static("bind", &sf::Shader::bind, py::arg("shader"))
        .def_static("is_available", &sf::Shader::isAvailable)
        .def_static("is_geometry_available", &sf::Shader::isGeometryAvailable)
        // .def_readonly_static("CurrentTexture", &sf::Shader::CurrentTexture)
        ;

    /****************
     * AUDIO MODULE *
     ****************/

    /* InputSoundFile class */
    py::class_<sf::InputSoundFile>(sfml, "InputSoundFile")
        .def(py::init<>())
        .def("open_from_file", &sf::InputSoundFile::openFromFile, py::arg("filename"))
        // Should be tested with Python bytes
        // .def("open_from_memory", &sf::InputSoundFile::openFromMemory)
        .def("open_from_stream", &sf::InputSoundFile::openFromStream, py::arg("stream"))
        .def_property_readonly("sample_count", &sf::InputSoundFile::getSampleCount)
        .def_property_readonly("channel_count", &sf::InputSoundFile::getChannelCount)
        .def_property_readonly("sample_rate", &sf::InputSoundFile::getSampleRate)
        .def_property_readonly("duration", &sf::InputSoundFile::getDuration)
        .def_property_readonly("time_offset", &sf::InputSoundFile::getTimeOffset)
        .def_property_readonly("sample_offset", &sf::InputSoundFile::getSampleOffset)
        .def("seek", [](sf::InputSoundFile& self, uint64_t sample_offset) {
            self.seek(sample_offset);
        }, py::arg("sample_offset"))
        .def("seek", [](sf::InputSoundFile& self, sf::Time time_offset) {
            self.seek(time_offset);
        }, py::arg("time_offset"))
        .def("read", [](sf::InputSoundFile& self, std::size_t count) {
            sf::Int16* samples = new sf::Int16[count];

            sf::Uint64 readcount = self.read(samples, count);
            // TODO: Raise if readcount is -1
            return std::vector<int16_t>(samples, samples + readcount);
        }, py::arg("count"));

    /* OutputSoundFile class */
    py::class_<sf::OutputSoundFile>(sfml, "OutputSoundFile")
        .def(py::init<>())
        .def("open_from_file", &sf::OutputSoundFile::openFromFile, py::arg("filename"), py::arg("sample_rate"), py::arg("channel_count"))
        .def("write", [](sf::OutputSoundFile& self, const std::vector<int16_t>& samples) {
            self.write(samples.data(), samples.size());
        }, py::arg("samples"));

    /* Listener class */
    py::class_<sf::Listener>(sfml, "Listener")
        .def_property_static(
            "global_volume",
            [](py::object) { return sf::Listener::getGlobalVolume(); },
            [](py::object, float volume) { sf::Listener::setGlobalVolume(volume); }
        )
        .def_property_static(
            "position",
            [](py::object) { return sf::Listener::getPosition(); },
            [](py::object, const sf::Vector3f& position) { sf::Listener::setPosition(position); }
        )
        .def_property_static(
            "direction",
            [](py::object) { return sf::Listener::getDirection(); },
            [](py::object, const sf::Vector3f& direction) { sf::Listener::setDirection(direction); }
        )
        .def_property_static(
            "up_vector",
            [](py::object) { return sf::Listener::getUpVector(); },
            [](py::object, const sf::Vector3f& up_vector) { sf::Listener::setUpVector(up_vector); }
        );

    /* SoundBuffer class */
    py::class_<sf::SoundBuffer>(sfml, "SoundBuffer")
        .def(py::init<>())
        .def("load_from_file", &sf::SoundBuffer::loadFromFile, py::arg("filename"))
        // Should be tested with Python bytes
        // .def("load_from_memory", &sf::SoundBuffer::loadFromMemory)
        .def("load_from_stream", &sf::SoundBuffer::loadFromStream, py::arg("stream"))
        .def("load_from_samples", [](sf::SoundBuffer& self, const std::vector<int16_t>& samples, uint64_t channelcount, uint64_t samplerate) {
            return self.loadFromSamples(samples.data(), samples.size(), channelcount, samplerate);
        }, py::arg("samples"), py::arg("channel_count"), py::arg("sample_rate"))
        .def("save_to_file", &sf::SoundBuffer::saveToFile, py::arg("filename"))
        .def_property_readonly("samples", [](const sf::SoundBuffer& self) {
            const int16_t* samples = self.getSamples();

            return std::vector<int16_t>(samples, samples + self.getSampleCount());
        })
        .def_property_readonly("sample_count", &sf::SoundBuffer::getSampleCount)
        .def_property_readonly("sample_rate", &sf::SoundBuffer::getSampleRate)
        .def_property_readonly("channel_count", &sf::SoundBuffer::getChannelCount)
        .def_property_readonly("duration", &sf::SoundBuffer::getDuration);

    /* SoundSource class */
    py::class_<sf::SoundSource> soundsource(sfml, "SoundSource");

    py::enum_<sf::SoundSource::Status>(soundsource, "Status")
        .value("Stopped", sf::SoundSource::Status::Stopped)
        .value("Paused", sf::SoundSource::Status::Paused)
        .value("Playing", sf::SoundSource::Status::Playing)
        .export_values();

    soundsource.def_property("pitch", &sf::SoundSource::getPitch, &sf::SoundSource::setPitch)
        .def_property("volume", &sf::SoundSource::getVolume, &sf::SoundSource::setVolume)
        .def_property("position", &sf::SoundSource::getPosition, [](sf::SoundSource& self, const sf::Vector3f& position) {
            self.setPosition(position);
        })
        .def_property("relative_to_listener", &sf::SoundSource::isRelativeToListener, &sf::SoundSource::setRelativeToListener)
        .def_property("min_distance", &sf::SoundSource::getMinDistance, &sf::SoundSource::setMinDistance)
        .def_property("attenuation", &sf::SoundSource::getAttenuation, &sf::SoundSource::setAttenuation)
        .def_property_readonly("status", &sf::SoundSource::getStatus);

    /* Sound class */
    py::class_<sf::Sound, sf::SoundSource>(sfml, "Sound")
        .def(py::init<>())
        .def("play", &sf::Sound::play)
        .def("pause", &sf::Sound::pause)
        .def("stop", &sf::Sound::stop)
        .def_property("buffer", &sf::Sound::getBuffer, &sf::Sound::setBuffer)
        .def("reset_buffer", &sf::Sound::resetBuffer)
        .def_property("loop", &sf::Sound::getLoop, &sf::Sound::setLoop)
        .def_property("playing_offset", &sf::Sound::getPlayingOffset, &sf::Sound::setPlayingOffset);

    /* SoundStream class */
    py::class_<sf::SoundStream, sf::SoundSource>(sfml, "SoundStream")
        .def("play", &sf::SoundStream::play)
        .def("pause", &sf::SoundStream::pause)
        .def("stop", &sf::SoundStream::stop);

    /* Music class */
    py::class_<sf::Music, sf::SoundStream>(sfml, "Music")
        .def(py::init<>())
        .def("open_from_file", &sf::Music::openFromFile, py::arg("filename"))
        // Should be tested with Python bytes
        // .def("open_from_memory", &sf::Music::openFromMemory)
        .def("open_from_stream", &sf::Music::openFromStream, py::arg("stream"))
        // .def_property("loop_points", &sf::Sound::getLoopPoints, &sf::Sound::setLoopPoints)
        .def_property_readonly("channel_count", &sf::Music::getChannelCount)
        .def_property_readonly("sample_rate", &sf::Music::getSampleRate)
        .def_property_readonly("duration", &sf::Music::getDuration)
        .def_property("loop", &sf::Music::getLoop, &sf::Music::setLoop)
        .def_property("playing_offset", &sf::Music::getPlayingOffset, &sf::Music::setPlayingOffset);

    /* SoundRecorder class */
    py::class_<sf::SoundRecorder>(sfml, "SoundRecorder")
        .def("start", &sf::SoundRecorder::start)
        .def("stop", &sf::SoundRecorder::stop)
        .def_property_readonly("sample_rate", &sf::SoundRecorder::getSampleRate)
        .def_property("device", &sf::SoundRecorder::getDevice, &sf::SoundRecorder::setDevice)
        .def_property("channel_count", &sf::SoundRecorder::getChannelCount, &sf::SoundRecorder::setChannelCount)
        // TODO + tests
        ;


#ifdef VERSION_INFO
    sfml.attr("__version__") = VERSION_INFO;
#else
    sfml.attr("__version__") = "dev";
#endif
}

#undef PYSFML_CONCAT_STRING
#undef PYSFML_STRINGIFY_IMPL
#undef PYSFML_STRINGIFY
#undef PYSFML_CONCATENATE_IMPL
#undef PYSFML_CONCATENATE
