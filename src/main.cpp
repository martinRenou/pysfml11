#include <SFML/Graphics.hpp>

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>


namespace py = pybind11;


PYBIND11_MODULE(pysfml, m)
{
    m.doc() = R"pbdoc(
        pysfml
        ------

        .. currentmodule:: pysfml

        .. autosummary::
           :toctree: _generate

           RenderWindow
           VideoMode
    )pbdoc";

    py::class_<sf::VideoMode>(m, "VideoMode")
        .def(py::init<int, int, int>(), py::arg("width"), py::arg("height"), py::arg("bits_per_pixel") = 32)
        .def("is_valid", &sf::VideoMode::isValid)
        .def_static("get_desktop_mode", &sf::VideoMode::getDesktopMode)
        .def_static("get_fullscreen_modes", &sf::VideoMode::getFullscreenModes)
        .def_readwrite("width", &sf::VideoMode::width)
        .def_readwrite("height", &sf::VideoMode::height)
        .def_readwrite("bits_per_pixel", &sf::VideoMode::bitsPerPixel);

    py::class_<sf::RenderWindow>(m, "RenderWindow")
        .def(py::init<const sf::VideoMode&, const std::string&>());

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
