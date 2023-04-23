cmake_minimum_required(VERSION 3.17)

project(zint)

set(zint_COMMON_SRCS common.c library.c render.c large.c reedsol.c gs1.c eci.c)
set(zint_ONEDIM_SRCS code.c code128.c 2of5.c upcean.c telepen.c medical.c plessey.c rss.c)
set(zint_POSTAL_SRCS postal.c auspost.c imail.c)
set(zint_TWODIM_SRCS code16k.c codablock.c dmatrix.c pdf417.c qr.c maxicode.c composite.c aztec.c code49.c code1.c gridmtx.c hanxin.c dotcode.c)
set(zint_OUTPUT_SRCS render.c ps.c svg.c emf.c bmp.c pcx.c gif.c png.c tif.c raster.c)
set(zint_SRCS ${zint_OUTPUT_SRCS} ${zint_COMMON_SRCS} ${zint_ONEDIM_SRCS} ${zint_POSTAL_SRCS} ${zint_TWODIM_SRCS})

add_library(${PROJECT_NAME} SHARED ${zint_SRCS})

target_link_libraries(${PROJECT_NAME} -lm png)
