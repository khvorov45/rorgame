// Freetype2 pulled out from
// https://github.com/freetype/freetype

#include <stdint.h>
#include <limits.h>

//
// SECTION Macros and constants
//

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

#define FT_CONFIG_OPTION_DISABLE_STREAM_SUPPORT
#define FREETYPE_WONT_INCLUDE 0

#define NULL 0
#define FALSE 0
#define TRUE 1

#define FREETYPE_MAJOR  2
#define FREETYPE_MINOR  12
#define FREETYPE_PATCH  0

#define FT_EXPORT_DEF(x) x

#define FT_FUNCTION_DEFINITION( x )  x
#define FT_BASE_DEF( x )  FT_FUNCTION_DEFINITION( x )
#define FT_CALLBACK_DEF( x )  static  x
#define FT_LOCAL( x )      static x
#define FT_LOCAL_DEF( x )  static x

#define FT_UNUSED( arg )  ( (arg) = (arg) )

#define FT_Err_Ok 0x00

#define FT_Err_Cannot_Open_Resource 0x01
#define FT_Err_Unknown_File_Format 0x02
#define FT_Err_Invalid_File_Format 0x03
#define FT_Err_Invalid_Version 0x04
#define FT_Err_Lower_Module_Version 0x05
#define FT_Err_Invalid_Argument 0x06
#define FT_Err_Unimplemented_Feature 0x07
#define FT_Err_Invalid_Table 0x08
#define FT_Err_Invalid_Offset 0x09
#define FT_Err_Array_Too_Large 0x0A
#define FT_Err_Missing_Module 0x0B
#define FT_Err_Missing_Property 0x0C

  /* glyph/character errors */

#define FT_Err_Invalid_Glyph_Index 0x10
#define FT_Err_Invalid_Character_Code 0x11
#define FT_Err_Invalid_Glyph_Format 0x12
#define FT_Err_Cannot_Render_Glyph 0x13
#define FT_Err_Invalid_Outline 0x14
#define FT_Err_Invalid_Composite 0x15
#define FT_Err_Too_Many_Hints 0x16
#define FT_Err_Invalid_Pixel_Size 0x17
#define FT_Err_Invalid_SVG_Document 0x18

  /* handle errors */

#define FT_Err_Invalid_Handle 0x20
#define FT_Err_Invalid_Library_Handle 0x21
#define FT_Err_Invalid_Driver_Handle 0x22
#define FT_Err_Invalid_Face_Handle 0x23
#define FT_Err_Invalid_Size_Handle 0x24
#define FT_Err_Invalid_Slot_Handle 0x25
#define FT_Err_Invalid_CharMap_Handle 0x26
#define FT_Err_Invalid_Cache_Handle 0x27
#define FT_Err_Invalid_Stream_Handle 0x28

  /* driver errors */

#define FT_Err_Too_Many_Drivers 0x30
#define FT_Err_Too_Many_Extensions 0x31

  /* memory errors */

#define FT_Err_Out_Of_Memory 0x40
#define FT_Err_Unlisted_Object 0x41

  /* stream errors */

#define FT_Err_Cannot_Open_Stream 0x51
#define FT_Err_Invalid_Stream_Seek 0x52
#define FT_Err_Invalid_Stream_Skip 0x53
#define FT_Err_Invalid_Stream_Read 0x54
#define FT_Err_Invalid_Stream_Operation 0x55
#define FT_Err_Invalid_Frame_Operation 0x56
#define FT_Err_Nested_Frame_Access 0x57
#define FT_Err_Invalid_Frame_Read 0x58

  /* raster errors */

#define FT_Err_Raster_Uninitialized 0x60
#define FT_Err_Raster_Corrupted 0x61
#define FT_Err_Raster_Overflow 0x62
#define FT_Err_Raster_Negative_Height 0x63

  /* cache errors */

#define FT_Err_Too_Many_Caches 0x70

  /* TrueType and SFNT errors */

#define FT_Err_Invalid_Opcode 0x80
#define FT_Err_Too_Few_Arguments 0x81
#define FT_Err_Stack_Overflow 0x82
#define FT_Err_Code_Overflow 0x83
#define FT_Err_Bad_Argument 0x84
#define FT_Err_Divide_By_Zero 0x85
#define FT_Err_Invalid_Reference 0x86
#define FT_Err_Debug_OpCode 0x87
#define FT_Err_ENDF_In_Exec_Stream 0x88
#define FT_Err_Nested_DEFS 0x89
#define FT_Err_Invalid_CodeRange 0x8A
#define FT_Err_Execution_Too_Long 0x8B
#define FT_Err_Too_Many_Function_Defs 0x8C
#define FT_Err_Too_Many_Instruction_Defs 0x8D
#define FT_Err_Table_Missing 0x8E
#define FT_Err_Horiz_Header_Missing 0x8F
#define FT_Err_Locations_Missing 0x90
#define FT_Err_Name_Table_Missing 0x91
#define FT_Err_CMap_Table_Missing 0x92
#define FT_Err_Hmtx_Table_Missing 0x93
#define FT_Err_Post_Table_Missing 0x94
#define FT_Err_Invalid_Horiz_Metrics 0x95
#define FT_Err_Invalid_CharMap_Format 0x96
#define FT_Err_Invalid_PPem 0x97
#define FT_Err_Invalid_Vert_Metrics 0x98
#define FT_Err_Could_Not_Find_Context 0x99
#define FT_Err_Invalid_Post_Table_Format 0x9A
#define FT_Err_Invalid_Post_Table 0x9B
#define FT_Err_DEF_In_Glyf_Bytecode 0x9C
#define FT_Err_Missing_Bitmap 0x9D
#define FT_Err_Missing_SVG_Hooks 0x9E

  /* CFF, CID, and Type 1 errors */

#define FT_Err_Syntax_Error 0xA0
#define FT_Err_Stack_Underflow 0xA1
#define FT_Err_Ignore 0xA2
#define FT_Err_No_Unicode_Glyph_Name 0xA3
#define FT_Err_Glyph_Too_Big 0xA4

  /* BDF errors */

#define FT_Err_Missing_Startfont_Field 0xB0
#define FT_Err_Missing_Font_Field 0xB1
#define FT_Err_Missing_Size_Field 0xB2
#define FT_Err_Missing_Fontboundingbox_Field 0xB3
#define FT_Err_Missing_Chars_Field 0xB4
#define FT_Err_Missing_Startchar_Field 0xB5
#define FT_Err_Missing_Encoding_Field 0xB6
#define FT_Err_Missing_Bbx_Field 0xB7
#define FT_Err_Bbx_Too_Big 0xB8
#define FT_Err_Corrupted_Font_Header 0xB9
#define FT_Err_Corrupted_Font_Glyphs 0xBA

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

#define FT_ENC_TAG( value, a, b, c, d )                             \
          value = ( ( FT_STATIC_BYTE_CAST( FT_UInt32, a ) << 24 ) | \
                    ( FT_STATIC_BYTE_CAST( FT_UInt32, b ) << 16 ) | \
                    ( FT_STATIC_BYTE_CAST( FT_UInt32, c ) <<  8 ) | \
                      FT_STATIC_BYTE_CAST( FT_UInt32, d )         )

#define FT_STATIC_CAST( type, var )       (type)(var)
#define FT_BOOL( x ) FT_STATIC_CAST( FT_Bool, (x) != 0 )

#define FT_ASSIGNP( p, val )  (p) = (val)
#define FT_ASSIGNP_INNER( p, exp )  FT_ASSIGNP( p, exp )
#define FT_MEM_ALLOC( ptr, size ) FT_ASSIGNP_INNER( ptr, ft_mem_alloc( memory, (FT_Long)(size), &error ) )
#define FT_MEM_NEW( ptr ) FT_MEM_ALLOC( ptr, sizeof ( *(ptr) ) )
#define FT_MEM_SET_ERROR( cond )  ( (cond), error != 0 )
#define FT_NEW( ptr )  FT_MEM_SET_ERROR( FT_MEM_NEW( ptr ) )
#define FT_MEM_QALLOC( ptr, size ) FT_ASSIGNP_INNER( ptr, ft_mem_qalloc( memory, (FT_Long)(size), &error ) )
#define FT_MEM_QNEW( ptr ) FT_MEM_QALLOC( ptr, sizeof ( *(ptr) ) )
#define FT_QNEW( ptr )  FT_MEM_SET_ERROR( FT_MEM_QNEW( ptr ) )
#define FT_ALLOC( ptr, size ) FT_MEM_SET_ERROR( FT_MEM_ALLOC( ptr, size ) )

#define FT_MEM_SET( dest, byte, count ) ft_memset( dest, byte, (FT_Offset)(count) )
#define FT_MEM_ZERO( dest, count )  FT_MEM_SET( dest, 0, count )

#define FT_ASSERT( condition )  do { } while ( 0 )

#define FT_BEGIN_STMNT  do {
#define FT_END_STMNT    } while ( 0 )

#define FT_DEBUG_INNER( exp ) (exp)

#define FT_MEM_FREE( ptr )                                  \
          FT_BEGIN_STMNT                                    \
            FT_DEBUG_INNER( ft_mem_free( memory, (ptr) ) ); \
            (ptr) = NULL;                                   \
          FT_END_STMNT
#define FT_FREE( ptr )  FT_MEM_FREE( ptr )

#define FT_Raster_Render_Func  FT_Raster_RenderFunc

#define FT_FACE_FLAG_SCALABLE          ( 1L <<  0 )
#define FT_FACE_FLAG_FIXED_SIZES       ( 1L <<  1 )
#define FT_FACE_FLAG_FIXED_WIDTH       ( 1L <<  2 )
#define FT_FACE_FLAG_SFNT              ( 1L <<  3 )
#define FT_FACE_FLAG_HORIZONTAL        ( 1L <<  4 )
#define FT_FACE_FLAG_VERTICAL          ( 1L <<  5 )
#define FT_FACE_FLAG_KERNING           ( 1L <<  6 )
#define FT_FACE_FLAG_FAST_GLYPHS       ( 1L <<  7 )
#define FT_FACE_FLAG_MULTIPLE_MASTERS  ( 1L <<  8 )
#define FT_FACE_FLAG_GLYPH_NAMES       ( 1L <<  9 )
#define FT_FACE_FLAG_EXTERNAL_STREAM   ( 1L << 10 )
#define FT_FACE_FLAG_HINTER            ( 1L << 11 )
#define FT_FACE_FLAG_CID_KEYED         ( 1L << 12 )
#define FT_FACE_FLAG_TRICKY            ( 1L << 13 )
#define FT_FACE_FLAG_COLOR             ( 1L << 14 )
#define FT_FACE_FLAG_VARIATION         ( 1L << 15 )
#define FT_FACE_FLAG_SVG               ( 1L << 16 )
#define FT_FACE_FLAG_SBIX              ( 1L << 17 )
#define FT_FACE_FLAG_SBIX_OVERLAY      ( 1L << 18 )

#define FT_HAS_FIXED_SIZES( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_FIXED_SIZES ) )
#define FT_IS_SCALABLE( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_SCALABLE ) )
#define FT_HAS_VERTICAL( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_VERTICAL ) )

#define FT_DEFINE_ROOT_MODULE(  \
          flags_,               \
          size_,                \
          name_,                \
          version_,             \
          requires_,            \
          interface_,           \
          init_,                \
          done_,                \
          get_interface_ )      \
  {                             \
    flags_,                     \
    size_,                      \
                                \
    name_,                      \
    version_,                   \
    requires_,                  \
                                \
    interface_,                 \
                                \
    init_,                      \
    done_,                      \
    get_interface_,             \
  },

#define FT_CALLBACK_TABLE_DEF  /* nothing */

#define FT_DEFINE_DRIVER(                    \
          class_,                            \
          flags_,                            \
          size_,                             \
          name_,                             \
          version_,                          \
          requires_,                         \
          interface_,                        \
          init_,                             \
          done_,                             \
          get_interface_,                    \
          face_object_size_,                 \
          size_object_size_,                 \
          slot_object_size_,                 \
          init_face_,                        \
          done_face_,                        \
          init_size_,                        \
          done_size_,                        \
          init_slot_,                        \
          done_slot_,                        \
          load_glyph_,                       \
          get_kerning_,                      \
          attach_file_,                      \
          get_advances_,                     \
          request_size_,                     \
          select_size_ )                     \
  FT_CALLBACK_TABLE_DEF                      \
  const FT_Driver_ClassRec  class_ =         \
  {                                          \
    FT_DEFINE_ROOT_MODULE( flags_,           \
                           size_,            \
                           name_,            \
                           version_,         \
                           requires_,        \
                           interface_,       \
                           init_,            \
                           done_,            \
                           get_interface_ )  \
                                             \
    face_object_size_,                       \
    size_object_size_,                       \
    slot_object_size_,                       \
                                             \
    init_face_,                              \
    done_face_,                              \
                                             \
    init_size_,                              \
    done_size_,                              \
                                             \
    init_slot_,                              \
    done_slot_,                              \
                                             \
    load_glyph_,                             \
                                             \
    get_kerning_,                            \
    attach_file_,                            \
    get_advances_,                           \
                                             \
    request_size_,                           \
    select_size_                             \
  };

#define FT_MODULE_FONT_DRIVER         1  /* this module is a font driver  */
#define FT_MODULE_RENDERER            2  /* this module is a renderer     */
#define FT_MODULE_HINTER              4  /* this module is a glyph hinter */
#define FT_MODULE_STYLER              8  /* this module is a styler       */

#define FT_MODULE_DRIVER_SCALABLE      0x100  /* the driver supports      */
                                              /* scalable fonts           */
#define FT_MODULE_DRIVER_NO_OUTLINES   0x200  /* the driver does not      */
                                              /* support vector outlines  */
#define FT_MODULE_DRIVER_HAS_HINTER    0x400  /* the driver provides its  */
                                              /* own hinter               */
#define FT_MODULE_DRIVER_HINTS_LIGHTLY 0x800  /* the driver's hinter      */
                                              /* produces LIGHT hints     */

#define FT_MODULE( x )  ( (FT_Module)(x) )

