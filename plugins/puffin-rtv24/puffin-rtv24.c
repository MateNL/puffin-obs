#include <obs-module.h>

OBS_DECLARE_MODULE()

OBS_MODULE_USE_DEFAULT_LOCALE("puffin-rtv24-source", "en-US")

extern struct obs_source_info rtv24_source;

bool obs_module_load(void)
{
    obs_register_source(&rtv24_source);

    return true;
}