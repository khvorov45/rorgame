// Freetype2 pulled out from
// https://github.com/freetype/freetype

#include <stdint.h>
#include <limits.h>

#define FT_CHAR_BIT    CHAR_BIT
#define FT_USHORT_MAX  USHRT_MAX
#define FT_INT_MAX     INT_MAX
#define FT_INT_MIN     INT_MIN
#define FT_UINT_MAX    UINT_MAX
#define FT_LONG_MIN    LONG_MIN
#define FT_LONG_MAX    LONG_MAX
#define FT_ULONG_MAX   ULONG_MAX
#ifdef LLONG_MAX
#define FT_LLONG_MAX   LLONG_MAX
#endif
#ifdef LLONG_MIN
#define FT_LLONG_MIN   LLONG_MIN
#endif
#ifdef ULLONG_MAX
#define FT_ULLONG_MAX  ULLONG_MAX
#endif

#define NULL 0

#define FREETYPE_MAJOR  2
#define FREETYPE_MINOR  12
#define FREETYPE_PATCH  0

#define FT_EXPORT_DEF(x) x

#define FT_FUNCTION_DEFINITION( x )  x
#define FT_BASE_DEF( x )  FT_FUNCTION_DEFINITION( x )
#define FT_CALLBACK_DEF( x )  static  x

#define FT_UNUSED( arg )  ( (arg) = (arg) )

#define FT_Err_Ok 0x00
#define FT_Err_Invalid_Argument 0x06
#define FT_Err_Unimplemented_Feature 0x07
#define FT_Err_Out_Of_Memory 0x40
#define FT_Err_Array_Too_Large 0x0A

#define FT_ERR_PREFIX FT_Err_
#define FT_ERR_XCAT(x, y) x ## y
#define FT_ERR_CAT(x, y) FT_ERR_XCAT( x, y )
#define FT_THROW(e) FT_ERR_CAT(FT_ERR_PREFIX, e)

#define FT_OPEN_MEMORY    0x1
#define FT_OPEN_STREAM    0x2
#define FT_OPEN_PATHNAME  0x4
#define FT_OPEN_DRIVER    0x8
#define FT_OPEN_PARAMS    0x10

#define FT_MAX_MODULES  32

#define FT_STATIC_BYTE_CAST( type, var )  (type)(FT_Byte)(var)

#define FT_IMAGE_TAG( value, _x1, _x2, _x3, _x4 )                         \
          value = ( ( FT_STATIC_BYTE_CAST( unsigned long, _x1 ) << 24 ) | \
                    ( FT_STATIC_BYTE_CAST( unsigned long, _x2 ) << 16 ) | \
                    ( FT_STATIC_BYTE_CAST( unsigned long, _x3 ) << 8  ) | \
                      FT_STATIC_BYTE_CAST( unsigned long, _x4 )         )

typedef uint32_t FT_UInt32;
typedef int32_t FT_Int32;
typedef uintptr_t size_t;
typedef intptr_t ft_ptrdiff_t;

typedef unsigned char FT_Bool;
typedef signed short FT_FWord;   /* distance in FUnits */
typedef unsigned short FT_UFWord;  /* unsigned distance */
typedef signed char FT_Char;
typedef unsigned char FT_Byte;
typedef const FT_Byte* FT_Bytes;
typedef FT_UInt32 FT_Tag;
typedef char FT_String;
typedef signed short FT_Short;
typedef unsigned short FT_UShort;
typedef signed int FT_Int;
typedef unsigned int FT_UInt;
typedef signed long FT_Long;
typedef unsigned long FT_ULong;
typedef signed short FT_F2Dot14;
typedef signed long FT_F26Dot6;
typedef signed long FT_Fixed;
typedef int FT_Error;
typedef void* FT_Pointer;
typedef size_t FT_Offset;
typedef ft_ptrdiff_t FT_PtrDist;

typedef union FT_StreamDesc_ {
  long   value;
  void*  pointer;
} FT_StreamDesc;

typedef struct FT_StreamRec_* FT_Stream;

typedef unsigned long
(*FT_Stream_IoFunc)( FT_Stream       stream,
                     unsigned long   offset,
                     unsigned char*  buffer,
                     unsigned long   count );

typedef void
(*FT_Stream_CloseFunc)( FT_Stream  stream );

typedef struct FT_MemoryRec_* FT_Memory;

typedef void* (*FT_Alloc_Func)( FT_Memory  memory,
                                long       size );

typedef void (*FT_Free_Func)( FT_Memory  memory,
                              void*      block );

typedef void* (*FT_Realloc_Func)( FT_Memory  memory,
                                  long       cur_size,
                                  long       new_size,
                                  void*      block );

struct  FT_MemoryRec_
{
  void*            user;
  FT_Alloc_Func    alloc;
  FT_Free_Func     free;
  FT_Realloc_Func  realloc;
};