#define FT_MODULE_CLASS( x )    FT_MODULE( x )->clazz
#define FT_MODULE_LIBRARY( x )  FT_MODULE( x )->library
#define FT_MODULE_MEMORY( x )   FT_MODULE( x )->memory

#define FT_MODULE_IS_DRIVER( x )  ( FT_MODULE_CLASS( x )->module_flags & FT_MODULE_FONT_DRIVER )
#define FT_MODULE_IS_RENDERER( x )  ( FT_MODULE_CLASS( x )->module_flags & FT_MODULE_RENDERER )
#define FT_MODULE_IS_HINTER( x )  ( FT_MODULE_CLASS( x )->module_flags & FT_MODULE_HINTER )
#define FT_MODULE_IS_STYLER( x )  ( FT_MODULE_CLASS( x )->module_flags & FT_MODULE_STYLER )
#define FT_DRIVER_IS_SCALABLE( x )  ( FT_MODULE_CLASS( x )->module_flags & FT_MODULE_DRIVER_SCALABLE )
#define FT_DRIVER_USES_OUTLINES( x )  !( FT_MODULE_CLASS( x )->module_flags &  FT_MODULE_DRIVER_NO_OUTLINES )
#define FT_DRIVER_HAS_HINTER( x )  ( FT_MODULE_CLASS( x )->module_flags & FT_MODULE_DRIVER_HAS_HINTER )
#define FT_DRIVER_HINTS_LIGHTLY( x )  ( FT_MODULE_CLASS( x )->module_flags & FT_MODULE_DRIVER_HINTS_LIGHTLY )

#define FT_USE_MODULE( type, x )  (const FT_Module_Class*)&(x),

#define FT_RENDERER( x )       ( (FT_Renderer)(x) )
#define FT_GLYPH( x )          ( (FT_Glyph)(x) )
#define FT_BITMAP_GLYPH( x )   ( (FT_BitmapGlyph)(x) )
#define FT_OUTLINE_GLYPH( x )  ( (FT_OutlineGlyph)(x) )

#define FT_DRIVER( x )  ( (FT_Driver)(x) )
#define FT_DRIVER_CLASS( x )  FT_DRIVER( x )->clazz

#define FREETYPE_VER_FIXED (((FT_Long)FREETYPE_MAJOR << 16 ) | FREETYPE_MINOR)

#define FT_MIN( a, b )  ( (a) < (b) ? (a) : (b) )
#define FT_MAX( a, b )  ( (a) > (b) ? (a) : (b) )

#define FT_ABS( a )     ( (a) < 0 ? -(a) : (a) )

  /*
   * Approximate sqrt(x*x+y*y) using the `alpha max plus beta min' algorithm.
   * We use alpha = 1, beta = 3/8, giving us results with a largest error
   * less than 7% compared to the exact value.
   */
#define FT_HYPOT( x, y )                 \
          ( x = FT_ABS( x ),             \
            y = FT_ABS( y ),             \
            x > y ? x + ( 3 * y >> 3 )   \
                  : y + ( 3 * x >> 3 ) )

#define FT_TYPEOF( type )  /* empty */

/* we use FT_TYPEOF to suppress signedness compilation warnings */
#define FT_PAD_FLOOR( x, n )  ( (x) & ~FT_TYPEOF( x )( (n) - 1 ) )
#define FT_PAD_ROUND( x, n )  FT_PAD_FLOOR( (x) + (n) / 2, n )
#define FT_PAD_CEIL( x, n )   FT_PAD_FLOOR( (x) + (n) - 1, n )

#define FT_PIX_FLOOR( x )     ( (x) & ~FT_TYPEOF( x )63 )
#define FT_PIX_ROUND( x )     FT_PIX_FLOOR( (x) + 32 )
#define FT_PIX_CEIL( x )      FT_PIX_FLOOR( (x) + 63 )

/* specialized versions (for signed values)                   */
/* that don't produce run-time errors due to integer overflow */
#define FT_PAD_ROUND_LONG( x, n )  FT_PAD_FLOOR( ADD_LONG( (x), (n) / 2 ), \
                                                 n )
#define FT_PAD_CEIL_LONG( x, n )   FT_PAD_FLOOR( ADD_LONG( (x), (n) - 1 ), \
                                                 n )
#define FT_PIX_ROUND_LONG( x )     FT_PIX_FLOOR( ADD_LONG( (x), 32 ) )
#define FT_PIX_CEIL_LONG( x )      FT_PIX_FLOOR( ADD_LONG( (x), 63 ) )

#define FT_PAD_ROUND_INT32( x, n )  FT_PAD_FLOOR( ADD_INT32( (x), (n) / 2 ), \
                                                  n )
#define FT_PAD_CEIL_INT32( x, n )   FT_PAD_FLOOR( ADD_INT32( (x), (n) - 1 ), \
                                                  n )
#define FT_PIX_ROUND_INT32( x )     FT_PIX_FLOOR( ADD_INT32( (x), 32 ) )
#define FT_PIX_CEIL_INT32( x )      FT_PIX_FLOOR( ADD_INT32( (x), 63 ) )

#define FT_MOVE_SIGN( x, x_unsigned, s ) \
  FT_BEGIN_STMNT                         \
    if ( x < 0 )                         \
    {                                    \
      x_unsigned = 0U - (x_unsigned);    \
      s          = -s;                   \
    }                                    \
  FT_END_STMNT

#define NEG_LONG( a ) (FT_Long)( (FT_ULong)0 - (FT_ULong)(a) )

#define FT_LOAD_DEFAULT                      0x0
#define FT_LOAD_NO_SCALE                     ( 1L << 0  )
#define FT_LOAD_NO_HINTING                   ( 1L << 1  )
#define FT_LOAD_RENDER                       ( 1L << 2  )
#define FT_LOAD_NO_BITMAP                    ( 1L << 3  )
#define FT_LOAD_VERTICAL_LAYOUT              ( 1L << 4  )
#define FT_LOAD_FORCE_AUTOHINT               ( 1L << 5  )
#define FT_LOAD_CROP_BITMAP                  ( 1L << 6  )
#define FT_LOAD_PEDANTIC                     ( 1L << 7  )
#define FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH  ( 1L << 9  )
#define FT_LOAD_NO_RECURSE                   ( 1L << 10 )
#define FT_LOAD_IGNORE_TRANSFORM             ( 1L << 11 )
#define FT_LOAD_MONOCHROME                   ( 1L << 12 )
#define FT_LOAD_LINEAR_DESIGN                ( 1L << 13 )
#define FT_LOAD_SBITS_ONLY                   ( 1L << 14 )
#define FT_LOAD_NO_AUTOHINT                  ( 1L << 15 )

#define FT_LOAD_COLOR                        ( 1L << 20 )
#define FT_LOAD_COMPUTE_METRICS              ( 1L << 21 )
#define FT_LOAD_BITMAP_METRICS_ONLY          ( 1L << 22 )
#define FT_LOAD_ADVANCE_ONLY                 ( 1L << 8  )
#define FT_LOAD_SVG_ONLY                     ( 1L << 23 )

#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#define TT_SIZE_SELECT  tt_size_select
#else
#define TT_SIZE_SELECT  0
#endif

#ifdef TT_USE_BYTECODE_INTERPRETER
#define TT_HINTER_FLAG  FT_MODULE_DRIVER_HAS_HINTER
#else
#define TT_HINTER_FLAG  0
#endif

#define TT_MAX_CODE_RANGES  3

//
// SECTION Types
//

typedef uint32_t FT_UInt32;
typedef uint64_t FT_UInt64;
typedef int32_t FT_Int32;
typedef int64_t FT_Int64;
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
typedef struct FT_ListRec_*  FT_List;

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

typedef struct FT_UnitVector_ {
  FT_F2Dot14  x;
  FT_F2Dot14  y;
} FT_UnitVector;

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

typedef struct  FT_Color_ {
  FT_Byte  blue;
  FT_Byte  green;
  FT_Byte  red;
  FT_Byte  alpha;
} FT_Color;

typedef void
(*FT_List_Destructor)( FT_Memory  memory,
                       void*      data,
                       void*      user );

//
// SECTION Types (truetype)
//

typedef FT_GlyphSlot TT_GlyphSlot;

typedef enum TT_SbitTableType_
{
  TT_SBIT_TABLE_TYPE_NONE = 0,
  TT_SBIT_TABLE_TYPE_EBLC, /* `EBLC' (Microsoft), */
                           /* `bloc' (Apple)      */
  TT_SBIT_TABLE_TYPE_CBLC, /* `CBLC' (Google)     */
  TT_SBIT_TABLE_TYPE_SBIX, /* `sbix' (Apple)      */
  /* do not remove */
  TT_SBIT_TABLE_TYPE_MAX
} TT_SbitTableType;

typedef FT_Error
(*TT_Interpreter)( void*  exec_context );

typedef struct FT_Palette_Data_ {
  FT_UShort         num_palettes;
  const FT_UShort*  palette_name_ids;
  const FT_UShort*  palette_flags;
  FT_UShort         num_palette_entries;
  const FT_UShort*  palette_entry_name_ids;
} FT_Palette_Data;

typedef struct TT_Post_20Rec_ {
  FT_UShort   num_glyphs;
  FT_UShort   num_names;
  FT_UShort*  glyph_indices;
  FT_Char**   glyph_names;
} TT_Post_20Rec, *TT_Post_20;

typedef struct TT_Post_25_ {
  FT_UShort  num_glyphs;
  FT_Char*   offsets;

} TT_Post_25Rec, *TT_Post_25;

typedef struct TT_Post_NamesRec_ {
  FT_Bool  loaded;
  union
  {
    TT_Post_20Rec  format_20;
    TT_Post_25Rec  format_25;
  } names;
} TT_Post_NamesRec, *TT_Post_Names;

typedef struct TT_SBit_LineMetricsRec_ {
  FT_Char  ascender;
  FT_Char  descender;
  FT_Byte  max_width;
  FT_Char  caret_slope_numerator;
  FT_Char  caret_slope_denominator;
  FT_Char  caret_offset;
  FT_Char  min_origin_SB;
  FT_Char  min_advance_SB;
  FT_Char  max_before_BL;
  FT_Char  min_after_BL;
  FT_Char  pads[2];
} TT_SBit_LineMetricsRec, *TT_SBit_LineMetrics;

typedef struct TT_SBit_ScaleRec_ {
  TT_SBit_LineMetricsRec  hori;
  TT_SBit_LineMetricsRec  vert;
  FT_Byte                 x_ppem;
  FT_Byte                 y_ppem;
  FT_Byte                 x_ppem_substitute;
  FT_Byte                 y_ppem_substitute;
} TT_SBit_ScaleRec, *TT_SBit_Scale;

typedef struct TT_PCLT_ {
  FT_Fixed   Version;
  FT_ULong   FontNumber;
  FT_UShort  Pitch;
  FT_UShort  xHeight;
  FT_UShort  Style;
  FT_UShort  TypeFamily;
  FT_UShort  CapHeight;
  FT_UShort  SymbolSet;
  FT_Char    TypeFace[16];
  FT_Char    CharacterComplement[8];
  FT_Char    FileName[6];
  FT_Char    StrokeWeight;
  FT_Char    WidthType;
  FT_Byte    SerifStyle;
  FT_Byte    Reserved;
} TT_PCLT;

typedef struct TT_GaspRangeRec_ {
  FT_UShort  maxPPEM;
  FT_UShort  gaspFlag;
} TT_GaspRangeRec, *TT_GaspRange;

typedef struct TT_Gasp_ {
  FT_UShort     version;
  FT_UShort     numRanges;
  TT_GaspRange  gaspRanges;
} TT_GaspRec;

typedef struct TT_CodeRange_ {
  FT_Byte*  base;
  FT_Long   size;
} TT_CodeRange;
typedef TT_CodeRange  TT_CodeRangeTable[TT_MAX_CODE_RANGES];

typedef struct TT_DefRecord_ {
  FT_Int    range;          /* in which code range is it located?     */
  FT_Long   start;          /* where does it start?                   */
  FT_Long   end;            /* where does it end?                     */
  FT_UInt   opc;            /* function #, or instruction code        */
  FT_Bool   active;         /* is it active?                          */
  FT_Bool   inline_delta;   /* is function that defines inline delta? */
  FT_ULong  sph_fdef_flags; /* flags to identify special functions    */
} TT_DefRecord, *TT_DefArray;

typedef struct TT_CallRec_ {
  FT_Int   Caller_Range;
  FT_Long  Caller_IP;
  FT_Long  Cur_Count;
  TT_DefRecord  *Def; /* either FDEF or IDEF */
} TT_CallRec, *TT_CallStack;

typedef struct TT_GlyphZoneRec_ {
  FT_Memory   memory;
  FT_UShort   max_points;
  FT_Short    max_contours;
  FT_UShort   n_points;    /* number of points in zone    */
  FT_Short    n_contours;  /* number of contours          */

  FT_Vector*  org;         /* original point coordinates  */
  FT_Vector*  cur;         /* current point coordinates   */
  FT_Vector*  orus;        /* original (unscaled) point coordinates */

  FT_Byte*    tags;        /* current touch flags         */
  FT_UShort*  contours;    /* contour end points          */

  FT_UShort   first_point; /* offset of first (#0) point  */
} TT_GlyphZoneRec, *TT_GlyphZone;

typedef struct TT_DriverRec_ {
  FT_DriverRec  root;
  TT_GlyphZoneRec  zone;     /* glyph loader points zone */
  FT_UInt  interpreter_version;
} TT_DriverRec;

typedef struct TTC_HeaderRec_ {
  FT_ULong   tag;
  FT_Fixed   version;
  FT_Long    count;
  FT_ULong*  offsets;
} TTC_HeaderRec;

typedef struct TT_TableRec_ {
  FT_ULong  Tag;        /*        table type */
  FT_ULong  CheckSum;   /*    table checksum */
  FT_ULong  Offset;     /* table file offset */
  FT_ULong  Length;     /*      table length */
} TT_TableRec, *TT_Table;

