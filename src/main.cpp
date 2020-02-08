#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>


namespace py = pybind11;


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
    // ANativeActivity *   sf::getNativeActivity ()
    // void    sf::sleep (Time duration)
    // std::ostream &  sf::err ()

    py::class_<sf::Time>(system, "Time")
        .def(py::init<>())
        .def("as_seconds", &sf::Time::asSeconds)
        .def("as_milliseconds", &sf::Time::asMilliseconds)
        .def("as_microseconds", &sf::Time::asMicroseconds)
        .def_property_readonly_static("zero", []() { return sf::Time::Zero; })
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

    py::class_<sf::Vector2<float>>(system, "Vector2")
        .def(py::init<float, float>(), py::arg("x") = 0, py::arg("y") = 0)
        .def(py::init<sf::Vector2<float>>(), py::arg("vector"))
        .def_readwrite("x", &sf::Vector2<float>::x)
        .def_readwrite("y", &sf::Vector2<float>::y)
        .def(-py::self)
        .def(py::self += py::self)
        .def(py::self -= py::self)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(float() * py::self)
        .def(py::self * float())
        .def(py::self *= float())
        .def(py::self / float())
        .def(py::self /= float())
        .def(py::self == py::self)
        .def(py::self != py::self);

    py::class_<sf::Vector3<float>>(system, "Vector3")
        .def(py::init<float, float, float>(), py::arg("x") = 0, py::arg("y") = 0, py::arg("z") = 0)
        .def(py::init<sf::Vector3<float>>(), py::arg("vector"))
        .def_readwrite("x", &sf::Vector3<float>::x)
        .def_readwrite("y", &sf::Vector3<float>::y)
        .def_readwrite("z", &sf::Vector3<float>::z)
        .def(-py::self)
        .def(py::self += py::self)
        .def(py::self -= py::self)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(float() * py::self)
        .def(py::self * float())
        .def(py::self *= float())
        .def(py::self / float())
        .def(py::self /= float())
        .def(py::self == py::self)
        .def(py::self != py::self);


    /*****************
     * WINDOW MODULE *
     *****************/

    py::module window = m.def_submodule("window");
    window.doc() = R"pbdoc(
        pysfml.window
        -------------

        .. currentmodule:: pysfml.window

        .. autosummary::
           :toctree: _generate

           VideoMode
           RenderWindow
    )pbdoc";

    py::class_<sf::VideoMode>(window, "VideoMode")
        .def(py::init<int, int, int>(), py::arg("width"), py::arg("height"), py::arg("bits_per_pixel") = 32)
        .def("is_valid", &sf::VideoMode::isValid)
        .def_static("get_desktop_mode", &sf::VideoMode::getDesktopMode)
        .def_static("get_fullscreen_modes", &sf::VideoMode::getFullscreenModes)
        .def_readwrite("width", &sf::VideoMode::width)
        .def_readwrite("height", &sf::VideoMode::height)
        .def_readwrite("bits_per_pixel", &sf::VideoMode::bitsPerPixel);

    py::class_<sf::RenderWindow>(window, "RenderWindow")
        .def(py::init<const sf::VideoMode&, const std::string&>());

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