typedef struct FT_StreamRec_ {
  unsigned char*       base;
  unsigned long        size;
  unsigned long        pos;

  FT_StreamDesc        descriptor;
  FT_StreamDesc        pathname;
  FT_Stream_IoFunc     read;
  FT_Stream_CloseFunc  close;

  FT_Memory            memory;

  unsigned char*       cursor;
  unsigned char*       limit;
} FT_StreamRec;

typedef struct FT_ModuleRec_*  FT_Module;

typedef FT_Error
(*FT_Module_Constructor)( FT_Module  module );

typedef void
(*FT_Module_Destructor)( FT_Module  module );

typedef FT_Pointer  FT_Module_Interface;

typedef FT_Module_Interface
(*FT_Module_Requester)( FT_Module    module,
                        const char*  name );

typedef struct  FT_Module_Class_ {
  FT_ULong               module_flags;
  FT_Long                module_size;
  const FT_String*       module_name;
  FT_Fixed               module_version;
  FT_Fixed               module_requires;

  const void*            module_interface;
  FT_Module_Constructor  module_init;
  FT_Module_Destructor   module_done;
  FT_Module_Requester    get_interface;
} FT_Module_Class;

typedef struct FT_LibraryRec_ *FT_Library;

typedef struct  FT_ModuleRec_ {
    FT_Module_Class*  clazz;
    FT_Library        library;
    FT_Memory         memory;
} FT_ModuleRec;

typedef struct FT_ListNodeRec_*  FT_ListNode;

typedef struct  FT_ListNodeRec_ {
  FT_ListNode  prev;
  FT_ListNode  next;
  void*        data;
} FT_ListNodeRec;

typedef struct  FT_ListRec_ {
  FT_ListNode  head;
  FT_ListNode  tail;
} FT_ListRec;

typedef enum  FT_Glyph_Format_ {
  FT_IMAGE_TAG( FT_GLYPH_FORMAT_NONE, 0, 0, 0, 0 ),

  FT_IMAGE_TAG( FT_GLYPH_FORMAT_COMPOSITE, 'c', 'o', 'm', 'p' ),
  FT_IMAGE_TAG( FT_GLYPH_FORMAT_BITMAP,    'b', 'i', 't', 's' ),
  FT_IMAGE_TAG( FT_GLYPH_FORMAT_OUTLINE,   'o', 'u', 't', 'l' ),
  FT_IMAGE_TAG( FT_GLYPH_FORMAT_PLOTTER,   'p', 'l', 'o', 't' ),
  FT_IMAGE_TAG( FT_GLYPH_FORMAT_SVG,       'S', 'V', 'G', ' ' )
} FT_Glyph_Format;

typedef enum  FT_Render_Mode_ {
  FT_RENDER_MODE_NORMAL = 0,
  FT_RENDER_MODE_LIGHT,
  FT_RENDER_MODE_MONO,
  FT_RENDER_MODE_LCD,
  FT_RENDER_MODE_LCD_V,
  FT_RENDER_MODE_SDF,

  FT_RENDER_MODE_MAX
} FT_Render_Mode;

typedef signed long  FT_Pos;

typedef struct FT_Vector_ {
  FT_Pos  x;
  FT_Pos  y;
} FT_Vector;

typedef struct  FT_Matrix_ {
  FT_Fixed  xx, xy;
  FT_Fixed  yx, yy;
} FT_Matrix;

typedef struct  FT_BBox_ {
  FT_Pos  xMin, yMin;
  FT_Pos  xMax, yMax;
} FT_BBox;

typedef struct  FT_Span_ {
  short           x;
  unsigned short  len;
  unsigned char   coverage;
} FT_Span;

typedef void  (*FT_Generic_Finalizer)( void*  object );

typedef struct  FT_Generic_{
  void*                 data;
  FT_Generic_Finalizer  finalizer;
} FT_Generic;

typedef struct  FT_Glyph_Metrics_ {
  FT_Pos  width;
  FT_Pos  height;

  FT_Pos  horiBearingX;
  FT_Pos  horiBearingY;
  FT_Pos  horiAdvance;

  FT_Pos  vertBearingX;
  FT_Pos  vertBearingY;
  FT_Pos  vertAdvance;
} FT_Glyph_Metrics;

typedef struct FT_Bitmap_ {
  unsigned int    rows;
  unsigned int    width;
  int             pitch;
  unsigned char*  buffer;
  unsigned short  num_grays;
  unsigned char   pixel_mode;
  unsigned char   palette_mode;
  void*           palette;
} FT_Bitmap;

typedef struct FT_Outline_ {
  short       n_contours;      /* number of contours in glyph        */
  short       n_points;        /* number of points in the glyph      */

  FT_Vector*  points;          /* the outline's points               */
  char*       tags;            /* the points flags                   */
  short*      contours;        /* the contour end points             */

  int         flags;           /* outline masks                      */
} FT_Outline;

typedef struct FT_SubGlyphRec_ {
  FT_Int     index;
  FT_UShort  flags;
  FT_Int     arg1;
  FT_Int     arg2;
  FT_Matrix  transform;
} FT_SubGlyphRec;
typedef struct FT_SubGlyphRec_*  FT_SubGlyph;

