set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

include_directories(include/)

set(SRC_FILES
  prng.c 
  args.c 
  io.c 
  randlc.c
  )

set(INCLUDE_FILES
  include/prng.h 
  include/args.h 
  include/io.h 
  include/randlc.h
  )

add_executable(prng ${SRC_FILES})

target_include_directories(prng PUBLIC include/)

install(FILES ${INCLUDE_FILES} DESTINATION include)

install(
  TARGETS prng
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
