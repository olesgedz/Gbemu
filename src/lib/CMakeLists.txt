

file (GLOB sources CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/lib/*.c")

file (GLOB headers CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.h")

add_library(emu STATIC ${sources} ${headers} ../include/io.h io.c dbg.c dma.c lcd.c ../include/ppu_sm.h ppu_sm.c ppu_pipeline.c)

target_include_directories(emu PUBLIC ${PROJECT_SOURCE_DIR}/include )


if (WIN32)
  target_include_directories(emu PUBLIC "${PROJECT_SOURCE_DIR}/../windows_deps/sdl2/include" )
  target_include_directories(emu PUBLIC ${PROJECT_SOURCE_DIR}/../windows_deps/sdl2_ttf/include )
  target_include_directories(emu PUBLIC ${PROJECT_SOURCE_DIR}/../windows_deps/)
  target_include_directories(emu PUBLIC ${PROJECT_SOURCE_DIR}/../windows_deps/wpthreads/include)
  set(WPTHREADS ${PROJECT_SOURCE_DIR}/../windows_deps/wpthreads/lib/x64/pthreadVC2.lib)
  target_link_libraries(emu  ${WPTHREADS})
else()
  target_include_directories(emu PUBLIC ${SDL2_INCLUDE_DIR})
  target_link_libraries(emu PUBLIC ${SDL2_LIBRARY}) 
  target_link_libraries(emu PUBLIC ${SDL2_TTF_LIBRARY}) 
endif()

include_directories("/usr/local/include")
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(emu ${SDL2_LIBRARIES})
target_link_libraries(emu ${SDL2_TTF_LIBRARIES})