typedef struct  FT_GlyphLoadRec_ {
  FT_Outline   outline;       /* outline                   */
  FT_Vector*   extra_points;  /* extra points table        */
  FT_Vector*   extra_points2; /* second extra points table */
  FT_UInt      num_subglyphs; /* number of subglyphs       */
  FT_SubGlyph  subglyphs;     /* subglyphs                 */
} FT_GlyphLoadRec, *FT_GlyphLoad;

typedef struct FT_GlyphLoaderRec_ {
  FT_Memory        memory;
  FT_UInt          max_points;
  FT_UInt          max_contours;
  FT_UInt          max_subglyphs;
  FT_Bool          use_extra;

  FT_GlyphLoadRec  base;
  FT_GlyphLoadRec  current;

  void*            other;            /* for possible future extension? */
} FT_GlyphLoaderRec, *FT_GlyphLoader;

typedef struct  FT_Slot_InternalRec_ {
  FT_GlyphLoader  loader;
  FT_UInt         flags;
  FT_Bool         glyph_transformed;
  FT_Matrix       glyph_matrix;
  FT_Vector       glyph_delta;
  void*           glyph_hints;
  FT_Int32        load_flags;
} FT_GlyphSlot_InternalRec;
typedef struct FT_Slot_InternalRec_*  FT_Slot_Internal;

typedef struct FT_GlyphSlotRec_*  FT_GlyphSlot;
typedef struct FT_FaceRec_* FT_Face;

typedef struct  FT_GlyphSlotRec_ {
  FT_Library        library;
  FT_Face           face;
  FT_GlyphSlot      next;
  FT_UInt           glyph_index; /* new in 2.10; was reserved previously */
  FT_Generic        generic;

  FT_Glyph_Metrics  metrics;
  FT_Fixed          linearHoriAdvance;
  FT_Fixed          linearVertAdvance;
  FT_Vector         advance;

  FT_Glyph_Format   format;

  FT_Bitmap         bitmap;
  FT_Int            bitmap_left;
  FT_Int            bitmap_top;

  FT_Outline        outline;

  FT_UInt           num_subglyphs;
  FT_SubGlyph       subglyphs;

  void*             control_data;
  long              control_len;

  FT_Pos            lsb_delta;
  FT_Pos            rsb_delta;

  void*             other;

  FT_Slot_Internal  internal;
} FT_GlyphSlotRec;

typedef struct FT_RendererRec_*  FT_Renderer;

typedef FT_Error
(*FT_Renderer_RenderFunc)( FT_Renderer       renderer,
                           FT_GlyphSlot      slot,
                           FT_Render_Mode    mode,
                           const FT_Vector*  origin );
#define FT_Raster_Render_Func  FT_Raster_RenderFunc

typedef FT_Error
(*FT_Renderer_TransformFunc)( FT_Renderer       renderer,
                              FT_GlyphSlot      slot,
                              const FT_Matrix*  matrix,
                              const FT_Vector*  delta );


typedef void
(*FT_Renderer_GetCBoxFunc)( FT_Renderer   renderer,
                            FT_GlyphSlot  slot,
                            FT_BBox*      cbox );


typedef FT_Error
(*FT_Renderer_SetModeFunc)( FT_Renderer  renderer,
                            FT_ULong     mode_tag,
                            FT_Pointer   mode_ptr );

typedef struct FT_RasterRec_*  FT_Raster;

typedef int
(*FT_Raster_NewFunc)( void*       memory,
                      FT_Raster*  raster );

typedef void
(*FT_Raster_ResetFunc)( FT_Raster       raster,
                        unsigned char*  pool_base,
                        unsigned long   pool_size );

typedef int
(*FT_Raster_SetModeFunc)( FT_Raster      raster,
                          unsigned long  mode,
                          void*          args );

typedef int
(*FT_Raster_BitTest_Func)( int    y,
                           int    x,
                           void*  user );

typedef void
(*FT_SpanFunc)( int             y,
                int             count,
                const FT_Span*  spans,
                void*           user );

typedef void
(*FT_Raster_BitSet_Func)( int    y,
                          int    x,
                          void*  user );

typedef struct  FT_Raster_Params_ {
  const FT_Bitmap*        target;
  const void*             source;
  int                     flags;
  FT_SpanFunc             gray_spans;
  FT_SpanFunc             black_spans;  /* unused */
  FT_Raster_BitTest_Func  bit_test;     /* unused */
  FT_Raster_BitSet_Func   bit_set;      /* unused */
  void*                   user;
  FT_BBox                 clip_box;
} FT_Raster_Params;

typedef int
(*FT_Raster_RenderFunc)( FT_Raster                raster,
                         const FT_Raster_Params*  params );

typedef void
(*FT_Raster_DoneFunc)( FT_Raster  raster );

typedef struct  FT_Raster_Funcs_
{
  FT_Glyph_Format        glyph_format;
  FT_Raster_NewFunc      raster_new;
  FT_Raster_ResetFunc    raster_reset;
  FT_Raster_SetModeFunc  raster_set_mode;
  FT_Raster_RenderFunc   raster_render;
  FT_Raster_DoneFunc     raster_done;
} FT_Raster_Funcs;