typedef struct TT_Header_ {
  FT_Fixed   Table_Version;
  FT_Fixed   Font_Revision;

  FT_Long    CheckSum_Adjust;
  FT_Long    Magic_Number;

  FT_UShort  Flags;
  FT_UShort  Units_Per_EM;

  FT_ULong   Created [2];
  FT_ULong   Modified[2];

  FT_Short   xMin;
  FT_Short   yMin;
  FT_Short   xMax;
  FT_Short   yMax;

  FT_UShort  Mac_Style;
  FT_UShort  Lowest_Rec_PPEM;

  FT_Short   Font_Direction;
  FT_Short   Index_To_Loc_Format;
  FT_Short   Glyph_Data_Format;
} TT_Header;

typedef struct TT_HoriHeader_ {
  FT_Fixed   Version;
  FT_Short   Ascender;
  FT_Short   Descender;
  FT_Short   Line_Gap;

  FT_UShort  advance_Width_Max;      /* advance width maximum */

  FT_Short   min_Left_Side_Bearing;  /* minimum left-sb       */
  FT_Short   min_Right_Side_Bearing; /* minimum right-sb      */
  FT_Short   xMax_Extent;            /* xmax extents          */
  FT_Short   caret_Slope_Rise;
  FT_Short   caret_Slope_Run;
  FT_Short   caret_Offset;

  FT_Short   Reserved[4];

  FT_Short   metric_Data_Format;
  FT_UShort  number_Of_HMetrics;

  /* The following fields are not defined by the OpenType specification */
  /* but they are used to connect the metrics header to the relevant    */
  /* 'hmtx' table.                                                      */

  void*      long_metrics;
  void*      short_metrics;
} TT_HoriHeader;

typedef struct TT_MaxProfile_ {
  FT_Fixed   version;
  FT_UShort  numGlyphs;
  FT_UShort  maxPoints;
  FT_UShort  maxContours;
  FT_UShort  maxCompositePoints;
  FT_UShort  maxCompositeContours;
  FT_UShort  maxZones;
  FT_UShort  maxTwilightPoints;
  FT_UShort  maxStorage;
  FT_UShort  maxFunctionDefs;
  FT_UShort  maxInstructionDefs;
  FT_UShort  maxStackElements;
  FT_UShort  maxSizeOfInstructions;
  FT_UShort  maxComponentElements;
  FT_UShort  maxComponentDepth;
} TT_MaxProfile;

typedef struct TT_VertHeader_ {
  FT_Fixed   Version;
  FT_Short   Ascender;
  FT_Short   Descender;
  FT_Short   Line_Gap;

  FT_UShort  advance_Height_Max;      /* advance height maximum */

  FT_Short   min_Top_Side_Bearing;    /* minimum top-sb          */
  FT_Short   min_Bottom_Side_Bearing; /* minimum bottom-sb       */
  FT_Short   yMax_Extent;             /* ymax extents            */
  FT_Short   caret_Slope_Rise;
  FT_Short   caret_Slope_Run;
  FT_Short   caret_Offset;

  FT_Short   Reserved[4];

  FT_Short   metric_Data_Format;
  FT_UShort  number_Of_VMetrics;

  /* The following fields are not defined by the OpenType specification */
  /* but they are used to connect the metrics header to the relevant    */
  /* 'vmtx' table.                                                      */

  void*      long_metrics;
  void*      short_metrics;
} TT_VertHeader;

typedef struct TT_LangTagRec_
{
  FT_UShort  stringLength;
  FT_ULong   stringOffset;

  /* this last field is not defined in the spec */
  /* but used by the FreeType engine            */

  FT_Byte*  string;
} TT_LangTagRec, *TT_LangTag;

typedef struct TT_NameRec_ {
  FT_UShort  platformID;
  FT_UShort  encodingID;
  FT_UShort  languageID;
  FT_UShort  nameID;
  FT_UShort  stringLength;
  FT_ULong   stringOffset;

  /* this last field is not defined in the spec */
  /* but used by the FreeType engine            */

  FT_Byte*  string;
} TT_NameRec, *TT_Name;

typedef struct TT_NameTableRec_ {
  FT_UShort       format;
  FT_UInt         numNameRecords;
  FT_UInt         storageOffset;
  TT_NameRec*     names;
  FT_UInt         numLangTagRecords;
  TT_LangTagRec*  langTags;
  FT_Stream       stream;
} TT_NameTableRec, *TT_NameTable;

typedef struct TT_OS2_ {
  FT_UShort  version;                /* 0x0001 - more or 0xFFFF */
  FT_Short   xAvgCharWidth;
  FT_UShort  usWeightClass;
  FT_UShort  usWidthClass;
  FT_UShort  fsType;
  FT_Short   ySubscriptXSize;
  FT_Short   ySubscriptYSize;
  FT_Short   ySubscriptXOffset;
  FT_Short   ySubscriptYOffset;
  FT_Short   ySuperscriptXSize;
  FT_Short   ySuperscriptYSize;
  FT_Short   ySuperscriptXOffset;
  FT_Short   ySuperscriptYOffset;
  FT_Short   yStrikeoutSize;
  FT_Short   yStrikeoutPosition;
  FT_Short   sFamilyClass;

  FT_Byte    panose[10];

  FT_ULong   ulUnicodeRange1;        /* Bits 0-31   */
  FT_ULong   ulUnicodeRange2;        /* Bits 32-63  */
  FT_ULong   ulUnicodeRange3;        /* Bits 64-95  */
  FT_ULong   ulUnicodeRange4;        /* Bits 96-127 */

  FT_Char    achVendID[4];

  FT_UShort  fsSelection;
  FT_UShort  usFirstCharIndex;
  FT_UShort  usLastCharIndex;
  FT_Short   sTypoAscender;
  FT_Short   sTypoDescender;
  FT_Short   sTypoLineGap;
  FT_UShort  usWinAscent;
  FT_UShort  usWinDescent;

  /* only version 1 and higher: */

  FT_ULong   ulCodePageRange1;       /* Bits 0-31   */
  FT_ULong   ulCodePageRange2;       /* Bits 32-63  */

  /* only version 2 and higher: */

  FT_Short   sxHeight;
  FT_Short   sCapHeight;
  FT_UShort  usDefaultChar;
  FT_UShort  usBreakChar;
  FT_UShort  usMaxContext;

  /* only version 5 and higher: */

  FT_UShort  usLowerOpticalPointSize;       /* in twips (1/20th points) */
  FT_UShort  usUpperOpticalPointSize;       /* in twips (1/20th points) */
} TT_OS2;

typedef struct TT_Postscript_ {
  FT_Fixed  FormatType;
  FT_Fixed  italicAngle;
  FT_Short  underlinePosition;
  FT_Short  underlineThickness;
  FT_ULong  isFixedPitch;
  FT_ULong  minMemType42;
  FT_ULong  maxMemType42;
  FT_ULong  minMemType1;
  FT_ULong  maxMemType1;
  /* Glyph names follow in the 'post' table, but we don't */
  /* load them by default.                                */
} TT_Postscript;

typedef struct TT_FaceRec_* TT_Face;

typedef FT_Error
(*TT_Loader_GotoTableFunc)( TT_Face    face,
                            FT_ULong   tag,
                            FT_Stream  stream,
                            FT_ULong*  length );

typedef struct TT_Size_Metrics_ {
  /* for non-square pixels */
  FT_Long     x_ratio;
  FT_Long     y_ratio;

  FT_UShort   ppem;               /* maximum ppem size              */
  FT_Long     ratio;              /* current ratio                  */
  FT_Fixed    scale;

  FT_F26Dot6  compensations[4];   /* device-specific compensations  */

  FT_Bool     valid;

  FT_Bool     rotated;            /* `is the glyph rotated?'-flag   */
  FT_Bool     stretched;          /* `is the glyph stretched?'-flag */
} TT_Size_Metrics;

typedef struct TT_SizeRec_*  TT_Size;

typedef struct TT_GraphicsState_ {
  FT_UShort      rp0;
  FT_UShort      rp1;
  FT_UShort      rp2;

  FT_UnitVector  dualVector;
  FT_UnitVector  projVector;
  FT_UnitVector  freeVector;

  FT_Long        loop;
  FT_F26Dot6     minimum_distance;
  FT_Int         round_state;

  FT_Bool        auto_flip;
  FT_F26Dot6     control_value_cutin;
  FT_F26Dot6     single_width_cutin;
  FT_F26Dot6     single_width_value;
  FT_UShort      delta_base;
  FT_UShort      delta_shift;

  FT_Byte        instruct_control;
  /* According to Greg Hitchcock from Microsoft, the `scan_control'     */
  /* variable as documented in the TrueType specification is a 32-bit   */
  /* integer; the high-word part holds the SCANTYPE value, the low-word */
  /* part the SCANCTRL value.  We separate it into two fields.          */
  FT_Bool        scan_control;
  FT_Int         scan_type;

  FT_UShort      gep0;
  FT_UShort      gep1;
  FT_UShort      gep2;
} TT_GraphicsState;

typedef struct TT_ExecContextRec_*  TT_ExecContext;

typedef FT_F26Dot6
(*TT_Round_Func)( TT_ExecContext  exc,
                  FT_F26Dot6      distance,
                  FT_Int          color );

typedef void
(*TT_Move_Func)( TT_ExecContext  exc,
                 TT_GlyphZone    zone,
                 FT_UShort       point,
                 FT_F26Dot6      distance );

typedef FT_F26Dot6
(*TT_Project_Func)( TT_ExecContext  exc,
                    FT_Pos          dx,
                    FT_Pos          dy );

typedef FT_Long
(*TT_Cur_Ppem_Func)( TT_ExecContext  exc );

typedef FT_F26Dot6
(*TT_Get_CVT_Func)( TT_ExecContext  exc,
                    FT_ULong        idx );

typedef void
(*TT_Set_CVT_Func)( TT_ExecContext  exc,
                    FT_ULong        idx,
                    FT_F26Dot6      value );

typedef struct TT_ExecContextRec_ {
  TT_Face            face;       /* ! */
  TT_Size            size;       /* ! */
  FT_Memory          memory;

  /* instructions state */

  FT_Error           error;      /* last execution error */

  FT_Long            top;        /* @ top of exec. stack */

  FT_Long            stackSize;  /* ! size of exec. stack */
  FT_Long*           stack;      /* ! current exec. stack */

  FT_Long            args;
  FT_Long            new_top;    /* new top after exec. */

  TT_GlyphZoneRec    zp0,        /* @! zone records */
                     zp1,        /* @!              */
                     zp2,        /* @!              */
                     pts,        /*  !              */
                     twilight;   /*  !              */

  FT_Long            pointSize;  /* ! in 26.6 format */
  FT_Size_Metrics    metrics;    /* !                */
  TT_Size_Metrics    tt_metrics; /* ! size metrics   */

  TT_GraphicsState   GS;         /* !@ current graphics state */

  FT_Int             iniRange;  /* initial code range number   */
  FT_Int             curRange;  /* current code range number   */
  FT_Byte*           code;      /* current code range          */
  FT_Long            IP;        /* current instruction pointer */
  FT_Long            codeSize;  /* size of current range       */

  FT_Byte            opcode;    /* current opcode              */
  FT_Int             length;    /* length of current opcode    */

  FT_Bool            step_ins;  /* true if the interpreter must */
                                /* increment IP after ins. exec */
  FT_ULong           cvtSize;   /* ! */
  FT_Long*           cvt;       /* ! */
  FT_ULong           glyfCvtSize;
  FT_Long*           glyfCvt;   /* cvt working copy for glyph */
  FT_Long*           origCvt;

  FT_UInt            glyphSize; /* ! glyph instructions buffer size */
  FT_Byte*           glyphIns;  /* ! glyph instructions buffer      */

  FT_UInt            numFDefs;  /* ! number of function defs         */
  FT_UInt            maxFDefs;  /* ! maximum number of function defs */
  TT_DefArray        FDefs;     /*   table of FDefs entries          */

  FT_UInt            numIDefs;  /* ! number of instruction defs */
  FT_UInt            maxIDefs;  /* ! maximum number of ins defs */
  TT_DefArray        IDefs;     /*   table of IDefs entries     */

  FT_UInt            maxFunc;   /* ! maximum function index    */
  FT_UInt            maxIns;    /* ! maximum instruction index */

  FT_Int             callTop,    /* @ top of call stack during execution */
                     callSize;   /*   size of call stack                 */
  TT_CallStack       callStack;  /*   call stack                         */

  FT_UShort          maxPoints;    /* capacity of this context's `pts' */
  FT_Short           maxContours;  /* record, expressed in points and  */
                                   /* contours.                        */

  TT_CodeRangeTable  codeRangeTable;  /* ! table of valid code ranges */
                                      /*   useful for the debugger    */

  FT_UShort          storeSize;    /* ! size of current storage */
  FT_Long*           storage;      /* ! storage area            */
  FT_UShort          glyfStoreSize;
  FT_Long*           glyfStorage;  /* storage working copy for glyph */
  FT_Long*           origStorage;

  FT_F26Dot6         period;     /* values used for the */
  FT_F26Dot6         phase;      /* `SuperRounding'     */
  FT_F26Dot6         threshold;

  FT_Bool            instruction_trap; /* ! If `True', the interpreter   */
                                       /*   exits after each instruction */

  TT_GraphicsState   default_GS;       /* graphics state resulting from   */
                                       /* the prep program                */
  FT_Bool            is_composite;     /* true if the glyph is composite  */
  FT_Bool            pedantic_hinting; /* true if pedantic interpretation */

  /* latest interpreter additions */

  FT_Long            F_dot_P;    /* dot product of freedom and projection */
                                 /* vectors                               */
  TT_Round_Func      func_round; /* current rounding function             */

  TT_Project_Func    func_project,   /* current projection function */
                     func_dualproj,  /* current dual proj. function */
                     func_freeProj;  /* current freedom proj. func  */

  TT_Move_Func       func_move;      /* current point move function     */
  TT_Move_Func       func_move_orig; /* move original position function */

  TT_Cur_Ppem_Func   func_cur_ppem;  /* get current proj. ppem value  */

  TT_Get_CVT_Func    func_read_cvt;  /* read a cvt entry              */
  TT_Set_CVT_Func    func_write_cvt; /* write a cvt entry (in pixels) */
  TT_Set_CVT_Func    func_move_cvt;  /* incr a cvt entry (in pixels)  */

  FT_Bool            grayscale;      /* bi-level hinting and */
                                     /* grayscale rendering  */

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL

  FT_Bool            subpixel_hinting_lean;
  FT_Bool            vertical_lcd_lean;
  FT_Bool            backward_compatibility;
  FT_Bool            iupx_called;
  FT_Bool            iupy_called;
  FT_Bool            grayscale_cleartype;
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL */

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
  TT_Round_Func      func_round_sphn;   /* subpixel rounding function */

  FT_Bool            subpixel_hinting;  /* Using subpixel hinting?       */
  FT_Bool            ignore_x_mode;     /* Standard rendering mode for   */
                                        /* subpixel hinting.  On if gray */
                                        /* or subpixel hinting is on.    */

  /* The following 6 aren't fully implemented but here for MS rasterizer */
  /* compatibility.                                                      */
  FT_Bool            compatible_widths;     /* compatible widths?        */
  FT_Bool            symmetrical_smoothing; /* symmetrical_smoothing?    */
  FT_Bool            bgr;                   /* bgr instead of rgb?       */
  FT_Bool            vertical_lcd;          /* long side of LCD subpixel */
                                            /* rectangles is horizontal  */
  FT_Bool            subpixel_positioned;   /* subpixel positioned       */
                                            /* (DirectWrite ClearType)?  */
  FT_Bool            gray_cleartype;        /* ClearType hinting but     */
                                            /* grayscale rendering       */

  FT_Int             rasterizer_version;    /* MS rasterizer version     */

  FT_Bool            iup_called;            /* IUP called for glyph?     */

  FT_ULong           sph_tweak_flags;       /* flags to control          */
                                            /* hint tweaks               */

  FT_ULong           sph_in_func_flags;     /* flags to indicate if in   */
                                            /* special functions         */

#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */

  /* We maintain two counters (in addition to the instruction counter) */
  /* that act as loop detectors for LOOPCALL and jump opcodes with     */
  /* negative arguments.                                               */
  FT_ULong           loopcall_counter;
  FT_ULong           loopcall_counter_max;
  FT_ULong           neg_jump_counter;
  FT_ULong           neg_jump_counter_max;
} TT_ExecContextRec;
typedef struct TT_ExecContextRec_*  TT_ExecContext;

