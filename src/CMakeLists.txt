# CMAKE_INSTALL_PREFIX在debian rules中已设置
SET(CMAKE_INSTALL_PREFIX /usr)

SET(NLOHMANN_SRC thirdparty/nlohmann/json.hpp)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX /usr)
endif()

# libqt5websockets5-dev
# find_package(Qt5 REQUIRED COMPONENTS WebSockets)

include_directories(thirdparty)

add_executable(nlohmann_test
    ${NLOHMANN_SRC}
    main.cpp
)

# target_link_libraries(echoclient PUBLIC
#    Qt5::Core
#    Qt5::WebSockets
#    stdc++
# )

install(TARGETS nlohmann_test RUNTIME DESTINATION bin)