typedef struct  FT_Renderer_Class_ {
  FT_Module_Class            root;

  FT_Glyph_Format            glyph_format;

  FT_Renderer_RenderFunc     render_glyph;
  FT_Renderer_TransformFunc  transform_glyph;
  FT_Renderer_GetCBoxFunc    get_glyph_cbox;
  FT_Renderer_SetModeFunc    set_mode;

  FT_Raster_Funcs*           raster_class;
} FT_Renderer_Class;

typedef struct FT_Glyph_Class_  FT_Glyph_Class;

typedef struct FT_GlyphRec_ {
  FT_Library             library;
  const FT_Glyph_Class*  clazz;
  FT_Glyph_Format        format;
  FT_Vector              advance;
} FT_GlyphRec;

typedef struct FT_GlyphRec_*  FT_Glyph;

typedef FT_Error
(*FT_Glyph_InitFunc)( FT_Glyph      glyph,
                      FT_GlyphSlot  slot );

typedef void
(*FT_Glyph_DoneFunc)( FT_Glyph  glyph );

typedef void
(*FT_Glyph_TransformFunc)( FT_Glyph          glyph,
                           const FT_Matrix*  matrix,
                           const FT_Vector*  delta );

typedef void
(*FT_Glyph_GetBBoxFunc)( FT_Glyph  glyph,
                         FT_BBox*  abbox );

typedef FT_Error
(*FT_Glyph_CopyFunc)( FT_Glyph   source,
                      FT_Glyph   target );

typedef FT_Error
(*FT_Glyph_PrepareFunc)( FT_Glyph      glyph,
                         FT_GlyphSlot  slot );

struct  FT_Glyph_Class_ {
  FT_Long                 glyph_size;
  FT_Glyph_Format         glyph_format;

  FT_Glyph_InitFunc       glyph_init;
  FT_Glyph_DoneFunc       glyph_done;
  FT_Glyph_CopyFunc       glyph_copy;
  FT_Glyph_TransformFunc  glyph_transform;
  FT_Glyph_GetBBoxFunc    glyph_bbox;
  FT_Glyph_PrepareFunc    glyph_prepare;
};

typedef struct  FT_RendererRec_ {
  FT_ModuleRec            root;
  FT_Renderer_Class*      clazz;
  FT_Glyph_Format         glyph_format;
  FT_Glyph_Class          glyph_class;

  FT_Raster               raster;
  FT_Raster_Render_Func   raster_render;
  FT_Renderer_RenderFunc  render;
} FT_RendererRec;

typedef FT_Error
(*FT_DebugHook_Func)( void*  arg );

typedef struct FT_LibraryRec_ {
  FT_Memory          memory;           /* library's memory manager */

  FT_Int             version_major;
  FT_Int             version_minor;
  FT_Int             version_patch;

  FT_UInt            num_modules;
  FT_Module          modules[FT_MAX_MODULES];  /* module objects  */

  FT_ListRec         renderers;        /* list of renderers        */
  FT_Renderer        cur_renderer;     /* current outline renderer */
  FT_Module          auto_hinter;

  FT_DebugHook_Func  debug_hooks[4];

#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
  FT_LcdFiveTapFilter      lcd_weights;      /* filter weights, if any */
  FT_Bitmap_LcdFilterFunc  lcd_filter_func;  /* filtering callback     */
#else
  FT_Vector                lcd_geometry[3];  /* RGB subpixel positions */
#endif

  FT_Int             refcount;
} FT_LibraryRec;

typedef struct FT_Bitmap_Size_ {
  FT_Short  height;
  FT_Short  width;

  FT_Pos    size;

  FT_Pos    x_ppem;
  FT_Pos    y_ppem;
} FT_Bitmap_Size;

#define FT_ENC_TAG( value, a, b, c, d )                             \
          value = ( ( FT_STATIC_BYTE_CAST( FT_UInt32, a ) << 24 ) | \
                    ( FT_STATIC_BYTE_CAST( FT_UInt32, b ) << 16 ) | \
                    ( FT_STATIC_BYTE_CAST( FT_UInt32, c ) <<  8 ) | \
                      FT_STATIC_BYTE_CAST( FT_UInt32, d )         )

