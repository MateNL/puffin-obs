#include <obs-module.h>

struct rtv24_source {
    uint32_t port;
    uint32_t channel;

	uint32_t width;
	uint32_t height;

    obs_source_t *src;
};

static const char *rtv24_source_get_name(void *unused)
{
	UNUSED_PARAMETER(unused);
	return obs_module_text("RTV24Source");
}

static void *rtv24_source_create(obs_data_t *settings, obs_source_t *source)
{
    UNUSED_PARAMETER(source);

    struct rtv24_source *context = bzalloc(sizeof(struct rtv24_source));
    context->src = source;

    rtv24_source_update(context, settings);

    return context;
}

static void rtv24_source_update(void *data, obs_data_t *settings)
{
	struct rtv24_source *context = data;

    uint32_t port = (uint32_t)obs_data_get_int(settings, "port");
    uint32_t channel = (uint32_t)obs_data_get_int(settings, "channel");
	uint32_t width = (uint32_t)obs_data_get_int(settings, "width");
	uint32_t height = (uint32_t)obs_data_get_int(settings, "height");

    context->width = width;
    context->height = height;
    
}

static void rtv24_source_destroy(void *data)
{
	bfree(data);
}

static void rtv24_source_defaults(obs_data_t *settings)
{
	obs_data_set_default_int(settings, "port", 0);
	obs_data_set_default_int(settings, "channel", 0);
	obs_data_set_default_int(settings, "width", 1280);
	obs_data_set_default_int(settings, "height", 720);
}

static uint32_t rtv24_source_getwidth(void *data)
{
	struct rtv24_source* context = data;
    return context->width;
}

static uint32_t rtv24_source_getheight(void *data)
{
	struct rtv24_source* context = data;
    return context->height;
}

static void rtv24_source_render(void *data, gs_effect_t *effect)
{
	
}

static obs_properties_t* rtv24_source_properties(void* unused)
{
    UNUSED_PARAMETER(unused);

    obs_properties_t* props = obs_properties_create();

    obs_properties_add_int(props, "port", obs_module_text("RTV24Source.Port"), 0, 4, 1);
    obs_properties_add_int(props, "channel", obs_module_text("RTV24Source.Channel"), 0, 4, 1);
    obs_properties_add_int(props, "width", obs_module_text("RTV24Source.Width"), 0, 4096, 1);
    obs_properties_add_int(props, "height", obs_module_text("RTV24Source.Height"), 0, 4096, 1);

    return props;
}

struct obs_source_info rtv24_source_info = {
    .id = "rtv_source",
    .type = OBS_SOURCE_TYPE_INPUT,
    .output_flags = OBS_SOURCE_VIDEO,
    .get_name = rtv24_source_get_name,
    .create = rtv24_source_create,
    .update = rtv24_source_update,
    .destroy = rtv24_source_destroy,
    .get_defaults = rtv24_source_defaults,
    .video_render = rtv24_source_render,
    .get_height = rtv24_source_getheight,
    .get_width = rtv24_source_getwidth,
    .get_properties = rtv24_source_properties

};