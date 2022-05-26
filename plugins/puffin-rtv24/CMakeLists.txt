project(puffin-rtv24)

add_library(puffin-rtv24)
add_library(OBS::rtv24 ALIAS puffin-rtv24)

target_sources(puffin-rtv24.c rtv24-source.c)