typedef enum FT_Encoding_ {
  FT_ENC_TAG( FT_ENCODING_NONE, 0, 0, 0, 0 ),

  FT_ENC_TAG( FT_ENCODING_MS_SYMBOL, 's', 'y', 'm', 'b' ),
  FT_ENC_TAG( FT_ENCODING_UNICODE,   'u', 'n', 'i', 'c' ),

  FT_ENC_TAG( FT_ENCODING_SJIS,    's', 'j', 'i', 's' ),
  FT_ENC_TAG( FT_ENCODING_PRC,     'g', 'b', ' ', ' ' ),
  FT_ENC_TAG( FT_ENCODING_BIG5,    'b', 'i', 'g', '5' ),
  FT_ENC_TAG( FT_ENCODING_WANSUNG, 'w', 'a', 'n', 's' ),
  FT_ENC_TAG( FT_ENCODING_JOHAB,   'j', 'o', 'h', 'a' ),

  /* for backward compatibility */
  FT_ENCODING_GB2312     = FT_ENCODING_PRC,
  FT_ENCODING_MS_SJIS    = FT_ENCODING_SJIS,
  FT_ENCODING_MS_GB2312  = FT_ENCODING_PRC,
  FT_ENCODING_MS_BIG5    = FT_ENCODING_BIG5,
  FT_ENCODING_MS_WANSUNG = FT_ENCODING_WANSUNG,
  FT_ENCODING_MS_JOHAB   = FT_ENCODING_JOHAB,

  FT_ENC_TAG( FT_ENCODING_ADOBE_STANDARD, 'A', 'D', 'O', 'B' ),
  FT_ENC_TAG( FT_ENCODING_ADOBE_EXPERT,   'A', 'D', 'B', 'E' ),
  FT_ENC_TAG( FT_ENCODING_ADOBE_CUSTOM,   'A', 'D', 'B', 'C' ),
  FT_ENC_TAG( FT_ENCODING_ADOBE_LATIN_1,  'l', 'a', 't', '1' ),

  FT_ENC_TAG( FT_ENCODING_OLD_LATIN_2, 'l', 'a', 't', '2' ),

  FT_ENC_TAG( FT_ENCODING_APPLE_ROMAN, 'a', 'r', 'm', 'n' )
} FT_Encoding;

typedef struct FT_CharMapRec_ {
  FT_Face      face;
  FT_Encoding  encoding;
  FT_UShort    platform_id;
  FT_UShort    encoding_id;
} FT_CharMapRec;
typedef struct FT_CharMapRec_*  FT_CharMap;

typedef struct FT_Size_Metrics_ {
  FT_UShort  x_ppem;      /* horizontal pixels per EM               */
  FT_UShort  y_ppem;      /* vertical pixels per EM                 */

  FT_Fixed   x_scale;     /* scaling values used to convert font    */
  FT_Fixed   y_scale;     /* units to 26.6 fractional pixels        */

  FT_Pos     ascender;    /* ascender in 26.6 frac. pixels          */
  FT_Pos     descender;   /* descender in 26.6 frac. pixels         */
  FT_Pos     height;      /* text height in 26.6 frac. pixels       */
  FT_Pos     max_advance; /* max horizontal advance, in 26.6 pixels */
} FT_Size_Metrics;

typedef struct FT_Size_InternalRec_ {
  void*  module_data;
  FT_Render_Mode   autohint_mode;
  FT_Size_Metrics  autohint_metrics;
} FT_Size_InternalRec;
typedef struct FT_Size_InternalRec_*  FT_Size_Internal;

typedef struct FT_SizeRec_ {
  FT_Face           face;      /* parent face object              */
  FT_Generic        generic;   /* generic pointer for client uses */
  FT_Size_Metrics   metrics;   /* size metrics                    */
  FT_Size_Internal  internal;
} FT_SizeRec;
typedef struct FT_SizeRec_* FT_Size;

typedef enum FT_Size_Request_Type_ {
  FT_SIZE_REQUEST_TYPE_NOMINAL,
  FT_SIZE_REQUEST_TYPE_REAL_DIM,
  FT_SIZE_REQUEST_TYPE_BBOX,
  FT_SIZE_REQUEST_TYPE_CELL,
  FT_SIZE_REQUEST_TYPE_SCALES,

  FT_SIZE_REQUEST_TYPE_MAX
} FT_Size_Request_Type;

typedef struct FT_Size_RequestRec_ {
  FT_Size_Request_Type  type;
  FT_Long               width;
  FT_Long               height;
  FT_UInt               horiResolution;
  FT_UInt               vertResolution;
} FT_Size_RequestRec;
typedef struct FT_Size_RequestRec_ *FT_Size_Request;

typedef struct FT_Parameter_ {
  FT_ULong    tag;
  FT_Pointer  data;
} FT_Parameter;

typedef FT_Error
(*FT_Face_InitFunc)( FT_Stream      stream,
                     FT_Face        face,
                     FT_Int         typeface_index,
                     FT_Int         num_params,
                     FT_Parameter*  parameters );

typedef void
(*FT_Face_DoneFunc)( FT_Face  face );


typedef FT_Error
(*FT_Size_InitFunc)( FT_Size  size );

typedef void
(*FT_Size_DoneFunc)( FT_Size  size );


typedef FT_Error
(*FT_Slot_InitFunc)( FT_GlyphSlot  slot );

typedef void
(*FT_Slot_DoneFunc)( FT_GlyphSlot  slot );


typedef FT_Error
(*FT_Size_RequestFunc)( FT_Size          size,
                        FT_Size_Request  req );

typedef FT_Error
(*FT_Size_SelectFunc)( FT_Size   size,
                       FT_ULong  size_index );