typedef struct TT_LoaderRec_ {
  TT_Face          face;
  TT_Size          size;
  FT_GlyphSlot     glyph;
  FT_GlyphLoader   gloader;

  FT_ULong         load_flags;
  FT_UInt          glyph_index;

  FT_Stream        stream;
  FT_UInt          byte_len;

  FT_Short         n_contours;
  FT_BBox          bbox;
  FT_Int           left_bearing;
  FT_Int           advance;
  FT_Int           linear;
  FT_Bool          linear_def;
  FT_Vector        pp1;
  FT_Vector        pp2;

  /* the zone where we load our glyphs */
  TT_GlyphZoneRec  base;
  TT_GlyphZoneRec  zone;

  TT_ExecContext   exec;
  FT_Byte*         instructions;
  FT_ULong         ins_pos;

  /* for possible extensibility in other formats */
  void*            other;

  /* since version 2.1.8 */
  FT_Int           top_bearing;
  FT_Int           vadvance;
  FT_Vector        pp3;
  FT_Vector        pp4;

  /* since version 2.2.1 */
  FT_Byte*         cursor;
  FT_Byte*         limit;

  /* since version 2.6.2 */
  FT_ListRec       composites;

  /* since version 2.11.2 */
  FT_Byte*         widthp;

} TT_LoaderRec;
typedef struct TT_LoaderRec_*  TT_Loader;

typedef FT_Error
(*TT_Loader_StartGlyphFunc)( TT_Loader  loader,
                             FT_UInt    glyph_index,
                             FT_ULong   offset,
                             FT_UInt    byte_count );

typedef void
(*TT_Loader_EndGlyphFunc)( TT_Loader  loader );

typedef FT_Error
(*TT_Loader_ReadGlyphFunc)( TT_Loader  loader );

typedef struct TT_FaceRec_ {
  FT_FaceRec            root;
  TTC_HeaderRec         ttc_header;

  FT_ULong              format_tag;
  FT_UShort             num_tables;
  TT_Table              dir_tables;

  TT_Header             header;       /* TrueType header table          */
  TT_HoriHeader         horizontal;   /* TrueType horizontal header     */

  TT_MaxProfile         max_profile;

  FT_Bool               vertical_info;
  TT_VertHeader         vertical;     /* TT Vertical header, if present */

  FT_UShort             num_names;    /* number of name records  */
  TT_NameTableRec       name_table;   /* name table              */

  TT_OS2                os2;          /* TrueType OS/2 table            */
  TT_Postscript         postscript;   /* TrueType Postscript table      */

  FT_Byte*              cmap_table;   /* extracted `cmap' table */
  FT_ULong              cmap_size;

  TT_Loader_GotoTableFunc   goto_table;

  TT_Loader_StartGlyphFunc  access_glyph_frame;
  TT_Loader_EndGlyphFunc    forget_glyph_frame;
  TT_Loader_ReadGlyphFunc   read_glyph_header;
  TT_Loader_ReadGlyphFunc   read_simple_glyph;
  TT_Loader_ReadGlyphFunc   read_composite_glyph;

  /* a typeless pointer to the SFNT_Interface table used to load */
  /* the basic TrueType tables in the face object                */
  void*                 sfnt;

  /* a typeless pointer to the FT_Service_PsCMapsRec table used to */
  /* handle glyph names <-> unicode & Mac values                   */
  void*                 psnames;

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
  /* a typeless pointer to the FT_Service_MultiMasters table used to */
  /* handle variation fonts                                          */
  void*                 mm;

  /* a typeless pointer to the FT_Service_MetricsVariationsRec table */
  /* used to handle the HVAR, VVAR, and MVAR OpenType tables         */
  void*                 var;
#endif

  /* a typeless pointer to the PostScript Aux service */
  void*                 psaux;


  /************************************************************************
   *
   * Optional TrueType/OpenType tables
   *
   */

  /* grid-fitting and scaling table */
  TT_GaspRec            gasp;                 /* the `gasp' table */

  /* PCL 5 table */
  TT_PCLT               pclt;

  /* embedded bitmaps support */
  FT_ULong              num_sbit_scales;
  TT_SBit_Scale         sbit_scales;

  /* postscript names table */
  TT_Post_NamesRec      postscript_names;

  /* glyph colors */
  FT_Palette_Data       palette_data;         /* since 2.10 */
  FT_UShort             palette_index;
  FT_Color*             palette;
  FT_Bool               have_foreground_color;
  FT_Color              foreground_color;


  /************************************************************************
   *
   * TrueType-specific fields (ignored by the CFF driver)
   *
   */

  /* the font program, if any */
  FT_ULong              font_program_size;
  FT_Byte*              font_program;

  /* the cvt program, if any */
  FT_ULong              cvt_program_size;
  FT_Byte*              cvt_program;

  /* the original, unscaled, control value table */
  FT_ULong              cvt_size;
  FT_Int32*             cvt;

  /* A pointer to the bytecode interpreter to use.  This is also */
  /* used to hook the debugger for the `ttdebug' utility.        */
  TT_Interpreter        interpreter;


  /************************************************************************
   *
   * Other tables or fields. This is used by derivative formats like
   * OpenType.
   *
   */

  FT_Generic            extra;

  const char*           postscript_name;

  FT_ULong              glyf_len;
  FT_ULong              glyf_offset;    /* since 2.7.1 */

  FT_Bool               is_cff2;        /* since 2.7.1 */

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
  FT_Bool               doblend;
  GX_Blend              blend;

  FT_UInt32             variation_support;     /* since 2.7.1 */

  const char*           var_postscript_prefix;     /* since 2.7.2 */
  FT_UInt               var_postscript_prefix_len; /* since 2.7.2 */

#endif

  /* since version 2.2 */

  FT_ULong              horz_metrics_size;
  FT_ULong              vert_metrics_size;

  FT_ULong              num_locations; /* up to 0xFFFF + 1 */
  FT_Byte*              glyph_locations;

  FT_Byte*              hdmx_table;
  FT_ULong              hdmx_table_size;
  FT_UInt               hdmx_record_count;
  FT_ULong              hdmx_record_size;
  FT_Byte**             hdmx_records;

  FT_Byte*              sbit_table;
  FT_ULong              sbit_table_size;
  TT_SbitTableType      sbit_table_type;
  FT_UInt               sbit_num_strikes;
  FT_UInt*              sbit_strike_map;

  FT_Byte*              kern_table;
  FT_ULong              kern_table_size;
  FT_UInt               num_kern_tables;
  FT_UInt32             kern_avail_bits;
  FT_UInt32             kern_order_bits;

#ifdef TT_CONFIG_OPTION_BDF
  TT_BDFRec             bdf;
#endif /* TT_CONFIG_OPTION_BDF */

  /* since 2.3.0 */
  FT_ULong              horz_metrics_offset;
  FT_ULong              vert_metrics_offset;

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
  /* since 2.4.12 */
  FT_ULong              sph_found_func_flags; /* special functions found */
                                              /* for this face           */
  FT_Bool               sph_compatibility_mode;
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */

#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
  /* since 2.7 */
  FT_ULong              ebdt_start;  /* either `CBDT', `EBDT', or `bdat' */
  FT_ULong              ebdt_size;
#endif

  /* since 2.10 */
  void*                 cpal;
  void*                 colr;

  /* since 2.12 */
  void*                 svg;
} TT_FaceRec;

typedef struct  TT_SizeRec_ {
  FT_SizeRec         root;

  /* we have our own copy of metrics so that we can modify */
  /* it without affecting auto-hinting (when used)         */
  FT_Size_Metrics*   metrics;        /* for the current rendering mode */
  FT_Size_Metrics    hinted_metrics; /* for the hinted rendering mode  */

  TT_Size_Metrics    ttmetrics;

  FT_Byte*           widthp;          /* glyph widths from the hdmx table */

  FT_ULong           strike_index;      /* 0xFFFFFFFF to indicate invalid */

#ifdef TT_USE_BYTECODE_INTERPRETER

  FT_Long            point_size;    /* for the `MPS' bytecode instruction */

  FT_UInt            num_function_defs; /* number of function definitions */
  FT_UInt            max_function_defs;
  TT_DefArray        function_defs;     /* table of function definitions  */

  FT_UInt            num_instruction_defs;  /* number of ins. definitions */
  FT_UInt            max_instruction_defs;
  TT_DefArray        instruction_defs;      /* table of ins. definitions  */

  FT_UInt            max_func;
  FT_UInt            max_ins;

  TT_CodeRangeTable  codeRangeTable;

  TT_GraphicsState   GS;

  FT_ULong           cvt_size;      /* the scaled control value table */
  FT_Long*           cvt;

  FT_UShort          storage_size; /* The storage area is now part of */
  FT_Long*           storage;      /* the instance                    */

  TT_GlyphZoneRec    twilight;     /* The instance's twilight zone    */

  TT_ExecContext     context;

  /* if negative, `fpgm' (resp. `prep'), wasn't executed yet; */
  /* otherwise it is the returned error code                  */
  FT_Error           bytecode_ready;
  FT_Error           cvt_ready;

#endif /* TT_USE_BYTECODE_INTERPRETER */
} TT_SizeRec;

typedef struct  SFNT_Interface_
{
  TT_Loader_GotoTableFunc  goto_table;

#if 0
  TT_Init_Face_Func    init_face;
  TT_Load_Face_Func    load_face;
  TT_Done_Face_Func    done_face;
  FT_Module_Requester  get_interface;

  TT_Load_Any_Func  load_any;

  /* these functions are called by `load_face' but they can also  */
  /* be called from external modules, if there is a need to do so */
  TT_Load_Table_Func    load_head;
  TT_Load_Metrics_Func  load_hhea;
  TT_Load_Table_Func    load_cmap;
  TT_Load_Table_Func    load_maxp;
  TT_Load_Table_Func    load_os2;
  TT_Load_Table_Func    load_post;

  TT_Load_Table_Func  load_name;
  TT_Free_Table_Func  free_name;

  /* this field was called `load_kerning' up to version 2.1.10 */
  TT_Load_Table_Func  load_kern;

  TT_Load_Table_Func  load_gasp;
  TT_Load_Table_Func  load_pclt;

  /* see `ttload.h'; this field was called `load_bitmap_header' up to */
  /* version 2.1.10                                                   */
  TT_Load_Table_Func  load_bhed;

  TT_Load_SBit_Image_Func  load_sbit_image;

  /* see `ttpost.h' */
  TT_Get_PS_Name_Func  get_psname;
  TT_Free_Table_Func   free_psnames;

  /* starting here, the structure differs from version 2.1.7 */

  /* this field was introduced in version 2.1.8, named `get_psname' */
  TT_Face_GetKerningFunc  get_kerning;

  /* new elements introduced after version 2.1.10 */

  /* load the font directory, i.e., the offset table and */
  /* the table directory                                 */
  TT_Load_Table_Func    load_font_dir;
  TT_Load_Metrics_Func  load_hmtx;

  TT_Load_Table_Func  load_eblc;
  TT_Free_Table_Func  free_eblc;

  TT_Set_SBit_Strike_Func      set_sbit_strike;
  TT_Load_Strike_Metrics_Func  load_strike_metrics;

  TT_Load_Table_Func               load_cpal;
  TT_Load_Table_Func               load_colr;
  TT_Free_Table_Func               free_cpal;
  TT_Free_Table_Func               free_colr;
  TT_Set_Palette_Func              set_palette;
  TT_Get_Colr_Layer_Func           get_colr_layer;
  TT_Get_Color_Glyph_Paint_Func    get_colr_glyph_paint;
  TT_Get_Color_Glyph_ClipBox_Func  get_color_glyph_clipbox;
  TT_Get_Paint_Layers_Func         get_paint_layers;
  TT_Get_Colorline_Stops_Func      get_colorline_stops;
  TT_Get_Paint_Func                get_paint;
  TT_Blend_Colr_Func               colr_blend;

  TT_Get_Metrics_Func  get_metrics;

  TT_Get_Name_Func     get_name;
  TT_Get_Name_ID_Func  get_name_id;

  /* OpenType SVG Support */
  TT_Load_Table_Func    load_svg;
  TT_Free_Table_Func    free_svg;
  TT_Load_Svg_Doc_Func  load_svg_doc;
#endif
} SFNT_Interface;


