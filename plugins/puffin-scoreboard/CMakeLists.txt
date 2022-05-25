project(puffin-scoreboard)

set(puffin-scoreboard_SOURCES
      puffin-scoreboard.c
      )

add_library(puffin-scoreboard MODULE
      ${puffin-scoreboard_SOURCES})
target_link_libraries(puffin-scoreboard
      libobs)

install_obs_plugin_with_data(puffin-scoreboard data)