#include <gdnative_api_struct.gen.h>
#include <stdlib.h>
#include <string.h>

#include "custombits.h"

const godot_gdnative_core_api_struct *api = NULL;
const godot_gdnative_ext_nativescript_api_struct *nativescript_api = NULL;

void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *p_options) {
	api = p_options->api_struct;
	
	size_t i;
	// now find our extensions
	for (i = 0; i < api->num_extensions; ++i) 
	{
		switch (api->extensions[i]->type) {
			case GDNATIVE_EXT_NATIVESCRIPT:
				nativescript_api = (godot_gdnative_ext_nativescript_api_struct *)(api->extensions[i]);
				break;
		}
	}
}

void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *p_options) {
	api = NULL;
	nativescript_api = NULL;
}

void GDN_EXPORT godot_nativescript_init(void *p_handle) {
	godot_instance_create_func create = { NULL, NULL, NULL };
	create.create_func = &custombits_constructor;

	godot_instance_destroy_func destroy = { NULL, NULL, NULL };
	destroy.destroy_func = &custombits_destructor;

	// Class name *MUST* match case of what is used in Godot
	nativescript_api->godot_nativescript_register_class(p_handle, "CustomBits", "Reference", create, destroy);

	godot_instance_method get_data = { NULL, NULL, NULL };
	get_data.method = &custombits_get_data;

	godot_method_attributes attributes = { GODOT_METHOD_RPC_MODE_DISABLED };

	nativescript_api->godot_nativescript_register_method(p_handle, "CustomBits", "get_data", attributes, get_data);
}

void *custombits_constructor(godot_object *p_instance, void *p_method_data) {
	printf("SIMPLE._init()\n");
	
	user_data_struct *user_data = api->godot_alloc(sizeof(user_data_struct));
	strcpy(user_data->data, "CustomBits, yay!");

	return user_data;
}

void custombits_destructor(godot_object *p_instance, void *p_method_data, void *p_user_data) {
	printf("SIMPLE._byebye()\n");

	api->godot_free(p_user_data);
}

godot_variant custombits_get_data(godot_object *p_instance, void *p_method_data, void *p_user_data, int p_num_args, godot_variant **p_args) {
	godot_string data;
	godot_variant ret;
	user_data_struct * user_data = (user_data_struct *) p_user_data;

	api->godot_string_new(&data);
	api->godot_string_parse_utf8(&data, user_data->data);
	api->godot_variant_new_string(&ret, &data);
	api->godot_string_destroy(&data);

	return ret;
}