/* transitional */
typedef SFNT_Interface*   SFNT_Service;

//
// SECTION CRT
//

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

int
ft_strcmp(const char *s1, const char *s2)
{
  for ( ; *s1 == *s2; s1++, s2++)
    if (*s1 == '\0')
      return 0;
  return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}

//
// SECTION Calc
//

FT_EXPORT_DEF( FT_Long )
FT_MulFix( FT_Long  a_,
           FT_Long  b_ )
{
#ifdef FT_MULFIX_ASSEMBLER

  return FT_MULFIX_ASSEMBLER( (FT_Int32)a_, (FT_Int32)b_ );

#else

  FT_Int64  ab = (FT_Int64)a_ * (FT_Int64)b_;

  /* this requires arithmetic right shift of signed numbers */
  return (FT_Long)( ( ab + 0x8000L - ( ab < 0 ) ) >> 16 );

#endif /* FT_MULFIX_ASSEMBLER */
}

FT_EXPORT_DEF( FT_Long )
FT_DivFix( FT_Long  a_,
           FT_Long  b_ )
{
  FT_Int     s = 1;
  FT_UInt64  a, b, q;
  FT_Long    q_;


  a = (FT_UInt64)a_;
  b = (FT_UInt64)b_;

  FT_MOVE_SIGN( a_, a, s );
  FT_MOVE_SIGN( b_, b, s );

  q = b > 0 ? ( ( a << 16 ) + ( b >> 1 ) ) / b
            : 0x7FFFFFFFUL;

  q_ = (FT_Long)q;

  return s < 0 ? NEG_LONG( q_ ) : q_;
}

//
// SECTION Memory
//

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

FT_BASE_DEF( void )
FT_Done_Memory( FT_Memory  memory )
{
#ifdef FT_DEBUG_MEMORY
  ft_mem_debug_done( memory );
#endif
  memory->free( memory, memory );
}

//
// SECTION List
//

FT_EXPORT_DEF( void )
FT_List_Remove( FT_List      list,
                FT_ListNode  node )
{
  FT_ListNode  before, after;

  if ( !list || !node )
    return;

  before = node->prev;
  after  = node->next;

  if ( before )
    before->next = after;
  else
    list->head = after;

  if ( after )
    after->prev = before;
  else
    list->tail = before;
}

FT_EXPORT_DEF( FT_ListNode )
FT_List_Find( FT_List  list,
              void*    data )
{
  FT_ListNode  cur;


  if ( !list )
    return NULL;

  cur = list->head;
  while ( cur )
  {
    if ( cur->data == data )
      return cur;

    cur = cur->next;
  }

  return NULL;
}

FT_EXPORT_DEF( void )
FT_List_Add( FT_List      list,
             FT_ListNode  node )
{
  FT_ListNode  before;

  if ( !list || !node )
    return;

  before = list->tail;

  node->next = NULL;
  node->prev = before;

  if ( before )
    before->next = node;
  else
    list->head = node;

  list->tail = node;
}

FT_EXPORT_DEF( void )
FT_List_Finalize( FT_List             list,
                  FT_List_Destructor  destroy,
                  FT_Memory           memory,
                  void*               user )
{
  FT_ListNode  cur;


  if ( !list || !memory )
    return;

  cur = list->head;
  while ( cur )
  {
    FT_ListNode  next = cur->next;
    void*        data = cur->data;


    if ( destroy )
      destroy( memory, data, user );

    FT_FREE( cur );
    cur = next;
  }

  list->head = NULL;
  list->tail = NULL;
}

//
// SECTION Stream
//

FT_BASE_DEF( void )
FT_Stream_OpenMemory( FT_Stream       stream,
                      const FT_Byte*  base,
                      FT_ULong        size )
{
  stream->base   = (FT_Byte*) base;
  stream->size   = size;
  stream->pos    = 0;
  stream->cursor = NULL;
  stream->read   = NULL;
  stream->close  = NULL;
}

FT_BASE_DEF( void )
FT_Stream_Close( FT_Stream  stream )
{
  if ( stream && stream->close )
    stream->close( stream );
}

FT_BASE_DEF( FT_Error )
FT_Stream_New( FT_Library           library,
               const FT_Open_Args*  args,
               FT_Stream           *astream )
{
  FT_Error   error = FT_Err_Ok;
  FT_Memory  memory;
  FT_Stream  stream = NULL;
  FT_UInt    mode;

  *astream = NULL;

  if ( !library )
    return FT_THROW( Invalid_Library_Handle );

  if ( !args )
    return FT_THROW( Invalid_Argument );

  memory = library->memory;
  mode   = args->flags &
             ( FT_OPEN_MEMORY | FT_OPEN_STREAM | FT_OPEN_PATHNAME );

  if ( mode == FT_OPEN_MEMORY )
  {
    /* create a memory-based stream */
    if ( FT_NEW( stream ) )
      goto Exit;

    FT_Stream_OpenMemory( stream,
                          (const FT_Byte*)args->memory_base,
                          (FT_ULong)args->memory_size );
    stream->memory = memory;
  }

#ifndef FT_CONFIG_OPTION_DISABLE_STREAM_SUPPORT

  else if ( mode == FT_OPEN_PATHNAME )
  {
    /* create a normal system stream */
    if ( FT_NEW( stream ) )
      goto Exit;

    stream->memory = memory;
    error = FT_Stream_Open( stream, args->pathname );
    if ( error )
      FT_FREE( stream );
  }
  else if ( ( mode == FT_OPEN_STREAM ) && args->stream )
  {
    /* use an existing, user-provided stream */

    /* in this case, we do not need to allocate a new stream object */
    /* since the caller is responsible for closing it himself       */
    stream         = args->stream;
    stream->memory = memory;
    error          = FT_Err_Ok;
  }

#endif

  else
  {
    error = FT_THROW( Invalid_Argument );
    if ( ( args->flags & FT_OPEN_STREAM ) && args->stream )
      FT_Stream_Close( args->stream );
  }

  if ( !error )
    *astream       = stream;
Exit:
  return error;
}

//
// SECTION Face
//

FT_BASE_DEF( FT_Error )
FT_Request_Metrics( FT_Face          face,
                    FT_Size_Request  req )
{
  FT_Error  error = FT_Err_Ok;

  FT_Size_Metrics*  metrics;

#if 0
  metrics = &face->size->metrics;

  if ( FT_IS_SCALABLE( face ) )
  {
    FT_Long  w = 0, h = 0, scaled_w = 0, scaled_h = 0;


    switch ( req->type )
    {
    case FT_SIZE_REQUEST_TYPE_NOMINAL:
      w = h = face->units_per_EM;
      break;

    case FT_SIZE_REQUEST_TYPE_REAL_DIM:
      w = h = face->ascender - face->descender;
      break;

    case FT_SIZE_REQUEST_TYPE_BBOX:
      w = face->bbox.xMax - face->bbox.xMin;
      h = face->bbox.yMax - face->bbox.yMin;
      break;

    case FT_SIZE_REQUEST_TYPE_CELL:
      w = face->max_advance_width;
      h = face->ascender - face->descender;
      break;

    case FT_SIZE_REQUEST_TYPE_SCALES:
      metrics->x_scale = (FT_Fixed)req->width;
      metrics->y_scale = (FT_Fixed)req->height;
      if ( !metrics->x_scale )
        metrics->x_scale = metrics->y_scale;
      else if ( !metrics->y_scale )
        metrics->y_scale = metrics->x_scale;
      goto Calculate_Ppem;

    case FT_SIZE_REQUEST_TYPE_MAX:
      break;
    }

    /* to be on the safe side */
    if ( w < 0 )
      w = -w;

    if ( h < 0 )
      h = -h;

    scaled_w = FT_REQUEST_WIDTH ( req );
    scaled_h = FT_REQUEST_HEIGHT( req );

    /* determine scales */
    if ( req->width )
    {
      metrics->x_scale = FT_DivFix( scaled_w, w );

      if ( req->height )
      {
        metrics->y_scale = FT_DivFix( scaled_h, h );

        if ( req->type == FT_SIZE_REQUEST_TYPE_CELL )
        {
          if ( metrics->y_scale > metrics->x_scale )
            metrics->y_scale = metrics->x_scale;
          else
            metrics->x_scale = metrics->y_scale;
        }
      }
      else
      {
        metrics->y_scale = metrics->x_scale;
        scaled_h = FT_MulDiv( scaled_w, h, w );
      }
    }
    else
    {
      metrics->x_scale = metrics->y_scale = FT_DivFix( scaled_h, h );
      scaled_w = FT_MulDiv( scaled_h, w, h );
    }

Calculate_Ppem:
    /* calculate the ppems */
    if ( req->type != FT_SIZE_REQUEST_TYPE_NOMINAL )
    {
      scaled_w = FT_MulFix( face->units_per_EM, metrics->x_scale );
      scaled_h = FT_MulFix( face->units_per_EM, metrics->y_scale );
    }

    scaled_w = ( scaled_w + 32 ) >> 6;
    scaled_h = ( scaled_h + 32 ) >> 6;
    if ( scaled_w > (FT_Long)FT_USHORT_MAX ||
         scaled_h > (FT_Long)FT_USHORT_MAX )
    {
      FT_ERROR(( "FT_Request_Metrics: Resulting ppem size too large\n" ));
      error = FT_ERR( Invalid_Pixel_Size );
      goto Exit;
    }

    metrics->x_ppem = (FT_UShort)scaled_w;
    metrics->y_ppem = (FT_UShort)scaled_h;

    ft_recompute_scaled_metrics( face, metrics );
  }
  else
  {
    FT_ZERO( metrics );
    metrics->x_scale = 1L << 16;
    metrics->y_scale = 1L << 16;
  }
#endif
Exit:
  return error;
}

static void
destroy_face( FT_Memory  memory,
              FT_Face    face,
              FT_Driver  driver )
{
  FT_Driver_Class  clazz = driver->clazz;

  #if 0
  /* discard auto-hinting data */
  if ( face->autohint.finalizer )
    face->autohint.finalizer( face->autohint.data );

  /* Discard glyph slots for this face.                           */
  /* Beware!  FT_Done_GlyphSlot() changes the field `face->glyph' */
  while ( face->glyph )
    FT_Done_GlyphSlot( face->glyph );

  /* discard all sizes for this face */
  FT_List_Finalize( &face->sizes_list,
                    (FT_List_Destructor)destroy_size,
                    memory,
                    driver );
  face->size = NULL;

  /* now discard client data */
  if ( face->generic.finalizer )
    face->generic.finalizer( face );

  /* discard charmaps */
  destroy_charmaps( face, memory );

  /* finalize format-specific stuff */
  if ( clazz->done_face )
    clazz->done_face( face );

  /* close the stream for this face if needed */
  FT_Stream_Free(
    face->stream,
    ( face->face_flags & FT_FACE_FLAG_EXTERNAL_STREAM ) != 0 );

  face->stream = NULL;

  /* get rid of it */
  if ( face->internal )
  {
    FT_FREE( face->internal );
  }
  FT_FREE( face );
  #endif
}

FT_EXPORT_DEF( FT_Error )
FT_Done_Face( FT_Face  face )
{
  FT_Error     error = FT_Err_Ok;
  FT_Driver    driver;
  FT_Memory    memory;
  FT_ListNode  node;

#if 0
  error = FT_ERR( Invalid_Face_Handle );
  if ( face && face->driver )
  {
    face->internal->refcount--;
    if ( face->internal->refcount > 0 )
      error = FT_Err_Ok;
    else
    {
      driver = face->driver;
      memory = driver->root.memory;

      /* find face in driver's list */
      node = FT_List_Find( &driver->faces_list, face );
      if ( node )
      {
        /* remove face object from the driver's list */
        FT_List_Remove( &driver->faces_list, node );
        FT_FREE( node );

        /* now destroy the object proper */
        destroy_face( memory, face, driver );
        error = FT_Err_Ok;
      }
    }
  }
#endif

  return error;
}

