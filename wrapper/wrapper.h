#ifndef WRAPPER_H
#define WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MetaInfoContainer {
   int db_version;
   const char* description;
} MetaInfoContainer;

typedef struct CustomQtLib CustomQtLib;

CustomQtLib* newInstance();

void CustomQtLib_init(CustomQtLib* v);

char* CustomQtLib_get_version(CustomQtLib* v);

MetaInfoContainer CustomQtLib_get_meta_info(CustomQtLib* v);

#ifdef __cplusplus
}
#endif

#endif // WRAPPER_H