typedef FT_Error
(*FT_Slot_LoadFunc)( FT_GlyphSlot  slot,
                     FT_Size       size,
                     FT_UInt       glyph_index,
                     FT_Int32      load_flags );


typedef FT_Error
(*FT_Face_GetKerningFunc)( FT_Face     face,
                           FT_UInt     left_glyph,
                           FT_UInt     right_glyph,
                           FT_Vector*  kerning );


typedef FT_Error
(*FT_Face_AttachFunc)( FT_Face    face,
                       FT_Stream  stream );


typedef FT_Error
(*FT_Face_GetAdvancesFunc)( FT_Face    face,
                            FT_UInt    first,
                            FT_UInt    count,
                            FT_Int32   flags,
                            FT_Fixed*  advances );

typedef struct FT_Driver_ClassRec_ {
  FT_Module_Class          root;

  FT_Long                  face_object_size;
  FT_Long                  size_object_size;
  FT_Long                  slot_object_size;

  FT_Face_InitFunc         init_face;
  FT_Face_DoneFunc         done_face;

  FT_Size_InitFunc         init_size;
  FT_Size_DoneFunc         done_size;

  FT_Slot_InitFunc         init_slot;
  FT_Slot_DoneFunc         done_slot;

  FT_Slot_LoadFunc         load_glyph;

  FT_Face_GetKerningFunc   get_kerning;
  FT_Face_AttachFunc       attach_file;
  FT_Face_GetAdvancesFunc  get_advances;

  /* since version 2.2 */
  FT_Size_RequestFunc      request_size;
  FT_Size_SelectFunc       select_size;
} FT_Driver_ClassRec, *FT_Driver_Class;

typedef struct FT_DriverRec_ {
  FT_ModuleRec     root;
  FT_Driver_Class  clazz;
  FT_ListRec       faces_list;
  FT_GlyphLoader   glyph_loader;
} FT_DriverRec;
typedef struct FT_DriverRec_*  FT_Driver;

typedef struct FT_ServiceCacheRec_ {
  FT_Pointer  service_POSTSCRIPT_FONT_NAME;
  FT_Pointer  service_MULTI_MASTERS;
  FT_Pointer  service_METRICS_VARIATIONS;
  FT_Pointer  service_GLYPH_DICT;
  FT_Pointer  service_PFR_METRICS;
  FT_Pointer  service_WINFNT;
} FT_ServiceCacheRec, *FT_ServiceCache;

typedef struct FT_Face_InternalRec_ {
  FT_Matrix  transform_matrix;
  FT_Vector  transform_delta;
  FT_Int     transform_flags;

  FT_ServiceCacheRec  services;

#ifdef FT_CONFIG_OPTION_INCREMENTAL
  FT_Incremental_InterfaceRec*  incremental_interface;
#endif

  FT_Char              no_stem_darkening;
  FT_Int32             random_seed;

#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
  FT_LcdFiveTapFilter      lcd_weights;      /* filter weights, if any */
  FT_Bitmap_LcdFilterFunc  lcd_filter_func;  /* filtering callback     */
#endif

  FT_Int  refcount;
} FT_Face_InternalRec;
typedef struct FT_Face_InternalRec_* FT_Face_Internal;

typedef struct  FT_FaceRec_ {
  FT_Long           num_faces;
  FT_Long           face_index;

  FT_Long           face_flags;
  FT_Long           style_flags;

  FT_Long           num_glyphs;

  FT_String*        family_name;
  FT_String*        style_name;

  FT_Int            num_fixed_sizes;
  FT_Bitmap_Size*   available_sizes;

  FT_Int            num_charmaps;
  FT_CharMap*       charmaps;

  FT_Generic        generic;

  /*# The following member variables (down to `underline_thickness`) */
  /*# are only relevant to scalable outlines; cf. @FT_Bitmap_Size    */
  /*# for bitmap fonts.                                              */
  FT_BBox           bbox;

  FT_UShort         units_per_EM;
  FT_Short          ascender;
  FT_Short          descender;
  FT_Short          height;

  FT_Short          max_advance_width;
  FT_Short          max_advance_height;

  FT_Short          underline_position;
  FT_Short          underline_thickness;

  FT_GlyphSlot      glyph;
  FT_Size           size;
  FT_CharMap        charmap;

  /*@private begin */

  FT_Driver         driver;
  FT_Memory         memory;
  FT_Stream         stream;

  FT_ListRec        sizes_list;

  FT_Generic        autohint;   /* face-specific auto-hinter data */
  void*             extensions; /* unused                         */

  FT_Face_Internal  internal;
  /*@private end */
} FT_FaceRec;

typedef struct  FT_Open_Args_ {
  FT_UInt         flags;
  const FT_Byte*  memory_base;
  FT_Long         memory_size;
  FT_String*      pathname;
  FT_Stream       stream;
  FT_Module       driver;
  FT_Int          num_params;
  FT_Parameter*   params;
} FT_Open_Args;

static FT_Error
ft_open_face_internal( FT_Library           library,
                       const FT_Open_Args*  args,
                       FT_Long              face_index,
                       FT_Face             *aface,
                       FT_Bool              test_mac_fonts )
{
  return 0;
}

