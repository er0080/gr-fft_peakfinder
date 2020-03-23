INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_FFT_PEAKFINDER fft_peakfinder)

FIND_PATH(
    FFT_PEAKFINDER_INCLUDE_DIRS
    NAMES fft_peakfinder/api.h
    HINTS $ENV{FFT_PEAKFINDER_DIR}/include
        ${PC_FFT_PEAKFINDER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    FFT_PEAKFINDER_LIBRARIES
    NAMES gnuradio-fft_peakfinder
    HINTS $ENV{FFT_PEAKFINDER_DIR}/lib
        ${PC_FFT_PEAKFINDER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/fft_peakfinderTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FFT_PEAKFINDER DEFAULT_MSG FFT_PEAKFINDER_LIBRARIES FFT_PEAKFINDER_INCLUDE_DIRS)
MARK_AS_ADVANCED(FFT_PEAKFINDER_LIBRARIES FFT_PEAKFINDER_INCLUDE_DIRS)