static FT_Error
ft_open_face_internal( FT_Library           library,
                       const FT_Open_Args*  args,
                       FT_Long              face_index,
                       FT_Face             *aface,
                       FT_Bool              test_mac_fonts )
{
    FT_Error     error;
    FT_Driver    driver = NULL;
    FT_Memory    memory = NULL;
    FT_Stream    stream = NULL;
    FT_Face      face   = NULL;
    FT_ListNode  node   = NULL;
    FT_Bool      external_stream;
    FT_Module*   cur;
    FT_Module*   limit;

#ifndef FT_CONFIG_OPTION_MAC_FONTS
    FT_UNUSED( test_mac_fonts );
#endif


    /* only use lower 31 bits together with sign bit */
    if ( face_index > 0 )
      face_index &= 0x7FFFFFFFL;
    else
    {
      face_index  = -face_index;
      face_index &= 0x7FFFFFFFL;
      face_index  = -face_index;
    }

#ifdef FT_DEBUG_LEVEL_TRACE
    FT_TRACE3(( "FT_Open_Face: " ));
    if ( face_index < 0 )
      FT_TRACE3(( "Requesting number of faces and named instances\n"));
    else
    {
      FT_TRACE3(( "Requesting face %ld", face_index & 0xFFFFL ));
      if ( face_index & 0x7FFF0000L )
        FT_TRACE3(( ", named instance %ld", face_index >> 16 ));
      FT_TRACE3(( "\n" ));
    }
#endif

    /* test for valid `library' delayed to `FT_Stream_New' */

    if ( ( !aface && face_index >= 0 ) || !args )
      return FT_THROW( Invalid_Argument );

    external_stream = FT_BOOL( ( args->flags & FT_OPEN_STREAM ) &&
                               args->stream                     );

    /* create input stream */
    error = FT_Stream_New( library, args, &stream );
    #if 0
    if ( error )
      goto Fail3;
    #endif

    memory = library->memory;

    /* If the font driver is specified in the `args' structure, use */
    /* it.  Otherwise, we scan the list of registered drivers.      */
    if ( ( args->flags & FT_OPEN_DRIVER ) && args->driver )
    {
    #if FREETYPE_WONT_INCLUDE
      driver = FT_DRIVER( args->driver );

      /* not all modules are drivers, so check... */
      if ( FT_MODULE_IS_DRIVER( driver ) )
      {
        FT_Int         num_params = 0;
        FT_Parameter*  params     = NULL;


        if ( args->flags & FT_OPEN_PARAMS )
        {
          num_params = args->num_params;
          params     = args->params;
        }

        error = open_face( driver, &stream, external_stream, face_index,
                           num_params, params, &face );
        if ( !error )
          goto Success;
      }
      else
        error = FT_THROW( Invalid_Handle );

      FT_Stream_Free( stream, external_stream );
      goto Fail;
    #endif
    }
    else
    {
      #if 0
      error = FT_ERR( Missing_Module );

      /* check each font driver for an appropriate format */
      cur   = library->modules;
      limit = cur + library->num_modules;

      for ( ; cur < limit; cur++ )
      {
        /* not all modules are font drivers, so check... */
        if ( FT_MODULE_IS_DRIVER( cur[0] ) )
        {
          FT_Int         num_params = 0;
          FT_Parameter*  params     = NULL;


          driver = FT_DRIVER( cur[0] );

          if ( args->flags & FT_OPEN_PARAMS )
          {
            num_params = args->num_params;
            params     = args->params;
          }

          error = open_face( driver, &stream, external_stream, face_index,
                             num_params, params, &face );
          if ( !error )
            goto Success;

#ifdef FT_CONFIG_OPTION_MAC_FONTS
          if ( test_mac_fonts                                           &&
               ft_strcmp( cur[0]->clazz->module_name, "truetype" ) == 0 &&
               FT_ERR_EQ( error, Table_Missing )                        )
          {
            /* TrueType but essential tables are missing */
            error = FT_Stream_Seek( stream, 0 );
            if ( error )
              break;

            error = open_face_PS_from_sfnt_stream( library,
                                                   stream,
                                                   face_index,
                                                   num_params,
                                                   params,
                                                   aface );
            if ( !error )
            {
              FT_Stream_Free( stream, external_stream );
              return error;
            }
          }
#endif

          if ( FT_ERR_NEQ( error, Unknown_File_Format ) )
            goto Fail3;
        }
      }

    Fail3:
      /* If we are on the mac, and we get an                          */
      /* FT_Err_Invalid_Stream_Operation it may be because we have an */
      /* empty data fork, so we need to check the resource fork.      */
      if ( FT_ERR_NEQ( error, Cannot_Open_Stream )       &&
           FT_ERR_NEQ( error, Unknown_File_Format )      &&
           FT_ERR_NEQ( error, Invalid_Stream_Operation ) )
        goto Fail2;

#if !defined( FT_MACINTOSH ) && defined( FT_CONFIG_OPTION_MAC_FONTS )
      if ( test_mac_fonts )
      {
        error = load_mac_face( library, stream, face_index, aface, args );
        if ( !error )
        {
          /* We don't want to go to Success here.  We've already done   */
          /* that.  On the other hand, if we succeeded we still need to */
          /* close this stream (we opened a different stream which      */
          /* extracted the interesting information out of this stream   */
          /* here.  That stream will still be open and the face will    */
          /* point to it).                                              */
          FT_Stream_Free( stream, external_stream );
          return error;
        }
      }

      if ( FT_ERR_NEQ( error, Unknown_File_Format ) )
        goto Fail2;
#endif  /* !FT_MACINTOSH && FT_CONFIG_OPTION_MAC_FONTS */

      /* no driver is able to handle this format */
      error = FT_THROW( Unknown_File_Format );

  Fail2:
      FT_Stream_Free( stream, external_stream );
      goto Fail;
      #endif
    }


  Success:
  #if FREETYPE_WONT_INCLUDE
    FT_TRACE4(( "FT_Open_Face: New face object, adding to list\n" ));
  #endif

    /* add the face object to its driver's list */
    if ( FT_QNEW( node ) )
      goto Fail;

    node->data = face;
    /* don't assume driver is the same as face->driver, so use */
    /* face->driver instead.                                   */
    FT_List_Add( &face->driver->faces_list, node );

    /* now allocate a glyph slot object for the face */
    #if FREETYPE_WONT_INCLUDE
    FT_TRACE4(( "FT_Open_Face: Creating glyph slot\n" ));
    #endif

    if ( face_index >= 0 )
    {
      #if 0
      error = FT_New_GlyphSlot( face, NULL );
      if ( error )
        goto Fail;

      /* finally, allocate a size object for the face */
      {
        FT_Size  size;

        #if FREETYPE_WONT_INCLUDE
        FT_TRACE4(( "FT_Open_Face: Creating size object\n" ));
        #endif

        error = FT_New_Size( face, &size );
        if ( error )
          goto Fail;

        face->size = size;
      }
      #endif
    }

    /* some checks */

    if ( FT_IS_SCALABLE( face ) )
    {
      if ( face->height < 0 )
        face->height = (FT_Short)-face->height;

      if ( !FT_HAS_VERTICAL( face ) )
        face->max_advance_height = (FT_Short)face->height;
    }

    if ( FT_HAS_FIXED_SIZES( face ) )
    {
      FT_Int  i;


      for ( i = 0; i < face->num_fixed_sizes; i++ )
      {
        FT_Bitmap_Size*  bsize = face->available_sizes + i;


        if ( bsize->height < 0 )
          bsize->height = -bsize->height;
        if ( bsize->x_ppem < 0 )
          bsize->x_ppem = -bsize->x_ppem;
        if ( bsize->y_ppem < 0 )
          bsize->y_ppem = -bsize->y_ppem;

        /* check whether negation actually has worked */
        if ( bsize->height < 0 || bsize->x_ppem < 0 || bsize->y_ppem < 0 )
        {
          #if FREETYPE_WONT_INCLUDE
          FT_TRACE0(( "FT_Open_Face:"
                      " Invalid bitmap dimensions for strike %d,"
                      " now disabled\n", i ));
          #endif
          bsize->width  = 0;
          bsize->height = 0;
          bsize->size   = 0;
          bsize->x_ppem = 0;
          bsize->y_ppem = 0;
        }
      }
    }

    /* initialize internal face data */
    {
      FT_Face_Internal  internal = face->internal;


      internal->transform_matrix.xx = 0x10000L;
      internal->transform_matrix.xy = 0;
      internal->transform_matrix.yx = 0;
      internal->transform_matrix.yy = 0x10000L;

      internal->transform_delta.x = 0;
      internal->transform_delta.y = 0;

      internal->refcount = 1;

      internal->no_stem_darkening = -1;

#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
      /* Per-face filtering can only be set up by FT_Face_Properties */
      internal->lcd_filter_func = NULL;
#endif
    }

    if ( aface )
      *aface = face;
    else
      FT_Done_Face( face );

    goto Exit;

  Fail:
    if ( node )
      FT_Done_Face( face );    /* face must be in the driver's list */
    else if ( face )
      destroy_face( memory, face, driver );

  Exit:
#ifdef FT_DEBUG_LEVEL_TRACE
    if ( !error && face_index < 0 )
    {
      FT_TRACE3(( "FT_Open_Face: The font has %ld face%s\n",
                  face->num_faces,
                  face->num_faces == 1 ? "" : "s" ));
      FT_TRACE3(( "              and %ld named instance%s for face %ld\n",
                  face->style_flags >> 16,
                  ( face->style_flags >> 16 ) == 1 ? "" : "s",
                  -face_index - 1 ));
    }
#endif

    #if FREETYPE_WONT_INCLUDE
    FT_TRACE4(( "FT_Open_Face: Return 0x%x\n", error ));
    #endif

    return error;
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

//
// SECTION GlyphLoader
//

FT_BASE_DEF( FT_Error )
FT_GlyphLoader_CreateExtra( FT_GlyphLoader  loader )
{
  FT_Error   error = FT_Err_Ok;
  FT_Memory  memory = loader->memory;

#if 0
  if ( loader->max_points == 0           ||
       loader->base.extra_points != NULL )
    return FT_Err_Ok;

  if ( !FT_NEW_ARRAY( loader->base.extra_points, 2 * loader->max_points ) )
  {
    loader->use_extra          = 1;
    loader->base.extra_points2 = loader->base.extra_points +
                                 loader->max_points;

    FT_GlyphLoader_Adjust_Points( loader );
  }
  #endif
  return error;
}

//
// SECTION System
//

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

//
// SECTION Truetype
//

FT_LOCAL_DEF( void )
TT_Get_HMetrics( TT_Face     face,
                 FT_UInt     idx,
                 FT_Short*   lsb,
                 FT_UShort*  aw )
{
  #if 0
  ( (SFNT_Service)face->sfnt )->get_metrics( face, 0, idx, lsb, aw );
  #endif
  #if FREETYPE_WONT_INCLUDE
  FT_TRACE5(( "  advance width (font units): %d\n", *aw ));
  FT_TRACE5(( "  left side bearing (font units): %d\n", *lsb ));
  #endif
}


FT_LOCAL_DEF( FT_Error )
tt_driver_init( FT_Module  ttdriver )     /* TT_Driver */
{

#ifdef TT_USE_BYTECODE_INTERPRETER

  TT_Driver  driver = (TT_Driver)ttdriver;

  driver->interpreter_version = TT_INTERPRETER_VERSION_35;
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
  driver->interpreter_version = TT_INTERPRETER_VERSION_38;
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
  driver->interpreter_version = TT_INTERPRETER_VERSION_40;
#endif

#else /* !TT_USE_BYTECODE_INTERPRETER */

  FT_UNUSED( ttdriver );

#endif /* !TT_USE_BYTECODE_INTERPRETER */

  return FT_Err_Ok;
}

FT_LOCAL_DEF( void )
tt_driver_done( FT_Module  ttdriver )     /* TT_Driver */
{
  FT_UNUSED( ttdriver );
}

FT_CALLBACK_DEF( FT_Module_Interface )
tt_get_interface( FT_Module    driver,    /* TT_Driver */
                  const char*  tt_interface )
{
  FT_Library           library;
  FT_Module_Interface  result;
  FT_Module            sfntd;
  #if 0
  SFNT_Service         sfnt;

  result = ft_service_list_lookup( tt_services, tt_interface );
  if ( result )
    return result;

  if ( !driver )
    return NULL;
  library = driver->library;
  if ( !library )
    return NULL;

  /* only return the default interface from the SFNT module */
  sfntd = FT_Get_Module( library, "sfnt" );
  if ( sfntd )
  {
    sfnt = (SFNT_Service)( sfntd->clazz->module_interface );
    if ( sfnt )
      return sfnt->get_interface( driver, tt_interface );
  }
  #endif

  return 0;
}

FT_LOCAL_DEF( FT_Error )
tt_face_init( FT_Stream      stream,
              FT_Face        ttface,      /* TT_Face */
              FT_Int         face_index,
              FT_Int         num_params,
              FT_Parameter*  params )
{
  FT_Error      error;
  FT_Library    library;
#if 0
  SFNT_Service  sfnt;
  TT_Face       face = (TT_Face)ttface;


  FT_TRACE2(( "TTF driver\n" ));

  library = ttface->driver->root.library;

  sfnt = (SFNT_Service)FT_Get_Module_Interface( library, "sfnt" );
  if ( !sfnt )
  {
    FT_ERROR(( "tt_face_init: cannot access `sfnt' module\n" ));
    error = FT_THROW( Missing_Module );
    goto Exit;
  }

  /* create input stream from resource */
  if ( FT_STREAM_SEEK( 0 ) )
    goto Exit;

  /* check that we have a valid TrueType file */
  FT_TRACE2(( "  " ));
  error = sfnt->init_face( stream, face, face_index, num_params, params );

  /* Stream may have changed. */
  stream = face->root.stream;

  if ( error )
    goto Exit;

  /* We must also be able to accept Mac/GX fonts, as well as OT ones. */
  /* The 0x00020000 tag is completely undocumented; some fonts from   */
  /* Arphic made for Chinese Windows 3.1 have this.                   */
  if ( face->format_tag != 0x00010000L  && /* MS fonts                             */
       face->format_tag != 0x00020000L  && /* CJK fonts for Win 3.1                */
       face->format_tag != TTAG_true    && /* Mac fonts                            */
       face->format_tag != TTAG_0xA5kbd && /* `Keyboard.dfont' (legacy Mac OS X)   */
       face->format_tag != TTAG_0xA5lst )  /* `LastResort.dfont' (legacy Mac OS X) */
  {
    FT_TRACE2(( "  not a TTF font\n" ));
    goto Bad_Format;
  }

#ifdef TT_USE_BYTECODE_INTERPRETER
  ttface->face_flags |= FT_FACE_FLAG_HINTER;
#endif

  /* If we are performing a simple font format check, exit immediately. */
  if ( face_index < 0 )
    return FT_Err_Ok;

  /* Load font directory */
  error = sfnt->load_face( stream, face, face_index, num_params, params );
  if ( error )
    goto Exit;

#ifdef TT_USE_BYTECODE_INTERPRETER
  if ( tt_check_trickyness( ttface ) )
    ttface->face_flags |= FT_FACE_FLAG_TRICKY;
#endif

  error = tt_face_load_hdmx( face, stream );
  if ( error )
    goto Exit;

  if ( FT_IS_SCALABLE( ttface ) ||
       FT_HAS_SBIX( ttface )    )
  {
#ifdef FT_CONFIG_OPTION_INCREMENTAL
    if ( !ttface->internal->incremental_interface )
#endif
    {
      error = tt_face_load_loca( face, stream );

      /* having a (non-zero) `glyf' table without */
      /* a `loca' table is not valid              */
      if ( face->glyf_len && FT_ERR_EQ( error, Table_Missing ) )
        goto Exit;
      if ( error )
        goto Exit;
    }

    /* `fpgm', `cvt', and `prep' are optional */
    error = tt_face_load_cvt( face, stream );
    if ( error && FT_ERR_NEQ( error, Table_Missing ) )
      goto Exit;

    error = tt_face_load_fpgm( face, stream );
    if ( error && FT_ERR_NEQ( error, Table_Missing ) )
      goto Exit;

    error = tt_face_load_prep( face, stream );
    if ( error && FT_ERR_NEQ( error, Table_Missing ) )
      goto Exit;

    /* Check the scalable flag based on `loca'. */
#ifdef FT_CONFIG_OPTION_INCREMENTAL
    if ( !ttface->internal->incremental_interface )
#endif
    {
      if ( ttface->num_fixed_sizes          &&
           face->glyph_locations            &&
           tt_check_single_notdef( ttface ) )
      {
        FT_TRACE5(( "tt_face_init:"
                    " Only the `.notdef' glyph has an outline.\n" ));
        FT_TRACE5(( "             "
                    " Resetting scalable flag to FALSE.\n" ));

        ttface->face_flags &= ~FT_FACE_FLAG_SCALABLE;
      }
    }
  }

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT

  {
    FT_UInt  instance_index = (FT_UInt)face_index >> 16;


    if ( FT_HAS_MULTIPLE_MASTERS( ttface ) &&
         instance_index > 0                )
    {
      error = TT_Set_Named_Instance( face, instance_index );
      if ( error )
        goto Exit;

      tt_apply_mvar( face );
    }
  }

#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */

  /* initialize standard glyph loading routines */
  TT_Init_Glyph_Loading( face );
#endif

Exit:
  return error;

Bad_Format:
  error = FT_THROW( Unknown_File_Format );
  goto Exit;
}

FT_LOCAL_DEF( void )
tt_face_done( FT_Face  ttface )           /* TT_Face */
{
  TT_Face       face = (TT_Face)ttface;
  FT_Memory     memory;
  FT_Stream     stream;
  #if 0
  SFNT_Service  sfnt;


  if ( !face )
    return;

  memory = ttface->memory;
  stream = ttface->stream;
  sfnt   = (SFNT_Service)face->sfnt;

  /* for `extended TrueType formats' (i.e. compressed versions) */
  if ( face->extra.finalizer )
    face->extra.finalizer( face->extra.data );

  if ( sfnt )
    sfnt->done_face( face );

  /* freeing the locations table */
  tt_face_done_loca( face );

  tt_face_free_hdmx( face );

  /* freeing the CVT */
  FT_FREE( face->cvt );
  face->cvt_size = 0;

  /* freeing the programs */
  FT_FRAME_RELEASE( face->font_program );
  FT_FRAME_RELEASE( face->cvt_program );
  face->font_program_size = 0;
  face->cvt_program_size  = 0;

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
  tt_done_blend( face );
  face->blend = NULL;
#endif
#endif
}

FT_LOCAL_DEF( FT_Error )
tt_size_init( FT_Size  ttsize )           /* TT_Size */
{
  TT_Size   size  = (TT_Size)ttsize;
  FT_Error  error = FT_Err_Ok;

#ifdef TT_USE_BYTECODE_INTERPRETER
  size->bytecode_ready = -1;
  size->cvt_ready      = -1;
#endif

  size->ttmetrics.valid = FALSE;
  size->strike_index    = 0xFFFFFFFFUL;

  return error;
}

FT_LOCAL_DEF( void )
tt_size_done( FT_Size  ttsize )           /* TT_Size */
{
  TT_Size  size = (TT_Size)ttsize;

#ifdef TT_USE_BYTECODE_INTERPRETER
  tt_size_done_bytecode( ttsize );
#endif

  size->ttmetrics.valid = FALSE;
}

FT_LOCAL_DEF( FT_Error )
tt_slot_init( FT_GlyphSlot  slot )
{
  return FT_GlyphLoader_CreateExtra( slot->internal->loader );
}

static FT_Error
tt_glyph_load( FT_GlyphSlot  ttslot,      /* TT_GlyphSlot */
               FT_Size       ttsize,      /* TT_Size      */
               FT_UInt       glyph_index,
               FT_Int32      load_flags )
{
  TT_GlyphSlot  slot = (TT_GlyphSlot)ttslot;
  TT_Size       size = (TT_Size)ttsize;
  FT_Face       face = ttslot->face;
  FT_Error      error;

#if 0
  if ( !slot )
    return FT_THROW( Invalid_Slot_Handle );

  if ( !size )
    return FT_THROW( Invalid_Size_Handle );

  if ( !face )
    return FT_THROW( Invalid_Face_Handle );

#ifdef FT_CONFIG_OPTION_INCREMENTAL
  if ( glyph_index >= (FT_UInt)face->num_glyphs &&
       !face->internal->incremental_interface   )
#else
  if ( glyph_index >= (FT_UInt)face->num_glyphs )
#endif
    return FT_THROW( Invalid_Argument );

  if ( load_flags & FT_LOAD_NO_HINTING )
  {
    /* both FT_LOAD_NO_HINTING and FT_LOAD_NO_AUTOHINT   */
    /* are necessary to disable hinting for tricky fonts */

    if ( FT_IS_TRICKY( face ) )
      load_flags &= ~FT_LOAD_NO_HINTING;

    if ( load_flags & FT_LOAD_NO_AUTOHINT )
      load_flags |= FT_LOAD_NO_HINTING;
  }

  if ( load_flags & ( FT_LOAD_NO_RECURSE | FT_LOAD_NO_SCALE ) )
  {
    load_flags |= FT_LOAD_NO_BITMAP | FT_LOAD_NO_SCALE;

    if ( !FT_IS_TRICKY( face ) )
      load_flags |= FT_LOAD_NO_HINTING;
  }

  /* use hinted metrics only if we load a glyph with hinting */
  size->metrics = ( load_flags & FT_LOAD_NO_HINTING )
                    ? &ttsize->metrics
                    : &size->hinted_metrics;

  /* now fill in the glyph slot with outline/bitmap/layered */
  error = TT_Load_Glyph( size, slot, glyph_index, load_flags );

  /* force drop-out mode to 2 - irrelevant now */
  /* slot->outline.dropout_mode = 2; */
#endif
  return error;
}

static FT_Error
tt_get_kerning( FT_Face     ttface,          /* TT_Face */
                FT_UInt     left_glyph,
                FT_UInt     right_glyph,
                FT_Vector*  kerning )
{
  TT_Face       face = (TT_Face)ttface;
#if 0
  SFNT_Service  sfnt = (SFNT_Service)face->sfnt;


  kerning->x = 0;
  kerning->y = 0;

  if ( sfnt )
    kerning->x = sfnt->get_kerning( face, left_glyph, right_glyph );
#endif
  return 0;
}

static FT_Error
tt_get_advances( FT_Face    ttface,
                 FT_UInt    start,
                 FT_UInt    count,
                 FT_Int32   flags,
                 FT_Fixed  *advances )
{
  FT_UInt  nn;
  TT_Face  face = (TT_Face)ttface;


  /* XXX: TODO: check for sbits */

  if ( flags & FT_LOAD_VERTICAL_LAYOUT )
  {
  #if 0
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
    /* no fast retrieval for blended MM fonts without VVAR table */
    if ( ( FT_IS_NAMED_INSTANCE( ttface ) || FT_IS_VARIATION( ttface ) ) &&
         !( face->variation_support & TT_FACE_FLAG_VAR_VADVANCE )        )
      return FT_THROW( Unimplemented_Feature );
#endif

    for ( nn = 0; nn < count; nn++ )
    {
      FT_Short   tsb;
      FT_UShort  ah;


      /* since we don't need `tsb', we use zero for `yMax' parameter */
      TT_Get_VMetrics( face, start + nn, 0, &tsb, &ah );
      advances[nn] = ah;
    }
#endif
  }
  else
  {
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
    /* no fast retrieval for blended MM fonts without HVAR table */
    if ( ( FT_IS_NAMED_INSTANCE( ttface ) || FT_IS_VARIATION( ttface ) ) &&
         !( face->variation_support & TT_FACE_FLAG_VAR_HADVANCE )        )
      return FT_THROW( Unimplemented_Feature );
#endif

    for ( nn = 0; nn < count; nn++ )
    {
      FT_Short   lsb;
      FT_UShort  aw;


      TT_Get_HMetrics( face, start + nn, &lsb, &aw );
      advances[nn] = aw;
    }
  }
  return FT_Err_Ok;
}

FT_LOCAL_DEF( FT_Byte* )
tt_face_get_device_metrics( TT_Face  face,
                            FT_UInt  ppem,
                            FT_UInt  gindex )
{
  FT_UInt   min    = 0;
  FT_UInt   max    = face->hdmx_record_count;
  FT_UInt   mid;
  FT_Byte*  result = NULL;

  while ( min < max )
  {
    mid = ( min + max ) >> 1;

    if ( face->hdmx_records[mid][0] > ppem )
      max = mid;
    else if ( face->hdmx_records[mid][0] < ppem )
      min = mid + 1;
    else
    {
      result = face->hdmx_records[mid] + 2 + gindex;
      break;
    }
  }

  return result;
}

FT_LOCAL_DEF( FT_Error )
tt_size_reset( TT_Size  size,
               FT_Bool  only_height )
{
  TT_Face           face;
  FT_Size_Metrics*  size_metrics;

  face = (TT_Face)size->root.face;

  /* nothing to do for CFF2 */
  if ( face->is_cff2 )
    return FT_Err_Ok;

  size->ttmetrics.valid = FALSE;

  size_metrics = &size->hinted_metrics;

  /* copy the result from base layer */
  *size_metrics = size->root.metrics;

  if ( size_metrics->x_ppem < 1 || size_metrics->y_ppem < 1 )
    return FT_THROW( Invalid_PPem );

  /* This bit flag, if set, indicates that the ppems must be       */
  /* rounded to integers.  Nearly all TrueType fonts have this bit */
  /* set, as hinting won't work really well otherwise.             */
  /*                                                               */
  if ( face->header.Flags & 8 )
  {
    /* the TT spec always asks for ROUND, not FLOOR or CEIL */
    size_metrics->ascender = FT_PIX_ROUND(
                               FT_MulFix( face->root.ascender,
                                          size_metrics->y_scale ) );
    size_metrics->descender = FT_PIX_ROUND(
                               FT_MulFix( face->root.descender,
                                          size_metrics->y_scale ) );
    size_metrics->height = FT_PIX_ROUND(
                             FT_MulFix( face->root.height,
                                        size_metrics->y_scale ) );
  }

  size->ttmetrics.valid = TRUE;

  if ( only_height )
  {
    /* we must not recompute the scaling values here since       */
    /* `tt_size_reset' was already called (with only_height = 0) */
    return FT_Err_Ok;
  }

  if ( face->header.Flags & 8 )
  {
    /* base scaling values on integer ppem values, */
    /* as mandated by the TrueType specification   */
    size_metrics->x_scale = FT_DivFix( size_metrics->x_ppem << 6,
                                       face->root.units_per_EM );
    size_metrics->y_scale = FT_DivFix( size_metrics->y_ppem << 6,
                                       face->root.units_per_EM );

    size_metrics->max_advance = FT_PIX_ROUND(
                                  FT_MulFix( face->root.max_advance_width,
                                             size_metrics->x_scale ) );
  }

  /* compute new transformation */
  if ( size_metrics->x_ppem >= size_metrics->y_ppem )
  {
    size->ttmetrics.scale   = size_metrics->x_scale;
    size->ttmetrics.ppem    = size_metrics->x_ppem;
    size->ttmetrics.x_ratio = 0x10000L;
    size->ttmetrics.y_ratio = FT_DivFix( size_metrics->y_ppem,
                                         size_metrics->x_ppem );
  }
  else
  {
    size->ttmetrics.scale   = size_metrics->y_scale;
    size->ttmetrics.ppem    = size_metrics->y_ppem;
    size->ttmetrics.x_ratio = FT_DivFix( size_metrics->x_ppem,
                                         size_metrics->y_ppem );
    size->ttmetrics.y_ratio = 0x10000L;
  }

  size->widthp = tt_face_get_device_metrics( face, size_metrics->x_ppem, 0 );

  size->metrics = size_metrics;

#ifdef TT_USE_BYTECODE_INTERPRETER
  size->cvt_ready = -1;
#endif /* TT_USE_BYTECODE_INTERPRETER */
  return FT_Err_Ok;
}

static FT_Error
tt_size_request( FT_Size          size,
                 FT_Size_Request  req )
{
  TT_Size   ttsize = (TT_Size)size;
  FT_Error  error  = FT_Err_Ok;

#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS

  if ( FT_HAS_FIXED_SIZES( size->face ) )
  {
    TT_Face       ttface = (TT_Face)size->face;
    SFNT_Service  sfnt   = (SFNT_Service)ttface->sfnt;
    FT_ULong      strike_index;


    error = sfnt->set_sbit_strike( ttface, req, &strike_index );

    if ( error )
      ttsize->strike_index = 0xFFFFFFFFUL;
    else
      return tt_size_select( size, strike_index );
  }

#endif /* TT_CONFIG_OPTION_EMBEDDED_BITMAPS */

  {
    FT_Error  err = FT_Request_Metrics( size->face, req );

    if ( err )
    {
      error = err;
      goto Exit;
    }
  }

  if ( FT_IS_SCALABLE( size->face ) )
  {
    error = tt_size_reset( ttsize, 0 );

#ifdef TT_USE_BYTECODE_INTERPRETER
    /* for the `MPS' bytecode instruction we need the point size */
    if ( !error )
    {
      FT_UInt  resolution =
                 ttsize->metrics->x_ppem > ttsize->metrics->y_ppem
                   ? req->horiResolution
                   : req->vertResolution;


      /* if we don't have a resolution value, assume 72dpi */
      if ( req->type == FT_SIZE_REQUEST_TYPE_SCALES ||
           !resolution                              )
        resolution = 72;

      ttsize->point_size = FT_MulDiv( ttsize->ttmetrics.ppem,
                                      64 * 72,
                                      resolution );
    }
#endif
  }
Exit:
  return error;
}

//
// SECTION Library
//

FT_BASE_DEF( FT_Renderer )
FT_Lookup_Renderer( FT_Library       library,
                    FT_Glyph_Format  format,
                    FT_ListNode*     node )
{
  FT_ListNode  cur;
  FT_Renderer  result = NULL;


  if ( !library )
    goto Exit;

  cur = library->renderers.head;

  if ( node )
  {
    if ( *node )
      cur = (*node)->next;
    *node = NULL;
  }

  while ( cur )
  {
    FT_Renderer  renderer = FT_RENDERER( cur->data );


    if ( renderer->glyph_format == format )
    {
      if ( node )
        *node = cur;

      result = renderer;
      break;
    }
    cur = cur->next;
  }

Exit:
  return result;
}

static void
ft_set_current_renderer( FT_Library  library )
{
  FT_Renderer  renderer;
  renderer = FT_Lookup_Renderer( library, FT_GLYPH_FORMAT_OUTLINE, 0 );
  library->cur_renderer = renderer;
}

static FT_Error
ft_add_renderer( FT_Module  module )
{
  FT_Library   library = module->library;
  FT_Memory    memory  = library->memory;
  FT_Error     error;
  FT_ListNode  node    = NULL;

  if ( FT_QNEW( node ) )
    goto Exit;

  {
    FT_Renderer         render = FT_RENDERER( module );
    FT_Renderer_Class*  clazz  = (FT_Renderer_Class*)module->clazz;


    render->clazz        = clazz;
    render->glyph_format = clazz->glyph_format;

    /* allocate raster object if needed */
    if ( clazz->raster_class && clazz->raster_class->raster_new )
    {
      error = clazz->raster_class->raster_new( memory, &render->raster );
      if ( error )
        goto Fail;

      render->raster_render = clazz->raster_class->raster_render;
      render->render        = clazz->render_glyph;
    }

#ifdef FT_CONFIG_OPTION_SVG
    if ( clazz->glyph_format == FT_GLYPH_FORMAT_SVG )
      render->render = clazz->render_glyph;
#endif

    /* add to list */
    node->data = module;
    FT_List_Add( &library->renderers, node );

    ft_set_current_renderer( library );
  }

Fail:
  if ( error )
    FT_FREE( node );

Exit:
  return error;
}

static void
ft_remove_renderer( FT_Module  module )
{
  FT_Library   library;
  FT_Memory    memory;
  FT_ListNode  node;

  library = module->library;
  if ( !library )
    return;

  memory = library->memory;

  node = FT_List_Find( &library->renderers, module );
  if ( node )
  {
    FT_Renderer  render = FT_RENDERER( module );


    /* release raster object, if any */
    if ( render->raster )
      render->clazz->raster_class->raster_done( render->raster );

    /* remove from list */
    FT_List_Remove( &library->renderers, node );
    FT_FREE( node );

    ft_set_current_renderer( library );
  }
}

static void
Destroy_Driver( FT_Driver  driver )
{
  FT_List_Finalize( &driver->faces_list,
                    (FT_List_Destructor)destroy_face,
                    driver->root.memory,
                    driver );
}

static void
Destroy_Module( FT_Module  module )
{
  FT_Memory         memory  = module->memory;
  FT_Module_Class*  clazz   = module->clazz;
  FT_Library        library = module->library;

  if ( library && library->auto_hinter == module )
    library->auto_hinter = NULL;

  /* if the module is a renderer */
  if ( FT_MODULE_IS_RENDERER( module ) )
    ft_remove_renderer( module );

  /* if the module is a font driver, add some steps */
  if ( FT_MODULE_IS_DRIVER( module ) )
    Destroy_Driver( FT_DRIVER( module ) );

  /* finalize the module object */
  if ( clazz->module_done )
    clazz->module_done( module );

  /* discard it */
  FT_FREE( module );
}

FT_EXPORT_DEF( FT_Error )
FT_Remove_Module( FT_Library  library,
                  FT_Module   module )
{
  /* try to find the module from the table, then remove it from there */

  if ( !library )
    return FT_THROW( Invalid_Library_Handle );

  if ( module )
  {
    FT_Module*  cur   = library->modules;
    FT_Module*  limit = cur + library->num_modules;


    for ( ; cur < limit; cur++ )
    {
      if ( cur[0] == module )
      {
        /* remove it from the table */
        library->num_modules--;
        limit--;
        while ( cur < limit )
        {
          cur[0] = cur[1];
          cur++;
        }
        limit[0] = NULL;

        /* destroy the module */
        Destroy_Module( module );

        return FT_Err_Ok;
      }
    }
  }
  return FT_THROW( Invalid_Driver_Handle );
}

FT_EXPORT_DEF( FT_Error )
FT_Add_Module( FT_Library              library,
               const FT_Module_Class*  clazz )
{
  FT_Error   error;
  FT_Memory  memory;
  FT_Module  module = NULL;
  FT_UInt    nn;

  if ( !library )
    return FT_THROW( Invalid_Library_Handle );

  if ( !clazz )
    return FT_THROW( Invalid_Argument );

  /* check FreeType version */
  if ( clazz->module_requires > FREETYPE_VER_FIXED )
    return FT_THROW( Invalid_Version );

  /* look for a module with the same name in the library's table */
  for ( nn = 0; nn < library->num_modules; nn++ )
  {
    module = library->modules[nn];
    if ( ft_strcmp( module->clazz->module_name, clazz->module_name ) == 0 )
    {
      /* this installed module has the same name, compare their versions */
      if ( clazz->module_version <= module->clazz->module_version )
        return FT_THROW( Lower_Module_Version );

      /* remove the module from our list, then exit the loop to replace */
      /* it by our new version..                                        */
      FT_Remove_Module( library, module );
      break;
    }
  }

  memory = library->memory;
  error  = FT_Err_Ok;

  if ( library->num_modules >= FT_MAX_MODULES )
  {
    error = FT_THROW( Too_Many_Drivers );
    goto Exit;
  }

  /* allocate module object */
  if ( FT_ALLOC( module, clazz->module_size ) )
    goto Exit;

  /* base initialization */
  module->library = library;
  module->memory  = memory;
  module->clazz   = (FT_Module_Class*)clazz;

  /* check whether the module is a renderer - this must be performed */
  /* before the normal module initialization                         */
  if ( FT_MODULE_IS_RENDERER( module ) )
  {
    /* add to the renderers list */
    error = ft_add_renderer( module );
    if ( error )
      goto Fail;
  }

  /* is the module a auto-hinter? */
  if ( FT_MODULE_IS_HINTER( module ) )
    library->auto_hinter = module;

  /* if the module is a font driver */
  if ( FT_MODULE_IS_DRIVER( module ) )
  {
    FT_Driver  driver = FT_DRIVER( module );
    driver->clazz = (FT_Driver_Class)module->clazz;
  }

  if ( clazz->module_init )
  {
    error = clazz->module_init( module );
    if ( error )
      goto Fail;
  }

  /* add module to the library's table */
  library->modules[library->num_modules++] = module;

Exit:
  return error;

Fail:
  if ( FT_MODULE_IS_RENDERER( module ) )
  {
    FT_Renderer  renderer = FT_RENDERER( module );


    if ( renderer->clazz                                          &&
         renderer->clazz->glyph_format == FT_GLYPH_FORMAT_OUTLINE &&
         renderer->raster                                         )
      renderer->clazz->raster_class->raster_done( renderer->raster );
  }

  FT_FREE( module );
  goto Exit;
}

FT_DEFINE_DRIVER(
  tt_driver_class,

    FT_MODULE_FONT_DRIVER     |
    FT_MODULE_DRIVER_SCALABLE |
    TT_HINTER_FLAG,

    sizeof ( TT_DriverRec ),

    "truetype",      /* driver name                           */
    0x10000L,        /* driver version == 1.0                 */
    0x20000L,        /* driver requires FreeType 2.0 or above */

    NULL,    /* module-specific interface */

    tt_driver_init,           /* FT_Module_Constructor  module_init   */
    tt_driver_done,           /* FT_Module_Destructor   module_done   */
    tt_get_interface,         /* FT_Module_Requester    get_interface */

  sizeof ( TT_FaceRec ),
  sizeof ( TT_SizeRec ),
  sizeof ( FT_GlyphSlotRec ),

  tt_face_init,               /* FT_Face_InitFunc  init_face */
  tt_face_done,               /* FT_Face_DoneFunc  done_face */
  tt_size_init,               /* FT_Size_InitFunc  init_size */
  tt_size_done,               /* FT_Size_DoneFunc  done_size */
  tt_slot_init,               /* FT_Slot_InitFunc  init_slot */
  NULL,                       /* FT_Slot_DoneFunc  done_slot */

  tt_glyph_load,              /* FT_Slot_LoadFunc  load_glyph */

  tt_get_kerning,             /* FT_Face_GetKerningFunc   get_kerning  */
  NULL,                       /* FT_Face_AttachFunc       attach_file  */
  tt_get_advances,            /* FT_Face_GetAdvancesFunc  get_advances */

  tt_size_request,            /* FT_Size_RequestFunc  request_size */
  TT_SIZE_SELECT              /* FT_Size_SelectFunc   select_size  */
)

static
const FT_Module_Class*  const ft_default_modules[] =
{
  #if FREETYPE_WONT_INCLUDE
  FT_USE_MODULE( FT_Module_Class, autofit_module_class )
  #endif
  FT_USE_MODULE( FT_Driver_ClassRec, tt_driver_class )
  #if FREETYPE_WONT_INCLUDE
  FT_USE_MODULE( FT_Driver_ClassRec, t1_driver_class )
  FT_USE_MODULE( FT_Driver_ClassRec, cff_driver_class )
  FT_USE_MODULE( FT_Driver_ClassRec, t1cid_driver_class )
  FT_USE_MODULE( FT_Driver_ClassRec, pfr_driver_class )
  FT_USE_MODULE( FT_Driver_ClassRec, t42_driver_class )
  FT_USE_MODULE( FT_Driver_ClassRec, winfnt_driver_class )
  FT_USE_MODULE( FT_Driver_ClassRec, pcf_driver_class )
  FT_USE_MODULE( FT_Driver_ClassRec, bdf_driver_class )
  FT_USE_MODULE( FT_Module_Class, psaux_module_class )
  FT_USE_MODULE( FT_Module_Class, psnames_module_class )
  FT_USE_MODULE( FT_Module_Class, pshinter_module_class )
  FT_USE_MODULE( FT_Module_Class, sfnt_module_class )
  FT_USE_MODULE( FT_Renderer_Class, ft_smooth_renderer_class )
  FT_USE_MODULE( FT_Renderer_Class, ft_raster1_renderer_class )
  FT_USE_MODULE( FT_Renderer_Class, ft_sdf_renderer_class )
  FT_USE_MODULE( FT_Renderer_Class, ft_bitmap_sdf_renderer_class )
  FT_USE_MODULE( FT_Renderer_Class, ft_svg_renderer_class )
  #endif
  0
};

FT_EXPORT_DEF( void )
FT_Add_Default_Modules( FT_Library  library )
{
  FT_Error                       error;
  const FT_Module_Class* const*  cur;

  /* GCC 4.6 warns the type difference:
   *   FT_Module_Class** != const FT_Module_Class* const*
   */
  cur = (const FT_Module_Class* const*)ft_default_modules;

  /* test for valid `library' delayed to FT_Add_Module() */
  while ( *cur )
  {
    error = FT_Add_Module( library, *cur );
    /* notify errors, but don't stop */
    #if FREETYPE_WONT_INCLUDE
    if ( error )
      FT_TRACE0(( "FT_Add_Default_Module:"
                 " Cannot install `%s', error = 0x%x\n",
                 (*cur)->module_name, error ));
    #endif
    cur++;
  }
}

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

#ifdef FT_CONFIG_OPTION_ENVIRONMENT_PROPERTIES

#define MAX_LENGTH  128

/* documentation is in ftmodapi.h */

FT_EXPORT_DEF( void )
FT_Set_Default_Properties( FT_Library  library )
{
  const char*  env;
  const char*  p;
  const char*  q;

  char  module_name[MAX_LENGTH + 1];
  char  property_name[MAX_LENGTH + 1];
  char  property_value[MAX_LENGTH + 1];

  int  i;


  env = ft_getenv( "FREETYPE_PROPERTIES" );
  if ( !env )
    return;

  for ( p = env; *p; p++ )
  {
    /* skip leading whitespace and separators */
    if ( *p == ' ' || *p == '\t' )
      continue;

    /* read module name, followed by `:' */
    q = p;
    for ( i = 0; i < MAX_LENGTH; i++ )
    {
      if ( !*p || *p == ':' )
        break;
      module_name[i] = *p++;
    }
    module_name[i] = '\0';

    if ( !*p || *p != ':' || p == q )
      break;

    /* read property name, followed by `=' */
    q = ++p;
    for ( i = 0; i < MAX_LENGTH; i++ )
    {
      if ( !*p || *p == '=' )
        break;
      property_name[i] = *p++;
    }
    property_name[i] = '\0';

    if ( !*p || *p != '=' || p == q )
      break;

    /* read property value, followed by whitespace (if any) */
    q = ++p;
    for ( i = 0; i < MAX_LENGTH; i++ )
    {
      if ( !*p || *p == ' ' || *p == '\t' )
        break;
      property_value[i] = *p++;
    }
    property_value[i] = '\0';

    if ( !( *p == '\0' || *p == ' ' || *p == '\t' ) || p == q )
      break;

    /* we completely ignore errors */
    ft_property_string_set( library,
                            module_name,
                            property_name,
                            property_value );

    if ( !*p )
      break;
  }
}

#else // FT_CONFIG_OPTION_ENVIRONMENT_PROPERTIES

FT_EXPORT_DEF( void )
FT_Set_Default_Properties( FT_Library  library )
{
  FT_UNUSED( library );
}

#endif // FT_CONFIG_OPTION_ENVIRONMENT_PROPERTIES

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
    #if FREETYPE_WONT_INCLUDE
    FT_ERROR(( "FT_Init_FreeType: cannot find memory manager\n" ));
    #endif
    return FT_THROW( Unimplemented_Feature );
  }

  /* build a library out of it, then fill it with the set of */
  /* default drivers.                                        */

  error = FT_New_Library( memory, alibrary );
  if ( error )
    FT_Done_Memory( memory );
  else
    FT_Add_Default_Modules( *alibrary );

  FT_Set_Default_Properties( *alibrary );
  return error;
}
