#ifndef __BUILTINS_H__
#define __BUILTINS_H__

typedef struct {
	int32_t id;
	char* name;
	int8_t kind;
} sn_type_t;

typedef struct {
	sn_type_t *type;
	int64_t size;
	struct {
		int32_t first;
		int32_t last;
	}* range;
	struct {
		int32_t size;
		void* intkeys;
		void* keys;
		void* values;
	}* dynmap;
	struct {
		int64_t* offsets;
	}* layout;
	void* vtable;
} sn_rtti_t;

#endif /* __BUILTINS_H__ */