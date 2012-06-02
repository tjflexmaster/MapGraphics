This is a tile-based "slippy map" library written in/for C++/Qt. It's meant to enable C++/Qt developers to easily add nice, interactive maps to their applications.
### Features
* Built-in support for OpenStreetMap and MapQuest tiles
* Support for custom tile sources
* **Panning**, **zooming**, and **rotating** the map programmatically and interactively
* An "over-zoom" feature for zooming in once a user has reached the maximum tile zoom level
* The ability to add custom interactive map objects. Map objects can move, rotate, resize, and interact with the mouse.
* A disk- and memory-based tile caching system
* Multi-threaded I/O to keep the map responsive regardless of what's going on with network requests and caching

Development is ongoing and there are still many problems and features to work out, but panning, zooming, and rotating around a map seems quite stable.

This project is based on (or hacked on top of) Qt's venerable QGraphics framework. It mimics the QGraphics framework in a few ways.