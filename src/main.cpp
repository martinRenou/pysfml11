#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>


namespace py = pybind11;

#define PYSFML_CONCATENATE(A, B) PYSFML_CONCATENATE_IMPL(A, B)
#define PYSFML_CONCATENATE_IMPL(A, B) A##B
#define PYSFML_STRINGIFY(a) PYSFML_STRINGIFY_IMPL(a)
#define PYSFML_STRINGIFY_IMPL(a) #a
#define PYSFML_CONCAT_STRING(A, B) PYSFML_STRINGIFY(PYSFML_CONCATENATE(A, B))


PYBIND11_MODULE(pysfml, m)
{
    m.doc() = R"pbdoc(
        pysfml
        ------

        .. currentmodule:: pysfml
    )pbdoc";

    /*****************
     * SYSTEM MODULE *
     *****************/

    py::module system = m.def_submodule("system");
    system.doc() = R"pbdoc(
        pysfml.system
        -------------

        .. currentmodule:: pysfml.system

        .. autosummary::
           :toctree: _generate

           Time
           Clock
           Vector2
           Vector3
    )pbdoc";

    // TODO
    // class   sf::FileInputStream
    // class   sf::InputStream
    // class   sf::Lock
    // class   sf::MemoryInputStream
    // class   sf::Mutex
    // class   sf::NonCopyable
    // class   sf::String
    // class   sf::Thread
    // class   sf::ThreadLocal
    // class   sf::ThreadLocalPtr< T >
    // class   sf::Utf< N >
    // std::ostream &  sf::err ()

    py::class_<sf::Time>(system, "Time")
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
        .def(py::self %= py::self);

    system.def("seconds", &sf::seconds);
    system.def("milliseconds", &sf::milliseconds);
    system.def("microseconds", &sf::microseconds);
    system.def("sleep", &sf::sleep);

    py::class_<sf::Clock>(system, "Clock")
        .def(py::init<>())
        .def("get_elapsed_time", &sf::Clock::getElapsedTime)
        .def("restart", &sf::Clock::restart);

    #define PYSFML_IMPLEMENT_VECTOR2(T, TS)                               \
    py::class_<sf::Vector2<T>>(system, PYSFML_CONCAT_STRING(Vector2, TS)) \
        .def(py::init<T, T>(), py::arg("x") = T(0), py::arg("y") = T(0))  \
        .def(py::init<sf::Vector2<T>>(), py::arg("vector"))               \
        .def_readwrite("x", &sf::Vector2<T>::x)                           \
        .def_readwrite("y", &sf::Vector2<T>::y)                           \
        .def(-py::self)                                                   \
        .def(py::self += py::self)                                        \
        .def(py::self -= py::self)                                        \
        .def(py::self + py::self)                                         \
        .def(py::self - py::self)                                         \
        .def(T() * py::self)                                              \
        .def(py::self * T())                                              \
        .def(py::self *= T())                                             \
        .def(py::self / T())                                              \
        .def(py::self /= T())                                             \
        .def(py::self == py::self)                                        \
        .def(py::self != py::self);

    PYSFML_IMPLEMENT_VECTOR2(float, f)
    PYSFML_IMPLEMENT_VECTOR2(int, i)
    PYSFML_IMPLEMENT_VECTOR2(uint, u)

    #undef PYSFML_IMPLEMENT_VECTOR2

    #define PYSFML_IMPLEMENT_VECTOR3(T, TS)                                                      \
    py::class_<sf::Vector3<T>>(system, PYSFML_CONCAT_STRING(Vector3, TS))                        \
        .def(py::init<T, T, T>(), py::arg("x") = T(0), py::arg("y") = T(0), py::arg("z") = T(0)) \
        .def(py::init<sf::Vector3<T>>(), py::arg("vector"))                                      \
        .def_readwrite("x", &sf::Vector3<T>::x)                                                  \
        .def_readwrite("y", &sf::Vector3<T>::y)                                                  \
        .def_readwrite("z", &sf::Vector3<T>::z)                                                  \
        .def(-py::self)                                                                          \
        .def(py::self += py::self)                                                               \
        .def(py::self -= py::self)                                                               \
        .def(py::self + py::self)                                                                \
        .def(py::self - py::self)                                                                \
        .def(T() * py::self)                                                                     \
        .def(py::self * T())                                                                     \
        .def(py::self *= T())                                                                    \
        .def(py::self / T())                                                                     \
        .def(py::self /= T())                                                                    \
        .def(py::self == py::self)                                                               \
        .def(py::self != py::self);

    PYSFML_IMPLEMENT_VECTOR3(float, f)
    PYSFML_IMPLEMENT_VECTOR3(int, i)
    PYSFML_IMPLEMENT_VECTOR3(uint, u)

    #undef PYSFML_IMPLEMENT_VECTOR3


    /*****************
     * WINDOW MODULE *
     *****************/

    // TODO
    // class   sf::Clipboard
    // class   sf::Context
    // class   sf::ContextSettings
    // class   sf::Cursor
    // class   sf::Event
    // class   sf::GlResource
    // class   sf::Joystick
    // class   sf::Keyboard
    // class   sf::Mouse
    // class   sf::Sensor
    // class   sf::Touch
    // class   sf::Window

    py::module window = m.def_submodule("window");
    window.doc() = R"pbdoc(
        pysfml.window
        -------------

        .. currentmodule:: pysfml.window

        .. autosummary::
           :toctree: _generate

           VideoMode
    )pbdoc";

    py::class_<sf::VideoMode>(window, "VideoMode")
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


    /*******************
     * GRAPHICS MODULE *
     *******************/

    // TODO
    // class   sf::BlendMode
    // class   sf::CircleShape
    // class   sf::ConvexShape
    // class   sf::Drawable
    // class   sf::Font
    // class   sf::Glyph
    // class   sf::Image
    // class   sf::Rect< T >
    // class   sf::RectangleShape
    // class   sf::RenderStates
    // class   sf::RenderTarget
    // class   sf::RenderTexture
    // class   sf::RenderWindow
    // class   sf::Shader
    // class   sf::Shape
    // class   sf::Sprite
    // class   sf::Text
    // class   sf::Texture
    // class   sf::Transform
    // class   sf::Transformable
    // class   sf::Vertex
    // class   sf::VertexArray
    // class   sf::VertexBuffer
    // class   sf::View

    py::module graphics = m.def_submodule("graphics");
    graphics.doc() = R"pbdoc(
        pysfml.graphics
        ---------------

        .. currentmodule:: pysfml.graphics

        .. autosummary::
           :toctree: _generate

           Color
           RenderWindow
    )pbdoc";

    py::class_<sf::Color>(graphics, "Color")
        .def(py::init<uint8_t, uint8_t, uint8_t, uint8_t>(), py::arg("r") = 255, py::arg("g") = 255, py::arg("b") = 255, py::arg("a") = 255)
        .def(py::init<uint32_t>(), py::arg("color"))
        .def("to_integer", &sf::Color::toInteger)
        .def_readwrite("r", &sf::Color::r)
        .def_readwrite("g", &sf::Color::g)
        .def_readwrite("b", &sf::Color::b)
        .def_readwrite("a", &sf::Color::a)
        .def_readonly_static("black", &sf::Color::Black)
        .def_readonly_static("white", &sf::Color::White)
        .def_readonly_static("red", &sf::Color::Red)
        .def_readonly_static("green", &sf::Color::Green)
        .def_readonly_static("blue", &sf::Color::Blue)
        .def_readonly_static("yellow", &sf::Color::Yellow)
        .def_readonly_static("magenta", &sf::Color::Magenta)
        .def_readonly_static("cyan", &sf::Color::Cyan)
        .def_readonly_static("transparent", &sf::Color::Transparent)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self * py::self)
        .def(py::self += py::self)
        .def(py::self -= py::self)
        .def(py::self *= py::self);

    py::class_<sf::Shape>(graphics, "Shape")
        // .def_property("texture", &sf::Shape::setTexture, &sf::Shape::getTexture)
        // .def_property("textureRect", &sf::Shape::setTextureRect, &sf::Shape::getTextureRect)
        .def_property("fill_color", &sf::Shape::getFillColor, &sf::Shape::setFillColor)
        .def_property("outline_color", &sf::Shape::getOutlineColor, &sf::Shape::setOutlineColor)
        .def_property("outline_thickness", &sf::Shape::getOutlineThickness, &sf::Shape::setOutlineThickness)
        .def_property_readonly("point_count", &sf::Shape::getPointCount)
        // .def("get_local_bounds", &sf::Shape::getLocalBounds)
        // .def("get_global_bounds", &sf::Shape::getGlobalBounds)
        .def("get_point", &sf::Shape::getPoint)
        .def_property("position", &sf::Shape::getPosition, [](sf::Shape& shape, const sf::Vector2f& position) { shape.setPosition(position); })
        .def_property("rotation", &sf::Shape::getRotation, &sf::Shape::setRotation)
        .def_property("scale", &sf::Shape::getScale, [](sf::Shape& shape, const sf::Vector2f& scale) { shape.setScale(scale); })
        .def_property("origin", &sf::Shape::getOrigin, [](sf::Shape& shape, const sf::Vector2f& origin) { shape.setOrigin(origin); })
        .def("move", [](sf::Shape& shape, float offsetx, float offsety) { shape.move(offsetx, offsety); })
        .def("move", [](sf::Shape& shape, const sf::Vector2f& offset) { shape.move(offset); })
        .def("rotate", &sf::Shape::rotate);
        // .def("get_transform", &sf::Shape::getTransform)
        // .def("get_inverse_transform", &sf::Shape::getInverseTransform);

    py::class_<sf::CircleShape, sf::Shape>(graphics, "CircleShape")
        .def(py::init<float, std::size_t>(), py::arg("radius"), py::arg("point_count") = 30)
        .def_property("radius", &sf::CircleShape::getRadius, &sf::CircleShape::setRadius)
        .def_property("point_count", &sf::CircleShape::getPointCount, &sf::CircleShape::setPointCount);

    py::class_<sf::RenderWindow>(graphics, "RenderWindow")
        .def(py::init<const sf::VideoMode&, const std::string&>())
        .def("is_open", &sf::Window::isOpen)
        .def("display", &sf::Window::display);


#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
