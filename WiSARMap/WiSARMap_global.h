#ifndef WISARMAP_GLOBAL_H
#define WISARMAP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WISARMAP_LIBRARY)
#  define WISARMAPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WISARMAPSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WISARMAP_GLOBAL_H
