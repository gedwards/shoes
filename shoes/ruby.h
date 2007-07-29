//
// shoes/ruby.h
// Some defs for Ruby.
//
#include <ruby.h>

#if SHOES_WIN32
typedef VALUE (*HOOK)(...);
#define CASTHOOK(x) reinterpret_cast<HOOK>(x)
#else
#define CASTHOOK(x) x
#endif

#ifndef RARRAY_LEN
#define RARRAY_LEN(arr)  RARRAY(arr)->len
#define RSTRING_LEN(str) RSTRING(str)->len
#define RSTRING_PTR(str) RSTRING(str)->ptr
#endif

extern VALUE mShoes, cCanvas, cFlow, cStack, cPath, cImage, cBackground, cTextClass, cButton, cEditLine, cEditBox, cListBox, cProgress, cColor, cLink;
extern VALUE reRGB_SOURCE;
extern ID s_new, s_run, s_to_s, s_call, s_center, s_change, s_click, s_corner, s_draw, s_font, s_hidden, s_insert, s_match, s_x, s_y, s_height, s_width, s_margin, s_marginleft, s_marginright, s_margintop, s_marginbottom;

VALUE mfp_instance_eval(VALUE, VALUE);
void shoes_ruby_init(void);

//
// Common funcs for dealing with attribute hashes
//
#define ATTR(n)           shoes_attr_find(s_##n, self_t->attr, Qnil)
#define ATTR2(n)          shoes_attr_find(s_##n, attr, self_t->attr)
#define ATTR_INT(n, dn)   shoes_attr_int(s_##n, attr, Qnil, dn)
#define ATTR2INT(n, dn)   shoes_attr_int(s_##n, attr, self_t->attr, dn)
#define ATTR2DBL(n, dn)   shoes_attr_dbl(s_##n, attr, self_t->attr, dn)
#define ATTR2CSTR(n, dn)  shoes_attr_cstr(s_##n, attr, self_t->attr, dn)
#define ATTRSET(k, v)     self_t->attr = shoes_attr_set(self_t->attr, s_##k, v)

//
// Common properties
//
#define ATTR_MARGINS(dm) \
  int margin = ATTR2INT(margin, dm); \
  int lmargin = ATTR2INT(marginleft, margin); \
  int rmargin = ATTR2INT(marginright, margin); \
  int tmargin = ATTR2INT(margintop, margin); \
  int bmargin = ATTR2INT(marginbottom, margin)

VALUE shoes_attr_set(VALUE, ID, VALUE);
VALUE shoes_attr_find(ID, VALUE, VALUE);
int shoes_attr_int(ID, VALUE, VALUE, int);
double shoes_attr_dbl(ID, VALUE, VALUE, double);
char *shoes_attr_cstr(ID, VALUE, VALUE, char *);
VALUE rb_str_to_pas(VALUE);