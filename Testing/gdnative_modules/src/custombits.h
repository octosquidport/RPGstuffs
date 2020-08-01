#ifndef CUSTOMBITS_H_INCLUDED
#define CUSTOMBITS_H_INCLUDED

typedef struct user_data_struct {
	char data[256];
} user_data_struct;

void *custombits_constructor(godot_object *p_instance, void *p_method_data);
void custombits_destructor(godot_object *p_instance, void *p_method_data, void *p_user_data);
godot_variant custombits_get_data(godot_object *p_instance, void *p_method_data, void *p_user_data, int p_num_args, godot_variant **p_args);

#endif