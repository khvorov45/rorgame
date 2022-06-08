// Freetype2 pulled out from
// https://github.com/freetype/freetype

#include <stdint.h>

#define NULL 0

#define FT_EXPORT_DEF(x) x

#define FT_Err_Invalid_Argument 0x06;

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

struct  FT_Glyph_Class_ {
  FT_Long                 glyph_size;
  FT_Glyph_Format         glyph_format;

#if 0
  FT_Glyph_InitFunc       glyph_init;
  FT_Glyph_DoneFunc       glyph_done;
  FT_Glyph_CopyFunc       glyph_copy;
  FT_Glyph_TransformFunc  glyph_transform;
  FT_Glyph_GetBBoxFunc    glyph_bbox;
  FT_Glyph_PrepareFunc    glyph_prepare;
#endif
};

typedef struct FT_Glyph_Class_  FT_Glyph_Class;

typedef struct  FT_RendererRec_ {
  FT_ModuleRec            root;
  FT_Renderer_Class*      clazz;
  FT_Glyph_Format         glyph_format;
  FT_Glyph_Class          glyph_class;

  FT_Raster               raster;
  FT_Raster_Render_Func   raster_render;
  FT_Renderer_RenderFunc  render;
} FT_RendererRec;

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

  #if 0
  FT_DebugHook_Func  debug_hooks[4];

#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
  FT_LcdFiveTapFilter      lcd_weights;      /* filter weights, if any */
  FT_Bitmap_LcdFilterFunc  lcd_filter_func;  /* filtering callback     */
#else
  FT_Vector                lcd_geometry[3];  /* RGB subpixel positions */
#endif
  #endif

  FT_Int             refcount;
} FT_LibraryRec;

typedef struct  FT_FaceRec_ {

  FT_Long           num_faces;
  FT_Long           face_index;

  FT_Long           face_flags;
  FT_Long           style_flags;

  FT_Long           num_glyphs;

  FT_String*        family_name;
  FT_String*        style_name;

  FT_Int            num_fixed_sizes;
  #if 0
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
  #endif
} FT_FaceRec;

typedef struct  FT_Open_Args_ {
  FT_UInt         flags;
  const FT_Byte*  memory_base;
  FT_Long         memory_size;
  FT_String*      pathname;
  FT_Stream       stream;
  FT_Module       driver;
  FT_Int          num_params;
  #if 0
  FT_Parameter*   params;
  #endif
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