FT_EXPORT_DEF( FT_Error )
FT_New_Memory_Face( FT_Library      library,
                    const FT_Byte*  file_base,
                    FT_Long         file_size,
                    FT_Long         face_index,
                    FT_Face        *aface )
{
  FT_Open_Args  args;


  /* test for valid `library' and `face' delayed to `FT_Open_Face' */
  if ( !file_base )
    return FT_THROW( Invalid_Argument );

  args.flags       = FT_OPEN_MEMORY;
  args.memory_base = file_base;
  args.memory_size = file_size;
  args.stream      = NULL;

  return ft_open_face_internal( library, &args, face_index, aface, 1 );
}


#if FREETYPE_WINDOWS

typedef void *HANDLE;
typedef void *LPVOID;
typedef uint32_t DWORD;
typedef size_t SIZE_T;
typedef int WINBOOL;

HANDLE GetProcessHeap();
LPVOID HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
LPVOID HeapReAlloc (HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
WINBOOL HeapFree (HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);

FT_CALLBACK_DEF( void* )
ft_alloc( FT_Memory  memory,
          long       size )
{
  return HeapAlloc( memory->user, 0, size );
}

FT_CALLBACK_DEF( void* )
ft_realloc( FT_Memory  memory,
            long       cur_size,
            long       new_size,
            void*      block )
{
  FT_UNUSED( cur_size );
  return HeapReAlloc( memory->user, 0, block, new_size );
}

FT_CALLBACK_DEF( void )
ft_free( FT_Memory  memory,
         void*      block )
{
  HeapFree( memory->user, 0, block );
}

FT_BASE_DEF( FT_Memory )
FT_New_Memory( void )
{
  HANDLE     heap;
  FT_Memory  memory;

  heap   = GetProcessHeap();
  memory = heap ? (FT_Memory)HeapAlloc( heap, 0, sizeof ( *memory ) ) : NULL;

  if ( memory )
  {
    memory->user    = heap;
    memory->alloc   = ft_alloc;
    memory->realloc = ft_realloc;
    memory->free    = ft_free;
#ifdef FT_DEBUG_MEMORY
    ft_mem_debug_init( memory );
#endif
  }

  return memory;
}

#endif // FREETYPE_WINDOWS

#define FT_ASSERT( condition )  do { } while ( 0 )

void
ft_memset(void* dest, uint8_t byte, uintptr_t count) {
  while (count--) *(uint8_t*)dest++ = byte;
}

void*
ft_memcpy(void *dest, const void *src, size_t n) {
  void* destOg = dest;
  while (n--) *(uint8_t*)dest++ = *(uint8_t*)src++;
  return destOg;
}

size_t 
ft_strlen(const char *str) {
  size_t result = 0;
  while (*str++) ++result;
  return result;
}

#define FT_MEM_SET( dest, byte, count ) ft_memset( dest, byte, (FT_Offset)(count) )
#define FT_MEM_ZERO( dest, count )  FT_MEM_SET( dest, 0, count )

FT_BASE_DEF( FT_Pointer )
ft_mem_qalloc( FT_Memory  memory,
               FT_Long    size,
               FT_Error  *p_error )
{
  FT_Error    error = FT_Err_Ok;
  FT_Pointer  block = NULL;


  if ( size > 0 )
  {
    block = memory->alloc( memory, size );
    if ( !block )
      error = FT_THROW( Out_Of_Memory );
  }
  else if ( size < 0 )
  {
    /* may help catch/prevent security issues */
    error = FT_THROW( Invalid_Argument );
  }

  *p_error = error;
  return block;
}

FT_BASE_DEF( FT_Pointer )
ft_mem_alloc( FT_Memory  memory,
              FT_Long    size,
              FT_Error  *p_error )
{
  FT_Error    error;
  FT_Pointer  block = ft_mem_qalloc( memory, size, &error );

  if ( !error && block && size > 0 )
    FT_MEM_ZERO( block, size );

  *p_error = error;
  return block;
}

FT_BASE_DEF( void )
ft_mem_free( FT_Memory   memory,
             const void *P )
{
  if ( P )
    memory->free( memory, (void*)P );
}

FT_BASE_DEF( FT_Pointer )
ft_mem_qrealloc( FT_Memory  memory,
                 FT_Long    item_size,
                 FT_Long    cur_count,
                 FT_Long    new_count,
                 void*      block,
                 FT_Error  *p_error )
{
  FT_Error  error = FT_Err_Ok;


  /* Note that we now accept `item_size == 0' as a valid parameter, in
   * order to cover very weird cases where an ALLOC_MULT macro would be
   * called.
   */
  if ( cur_count < 0 || new_count < 0 || item_size < 0 )
  {
    /* may help catch/prevent nasty security issues */
    error = FT_THROW( Invalid_Argument );
  }
  else if ( new_count == 0 || item_size == 0 )
  {
    ft_mem_free( memory, block );
    block = NULL;
  }
  else if ( new_count > FT_INT_MAX / item_size )
  {
    error = FT_THROW( Array_Too_Large );
  }
  else if ( cur_count == 0 )
  {
    FT_ASSERT( !block );

    block = memory->alloc( memory, new_count * item_size );
    if ( block == NULL )
      error = FT_THROW( Out_Of_Memory );
  }
  else
  {
    FT_Pointer  block2;
    FT_Long     cur_size = cur_count * item_size;
    FT_Long     new_size = new_count * item_size;


    block2 = memory->realloc( memory, cur_size, new_size, block );
    if ( !block2 )
      error = FT_THROW( Out_Of_Memory );
    else
      block = block2;
  }

  *p_error = error;
  return block;
}

FT_BASE_DEF( FT_Pointer )
ft_mem_realloc( FT_Memory  memory,
                FT_Long    item_size,
                FT_Long    cur_count,
                FT_Long    new_count,
                void*      block,
                FT_Error  *p_error )
{
  FT_Error  error = FT_Err_Ok;


  block = ft_mem_qrealloc( memory, item_size,
                           cur_count, new_count, block, &error );
  if ( !error && block && new_count > cur_count )
    FT_MEM_ZERO( (char*)block + cur_count * item_size,
                 ( new_count - cur_count ) * item_size );

  *p_error = error;
  return block;
}


FT_BASE_DEF( FT_Pointer )
ft_mem_dup( FT_Memory    memory,
            const void*  address,
            FT_ULong     size,
            FT_Error    *p_error )
{
  FT_Error    error;
  FT_Pointer  p = ft_mem_qalloc( memory, (FT_Long)size, &error );


  if ( !error && address && size > 0 )
    ft_memcpy( p, address, size );

  *p_error = error;
  return p;
}


FT_BASE_DEF( FT_Pointer )
ft_mem_strdup( FT_Memory    memory,
               const char*  str,
               FT_Error    *p_error )
{
  FT_ULong  len = str ? (FT_ULong)ft_strlen( str ) + 1
                      : 0;


  return ft_mem_dup( memory, str, len, p_error );
}


FT_BASE_DEF( FT_Int )
ft_mem_strcpyn( char*        dst,
                const char*  src,
                FT_ULong     size )
{
  while ( size > 1 && *src != 0 )
  {
    *dst++ = *src++;
    size--;
  }

  *dst = 0;  /* always zero-terminate */

  return *src != 0;
}

#define FT_ASSIGNP( p, val )  (p) = (val)
#define FT_ASSIGNP_INNER( p, exp )  FT_ASSIGNP( p, exp )
#define FT_MEM_ALLOC( ptr, size ) FT_ASSIGNP_INNER( ptr, ft_mem_alloc( memory, (FT_Long)(size), &error ) )
#define FT_MEM_NEW( ptr ) FT_MEM_ALLOC( ptr, sizeof ( *(ptr) ) )
#define FT_MEM_SET_ERROR( cond )  ( (cond), error != 0 )
#define FT_NEW( ptr )  FT_MEM_SET_ERROR( FT_MEM_NEW( ptr ) )

FT_EXPORT_DEF( FT_Error )
FT_New_Library( FT_Memory    memory,
                FT_Library  *alibrary )
{
  FT_Library  library = NULL;
  FT_Error    error;

  if ( !memory || !alibrary )
    return FT_THROW( Invalid_Argument );

#ifndef FT_DEBUG_LOGGING
#ifdef FT_DEBUG_LEVEL_ERROR
  /* init debugging support */
  ft_debug_init();
#endif /* FT_DEBUG_LEVEL_ERROR */
#endif /* !FT_DEBUG_LOGGING */

  /* first of all, allocate the library object */
  if ( FT_NEW( library ) )
    return error;

  library->memory = memory;

  library->version_major = FREETYPE_MAJOR;
  library->version_minor = FREETYPE_MINOR;
  library->version_patch = FREETYPE_PATCH;

  library->refcount = 1;

  /* That's ok now */
  *alibrary = library;

  return FT_Err_Ok;
}

FT_EXPORT_DEF( FT_Error )
FT_Init_FreeType( FT_Library  *alibrary )
{
  FT_Error   error;
  FT_Memory  memory;

#ifdef FT_DEBUG_LOGGING
  ft_logging_init();
#endif

  /* check of `alibrary' delayed to `FT_New_Library' */

  /* First of all, allocate a new system object -- this function is part */
  /* of the system-specific component, i.e. `ftsystem.c'.                */

  memory = FT_New_Memory();

  if ( !memory )
  {
    //FT_ERROR(( "FT_Init_FreeType: cannot find memory manager\n" ));
    return FT_THROW( Unimplemented_Feature );
  }

  /* build a library out of it, then fill it with the set of */
  /* default drivers.                                        */

  error = FT_New_Library( memory, alibrary );
  #if 0
  if ( error )
    FT_Done_Memory( memory );
  else
    FT_Add_Default_Modules( *alibrary );

  FT_Set_Default_Properties( *alibrary );
  #endif
  return error;
}
