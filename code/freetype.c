// Freetype2 pulled out from
// https://github.com/freetype/freetype

#include <stdint.h>
#include <limits.h>
#include <stddef.h>

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
#define FREETYPE_OG_ZERO 0

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

#define FT_ERR( e )  FT_ERR_CAT( FT_ERR_PREFIX, e )

#define FT_ERROR_BASE( x )    ( (x) & 0xFF )
#define FT_ERROR_MODULE( x )  ( (x) & 0xFF00U )

#define FT_ERR_EQ( x, e ) ( FT_ERROR_BASE( x ) == FT_ERROR_BASE( FT_ERR( e ) ) )
#define FT_ERR_NEQ( x, e ) ( FT_ERROR_BASE( x ) != FT_ERROR_BASE( FT_ERR( e ) ) )

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
#define FT_QALLOC( ptr, size ) FT_MEM_SET_ERROR( FT_MEM_QALLOC( ptr, size ) )

#define FT_MEM_SET( dest, byte, count ) ft_memset( dest, byte, (FT_Offset)(count) )
#define FT_MEM_ZERO( dest, count )  FT_MEM_SET( dest, 0, count )
#define FT_ZERO( p ) FT_MEM_ZERO( p, sizeof ( *(p) ) )

#define FT_ASSERT( condition )  do { } while ( 0 )

#define FT_OFFSET( base, count )  ( (base) ? (base) + (count) : NULL )

#define FT_BEGIN_STMNT  do {
#define FT_END_STMNT    } while ( 0 )

#define FT_DEBUG_INNER( exp ) (exp)

#define FT_MEM_FREE( ptr )                                  \
          FT_BEGIN_STMNT                                    \
            FT_DEBUG_INNER( ft_mem_free( memory, (ptr) ) ); \
            (ptr) = NULL;                                   \
          FT_END_STMNT
#define FT_FREE( ptr )  FT_MEM_FREE( ptr )

#define FT_ARRAY_ZERO( dest, count )                             \
          FT_MEM_ZERO( dest,                                     \
                       (FT_Offset)(count) * sizeof ( *(dest) ) )

#define FT_ARRAY_COPY( dest, source, count )                     \
          FT_MEM_COPY( dest,                                     \
                       source,                                   \
                       (FT_Offset)(count) * sizeof ( *(dest) ) )

#define FT_ARRAY_MOVE( dest, source, count )                     \
          FT_MEM_MOVE( dest,                                     \
                       source,                                   \
                       (FT_Offset)(count) * sizeof ( *(dest) ) )

#define FT_MEM_COPY( dest, source, count ) ft_memcpy( dest, source, (FT_Offset)(count) )
#define FT_MEM_MOVE( dest, source, count ) ft_memmove( dest, source, (FT_Offset)(count) )

#define FT_ARRAY_MAX( ptr )           ( FT_INT_MAX / sizeof ( *(ptr) ) )
#define FT_ARRAY_CHECK( ptr, count )  ( (count) <= FT_ARRAY_MAX( ptr ) )

#define FT_STREAM_POS() FT_Stream_Pos( stream )

#define FT_SET_ERROR( expression ) ( ( error = (expression) ) != 0 )

#define FT_STREAM_SEEK( position )                               \
          FT_SET_ERROR( FT_Stream_Seek( stream,                  \
                                        (FT_ULong)(position) ) )

#define FT_STREAM_SKIP( distance )                              \
          FT_SET_ERROR( FT_Stream_Skip( stream,                 \
                                        (FT_Long)(distance) ) )

#define FT_STREAM_READ( buffer, count )                       \
          FT_SET_ERROR( FT_Stream_Read( stream,               \
                                        (FT_Byte*)(buffer),   \
                                        (FT_ULong)(count) ) )

#define FT_STREAM_READ_AT( position, buffer, count )            \
          FT_SET_ERROR( FT_Stream_ReadAt( stream,               \
                                          (FT_ULong)(position), \
                                          (FT_Byte*)(buffer),   \
                                          (FT_ULong)(count) ) )

#define FT_STREAM_READ_FIELDS( fields, object )                          \
          FT_SET_ERROR( FT_Stream_ReadFields( stream, fields, object ) )


#define FT_FRAME_ENTER( size )                                           \
          FT_SET_ERROR(                                                  \
            FT_DEBUG_INNER( FT_Stream_EnterFrame( stream,                \
                                                  (FT_ULong)(size) ) ) )

#define FT_FRAME_EXIT()                                   \
          FT_DEBUG_INNER( FT_Stream_ExitFrame( stream ) )

#define FT_FRAME_EXTRACT( size, bytes )                                       \
          FT_SET_ERROR(                                                       \
            FT_DEBUG_INNER( FT_Stream_ExtractFrame( stream,                   \
                                                    (FT_ULong)(size),         \
                                                    (FT_Byte**)&(bytes) ) ) )

#define FT_FRAME_RELEASE( bytes )                                         \
          FT_DEBUG_INNER( FT_Stream_ReleaseFrame( stream,                 \
                                                  (FT_Byte**)&(bytes) ) )

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

#define FT_HAS_HORIZONTAL( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_HORIZONTAL ) )
#define FT_HAS_VERTICAL( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_VERTICAL ) )
#define FT_HAS_KERNING( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_KERNING ) )
#define FT_IS_SCALABLE( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_SCALABLE ) )
#define FT_IS_SFNT( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_SFNT ) )
#define FT_IS_FIXED_WIDTH( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_FIXED_WIDTH ) )
#define FT_HAS_FIXED_SIZES( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_FIXED_SIZES ) )
#define FT_HAS_FAST_GLYPHS( face )  0
#define FT_HAS_GLYPH_NAMES( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_GLYPH_NAMES ) )
#define FT_HAS_MULTIPLE_MASTERS( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_MULTIPLE_MASTERS ) )
#define FT_IS_NAMED_INSTANCE( face ) ( !!( (face)->face_index & 0x7FFF0000L ) )
#define FT_IS_VARIATION( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_VARIATION ) )
#define FT_IS_CID_KEYED( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_CID_KEYED ) )
#define FT_IS_TRICKY( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_TRICKY ) )
#define FT_HAS_COLOR( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_COLOR ) )
#define FT_HAS_SVG( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_SVG ) )
#define FT_HAS_SBIX( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_SBIX ) )
#define FT_HAS_SBIX_OVERLAY( face ) ( !!( (face)->face_flags & FT_FACE_FLAG_SBIX_OVERLAY ) )
#define FT_STYLE_FLAG_ITALIC  ( 1 << 0 )
#define FT_STYLE_FLAG_BOLD    ( 1 << 1 )

#define FT_OUTLINE_NONE             0x0
#define FT_OUTLINE_OWNER            0x1
#define FT_OUTLINE_EVEN_ODD_FILL    0x2
#define FT_OUTLINE_REVERSE_FILL     0x4
#define FT_OUTLINE_IGNORE_DROPOUTS  0x8
#define FT_OUTLINE_SMART_DROPOUTS   0x10
#define FT_OUTLINE_INCLUDE_STUBS    0x20
#define FT_OUTLINE_OVERLAP          0x40

#define FT_OUTLINE_HIGH_PRECISION   0x100
#define FT_OUTLINE_SINGLE_PASS      0x200

#define ADD_INT( a, b ) (FT_Int)( (FT_UInt)(a) + (FT_UInt)(b) )
#define SUB_INT( a, b ) (FT_Int)( (FT_UInt)(a) - (FT_UInt)(b) )
#define MUL_INT( a, b ) (FT_Int)( (FT_UInt)(a) * (FT_UInt)(b) )
#define NEG_INT( a ) (FT_Int)( (FT_UInt)0 - (FT_UInt)(a) )

#define ADD_LONG( a, b ) (FT_Long)( (FT_ULong)(a) + (FT_ULong)(b) )
#define SUB_LONG( a, b ) (FT_Long)( (FT_ULong)(a) - (FT_ULong)(b) )
#define MUL_LONG( a, b ) (FT_Long)( (FT_ULong)(a) * (FT_ULong)(b) )
#define NEG_LONG( a ) (FT_Long)( (FT_ULong)0 - (FT_ULong)(a) )

#define ADD_INT32( a, b ) (FT_Int32)( (FT_UInt32)(a) + (FT_UInt32)(b) )
#define SUB_INT32( a, b ) (FT_Int32)( (FT_UInt32)(a) - (FT_UInt32)(b) )
#define MUL_INT32( a, b ) (FT_Int32)( (FT_UInt32)(a) * (FT_UInt32)(b) )
#define NEG_INT32( a ) (FT_Int32)( (FT_UInt32)0 - (FT_UInt32)(a) )

#define ADD_INT64( a, b ) (FT_Int64)( (FT_UInt64)(a) + (FT_UInt64)(b) )
#define SUB_INT64( a, b ) (FT_Int64)( (FT_UInt64)(a) - (FT_UInt64)(b) )
#define MUL_INT64( a, b ) (FT_Int64)( (FT_UInt64)(a) * (FT_UInt64)(b) )
#define NEG_INT64( a ) (FT_Int64)( (FT_UInt64)0 - (FT_UInt64)(a) )

#define FT_UINT_TO_POINTER(x) (void*)(x)

#define ON_CURVE_POINT  0x01  /* same value as FT_CURVE_TAG_ON            */
#define X_SHORT_VECTOR  0x02
#define Y_SHORT_VECTOR  0x04
#define REPEAT_FLAG     0x08
#define X_POSITIVE      0x10  /* two meanings depending on X_SHORT_VECTOR */
#define SAME_X          0x10
#define Y_POSITIVE      0x20  /* two meanings depending on Y_SHORT_VECTOR */
#define SAME_Y          0x20
#define OVERLAP_SIMPLE  0x40  /* retained as FT_OUTLINE_OVERLAP           */

#define ARGS_ARE_WORDS             0x0001
#define ARGS_ARE_XY_VALUES         0x0002
#define ROUND_XY_TO_GRID           0x0004
#define WE_HAVE_A_SCALE            0x0008
/* reserved                        0x0010 */
#define MORE_COMPONENTS            0x0020
#define WE_HAVE_AN_XY_SCALE        0x0040
#define WE_HAVE_A_2X2              0x0080
#define WE_HAVE_INSTR              0x0100
#define USE_MY_METRICS             0x0200
#define OVERLAP_COMPOUND           0x0400  /* retained as FT_OUTLINE_OVERLAP */
#define SCALED_COMPONENT_OFFSET    0x0800
#define UNSCALED_COMPONENT_OFFSET  0x1000

#define IS_HINTED( flags )  ( ( flags & FT_LOAD_NO_HINTING ) == 0 )

#define FT_FACE( x )          ( (FT_Face)(x) )
#define FT_SIZE( x )          ( (FT_Size)(x) )
#define FT_SLOT( x )          ( (FT_GlyphSlot)(x) )

#define FT_FACE_DRIVER( x )   FT_FACE( x )->driver
#define FT_FACE_LIBRARY( x )  FT_FACE_DRIVER( x )->root.library
#define FT_FACE_MEMORY( x )   FT_FACE( x )->memory
#define FT_FACE_STREAM( x )   FT_FACE( x )->stream

#define FT_SIZE_FACE( x )     FT_SIZE( x )->face
#define FT_SLOT_FACE( x )     FT_SLOT( x )->face

#define FT_FACE_SLOT( x )     FT_FACE( x )->glyph
#define FT_FACE_SIZE( x )     FT_FACE( x )->size

#define FT_GLYPHLOADER_CHECK_P( _loader, _count )       \
  ( (_count) == 0                                    || \
    ( (FT_UInt)(_loader)->base.outline.n_points    +    \
      (FT_UInt)(_loader)->current.outline.n_points +    \
      (FT_UInt)(_count) ) <= (_loader)->max_points   )

#define FT_GLYPHLOADER_CHECK_C( _loader, _count )         \
  ( (_count) == 0                                      || \
    ( (FT_UInt)(_loader)->base.outline.n_contours    +    \
      (FT_UInt)(_loader)->current.outline.n_contours +    \
      (FT_UInt)(_count) ) <= (_loader)->max_contours   )

#define FT_GLYPHLOADER_CHECK_POINTS( _loader, _points, _contours ) \
  ( ( FT_GLYPHLOADER_CHECK_P( _loader, _points )   &&              \
      FT_GLYPHLOADER_CHECK_C( _loader, _contours ) )               \
    ? 0                                                            \
    : FT_GlyphLoader_CheckPoints( (_loader),                       \
                                  (FT_UInt)(_points),              \
                                  (FT_UInt)(_contours) ) )

#define FT_CURVE_TAG( flag )  ( flag & 0x03 )

#define FT_BYTE_( p, i )  ( ((const FT_Byte*)(p))[(i)] )

#define FT_INT16( x )   ( (FT_Int16)(x)  )
#define FT_UINT16( x )  ( (FT_UInt16)(x) )
#define FT_INT32( x )   ( (FT_Int32)(x)  )
#define FT_UINT32( x )  ( (FT_UInt32)(x) )

#define FT_BYTE_U16( p, i, s )  ( FT_UINT16( FT_BYTE_( p, i ) ) << (s) )
#define FT_BYTE_U32( p, i, s )  ( FT_UINT32( FT_BYTE_( p, i ) ) << (s) )

#define FT_PEEK_SHORT( p )  FT_INT16( FT_BYTE_U16( p, 0, 8 ) | \
                                    FT_BYTE_U16( p, 1, 0 ) )

#define FT_PEEK_USHORT( p )  FT_UINT16( FT_BYTE_U16( p, 0, 8 ) | \
                                      FT_BYTE_U16( p, 1, 0 ) )

#define FT_PEEK_LONG( p )  FT_INT32( FT_BYTE_U32( p, 0, 24 ) | \
                                   FT_BYTE_U32( p, 1, 16 ) | \
                                   FT_BYTE_U32( p, 2,  8 ) | \
                                   FT_BYTE_U32( p, 3,  0 ) )

#define FT_PEEK_ULONG( p )  FT_UINT32( FT_BYTE_U32( p, 0, 24 ) | \
                                     FT_BYTE_U32( p, 1, 16 ) | \
                                     FT_BYTE_U32( p, 2,  8 ) | \
                                     FT_BYTE_U32( p, 3,  0 ) )

#define FT_PEEK_OFF3( p )  ( FT_INT32( FT_BYTE_U32( p, 0, 24 ) | \
                                     FT_BYTE_U32( p, 1, 16 ) | \
                                     FT_BYTE_U32( p, 2,  8 ) ) >> 8 )

#define FT_PEEK_UOFF3( p )  FT_UINT32( FT_BYTE_U32( p, 0, 16 ) | \
                                     FT_BYTE_U32( p, 1,  8 ) | \
                                     FT_BYTE_U32( p, 2,  0 ) )

#define FT_PEEK_SHORT_LE( p )  FT_INT16( FT_BYTE_U16( p, 1, 8 ) | \
                                       FT_BYTE_U16( p, 0, 0 ) )

#define FT_PEEK_USHORT_LE( p )  FT_UINT16( FT_BYTE_U16( p, 1, 8 ) |  \
                                         FT_BYTE_U16( p, 0, 0 ) )

#define FT_PEEK_LONG_LE( p )  FT_INT32( FT_BYTE_U32( p, 3, 24 ) | \
                                      FT_BYTE_U32( p, 2, 16 ) | \
                                      FT_BYTE_U32( p, 1,  8 ) | \
                                      FT_BYTE_U32( p, 0,  0 ) )

#define FT_PEEK_ULONG_LE( p )  FT_UINT32( FT_BYTE_U32( p, 3, 24 ) | \
                                        FT_BYTE_U32( p, 2, 16 ) | \
                                        FT_BYTE_U32( p, 1,  8 ) | \
                                        FT_BYTE_U32( p, 0,  0 ) )

#define FT_PEEK_OFF3_LE( p )  ( FT_INT32( FT_BYTE_U32( p, 2, 24 ) | \
                                        FT_BYTE_U32( p, 1, 16 ) | \
                                        FT_BYTE_U32( p, 0,  8 ) ) >> 8 )

#define FT_PEEK_UOFF3_LE( p )  FT_UINT32( FT_BYTE_U32( p, 2, 16 ) | \
                                        FT_BYTE_U32( p, 1,  8 ) | \
                                        FT_BYTE_U32( p, 0,  0 ) )

#define FT_NEXT_CHAR( buffer ) ( (signed char)*buffer++ )
#define FT_NEXT_BYTE( buffer ) ( (unsigned char)*buffer++ )
#define FT_NEXT_SHORT( buffer ) ( (short)( buffer += 2, FT_PEEK_SHORT( buffer - 2 ) ) )
#define FT_NEXT_USHORT( buffer ) ( (unsigned short)( buffer += 2, FT_PEEK_USHORT( buffer - 2 ) ) )
#define FT_NEXT_OFF3( buffer ) ( (long)( buffer += 3, FT_PEEK_OFF3( buffer - 3 ) ) )
#define FT_NEXT_UOFF3( buffer ) ( (unsigned long)( buffer += 3, FT_PEEK_UOFF3( buffer - 3 ) ) )
#define FT_NEXT_LONG( buffer ) ( (long)( buffer += 4, FT_PEEK_LONG( buffer - 4 ) ) )
#define FT_NEXT_ULONG( buffer ) ( (unsigned long)( buffer += 4, FT_PEEK_ULONG( buffer - 4 ) ) )

#define FT_NEXT_SHORT_LE( buffer ) ( (short)( buffer += 2, FT_PEEK_SHORT_LE( buffer - 2 ) ) )
#define FT_NEXT_USHORT_LE( buffer ) ( (unsigned short)( buffer += 2, FT_PEEK_USHORT_LE( buffer - 2 ) ) )
#define FT_NEXT_OFF3_LE( buffer ) ( (long)( buffer += 3, FT_PEEK_OFF3_LE( buffer - 3 ) ) )
#define FT_NEXT_UOFF3_LE( buffer ) ( (unsigned long)( buffer += 3, FT_PEEK_UOFF3_LE( buffer - 3 ) ) )
#define FT_NEXT_LONG_LE( buffer ) ( (long)( buffer += 4, FT_PEEK_LONG_LE( buffer - 4 ) ) )
#define FT_NEXT_ULONG_LE( buffer ) ( (unsigned long)( buffer += 4, FT_PEEK_ULONG_LE( buffer - 4 ) ) )

#define FT_TRIG_SCALE      0xDBD95B16UL
#define FT_TRIG_SAFE_MSB   29
#define FT_TRIG_MAX_ITERS  23

/* see the `tags` field in `FT_Outline` for a description of the values */
#define FT_CURVE_TAG_ON            0x01
#define FT_CURVE_TAG_CONIC         0x00
#define FT_CURVE_TAG_CUBIC         0x02

#define FT_CURVE_TAG_HAS_SCANMODE  0x04

#define FT_CURVE_TAG_TOUCH_X       0x08  /* reserved for TrueType hinter */
#define FT_CURVE_TAG_TOUCH_Y       0x10  /* reserved for TrueType hinter */

#define FT_CURVE_TAG_TOUCH_BOTH    ( FT_CURVE_TAG_TOUCH_X | FT_CURVE_TAG_TOUCH_Y )

#define FT_MAKE_TAG( _x1, _x2, _x3, _x4 )                  \
          ( ( FT_STATIC_BYTE_CAST( FT_Tag, _x1 ) << 24 ) | \
            ( FT_STATIC_BYTE_CAST( FT_Tag, _x2 ) << 16 ) | \
            ( FT_STATIC_BYTE_CAST( FT_Tag, _x3 ) <<  8 ) | \
              FT_STATIC_BYTE_CAST( FT_Tag, _x4 )         )

#define FT_ANGLE_PI  ( 180L << 16 )
#define FT_ANGLE_2PI  ( FT_ANGLE_PI * 2 )
#define FT_ANGLE_PI2  ( FT_ANGLE_PI / 2 )
#define FT_ANGLE_PI4  ( FT_ANGLE_PI / 4 )

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

#define TT_INTERPRETER_VERSION_35  35
#define TT_INTERPRETER_VERSION_38  38
#define TT_INTERPRETER_VERSION_40  40

#define TTAG_avar  FT_MAKE_TAG( 'a', 'v', 'a', 'r' )
#define TTAG_BASE  FT_MAKE_TAG( 'B', 'A', 'S', 'E' )
#define TTAG_bdat  FT_MAKE_TAG( 'b', 'd', 'a', 't' )
#define TTAG_BDF   FT_MAKE_TAG( 'B', 'D', 'F', ' ' )
#define TTAG_bhed  FT_MAKE_TAG( 'b', 'h', 'e', 'd' )
#define TTAG_bloc  FT_MAKE_TAG( 'b', 'l', 'o', 'c' )
#define TTAG_bsln  FT_MAKE_TAG( 'b', 's', 'l', 'n' )
#define TTAG_CBDT  FT_MAKE_TAG( 'C', 'B', 'D', 'T' )
#define TTAG_CBLC  FT_MAKE_TAG( 'C', 'B', 'L', 'C' )
#define TTAG_CFF   FT_MAKE_TAG( 'C', 'F', 'F', ' ' )
#define TTAG_CFF2  FT_MAKE_TAG( 'C', 'F', 'F', '2' )
#define TTAG_CID   FT_MAKE_TAG( 'C', 'I', 'D', ' ' )
#define TTAG_cmap  FT_MAKE_TAG( 'c', 'm', 'a', 'p' )
#define TTAG_COLR  FT_MAKE_TAG( 'C', 'O', 'L', 'R' )
#define TTAG_CPAL  FT_MAKE_TAG( 'C', 'P', 'A', 'L' )
#define TTAG_cvar  FT_MAKE_TAG( 'c', 'v', 'a', 'r' )
#define TTAG_cvt   FT_MAKE_TAG( 'c', 'v', 't', ' ' )
#define TTAG_DSIG  FT_MAKE_TAG( 'D', 'S', 'I', 'G' )
#define TTAG_EBDT  FT_MAKE_TAG( 'E', 'B', 'D', 'T' )
#define TTAG_EBLC  FT_MAKE_TAG( 'E', 'B', 'L', 'C' )
#define TTAG_EBSC  FT_MAKE_TAG( 'E', 'B', 'S', 'C' )
#define TTAG_feat  FT_MAKE_TAG( 'f', 'e', 'a', 't' )
#define TTAG_FOND  FT_MAKE_TAG( 'F', 'O', 'N', 'D' )
#define TTAG_fpgm  FT_MAKE_TAG( 'f', 'p', 'g', 'm' )
#define TTAG_fvar  FT_MAKE_TAG( 'f', 'v', 'a', 'r' )
#define TTAG_gasp  FT_MAKE_TAG( 'g', 'a', 's', 'p' )
#define TTAG_GDEF  FT_MAKE_TAG( 'G', 'D', 'E', 'F' )
#define TTAG_glyf  FT_MAKE_TAG( 'g', 'l', 'y', 'f' )
#define TTAG_GPOS  FT_MAKE_TAG( 'G', 'P', 'O', 'S' )
#define TTAG_GSUB  FT_MAKE_TAG( 'G', 'S', 'U', 'B' )
#define TTAG_gvar  FT_MAKE_TAG( 'g', 'v', 'a', 'r' )
#define TTAG_HVAR  FT_MAKE_TAG( 'H', 'V', 'A', 'R' )
#define TTAG_hdmx  FT_MAKE_TAG( 'h', 'd', 'm', 'x' )
#define TTAG_head  FT_MAKE_TAG( 'h', 'e', 'a', 'd' )
#define TTAG_hhea  FT_MAKE_TAG( 'h', 'h', 'e', 'a' )
#define TTAG_hmtx  FT_MAKE_TAG( 'h', 'm', 't', 'x' )
#define TTAG_JSTF  FT_MAKE_TAG( 'J', 'S', 'T', 'F' )
#define TTAG_just  FT_MAKE_TAG( 'j', 'u', 's', 't' )
#define TTAG_kern  FT_MAKE_TAG( 'k', 'e', 'r', 'n' )
#define TTAG_lcar  FT_MAKE_TAG( 'l', 'c', 'a', 'r' )
#define TTAG_loca  FT_MAKE_TAG( 'l', 'o', 'c', 'a' )
#define TTAG_LTSH  FT_MAKE_TAG( 'L', 'T', 'S', 'H' )
#define TTAG_LWFN  FT_MAKE_TAG( 'L', 'W', 'F', 'N' )
#define TTAG_MATH  FT_MAKE_TAG( 'M', 'A', 'T', 'H' )
#define TTAG_maxp  FT_MAKE_TAG( 'm', 'a', 'x', 'p' )
#define TTAG_META  FT_MAKE_TAG( 'M', 'E', 'T', 'A' )
#define TTAG_MMFX  FT_MAKE_TAG( 'M', 'M', 'F', 'X' )
#define TTAG_MMSD  FT_MAKE_TAG( 'M', 'M', 'S', 'D' )
#define TTAG_mort  FT_MAKE_TAG( 'm', 'o', 'r', 't' )
#define TTAG_morx  FT_MAKE_TAG( 'm', 'o', 'r', 'x' )
#define TTAG_MVAR  FT_MAKE_TAG( 'M', 'V', 'A', 'R' )
#define TTAG_name  FT_MAKE_TAG( 'n', 'a', 'm', 'e' )
#define TTAG_opbd  FT_MAKE_TAG( 'o', 'p', 'b', 'd' )
#define TTAG_OS2   FT_MAKE_TAG( 'O', 'S', '/', '2' )
#define TTAG_OTTO  FT_MAKE_TAG( 'O', 'T', 'T', 'O' )
#define TTAG_PCLT  FT_MAKE_TAG( 'P', 'C', 'L', 'T' )
#define TTAG_POST  FT_MAKE_TAG( 'P', 'O', 'S', 'T' )
#define TTAG_post  FT_MAKE_TAG( 'p', 'o', 's', 't' )
#define TTAG_prep  FT_MAKE_TAG( 'p', 'r', 'e', 'p' )
#define TTAG_prop  FT_MAKE_TAG( 'p', 'r', 'o', 'p' )
#define TTAG_sbix  FT_MAKE_TAG( 's', 'b', 'i', 'x' )
#define TTAG_sfnt  FT_MAKE_TAG( 's', 'f', 'n', 't' )
#define TTAG_SING  FT_MAKE_TAG( 'S', 'I', 'N', 'G' )
#define TTAG_SVG   FT_MAKE_TAG( 'S', 'V', 'G', ' ' )
#define TTAG_trak  FT_MAKE_TAG( 't', 'r', 'a', 'k' )
#define TTAG_true  FT_MAKE_TAG( 't', 'r', 'u', 'e' )
#define TTAG_ttc   FT_MAKE_TAG( 't', 't', 'c', ' ' )
#define TTAG_ttcf  FT_MAKE_TAG( 't', 't', 'c', 'f' )
#define TTAG_TYP1  FT_MAKE_TAG( 'T', 'Y', 'P', '1' )
#define TTAG_typ1  FT_MAKE_TAG( 't', 'y', 'p', '1' )
#define TTAG_VDMX  FT_MAKE_TAG( 'V', 'D', 'M', 'X' )
#define TTAG_vhea  FT_MAKE_TAG( 'v', 'h', 'e', 'a' )
#define TTAG_vmtx  FT_MAKE_TAG( 'v', 'm', 't', 'x' )
#define TTAG_VVAR  FT_MAKE_TAG( 'V', 'V', 'A', 'R' )
#define TTAG_wOFF  FT_MAKE_TAG( 'w', 'O', 'F', 'F' )
#define TTAG_wOF2  FT_MAKE_TAG( 'w', 'O', 'F', '2' )

/* used by "Keyboard.dfont" on legacy Mac OS X */
#define TTAG_0xA5kbd  FT_MAKE_TAG( 0xA5, 'k', 'b', 'd' )

/* used by "LastResort.dfont" on legacy Mac OS X */
#define TTAG_0xA5lst  FT_MAKE_TAG( 0xA5, 'l', 's', 't' )

//
// SECTION Types
//

typedef uint16_t FT_UInt16;
typedef uint32_t FT_UInt32;
typedef uint64_t FT_UInt64;
typedef int16_t FT_Int16;
typedef int32_t FT_Int32;
typedef int64_t FT_Int64;

typedef ptrdiff_t ft_ptrdiff_t;

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
typedef FT_Fixed FT_Angle;

typedef int             Int;
typedef unsigned int    UInt;
typedef short           Short;
typedef unsigned short  UShort, *PUShort;
typedef long            Long, *PLong;
typedef unsigned long   ULong;

typedef unsigned char   Byte, *PByte;
typedef char            Bool;

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

typedef struct FT_LayerIterator_ {
  FT_UInt   num_layers;
  FT_UInt   layer;
  FT_Byte*  p;
} FT_LayerIterator;

typedef enum FT_Color_Root_Transform_ {
  FT_COLOR_INCLUDE_ROOT_TRANSFORM,
  FT_COLOR_NO_ROOT_TRANSFORM,
  FT_COLOR_ROOT_TRANSFORM_MAX
} FT_Color_Root_Transform;

typedef struct FT_Opaque_Paint_ {
  FT_Byte*  p;
  FT_Bool   insert_root_transform;
} FT_OpaquePaint;

typedef struct FT_ClipBox_ {
  FT_Vector  bottom_left;
  FT_Vector  top_left;
  FT_Vector  top_right;
  FT_Vector  bottom_right;
} FT_ClipBox;

typedef struct FT_ColorIndex_ {
  FT_UInt16   palette_index;
  FT_F2Dot14  alpha;
} FT_ColorIndex;

typedef struct FT_ColorStop_ {
  FT_F2Dot14     stop_offset;
  FT_ColorIndex  color;
} FT_ColorStop;

typedef struct FT_ColorStopIterator_ {
  FT_UInt  num_color_stops;
  FT_UInt  current_color_stop;
  FT_Byte*  p;
} FT_ColorStopIterator;

typedef enum FT_PaintExtend_ {
  FT_COLR_PAINT_EXTEND_PAD     = 0,
  FT_COLR_PAINT_EXTEND_REPEAT  = 1,
  FT_COLR_PAINT_EXTEND_REFLECT = 2
} FT_PaintExtend;

typedef struct FT_ColorLine_ {
  FT_PaintExtend        extend;
  FT_ColorStopIterator  color_stop_iterator;
} FT_ColorLine;

typedef enum FT_PaintFormat_ {
  FT_COLR_PAINTFORMAT_COLR_LAYERS     = 1,
  FT_COLR_PAINTFORMAT_SOLID           = 2,
  FT_COLR_PAINTFORMAT_LINEAR_GRADIENT = 4,
  FT_COLR_PAINTFORMAT_RADIAL_GRADIENT = 6,
  FT_COLR_PAINTFORMAT_SWEEP_GRADIENT  = 8,
  FT_COLR_PAINTFORMAT_GLYPH           = 10,
  FT_COLR_PAINTFORMAT_COLR_GLYPH      = 11,
  FT_COLR_PAINTFORMAT_TRANSFORM       = 12,
  FT_COLR_PAINTFORMAT_TRANSLATE       = 14,
  FT_COLR_PAINTFORMAT_SCALE           = 16,
  FT_COLR_PAINTFORMAT_ROTATE          = 24,
  FT_COLR_PAINTFORMAT_SKEW            = 28,
  FT_COLR_PAINTFORMAT_COMPOSITE       = 32,
  FT_COLR_PAINT_FORMAT_MAX            = 33,
  FT_COLR_PAINTFORMAT_UNSUPPORTED     = 255
} FT_PaintFormat;

typedef struct FT_PaintGlyph_ {
  FT_OpaquePaint  paint;
  FT_UInt         glyphID;
} FT_PaintGlyph;

typedef struct FT_PaintSolid_ {
  FT_ColorIndex  color;
} FT_PaintSolid;

typedef struct FT_PaintLinearGradient_ {
  FT_ColorLine  colorline;
  /* TODO: Potentially expose those as x0, y0 etc. */
  FT_Vector  p0;
  FT_Vector  p1;
  FT_Vector  p2;
} FT_PaintLinearGradient;

typedef struct FT_PaintRadialGradient_ {
  FT_ColorLine  colorline;
  FT_Vector  c0;
  FT_Pos     r0;
  FT_Vector  c1;
  FT_Pos     r1;
} FT_PaintRadialGradient;

typedef struct FT_PaintColrLayers_ {
  FT_LayerIterator  layer_iterator;
} FT_PaintColrLayers;

typedef struct FT_PaintSweepGradient_ {
  FT_ColorLine  colorline;
  FT_Vector  center;
  FT_Fixed   start_angle;
  FT_Fixed   end_angle;
} FT_PaintSweepGradient;

typedef struct FT_Affine_23_ {
  FT_Fixed  xx, xy, dx;
  FT_Fixed  yx, yy, dy;
} FT_Affine23;

typedef struct FT_PaintTransform_ {
  FT_OpaquePaint  paint;
  FT_Affine23     affine;
} FT_PaintTransform;

typedef struct FT_PaintTranslate_ {
  FT_OpaquePaint  paint;
  FT_Fixed  dx;
  FT_Fixed  dy;
} FT_PaintTranslate;

typedef struct FT_PaintScale_ {
  FT_OpaquePaint  paint;
  FT_Fixed  scale_x;
  FT_Fixed  scale_y;
  FT_Fixed  center_x;
  FT_Fixed  center_y;
} FT_PaintScale;

typedef struct FT_PaintRotate_ {
  FT_OpaquePaint  paint;
  FT_Fixed  angle;
  FT_Fixed  center_x;
  FT_Fixed  center_y;
} FT_PaintRotate;

typedef struct  FT_PaintSkew_ {
  FT_OpaquePaint  paint;
  FT_Fixed  x_skew_angle;
  FT_Fixed  y_skew_angle;
  FT_Fixed  center_x;
  FT_Fixed  center_y;
} FT_PaintSkew;

typedef enum FT_Composite_Mode_ {
  FT_COLR_COMPOSITE_CLEAR          = 0,
  FT_COLR_COMPOSITE_SRC            = 1,
  FT_COLR_COMPOSITE_DEST           = 2,
  FT_COLR_COMPOSITE_SRC_OVER       = 3,
  FT_COLR_COMPOSITE_DEST_OVER      = 4,
  FT_COLR_COMPOSITE_SRC_IN         = 5,
  FT_COLR_COMPOSITE_DEST_IN        = 6,
  FT_COLR_COMPOSITE_SRC_OUT        = 7,
  FT_COLR_COMPOSITE_DEST_OUT       = 8,
  FT_COLR_COMPOSITE_SRC_ATOP       = 9,
  FT_COLR_COMPOSITE_DEST_ATOP      = 10,
  FT_COLR_COMPOSITE_XOR            = 11,
  FT_COLR_COMPOSITE_PLUS           = 12,
  FT_COLR_COMPOSITE_SCREEN         = 13,
  FT_COLR_COMPOSITE_OVERLAY        = 14,
  FT_COLR_COMPOSITE_DARKEN         = 15,
  FT_COLR_COMPOSITE_LIGHTEN        = 16,
  FT_COLR_COMPOSITE_COLOR_DODGE    = 17,
  FT_COLR_COMPOSITE_COLOR_BURN     = 18,
  FT_COLR_COMPOSITE_HARD_LIGHT     = 19,
  FT_COLR_COMPOSITE_SOFT_LIGHT     = 20,
  FT_COLR_COMPOSITE_DIFFERENCE     = 21,
  FT_COLR_COMPOSITE_EXCLUSION      = 22,
  FT_COLR_COMPOSITE_MULTIPLY       = 23,
  FT_COLR_COMPOSITE_HSL_HUE        = 24,
  FT_COLR_COMPOSITE_HSL_SATURATION = 25,
  FT_COLR_COMPOSITE_HSL_COLOR      = 26,
  FT_COLR_COMPOSITE_HSL_LUMINOSITY = 27,
  FT_COLR_COMPOSITE_MAX            = 28
} FT_Composite_Mode;

typedef struct FT_PaintComposite_ {
  FT_OpaquePaint     source_paint;
  FT_Composite_Mode  composite_mode;
  FT_OpaquePaint     backdrop_paint;
} FT_PaintComposite;

typedef struct FT_PaintColrGlyph_ {
  FT_UInt  glyphID;
} FT_PaintColrGlyph;

typedef struct  FT_COLR_Paint_ {
  FT_PaintFormat format;
  union {
    FT_PaintColrLayers      colr_layers;
    FT_PaintGlyph           glyph;
    FT_PaintSolid           solid;
    FT_PaintLinearGradient  linear_gradient;
    FT_PaintRadialGradient  radial_gradient;
    FT_PaintSweepGradient   sweep_gradient;
    FT_PaintTransform       transform;
    FT_PaintTranslate       translate;
    FT_PaintScale           scale;
    FT_PaintRotate          rotate;
    FT_PaintSkew            skew;
    FT_PaintComposite       composite;
    FT_PaintColrGlyph       colr_glyph;
  } u;
} FT_COLR_Paint;

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
typedef struct TT_DriverRec_*  TT_Driver;

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

typedef struct TT_SBit_MetricsRec_ {
  FT_UShort  height;
  FT_UShort  width;

  FT_Short   horiBearingX;
  FT_Short   horiBearingY;
  FT_UShort  horiAdvance;

  FT_Short   vertBearingX;
  FT_Short   vertBearingY;
  FT_UShort  vertAdvance;
} TT_SBit_MetricsRec, *TT_SBit_Metrics;

typedef struct TT_SBit_RangeRec_ {
  FT_UShort           first_glyph;
  FT_UShort           last_glyph;

  FT_UShort           index_format;
  FT_UShort           image_format;
  FT_ULong            image_offset;

  FT_ULong            image_size;
  TT_SBit_MetricsRec  metrics;
  FT_ULong            num_glyphs;

  FT_ULong*           glyph_offsets;
  FT_UShort*          glyph_codes;

  FT_ULong            table_offset;
} TT_SBit_RangeRec, *TT_SBit_Range;

typedef struct TT_SBit_StrikeRec_ {
  FT_Int                  num_ranges;
  TT_SBit_Range           sbit_ranges;
  FT_ULong                ranges_offset;

  FT_ULong                color_ref;

  TT_SBit_LineMetricsRec  hori;
  TT_SBit_LineMetricsRec  vert;

  FT_UShort               start_glyph;
  FT_UShort               end_glyph;

  FT_Byte                 x_ppem;
  FT_Byte                 y_ppem;

  FT_Byte                 bit_depth;
  FT_Char                 flags;
} TT_SBit_StrikeRec, *TT_SBit_Strike;

typedef FT_Error
  (*TT_Init_Face_Func)( FT_Stream      stream,
                        TT_Face        face,
                        FT_Int         face_index,
                        FT_Int         num_params,
                        FT_Parameter*  params );

typedef FT_Error
  (*TT_Load_Face_Func)( FT_Stream      stream,
                        TT_Face        face,
                        FT_Int         face_index,
                        FT_Int         num_params,
                        FT_Parameter*  params );

typedef void
  (*TT_Done_Face_Func)( TT_Face  face );

typedef FT_Error
  (*TT_Load_Any_Func)( TT_Face    face,
                       FT_ULong   tag,
                       FT_Long    offset,
                       FT_Byte   *buffer,
                       FT_ULong*  length );

typedef FT_Error
  (*TT_Find_SBit_Image_Func)( TT_Face          face,
                              FT_UInt          glyph_index,
                              FT_ULong         strike_index,
                              TT_SBit_Range   *arange,
                              TT_SBit_Strike  *astrike,
                              FT_ULong        *aglyph_offset );

typedef FT_Error
  (*TT_Load_SBit_Metrics_Func)( FT_Stream        stream,
                                TT_SBit_Range    range,
                                TT_SBit_Metrics  metrics );

typedef FT_Error
  (*TT_Load_SBit_Image_Func)( TT_Face              face,
                              FT_ULong             strike_index,
                              FT_UInt              glyph_index,
                              FT_UInt              load_flags,
                              FT_Stream            stream,
                              FT_Bitmap           *amap,
                              TT_SBit_MetricsRec  *ametrics );

typedef FT_Error
  (*TT_Load_Svg_Doc_Func)( FT_GlyphSlot  glyph,
                           FT_UInt       glyph_index );

typedef FT_Error
  (*TT_Set_SBit_Strike_Func)( TT_Face          face,
                              FT_Size_Request  req,
                              FT_ULong*        astrike_index );

typedef FT_Error
  (*TT_Load_Strike_Metrics_Func)( TT_Face           face,
                                  FT_ULong          strike_index,
                                  FT_Size_Metrics*  metrics );

typedef FT_Error
  (*TT_Get_PS_Name_Func)( TT_Face      face,
                          FT_UInt      idx,
                          FT_String**  PSname );

typedef FT_Error
  (*TT_Load_Metrics_Func)( TT_Face    face,
                           FT_Stream  stream,
                           FT_Bool    vertical );

typedef void
  (*TT_Get_Metrics_Func)( TT_Face     face,
                          FT_Bool     vertical,
                          FT_UInt     gindex,
                          FT_Short*   abearing,
                          FT_UShort*  aadvance );

typedef FT_Error
  (*TT_Set_Palette_Func)( TT_Face  face,
                          FT_UInt  idx );

typedef FT_Bool
  (*TT_Get_Colr_Layer_Func)( TT_Face            face,
                             FT_UInt            base_glyph,
                             FT_UInt           *aglyph_index,
                             FT_UInt           *acolor_index,
                             FT_LayerIterator*  iterator );

typedef FT_Bool
  ( *TT_Get_Color_Glyph_Paint_Func )( TT_Face                   face,
                                      FT_UInt                   base_glyph,
                                      FT_Color_Root_Transform   root_transform,
                                      FT_OpaquePaint           *paint );

typedef FT_Bool
  ( *TT_Get_Color_Glyph_ClipBox_Func )( TT_Face      face,
                                        FT_UInt      base_glyph,
                                        FT_ClipBox*  clip_box );

typedef FT_Bool
  ( *TT_Get_Paint_Layers_Func )( TT_Face            face,
                                 FT_LayerIterator*  iterator,
                                 FT_OpaquePaint    *paint );

typedef FT_Bool
  ( *TT_Get_Colorline_Stops_Func )( TT_Face                face,
                                    FT_ColorStop          *color_stop,
                                    FT_ColorStopIterator*  iterator );

typedef FT_Bool
  ( *TT_Get_Paint_Func )( TT_Face         face,
                          FT_OpaquePaint  opaque_paint,
                          FT_COLR_Paint  *paint );

typedef FT_Error
  (*TT_Blend_Colr_Func)( TT_Face       face,
                         FT_UInt       color_index,
                         FT_GlyphSlot  base_glyph,
                         FT_GlyphSlot  new_glyph );

typedef FT_Error
  (*TT_Get_Name_Func)( TT_Face      face,
                       FT_UShort    nameid,
                       FT_String**  name );

typedef FT_Bool
  (*TT_Get_Name_ID_Func)( TT_Face    face,
                          FT_UShort  nameid,
                          FT_Int    *win,
                          FT_Int    *apple );

typedef FT_Error
  (*TT_Load_Table_Func)( TT_Face    face,
                         FT_Stream  stream );

typedef void
  (*TT_Free_Table_Func)( TT_Face  face );

typedef FT_Int
  (*TT_Face_GetKerningFunc)( TT_Face  face,
                             FT_UInt  left_glyph,
                             FT_UInt  right_glyph );

typedef struct  SFNT_Interface_
{
  TT_Loader_GotoTableFunc  goto_table;

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

int
ft_strncmp(const char *s1, const char *s2, size_t n) {
  if (n == 0)
    return (0);
  do {
    if (*s1 != *s2++)
      return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
    if (*s1++ == '\0')
      break;
  } while (--n != 0);
  return (0);
}

//
// SECTION Calc
//

static const FT_Angle
ft_trig_arctan_table[] = {
  1740967L, 919879L, 466945L, 234379L, 117304L, 58666L, 29335L,
  14668L, 7334L, 3667L, 1833L, 917L, 458L, 229L, 115L,
  57L, 29L, 14L, 7L, 4L, 2L, 1L
};

static FT_Fixed
ft_trig_downscale( FT_Fixed  val )
{
  FT_Int  s = 1;

  if ( val < 0 )
  {
     val = -val;
     s = -1;
  }

  val = (FT_Fixed)(
          ( (FT_UInt64)val * FT_TRIG_SCALE + 0x40000000UL ) >> 32 );

  return s < 0 ? -val : val;
}

static void
ft_trig_pseudo_polarize( FT_Vector*  vec )
{
  FT_Angle         theta;
  FT_Int           i;
  FT_Fixed         x, y, xtemp, b;
  const FT_Angle  *arctanptr;
  x = vec->x;
  y = vec->y;

  /* Get the vector into [-PI/4,PI/4] sector */
  if ( y > x )
  {
    if ( y > -x )
    {
      theta =  FT_ANGLE_PI2;
      xtemp =  y;
      y     = -x;
      x     =  xtemp;
    }
    else
    {
      theta =  y > 0 ? FT_ANGLE_PI : -FT_ANGLE_PI;
      x     = -x;
      y     = -y;
    }
  }
  else
  {
    if ( y < -x )
    {
      theta = -FT_ANGLE_PI2;
      xtemp = -y;
      y     =  x;
      x     =  xtemp;
    }
    else
    {
      theta = 0;
    }
  }

  arctanptr = ft_trig_arctan_table;

  /* Pseudorotations, with right shifts */
  for ( i = 1, b = 1; i < FT_TRIG_MAX_ITERS; b <<= 1, i++ )
  {
    if ( y > 0 )
    {
      xtemp  = x + ( ( y + b ) >> i );
      y      = y - ( ( x + b ) >> i );
      x      = xtemp;
      theta += *arctanptr++;
    }
    else
    {
      xtemp  = x - ( ( y + b ) >> i );
      y      = y + ( ( x + b ) >> i );
      x      = xtemp;
      theta -= *arctanptr++;
    }
  }

  /* round theta to acknowledge its error that mostly comes */
  /* from accumulated rounding errors in the arctan table   */
  if ( theta >= 0 )
    theta = FT_PAD_ROUND( theta, 16 );
  else
    theta = -FT_PAD_ROUND( -theta, 16 );

  vec->x = x;
  vec->y = theta;
}

FT_BASE_DEF( FT_Int )
FT_MSB( FT_UInt32 z )
{
  FT_Int  shift = 0;

  /* determine msb bit index in `shift' */
  if ( z & 0xFFFF0000UL )
  {
    z     >>= 16;
    shift  += 16;
  }
  if ( z & 0x0000FF00UL )
  {
    z     >>= 8;
    shift  += 8;
  }
  if ( z & 0x000000F0UL )
  {
    z     >>= 4;
    shift  += 4;
  }
  if ( z & 0x0000000CUL )
  {
    z     >>= 2;
    shift  += 2;
  }
  if ( z & 0x00000002UL )
  {
 /* z     >>= 1; */
    shift  += 1;
  }

  return shift;
}

static FT_Int
ft_trig_prenorm( FT_Vector*  vec )
{
  FT_Pos  x, y;
  FT_Int  shift;

  x = vec->x;
  y = vec->y;

  shift = FT_MSB( (FT_UInt32)( FT_ABS( x ) | FT_ABS( y ) ) );

  if ( shift <= FT_TRIG_SAFE_MSB )
  {
    shift  = FT_TRIG_SAFE_MSB - shift;
    vec->x = (FT_Pos)( (FT_ULong)x << shift );
    vec->y = (FT_Pos)( (FT_ULong)y << shift );
  }
  else
  {
    shift -= FT_TRIG_SAFE_MSB;
    vec->x = x >> shift;
    vec->y = y >> shift;
    shift  = -shift;
  }

  return shift;
}

FT_EXPORT_DEF( FT_Fixed )
FT_Vector_Length( FT_Vector*  vec )
{
  FT_Int     shift;
  FT_Vector  v;


  if ( !vec )
    return 0;

  v = *vec;

  /* handle trivial cases */
  if ( v.x == 0 )
  {
    return FT_ABS( v.y );
  }
  else if ( v.y == 0 )
  {
    return FT_ABS( v.x );
  }
  /* general case */
  shift = ft_trig_prenorm( &v );
  ft_trig_pseudo_polarize( &v );

  v.x = ft_trig_downscale( v.x );
  if ( shift > 0 )
    return ( v.x + ( 1L << ( shift - 1 ) ) ) >> shift;

  return (FT_Fixed)( (FT_UInt32)v.x << -shift );
}

FT_BASE_DEF( FT_Fixed )
FT_Hypot( FT_Fixed  x,
          FT_Fixed  y )
{
  FT_Vector  v;

  v.x = x;
  v.y = y;

  return FT_Vector_Length( &v );
}

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

FT_EXPORT_DEF( void )
FT_Vector_Transform( FT_Vector*        vector,
                     const FT_Matrix*  matrix )
{
  FT_Pos  xz, yz;

  if ( !vector || !matrix )
    return;

  xz = FT_MulFix( vector->x, matrix->xx ) +
       FT_MulFix( vector->y, matrix->xy );

  yz = FT_MulFix( vector->x, matrix->yx ) +
       FT_MulFix( vector->y, matrix->yy );

  vector->x = xz;
  vector->y = yz;
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

static FT_ListNode
ft_list_get_node_at( FT_List  list,
                     FT_UInt  idx )
{
  FT_ListNode  cur;

  if ( !list )
    return NULL;

  for ( cur = list->head; cur; cur = cur->next )
  {
    if ( !idx )
      return cur;

    idx--;
  }

  return NULL;
}

//
// SECTION Stream
//

FT_BASE_DEF( void )
FT_Stream_ExitFrame( FT_Stream  stream )
{
  /* IMPORTANT: The assertion stream->cursor != 0 was removed, given    */
  /*            that it is possible to access a frame of length 0 in    */
  /*            some weird fonts (usually, when accessing an array of   */
  /*            0 records, like in some strange kern tables).           */
  /*                                                                    */
  /*  In this case, the loader code handles the 0-length table          */
  /*  gracefully; however, stream.cursor is really set to 0 by the      */
  /*  FT_Stream_EnterFrame() call, and this is not an error.            */

#if FREETYPE_WONT_INCLUDE
  FT_TRACE7(( "FT_Stream_ExitFrame\n" ));
#endif

  FT_ASSERT( stream );

  if ( stream->read )
  {
    FT_Memory  memory = stream->memory;


#ifdef FT_DEBUG_MEMORY
    ft_mem_free( memory, stream->base );
    stream->base = NULL;
#else
    FT_FREE( stream->base );
#endif
  }

  stream->cursor = NULL;
  stream->limit  = NULL;
}

FT_BASE_DEF( FT_Error )
FT_Stream_EnterFrame( FT_Stream  stream,
                      FT_ULong   count )
{
  FT_Error  error = FT_Err_Ok;
  FT_ULong  read_bytes;

#if FREETYPE_WONT_INCLUDE
  FT_TRACE7(( "FT_Stream_EnterFrame: %ld bytes\n", count ));
#endif

  /* check for nested frame access */
  FT_ASSERT( stream && stream->cursor == 0 );

  if ( stream->read )
  {
    /* allocate the frame in memory */
    FT_Memory  memory = stream->memory;


    /* simple sanity check */
    if ( count > stream->size )
    {
      #if FREETYPE_WONT_INCLUDE
      FT_ERROR(( "FT_Stream_EnterFrame:"
                 " frame size (%lu) larger than stream size (%lu)\n",
                 count, stream->size ));
      #endif
      error = FT_THROW( Invalid_Stream_Operation );
      goto Exit;
    }

#ifdef FT_DEBUG_MEMORY
    /* assume _ft_debug_file and _ft_debug_lineno are already set */
    stream->base = (unsigned char*)ft_mem_qalloc( memory,
                                                  (FT_Long)count,
                                                  &error );
    if ( error )
      goto Exit;
#else
    if ( FT_QALLOC( stream->base, count ) )
      goto Exit;
#endif
    /* read it */
    read_bytes = stream->read( stream, stream->pos,
                               stream->base, count );
    if ( read_bytes < count )
    {
      #if FREETYPE_WONT_INCLUDE
      FT_ERROR(( "FT_Stream_EnterFrame:"
                 " invalid read; expected %lu bytes, got %lu\n",
                 count, read_bytes ));
      #endif
      FT_FREE( stream->base );
      error = FT_THROW( Invalid_Stream_Operation );
    }

    stream->cursor = stream->base;
    stream->limit  = FT_OFFSET( stream->cursor, count );
    stream->pos   += read_bytes;
  }
  else
  {
    /* check current and new position */
    if ( stream->pos >= stream->size        ||
         stream->size - stream->pos < count )
    {
      #if FREETYPE_WONT_INCLUDE
      FT_ERROR(( "FT_Stream_EnterFrame:"
                 " invalid i/o; pos = 0x%lx, count = %lu, size = 0x%lx\n",
                 stream->pos, count, stream->size ));
      #endif
      error = FT_THROW( Invalid_Stream_Operation );
      goto Exit;
    }

    /* set cursor */
    stream->cursor = stream->base + stream->pos;
    stream->limit  = stream->cursor + count;
    stream->pos   += count;
  }
Exit:
  return error;
}

FT_BASE_DEF( void )
FT_Stream_ReleaseFrame( FT_Stream  stream,
                        FT_Byte**  pbytes )
{
  if ( stream && stream->read )
  {
    FT_Memory  memory = stream->memory;

#ifdef FT_DEBUG_MEMORY
    ft_mem_free( memory, *pbytes );
#else
    FT_FREE( *pbytes );
#endif
  }

  *pbytes = NULL;
}

FT_BASE_DEF( FT_Error )
FT_Stream_Seek( FT_Stream  stream,
                FT_ULong   pos )
{
  FT_Error  error = FT_Err_Ok;


  if ( stream->read )
  {
    if ( stream->read( stream, pos, NULL, 0 ) )
    {
      #if FREETYPE_WONT_INCLUDE
      FT_ERROR(( "FT_Stream_Seek:"
                 " invalid i/o; pos = 0x%lx, size = 0x%lx\n",
                 pos, stream->size ));
      #endif
      error = FT_THROW( Invalid_Stream_Operation );
    }
  }
  /* note that seeking to the first position after the file is valid */
  else if ( pos > stream->size )
  {
    #if FREETYPE_WONT_INCLUDE
    FT_ERROR(( "FT_Stream_Seek:"
               " invalid i/o; pos = 0x%lx, size = 0x%lx\n",
               pos, stream->size ));
    #endif
    error = FT_THROW( Invalid_Stream_Operation );
  }

  if ( !error )
    stream->pos = pos;

  return error;
}

FT_BASE_DEF( FT_ULong )
FT_Stream_Pos( FT_Stream  stream )
{
  return stream->pos;
}

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

FT_EXPORT_DEF( FT_Error )
FT_Get_Glyph_Name( FT_Face     face,
                   FT_UInt     glyph_index,
                   FT_Pointer  buffer,
                   FT_UInt     buffer_max )
{
  FT_Error              error;
#if 0
  FT_Service_GlyphDict  service;

  if ( !face )
    return FT_THROW( Invalid_Face_Handle );

  if ( !buffer || buffer_max == 0 )
    return FT_THROW( Invalid_Argument );

  /* clean up buffer */
  ((FT_Byte*)buffer)[0] = '\0';

  if ( (FT_Long)glyph_index >= face->num_glyphs )
    return FT_THROW( Invalid_Glyph_Index );

  if ( !FT_HAS_GLYPH_NAMES( face ) )
    return FT_THROW( Invalid_Argument );

  FT_FACE_LOOKUP_SERVICE( face, service, GLYPH_DICT );
  if ( service && service->get_name )
    error = service->get_name( face, glyph_index, buffer, buffer_max );
  else
    error = FT_THROW( Invalid_Argument );
#endif

  return error;
}


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
FT_GlyphLoader_CheckSubGlyphs( FT_GlyphLoader  loader,
                               FT_UInt         n_subs )
{
  FT_Memory     memory = loader->memory;
  FT_Error      error  = FT_Err_Ok;
  FT_UInt       new_max, old_max;

  FT_GlyphLoad  base    = &loader->base;
  FT_GlyphLoad  current = &loader->current;
#if 0
  new_max = base->num_subglyphs + current->num_subglyphs + n_subs;
  old_max = loader->max_subglyphs;
  if ( new_max > old_max )
  {
    new_max = FT_PAD_CEIL( new_max, 2 );
    if ( FT_RENEW_ARRAY( base->subglyphs, old_max, new_max ) )
      goto Exit;

    loader->max_subglyphs = new_max;

    FT_GlyphLoader_Adjust_Subglyphs( loader );
  }
#endif
Exit:
  return error;
}

FT_BASE_DEF( void )
FT_GlyphLoader_Rewind( FT_GlyphLoader  loader )
{
  FT_GlyphLoad  base    = &loader->base;
  FT_GlyphLoad  current = &loader->current;

  base->outline.n_points   = 0;
  base->outline.n_contours = 0;
  base->outline.flags      = 0;
  base->num_subglyphs      = 0;

  *current = *base;
}

FT_BASE_DEF( void )
FT_GlyphLoader_Add( FT_GlyphLoader  loader )
{
  FT_GlyphLoad  base;
  FT_GlyphLoad  current;

  FT_Int        n_curr_contours;
  FT_Int        n_base_points;
  FT_Int        n;


  if ( !loader )
    return;
#if 0
  base    = &loader->base;
  current = &loader->current;

  n_curr_contours = current->outline.n_contours;
  n_base_points   = base->outline.n_points;

  base->outline.n_points =
    (short)( base->outline.n_points + current->outline.n_points );
  base->outline.n_contours =
    (short)( base->outline.n_contours + current->outline.n_contours );

  base->num_subglyphs += current->num_subglyphs;

  /* adjust contours count in newest outline */
  for ( n = 0; n < n_curr_contours; n++ )
    current->outline.contours[n] =
      (short)( current->outline.contours[n] + n_base_points );

  /* prepare for another new glyph image */
  FT_GlyphLoader_Prepare( loader );
#endif
}

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

FT_BASE_DEF( FT_Error )
FT_GlyphLoader_CheckPoints( FT_GlyphLoader  loader,
                            FT_UInt         n_points,
                            FT_UInt         n_contours )
{
  FT_Memory    memory  = loader->memory;
  FT_Error     error   = FT_Err_Ok;
  FT_Outline*  base    = &loader->base.outline;
  FT_Outline*  current = &loader->current.outline;
  FT_Bool      adjust  = 0;

  FT_UInt      new_max, old_max;

#if 0
  error = FT_GlyphLoader_CreateExtra( loader );
  if ( error )
    return error;

  /* check points & tags */
  new_max = (FT_UInt)base->n_points + (FT_UInt)current->n_points +
            n_points;
  old_max = loader->max_points;

  if ( new_max > old_max )
  {
    new_max = FT_PAD_CEIL( new_max, 8 );

    if ( new_max > FT_OUTLINE_POINTS_MAX )
      return FT_THROW( Array_Too_Large );

    if ( FT_RENEW_ARRAY( base->points, old_max, new_max ) ||
         FT_RENEW_ARRAY( base->tags,   old_max, new_max ) )
      goto Exit;

    if ( loader->use_extra )
    {
      if ( FT_RENEW_ARRAY( loader->base.extra_points,
                           old_max * 2, new_max * 2 ) )
        goto Exit;

      FT_ARRAY_MOVE( loader->base.extra_points + new_max,
                     loader->base.extra_points + old_max,
                     old_max );

      loader->base.extra_points2 = loader->base.extra_points + new_max;
    }

    adjust = 1;
    loader->max_points = new_max;
  }

  error = FT_GlyphLoader_CreateExtra( loader );
  if ( error )
    return error;

  /* check contours */
  old_max = loader->max_contours;
  new_max = (FT_UInt)base->n_contours + (FT_UInt)current->n_contours +
            n_contours;
  if ( new_max > old_max )
  {
    new_max = FT_PAD_CEIL( new_max, 4 );

    if ( new_max > FT_OUTLINE_CONTOURS_MAX )
      return FT_THROW( Array_Too_Large );

    if ( FT_RENEW_ARRAY( base->contours, old_max, new_max ) )
      goto Exit;

    adjust = 1;
    loader->max_contours = new_max;
  }

  if ( adjust )
    FT_GlyphLoader_Adjust_Points( loader );

Exit:
  if ( error )
    FT_GlyphLoader_Reset( loader );
#endif
  return error;
}

//
// SECTION Outline
//

FT_EXPORT_DEF( void )
FT_Outline_Transform( const FT_Outline*  outline,
                      const FT_Matrix*   matrix )
{
  FT_Vector*  vec;
  FT_Vector*  limit;


  if ( !outline || !matrix || !outline->points )
    return;

  vec   = outline->points;
  limit = vec + outline->n_points;

  for ( ; vec < limit; vec++ )
    FT_Vector_Transform( vec, matrix );
}

static void
FT_Outline_Get_CBox( const FT_Outline*  outline,
                     FT_BBox           *acbox )
{
  if ( outline && acbox )
  {
    Long  xMin, yMin, xMax, yMax;


    if ( outline->n_points == 0 )
    {
      xMin = 0;
      yMin = 0;
      xMax = 0;
      yMax = 0;
    }
    else
    {
      FT_Vector*  vec   = outline->points;
      FT_Vector*  limit = vec + outline->n_points;


      xMin = xMax = vec->x;
      yMin = yMax = vec->y;
      vec++;

      for ( ; vec < limit; vec++ )
      {
        Long  x, y;


        x = vec->x;
        if ( x < xMin ) xMin = x;
        if ( x > xMax ) xMax = x;

        y = vec->y;
        if ( y < yMin ) yMin = y;
        if ( y > yMax ) yMax = y;
      }
    }
    acbox->xMin = xMin;
    acbox->xMax = xMax;
    acbox->yMin = yMin;
    acbox->yMax = yMax;
  }
}

FT_EXPORT_DEF( void )
FT_Outline_Translate( const FT_Outline*  outline,
                      FT_Pos             xOffset,
                      FT_Pos             yOffset )
{
  FT_UShort   n;
  FT_Vector*  vec;


  if ( !outline )
    return;

  vec = outline->points;

  for ( n = 0; n < outline->n_points; n++ )
  {
    vec->x = ADD_LONG( vec->x, xOffset );
    vec->y = ADD_LONG( vec->y, yOffset );
    vec++;
  }
}

//
// SECTION Module
//

FT_EXPORT_DEF( FT_Module )
FT_Get_Module( FT_Library   library,
               const char*  module_name )
{
  FT_Module   result = NULL;
  FT_Module*  cur;
  FT_Module*  limit;

  if ( !library || !module_name )
    return result;

  cur   = library->modules;
  limit = cur + library->num_modules;

  for ( ; cur < limit; cur++ )
    if ( ft_strcmp( cur[0]->clazz->module_name, module_name ) == 0 )
    {
      result = cur[0];
      break;
    }

  return result;
}

FT_BASE_DEF( const void* )
FT_Get_Module_Interface( FT_Library   library,
                         const char*  mod_name )
{
  FT_Module  module;
  module = FT_Get_Module( library, mod_name );
  return module ? module->clazz->module_interface : 0;
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
TT_Get_VMetrics( TT_Face     face,
                 FT_UInt     idx,
                 FT_Pos      yMax,
                 FT_Short*   tsb,
                 FT_UShort*  ah )
{
  if ( face->vertical_info )
    ( (SFNT_Service)face->sfnt )->get_metrics( face, 1, idx, tsb, ah );

  else if ( face->os2.version != 0xFFFFU )
  {
    *tsb = (FT_Short)( face->os2.sTypoAscender - yMax );
    *ah  = (FT_UShort)FT_ABS( face->os2.sTypoAscender -
                              face->os2.sTypoDescender );
  }

  else
  {
    *tsb = (FT_Short)( face->horizontal.Ascender - yMax );
    *ah  = (FT_UShort)FT_ABS( face->horizontal.Ascender -
                              face->horizontal.Descender );
  }

#ifdef FT_DEBUG_LEVEL_TRACE
  if ( !face->vertical_info )
    FT_TRACE5(( "  [vertical metrics missing, computing values]\n" ));
#endif

  #if FREETYPE_WONT_INCLUDE
  FT_TRACE5(( "  advance height (font units): %d\n", *ah ));
  FT_TRACE5(( "  top side bearing (font units): %d\n", *tsb ));
  #endif
}

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
tt_face_load_hdmx( TT_Face    face,
                   FT_Stream  stream )
{
  FT_Error   error;
  FT_Memory  memory = stream->memory;
  FT_UInt    nn, num_records;
  FT_ULong   table_size, record_size;
  FT_Byte*   p;
  FT_Byte*   limit;

#if 0
  /* this table is optional */
  error = face->goto_table( face, TTAG_hdmx, stream, &table_size );
  if ( error || table_size < 8 )
    return FT_Err_Ok;

  if ( FT_FRAME_EXTRACT( table_size, face->hdmx_table ) )
    goto Exit;

  p     = face->hdmx_table;
  limit = p + table_size;

  /* Given that `hdmx' tables are losing its importance (for example, */
  /* variation fonts introduced in OpenType 1.8 must not have this    */
  /* table) we no longer test for a correct `version' field.          */
  p          += 2;
  num_records = FT_NEXT_USHORT( p );
  record_size = FT_NEXT_ULONG( p );

  /* There are at least two fonts, HANNOM-A and HANNOM-B version */
  /* 2.0 (2005), which get this wrong: The upper two bytes of    */
  /* the size value are set to 0xFF instead of 0x00.  We catch   */
  /* and fix this.                                               */

  if ( record_size >= 0xFFFF0000UL )
    record_size &= 0xFFFFU;

  FT_TRACE2(( "Hdmx " ));

  /* The limit for `num_records' is a heuristic value. */
  if ( num_records > 255 || num_records == 0 )
  {
    FT_TRACE2(( "with unreasonable %u records rejected\n", num_records ));
    goto Fail;
  }

  /* Out-of-spec tables are rejected.  The record size must be */
  /* equal to the number of glyphs + 2 + 32-bit padding.       */
  if ( (FT_Long)record_size != ( ( face->root.num_glyphs + 2 + 3 ) & ~3 ) )
  {
    FT_TRACE2(( "with record size off by %ld bytes rejected\n",
                (FT_Long)record_size -
                  ( ( face->root.num_glyphs + 2 + 3 ) & ~3 ) ));
    goto Fail;
  }

  if ( FT_QNEW_ARRAY( face->hdmx_records, num_records ) )
    goto Fail;

  for ( nn = 0; nn < num_records; nn++ )
  {
    if ( p + record_size > limit )
      break;
    face->hdmx_records[nn] = p;
    p                     += record_size;
  }

  /* The records must be already sorted by ppem but it does not */
  /* hurt to make sure so that the binary search works later.   */
  ft_qsort( face->hdmx_records, nn, sizeof ( FT_Byte* ), compare_ppem );

  face->hdmx_record_count = nn;
  face->hdmx_table_size   = table_size;
  face->hdmx_record_size  = record_size;

  FT_TRACE2(( "%ux%lu loaded\n", num_records, record_size ));
#endif
Exit:
  return error;

Fail:
  FT_FRAME_RELEASE( face->hdmx_table );
  face->hdmx_table_size = 0;
  goto Exit;
}

FT_LOCAL_DEF( FT_Error )
tt_face_load_loca( TT_Face    face,
                   FT_Stream  stream )
{
  FT_Error  error;
  FT_ULong  table_len;
  FT_Int    shift;


  /* we need the size of the `glyf' table for malformed `loca' tables */
  error = face->goto_table( face, TTAG_glyf, stream, &face->glyf_len );
#if 0
  /* it is possible that a font doesn't have a glyf table at all */
  /* or its size is zero                                         */
  if ( FT_ERR_EQ( error, Table_Missing ) )
  {
    face->glyf_len    = 0;
    face->glyf_offset = 0;
  }
  else if ( error )
    goto Exit;
  else
  {
#ifdef FT_CONFIG_OPTION_INCREMENTAL
    if ( face->root.internal->incremental_interface )
      face->glyf_offset = 0;
    else
#endif
      face->glyf_offset = FT_STREAM_POS();
  }

  FT_TRACE2(( "Locations " ));
  error = face->goto_table( face, TTAG_loca, stream, &table_len );
  if ( error )
  {
    error = FT_THROW( Locations_Missing );
    goto Exit;
  }

  shift = face->header.Index_To_Loc_Format != 0 ? 2 : 1;

  if ( table_len > 0x10000UL << shift )
  {
    FT_TRACE2(( "table too large\n" ));
    table_len = 0x10000UL << shift;
  }

  face->num_locations = table_len >> shift;

  if ( face->num_locations != (FT_ULong)face->root.num_glyphs + 1 )
  {
    FT_TRACE2(( "glyph count mismatch!  loca: %ld, maxp: %ld\n",
                face->num_locations - 1, face->root.num_glyphs ));

    /* we only handle the case where `maxp' gives a larger value */
    if ( face->num_locations < (FT_ULong)face->root.num_glyphs + 1 )
    {
      FT_ULong  new_loca_len =
                  ( (FT_ULong)face->root.num_glyphs + 1 ) << shift;

      TT_Table  entry = face->dir_tables;
      TT_Table  limit = entry + face->num_tables;

      FT_Long  pos   = (FT_Long)FT_STREAM_POS();
      FT_Long  dist  = 0x7FFFFFFFL;
      FT_Bool  found = 0;


      /* compute the distance to next table in font file */
      for ( ; entry < limit; entry++ )
      {
        FT_Long  diff = (FT_Long)entry->Offset - pos;


        if ( diff > 0 && diff < dist )
        {
          dist  = diff;
          found = 1;
        }
      }

      if ( !found )
      {
        /* `loca' is the last table */
        dist = (FT_Long)stream->size - pos;
      }

      if ( new_loca_len <= (FT_ULong)dist )
      {
        face->num_locations = (FT_ULong)face->root.num_glyphs + 1;
        table_len           = new_loca_len;

        FT_TRACE2(( "adjusting num_locations to %ld\n",
                    face->num_locations ));
      }
      else
      {
        face->root.num_glyphs = face->num_locations
                                  ? (FT_Long)face->num_locations - 1 : 0;

        FT_TRACE2(( "adjusting num_glyphs to %ld\n",
                    face->root.num_glyphs ));
      }
    }
  }

  /*
   * Extract the frame.  We don't need to decompress it since
   * we are able to parse it directly.
   */
  if ( FT_FRAME_EXTRACT( table_len, face->glyph_locations ) )
    goto Exit;

  FT_TRACE2(( "loaded\n" ));
#endif
Exit:
  return error;
}

FT_LOCAL_DEF( FT_Error )
tt_face_load_cvt( TT_Face    face,
                  FT_Stream  stream )
{
#ifdef TT_USE_BYTECODE_INTERPRETER

  FT_Error   error;
  FT_Memory  memory = stream->memory;
  FT_ULong   table_len;


  FT_TRACE2(( "CVT " ));

  error = face->goto_table( face, TTAG_cvt, stream, &table_len );
  if ( error )
  {
    FT_TRACE2(( "is missing\n" ));

    face->cvt_size = 0;
    face->cvt      = NULL;
    error          = FT_Err_Ok;

    goto Exit;
  }

  face->cvt_size = table_len / 2;

  if ( FT_QNEW_ARRAY( face->cvt, face->cvt_size ) )
    goto Exit;

  if ( FT_FRAME_ENTER( face->cvt_size * 2L ) )
    goto Exit;

  {
    FT_Int32*  cur   = face->cvt;
    FT_Int32*  limit = cur + face->cvt_size;


    for ( ; cur < limit; cur++ )
      *cur = FT_GET_SHORT() * 64;
  }

  FT_FRAME_EXIT();
  FT_TRACE2(( "loaded\n" ));

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
  if ( face->doblend )
    error = tt_face_vary_cvt( face, stream );
#endif

Exit:
  return error;

#else /* !TT_USE_BYTECODE_INTERPRETER */

  FT_UNUSED( face   );
  FT_UNUSED( stream );

  return FT_Err_Ok;

#endif
}

FT_LOCAL_DEF( FT_Error )
tt_face_load_fpgm( TT_Face    face,
                   FT_Stream  stream )
{
#ifdef TT_USE_BYTECODE_INTERPRETER

  FT_Error  error;
  FT_ULong  table_len;


  FT_TRACE2(( "Font program " ));

  /* The font program is optional */
  error = face->goto_table( face, TTAG_fpgm, stream, &table_len );
  if ( error )
  {
    face->font_program      = NULL;
    face->font_program_size = 0;
    error                   = FT_Err_Ok;

    FT_TRACE2(( "is missing\n" ));
  }
  else
  {
    face->font_program_size = table_len;
    if ( FT_FRAME_EXTRACT( table_len, face->font_program ) )
      goto Exit;

    FT_TRACE2(( "loaded, %12ld bytes\n", face->font_program_size ));
  }

Exit:
  return error;

#else /* !TT_USE_BYTECODE_INTERPRETER */

  FT_UNUSED( face   );
  FT_UNUSED( stream );

  return FT_Err_Ok;

#endif
}

FT_LOCAL_DEF( FT_Error )
tt_face_load_prep( TT_Face    face,
                   FT_Stream  stream )
{
#ifdef TT_USE_BYTECODE_INTERPRETER

  FT_Error  error;
  FT_ULong  table_len;


  FT_TRACE2(( "Prep program " ));

  error = face->goto_table( face, TTAG_prep, stream, &table_len );
  if ( error )
  {
    face->cvt_program      = NULL;
    face->cvt_program_size = 0;
    error                  = FT_Err_Ok;

    FT_TRACE2(( "is missing\n" ));
  }
  else
  {
    face->cvt_program_size = table_len;
    if ( FT_FRAME_EXTRACT( table_len, face->cvt_program ) )
      goto Exit;

    FT_TRACE2(( "loaded, %12ld bytes\n", face->cvt_program_size ));
  }

Exit:
  return error;

#else /* !TT_USE_BYTECODE_INTERPRETER */

  FT_UNUSED( face   );
  FT_UNUSED( stream );

  return FT_Err_Ok;

#endif
}

FT_LOCAL_DEF( FT_ULong )
tt_face_get_location( TT_Face   face,
                      FT_UInt   gindex,
                      FT_UInt  *asize )
{
  FT_ULong  pos1, pos2;
  FT_Byte*  p;
  FT_Byte*  p_limit;

  pos1 = pos2 = 0;

  if ( gindex < face->num_locations )
  {
    if ( face->header.Index_To_Loc_Format != 0 )
    {
      p       = face->glyph_locations + gindex * 4;
      p_limit = face->glyph_locations + face->num_locations * 4;

      pos1 = FT_NEXT_ULONG( p );
      pos2 = pos1;

      if ( p + 4 <= p_limit )
        pos2 = FT_NEXT_ULONG( p );
    }
    else
    {
      p       = face->glyph_locations + gindex * 2;
      p_limit = face->glyph_locations + face->num_locations * 2;

      pos1 = FT_NEXT_USHORT( p );
      pos2 = pos1;

      if ( p + 2 <= p_limit )
        pos2 = FT_NEXT_USHORT( p );

      pos1 <<= 1;
      pos2 <<= 1;
    }
  }

  /* Check broken location data. */
  if ( pos1 > face->glyf_len )
  {
    #if FREETYPE_WONT_INCLUDE
    FT_TRACE1(( "tt_face_get_location:"
                " too large offset (0x%08lx) found for glyph index %d,\n",
                pos1, gindex ));
    FT_TRACE1(( "                     "
                " exceeding the end of `glyf' table (0x%08lx)\n",
                face->glyf_len ));
    #endif
    *asize = 0;
    return 0;
  }

  if ( pos2 > face->glyf_len )
  {
    /* We try to sanitize the last `loca' entry. */
    if ( gindex == face->num_locations - 2 )
    {
      #if FREETYPE_WONT_INCLUDE
      FT_TRACE1(( "tt_face_get_location:"
                  " too large size (%ld bytes) found for glyph index %d,\n",
                  pos2 - pos1, gindex ));
      FT_TRACE1(( "                     "
                  " truncating at the end of `glyf' table to %ld bytes\n",
                  face->glyf_len - pos1 ));
      #endif
      pos2 = face->glyf_len;
    }
    else
    {
      #if FREETYPE_WONT_INCLUDE
      FT_TRACE1(( "tt_face_get_location:"
                  " too large offset (0x%08lx) found for glyph index %d,\n",
                  pos2, gindex + 1 ));
      FT_TRACE1(( "                     "
                  " exceeding the end of `glyf' table (0x%08lx)\n",
                  face->glyf_len ));
      #endif
      *asize = 0;
      return 0;
    }
  }

  /* The `loca' table must be ordered; it refers to the length of */
  /* an entry as the difference between the current and the next  */
  /* position.  However, there do exist (malformed) fonts which   */
  /* don't obey this rule, so we are only able to provide an      */
  /* upper bound for the size.                                    */
  /*                                                              */
  /* We get (intentionally) a wrong, non-zero result in case the  */
  /* `glyf' table is missing.                                     */
  if ( pos2 >= pos1 )
    *asize = (FT_UInt)( pos2 - pos1 );
  else
    *asize = (FT_UInt)( face->glyf_len - pos1 );
  return pos1;
}

static FT_Bool
tt_check_single_notdef( FT_Face  ttface )
{
  FT_Bool   result = FALSE;

  TT_Face   face = (TT_Face)ttface;
  FT_UInt   asize;
  FT_ULong  i;
  FT_ULong  glyph_index = 0;
  FT_UInt   count       = 0;

  for( i = 0; i < face->num_locations; i++ )
  {
    tt_face_get_location( face, i, &asize );
    if ( asize > 0 )
    {
      count += 1;
      if ( count > 1 )
        break;
      glyph_index = i;
    }
  }

  /* Only have a single outline. */
  if ( count == 1 )
  {
    if ( glyph_index == 0 )
      result = TRUE;
    else
    {
      /* FIXME: Need to test glyphname == .notdef ? */
      FT_Error error;
      char buf[8];


      error = FT_Get_Glyph_Name( ttface, glyph_index, buf, 8 );
      if ( !error                                            &&
           buf[0] == '.' && !ft_strncmp( buf, ".notdef", 8 ) )
        result = TRUE;
    }
  }
  return result;
}

FT_CALLBACK_DEF( FT_Error )
TT_Access_Glyph_Frame( TT_Loader  loader,
                       FT_UInt    glyph_index,
                       FT_ULong   offset,
                       FT_UInt    byte_count )
{
  FT_Error   error;
  FT_Stream  stream = loader->stream;

  FT_UNUSED( glyph_index );


  /* the following line sets the `error' variable through macros! */
  if ( FT_STREAM_SEEK( offset ) || FT_FRAME_ENTER( byte_count ) )
    return error;

  loader->cursor = stream->cursor;
  loader->limit  = stream->limit;

  return FT_Err_Ok;
}

FT_CALLBACK_DEF( FT_Error )
TT_Load_Glyph_Header( TT_Loader  loader )
{
  FT_Byte*  p     = loader->cursor;
  FT_Byte*  limit = loader->limit;


  if ( p + 10 > limit )
    return FT_THROW( Invalid_Outline );

  loader->n_contours = FT_NEXT_SHORT( p );

  loader->bbox.xMin = FT_NEXT_SHORT( p );
  loader->bbox.yMin = FT_NEXT_SHORT( p );
  loader->bbox.xMax = FT_NEXT_SHORT( p );
  loader->bbox.yMax = FT_NEXT_SHORT( p );

  #if FREETYPE_WONT_INCLUDE
  FT_TRACE5(( "  # of contours: %d\n", loader->n_contours ));
  FT_TRACE5(( "  xMin: %4ld  xMax: %4ld\n", loader->bbox.xMin,
                                          loader->bbox.xMax ));
  FT_TRACE5(( "  yMin: %4ld  yMax: %4ld\n", loader->bbox.yMin,
                                          loader->bbox.yMax ));
  #endif

  loader->cursor = p;

  return FT_Err_Ok;
}

FT_CALLBACK_DEF( FT_Error )
TT_Load_Simple_Glyph( TT_Loader  load )
{
  FT_Error        error;
  FT_Byte*        p          = load->cursor;
  FT_Byte*        limit      = load->limit;
  FT_GlyphLoader  gloader    = load->gloader;
  FT_Int          n_contours = load->n_contours;
  FT_Outline*     outline;
  FT_UShort       n_ins;
  FT_Int          n_points;

  FT_Byte         *flag, *flag_limit;
  FT_Byte         c, count;
  FT_Vector       *vec, *vec_limit;
  FT_Pos          x, y;
  FT_Short        *cont, *cont_limit, prev_cont;
  FT_Int          xy_size = 0;

  /* check that we can add the contours to the glyph */
  error = FT_GLYPHLOADER_CHECK_POINTS( gloader, 0, n_contours );
  if ( error )
    goto Fail;

  /* reading the contours' endpoints & number of points */
  cont       = gloader->current.outline.contours;
  cont_limit = cont + n_contours;

  /* check space for contours array + instructions count */
  if ( n_contours >= 0xFFF || p + ( n_contours + 1 ) * 2 > limit )
    goto Invalid_Outline;

  prev_cont = FT_NEXT_SHORT( p );

  if ( n_contours > 0 )
    cont[0] = prev_cont;

  if ( prev_cont < 0 )
    goto Invalid_Outline;

  for ( cont++; cont < cont_limit; cont++ )
  {
    cont[0] = FT_NEXT_SHORT( p );
    if ( cont[0] <= prev_cont )
    {
      /* unordered contours: this is invalid */
      goto Invalid_Outline;
    }
    prev_cont = cont[0];
  }

  n_points = 0;
  if ( n_contours > 0 )
  {
    n_points = cont[-1] + 1;
    if ( n_points < 0 )
      goto Invalid_Outline;
  }

#if FREETYPE_WONT_INCLUDE
  FT_TRACE5(( "  # of points: %d\n", n_points ));
#endif

  /* note that we will add four phantom points later */
  error = FT_GLYPHLOADER_CHECK_POINTS( gloader, n_points + 4, 0 );
  if ( error )
    goto Fail;

  /* reading the bytecode instructions */
  load->glyph->control_len  = 0;
  load->glyph->control_data = NULL;

  if ( p + 2 > limit )
    goto Invalid_Outline;

  n_ins = FT_NEXT_USHORT( p );

#if FREETYPE_WONT_INCLUDE
  FT_TRACE5(( "  Instructions size: %u\n", n_ins ));
#endif

#ifdef TT_USE_BYTECODE_INTERPRETER

  if ( IS_HINTED( load->load_flags ) )
  {
    FT_ULong  tmp;


    /* check instructions size */
    if ( ( limit - p ) < n_ins )
    {
      FT_TRACE1(( "TT_Load_Simple_Glyph: instruction count mismatch\n" ));
      error = FT_THROW( Too_Many_Hints );
      goto Fail;
    }

    /* we don't trust `maxSizeOfInstructions' in the `maxp' table */
    /* and thus update the bytecode array size by ourselves       */

    tmp   = load->exec->glyphSize;
    error = Update_Max( load->exec->memory,
                        &tmp,
                        sizeof ( FT_Byte ),
                        (void*)&load->exec->glyphIns,
                        n_ins );

    load->exec->glyphSize = (FT_UInt)tmp;
    if ( error )
      return error;

    load->glyph->control_len  = n_ins;
    load->glyph->control_data = load->exec->glyphIns;

    if ( n_ins )
      FT_MEM_COPY( load->exec->glyphIns, p, (FT_Long)n_ins );
  }

#endif /* TT_USE_BYTECODE_INTERPRETER */

  p += n_ins;

  outline = &gloader->current.outline;

  /* reading the point tags */
  flag       = (FT_Byte*)outline->tags;
  flag_limit = flag + n_points;

  FT_ASSERT( flag );

  while ( flag < flag_limit )
  {
    if ( p + 1 > limit )
      goto Invalid_Outline;

    *flag++ = c = FT_NEXT_BYTE( p );
    if ( c & REPEAT_FLAG )
    {
      if ( p + 1 > limit )
        goto Invalid_Outline;

      count = FT_NEXT_BYTE( p );
      if ( flag + (FT_Int)count > flag_limit )
        goto Invalid_Outline;

      for ( ; count > 0; count-- )
        *flag++ = c;
    }
  }

  /* retain the overlap flag */
  if ( n_points && outline->tags[0] & OVERLAP_SIMPLE )
    gloader->base.outline.flags |= FT_OUTLINE_OVERLAP;

  /* reading the X coordinates */

  vec       = outline->points;
  vec_limit = vec + n_points;
  flag      = (FT_Byte*)outline->tags;
  x         = 0;

  if ( p + xy_size > limit )
    goto Invalid_Outline;

  for ( ; vec < vec_limit; vec++, flag++ )
  {
    FT_Pos   delta = 0;
    FT_Byte  f     = *flag;


    if ( f & X_SHORT_VECTOR )
    {
      if ( p + 1 > limit )
        goto Invalid_Outline;

      delta = (FT_Pos)FT_NEXT_BYTE( p );
      if ( !( f & X_POSITIVE ) )
        delta = -delta;
    }
    else if ( !( f & SAME_X ) )
    {
      if ( p + 2 > limit )
        goto Invalid_Outline;

      delta = (FT_Pos)FT_NEXT_SHORT( p );
    }

    x     += delta;
    vec->x = x;
  }

  /* reading the Y coordinates */

  vec       = gloader->current.outline.points;
  vec_limit = vec + n_points;
  flag      = (FT_Byte*)outline->tags;
  y         = 0;

  for ( ; vec < vec_limit; vec++, flag++ )
  {
    FT_Pos   delta = 0;
    FT_Byte  f     = *flag;


    if ( f & Y_SHORT_VECTOR )
    {
      if ( p + 1 > limit )
        goto Invalid_Outline;

      delta = (FT_Pos)FT_NEXT_BYTE( p );
      if ( !( f & Y_POSITIVE ) )
        delta = -delta;
    }
    else if ( !( f & SAME_Y ) )
    {
      if ( p + 2 > limit )
        goto Invalid_Outline;

      delta = (FT_Pos)FT_NEXT_SHORT( p );
    }

    y     += delta;
    vec->y = y;

    /* the cast is for stupid compilers */
    *flag  = (FT_Byte)( f & ON_CURVE_POINT );
  }

  outline->n_points   = (FT_Short)n_points;
  outline->n_contours = (FT_Short)n_contours;

  load->cursor = p;

Fail:
  return error;

Invalid_Outline:
  error = FT_THROW( Invalid_Outline );
  goto Fail;
}

FT_CALLBACK_DEF( FT_Error )
TT_Load_Composite_Glyph( TT_Loader  loader )
{
  FT_Error        error;
  FT_Byte*        p          = loader->cursor;
  FT_Byte*        limit      = loader->limit;
  FT_GlyphLoader  gloader    = loader->gloader;
  FT_Long         num_glyphs = loader->face->root.num_glyphs;
  FT_SubGlyph     subglyph;
  FT_UInt         num_subglyphs;


  num_subglyphs = 0;
  do
  {
    FT_Fixed  xx, xy, yy, yx;
    FT_UInt   count;

    /* check that we can load a new subglyph */
    error = FT_GlyphLoader_CheckSubGlyphs( gloader, num_subglyphs + 1 );
    if ( error )
      goto Fail;

    /* check space */
    if ( p + 4 > limit )
      goto Invalid_Composite;

    subglyph = gloader->current.subglyphs + num_subglyphs;

    subglyph->arg1 = subglyph->arg2 = 0;

    subglyph->flags = FT_NEXT_USHORT( p );
    subglyph->index = FT_NEXT_USHORT( p );

    /* we reject composites that have components */
    /* with invalid glyph indices                */
    if ( subglyph->index >= num_glyphs )
      goto Invalid_Composite;

    /* check space */
    count = 2;
    if ( subglyph->flags & ARGS_ARE_WORDS )
      count += 2;
    if ( subglyph->flags & WE_HAVE_A_SCALE )
      count += 2;
    else if ( subglyph->flags & WE_HAVE_AN_XY_SCALE )
      count += 4;
    else if ( subglyph->flags & WE_HAVE_A_2X2 )
      count += 8;

    if ( p + count > limit )
      goto Invalid_Composite;

    /* read arguments */
    if ( subglyph->flags & ARGS_ARE_XY_VALUES )
    {
      if ( subglyph->flags & ARGS_ARE_WORDS )
      {
        subglyph->arg1 = FT_NEXT_SHORT( p );
        subglyph->arg2 = FT_NEXT_SHORT( p );
      }
      else
      {
        subglyph->arg1 = FT_NEXT_CHAR( p );
        subglyph->arg2 = FT_NEXT_CHAR( p );
      }
    }
    else
    {
      if ( subglyph->flags & ARGS_ARE_WORDS )
      {
        subglyph->arg1 = (FT_Int)FT_NEXT_USHORT( p );
        subglyph->arg2 = (FT_Int)FT_NEXT_USHORT( p );
      }
      else
      {
        subglyph->arg1 = (FT_Int)FT_NEXT_BYTE( p );
        subglyph->arg2 = (FT_Int)FT_NEXT_BYTE( p );
      }
    }

    /* read transform */
    xx = yy = 0x10000L;
    xy = yx = 0;

    if ( subglyph->flags & WE_HAVE_A_SCALE )
    {
      xx = (FT_Fixed)FT_NEXT_SHORT( p ) * 4;
      yy = xx;
    }
    else if ( subglyph->flags & WE_HAVE_AN_XY_SCALE )
    {
      xx = (FT_Fixed)FT_NEXT_SHORT( p ) * 4;
      yy = (FT_Fixed)FT_NEXT_SHORT( p ) * 4;
    }
    else if ( subglyph->flags & WE_HAVE_A_2X2 )
    {
      xx = (FT_Fixed)FT_NEXT_SHORT( p ) * 4;
      yx = (FT_Fixed)FT_NEXT_SHORT( p ) * 4;
      xy = (FT_Fixed)FT_NEXT_SHORT( p ) * 4;
      yy = (FT_Fixed)FT_NEXT_SHORT( p ) * 4;
    }

    subglyph->transform.xx = xx;
    subglyph->transform.xy = xy;
    subglyph->transform.yx = yx;
    subglyph->transform.yy = yy;

    num_subglyphs++;

  } while ( subglyph->flags & MORE_COMPONENTS );

  gloader->current.num_subglyphs = num_subglyphs;

#if FREETYPE_WONT_INCLUDE
  FT_TRACE5(( "  %d component%s\n",
              num_subglyphs,
              num_subglyphs > 1 ? "s" : "" ));
#endif

#ifdef FT_DEBUG_LEVEL_TRACE
  {
    FT_UInt  i;


    subglyph = gloader->current.subglyphs;

    for ( i = 0; i < num_subglyphs; i++ )
    {
      if ( num_subglyphs > 1 )
        FT_TRACE7(( "    subglyph %d:\n", i ));

      FT_TRACE7(( "      glyph index: %d\n", subglyph->index ));

      if ( subglyph->flags & ARGS_ARE_XY_VALUES )
        FT_TRACE7(( "      offset: x=%d, y=%d\n",
                    subglyph->arg1,
                    subglyph->arg2 ));
      else
        FT_TRACE7(( "      matching points: base=%d, component=%d\n",
                    subglyph->arg1,
                    subglyph->arg2 ));

      if ( subglyph->flags & WE_HAVE_A_SCALE )
        FT_TRACE7(( "      scaling: %f\n",
                    subglyph->transform.xx / 65536.0 ));
      else if ( subglyph->flags & WE_HAVE_AN_XY_SCALE )
        FT_TRACE7(( "      scaling: x=%f, y=%f\n",
                    subglyph->transform.xx / 65536.0,
                    subglyph->transform.yy / 65536.0 ));
      else if ( subglyph->flags & WE_HAVE_A_2X2 )
      {
        FT_TRACE7(( "      scaling: xx=%f, yx=%f\n",
                    subglyph->transform.xx / 65536.0,
                    subglyph->transform.yx / 65536.0 ));
        FT_TRACE7(( "               xy=%f, yy=%f\n",
                    subglyph->transform.xy / 65536.0,
                    subglyph->transform.yy / 65536.0 ));
      }

      subglyph++;
    }
  }
#endif /* FT_DEBUG_LEVEL_TRACE */

#ifdef TT_USE_BYTECODE_INTERPRETER

  {
    FT_Stream  stream = loader->stream;


    /* we must undo the FT_FRAME_ENTER in order to point */
    /* to the composite instructions, if we find some.   */
    /* We will process them later.                       */
    /*                                                   */
    loader->ins_pos = (FT_ULong)( FT_STREAM_POS() +
                                  p - limit );
  }

#endif
  loader->cursor = p;

Fail:
  return error;

Invalid_Composite:
  error = FT_THROW( Invalid_Composite );
  goto Fail;
}

FT_CALLBACK_DEF( void )
TT_Forget_Glyph_Frame( TT_Loader  loader )
{
  FT_Stream  stream = loader->stream;
  FT_FRAME_EXIT();
}

FT_LOCAL_DEF( void )
TT_Init_Glyph_Loading( TT_Face  face )
{
  face->access_glyph_frame   = TT_Access_Glyph_Frame;
  face->read_glyph_header    = TT_Load_Glyph_Header;
  face->read_simple_glyph    = TT_Load_Simple_Glyph;
  face->read_composite_glyph = TT_Load_Composite_Glyph;
  face->forget_glyph_frame   = TT_Forget_Glyph_Frame;
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
  SFNT_Service  sfnt;
  TT_Face       face = (TT_Face)ttface;

#if FREETYPE_WONT_INCLUDE
  FT_TRACE2(( "TTF driver\n" ));
#endif

  library = ttface->driver->root.library;

  sfnt = (SFNT_Service)FT_Get_Module_Interface( library, "sfnt" );
  if ( !sfnt )
  {
    #if FREETYPE_WONT_INCLUDE
    FT_ERROR(( "tt_face_init: cannot access `sfnt' module\n" ));
    #endif
    error = FT_THROW( Missing_Module );
    goto Exit;
  }

  /* create input stream from resource */
  if ( FT_STREAM_SEEK( 0 ) )
    goto Exit;

  /* check that we have a valid TrueType file */
  #if FREETYPE_WONT_INCLUDE
  FT_TRACE2(( "  " ));
  #endif
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
    #if FREETYPE_WONT_INCLUDE
    FT_TRACE2(( "  not a TTF font\n" ));
    #endif
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
        #if FREETYPE_WONT_INCLUDE
        FT_TRACE5(( "tt_face_init:"
                    " Only the `.notdef' glyph has an outline.\n" ));
        FT_TRACE5(( "             "
                    " Resetting scalable flag to FALSE.\n" ));
        #endif
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

Exit:
  return error;

Bad_Format:
  error = FT_THROW( Unknown_File_Format );
  goto Exit;
}

FT_LOCAL_DEF( void )
tt_face_done_loca( TT_Face  face )
{
  FT_Stream  stream = face->root.stream;
  FT_FRAME_RELEASE( face->glyph_locations );
  face->num_locations = 0;
}

FT_LOCAL_DEF( void )
tt_face_free_hdmx( TT_Face  face )
{
  FT_Stream  stream = face->root.stream;
  FT_Memory  memory = stream->memory;
  FT_FREE( face->hdmx_records );
  FT_FRAME_RELEASE( face->hdmx_table );
}

FT_LOCAL_DEF( void )
tt_face_done( FT_Face  ttface )           /* TT_Face */
{
  TT_Face       face = (TT_Face)ttface;
  FT_Memory     memory;
  FT_Stream     stream;
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
tt_loader_init( TT_Loader     loader,
                TT_Size       size,
                TT_GlyphSlot  glyph,
                FT_Int32      load_flags,
                FT_Bool       glyf_table_only )
{
  TT_Face    face;
  FT_Stream  stream;

#ifdef TT_USE_BYTECODE_INTERPRETER
  FT_Error   error;
  FT_Bool    pedantic = FT_BOOL( load_flags & FT_LOAD_PEDANTIC );
#if defined TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY || \
  defined TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
  TT_Driver  driver = (TT_Driver)FT_FACE_DRIVER( (TT_Face)glyph->face );
#endif
#endif

  face   = (TT_Face)glyph->face;
  stream = face->root.stream;

  FT_ZERO( loader );

#ifdef TT_USE_BYTECODE_INTERPRETER

  /* load execution context */
  if ( IS_HINTED( load_flags ) && !glyf_table_only )
  {
    TT_ExecContext  exec;
    FT_Bool         grayscale = TRUE;
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
    FT_Bool         subpixel_hinting_lean;
    FT_Bool         grayscale_cleartype;
#endif //TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
    FT_Bool  subpixel_hinting = FALSE;

#if FREETYPE_OG_ZERO
    /* not used yet */
    FT_Bool  compatible_widths;
    FT_Bool  symmetrical_smoothing;
    FT_Bool  bgr;
    FT_Bool  vertical_lcd;
    FT_Bool  subpixel_positioned;
    FT_Bool  gray_cleartype;
#endif
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */

    FT_Bool  reexecute = FALSE;


    if ( size->bytecode_ready < 0 || size->cvt_ready < 0 )
    {
      error = tt_size_ready_bytecode( size, pedantic );
      if ( error )
        return error;
    }
    else if ( size->bytecode_ready )
      return size->bytecode_ready;
    else if ( size->cvt_ready )
      return size->cvt_ready;

    /* query new execution context */
    exec = size->context;
    if ( !exec )
      return FT_THROW( Could_Not_Find_Context );

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
    if ( driver->interpreter_version == TT_INTERPRETER_VERSION_40 )
    {
      subpixel_hinting_lean =
        FT_BOOL( FT_LOAD_TARGET_MODE( load_flags ) !=
                 FT_RENDER_MODE_MONO               );
      grayscale_cleartype =
        FT_BOOL( subpixel_hinting_lean         &&
                 !( ( load_flags         &
                      FT_LOAD_TARGET_LCD )   ||
                    ( load_flags           &
                      FT_LOAD_TARGET_LCD_V ) ) );
      exec->vertical_lcd_lean =
        FT_BOOL( subpixel_hinting_lean    &&
                 ( load_flags           &
                   FT_LOAD_TARGET_LCD_V ) );
    }
    else
    {
      subpixel_hinting_lean   = FALSE;
      grayscale_cleartype     = FALSE;
      exec->vertical_lcd_lean = FALSE;
    }
#endif // TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY

    if ( driver->interpreter_version == TT_INTERPRETER_VERSION_38 )
    {
      subpixel_hinting = FT_BOOL( ( FT_LOAD_TARGET_MODE( load_flags ) !=
                                    FT_RENDER_MODE_MONO               )  &&
                                  SPH_OPTION_SET_SUBPIXEL                );

      if ( subpixel_hinting )
        grayscale = FALSE;
      else if ( SPH_OPTION_SET_GRAYSCALE )
      {
        grayscale        = TRUE;
        subpixel_hinting = FALSE;
      }
      else
        grayscale = FALSE;

      if ( FT_IS_TRICKY( glyph->face ) )
        subpixel_hinting = FALSE;

      exec->ignore_x_mode      = subpixel_hinting || grayscale;
      exec->rasterizer_version = SPH_OPTION_SET_RASTERIZER_VERSION;
      if ( exec->sph_tweak_flags & SPH_TWEAK_RASTERIZER_35 )
        exec->rasterizer_version = TT_INTERPRETER_VERSION_35;

#if 1
      exec->compatible_widths     = SPH_OPTION_SET_COMPATIBLE_WIDTHS;
      exec->symmetrical_smoothing = TRUE;
      exec->bgr                   = FALSE;
      exec->vertical_lcd          = FALSE;
      exec->subpixel_positioned   = TRUE;
      exec->gray_cleartype        = FALSE;
#else /* 0 */
      exec->compatible_widths =
        FT_BOOL( FT_LOAD_TARGET_MODE( load_flags ) !=
                 TT_LOAD_COMPATIBLE_WIDTHS );
      exec->symmetrical_smoothing =
        FT_BOOL( FT_LOAD_TARGET_MODE( load_flags ) !=
                 TT_LOAD_SYMMETRICAL_SMOOTHING );
      exec->bgr =
        FT_BOOL( FT_LOAD_TARGET_MODE( load_flags ) !=
                 TT_LOAD_BGR );
      exec->vertical_lcd =
        FT_BOOL( FT_LOAD_TARGET_MODE( load_flags ) !=
                 TT_LOAD_VERTICAL_LCD );
      exec->subpixel_positioned =
        FT_BOOL( FT_LOAD_TARGET_MODE( load_flags ) !=
                 TT_LOAD_SUBPIXEL_POSITIONED );
      exec->gray_cleartype =
        FT_BOOL( FT_LOAD_TARGET_MODE( load_flags ) !=
                 TT_LOAD_GRAY_CLEARTYPE );
#endif /* 0 */

    }
    else

#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
    if ( driver->interpreter_version == TT_INTERPRETER_VERSION_40 )
      grayscale = FT_BOOL( !subpixel_hinting_lean               &&
                           FT_LOAD_TARGET_MODE( load_flags ) !=
                             FT_RENDER_MODE_MONO                );
    else
#endif
      grayscale = FT_BOOL( FT_LOAD_TARGET_MODE( load_flags ) !=
                             FT_RENDER_MODE_MONO             );

    error = TT_Load_Context( exec, face, size );
    if ( error )
      return error;

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY

    if ( driver->interpreter_version == TT_INTERPRETER_VERSION_38 )
    {
      /* a change from mono to subpixel rendering (and vice versa) */
      /* requires a re-execution of the CVT program                */
      if ( subpixel_hinting != exec->subpixel_hinting )
      {
        FT_TRACE4(( "tt_loader_init: subpixel hinting change,"
                    " re-executing `prep' table\n" ));

        exec->subpixel_hinting = subpixel_hinting;
        reexecute              = TRUE;
      }

      /* a change from mono to grayscale rendering (and vice versa) */
      /* requires a re-execution of the CVT program                 */
      if ( grayscale != exec->grayscale )
      {
        FT_TRACE4(( "tt_loader_init: grayscale hinting change,"
                    " re-executing `prep' table\n" ));

        exec->grayscale = grayscale;
        reexecute       = TRUE;
      }
    }
    else

#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */

    {

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
      if ( driver->interpreter_version == TT_INTERPRETER_VERSION_40 )
      {
        /* a change from mono to subpixel rendering (and vice versa) */
        /* requires a re-execution of the CVT program                */
        if ( subpixel_hinting_lean != exec->subpixel_hinting_lean )
        {
          FT_TRACE4(( "tt_loader_init: subpixel hinting change,"
                      " re-executing `prep' table\n" ));

          exec->subpixel_hinting_lean = subpixel_hinting_lean;
          reexecute                   = TRUE;
        }

        /* a change from colored to grayscale subpixel rendering (and */
        /* vice versa) requires a re-execution of the CVT program     */
        if ( grayscale_cleartype != exec->grayscale_cleartype )
        {
          FT_TRACE4(( "tt_loader_init: grayscale subpixel hinting change,"
                      " re-executing `prep' table\n" ));

          exec->grayscale_cleartype = grayscale_cleartype;
          reexecute                 = TRUE;
        }
      }
#endif

      /* a change from mono to grayscale rendering (and vice versa) */
      /* requires a re-execution of the CVT program                 */
      if ( grayscale != exec->grayscale )
      {
        FT_TRACE4(( "tt_loader_init: grayscale hinting change,"
                    " re-executing `prep' table\n" ));

        exec->grayscale = grayscale;
        reexecute       = TRUE;
      }
    }

    if ( reexecute )
    {
      error = tt_size_run_prep( size, pedantic );
      if ( error )
        return error;
      error = TT_Load_Context( exec, face, size );
      if ( error )
        return error;
    }

    /* check whether the cvt program has disabled hinting */
    if ( exec->GS.instruct_control & 1 )
      load_flags |= FT_LOAD_NO_HINTING;

    /* load default graphics state -- if needed */
    if ( exec->GS.instruct_control & 2 )
      exec->GS = tt_default_graphics_state;

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
    /* check whether we have a font hinted for ClearType --           */
    /* note that this flag can also be modified in a glyph's bytecode */
    if ( driver->interpreter_version == TT_INTERPRETER_VERSION_38 &&
         exec->GS.instruct_control & 4                            )
      exec->ignore_x_mode = FALSE;
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
    /*
     * Toggle backward compatibility according to what font wants, except
     * when
     *
     * 1) we have a `tricky' font that heavily relies on the interpreter to
     *    render glyphs correctly, for example DFKai-SB, or
     * 2) FT_RENDER_MODE_MONO (i.e, monochome rendering) is requested.
     *
     * In those cases, backward compatibility needs to be turned off to get
     * correct rendering.  The rendering is then completely up to the
     * font's programming.
     *
     */
    if ( driver->interpreter_version == TT_INTERPRETER_VERSION_40 &&
         subpixel_hinting_lean                                    &&
         !FT_IS_TRICKY( glyph->face )                             )
      exec->backward_compatibility = !( exec->GS.instruct_control & 4 );
    else
      exec->backward_compatibility = FALSE;
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL */

    exec->pedantic_hinting = FT_BOOL( load_flags & FT_LOAD_PEDANTIC );
    loader->exec = exec;
    loader->instructions = exec->glyphIns;

    /* Use the hdmx table if any unless FT_LOAD_COMPUTE_METRICS */
    /* is set or backward compatibility mode of the v38 or v40  */
    /* interpreters is active.  See `ttinterp.h' for details on */
    /* backward compatibility mode.                             */
    if ( IS_HINTED( loader->load_flags )                                &&
         !( loader->load_flags & FT_LOAD_COMPUTE_METRICS )              &&
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
         !( driver->interpreter_version == TT_INTERPRETER_VERSION_40  &&
            exec->backward_compatibility                              ) &&
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
         !( driver->interpreter_version == TT_INTERPRETER_VERSION_38  &&
            !SPH_OPTION_BITMAP_WIDTHS                                 &&
            FT_LOAD_TARGET_MODE( loader->load_flags ) !=
                                                 FT_RENDER_MODE_MONO  &&
            exec->compatible_widths                                   ) &&
#endif
         !face->postscript.isFixedPitch                                 )
    {
      loader->widthp = size->widthp;
    }
    else
      loader->widthp = NULL;
  }

#endif /* TT_USE_BYTECODE_INTERPRETER */
  /* get face's glyph loader */
  if ( !glyf_table_only )
  {
    FT_GlyphLoader  gloader = glyph->internal->loader;


    FT_GlyphLoader_Rewind( gloader );
    loader->gloader = gloader;
  }

  loader->load_flags = (FT_ULong)load_flags;

  loader->face   = face;
  loader->size   = size;
  loader->glyph  = (FT_GlyphSlot)glyph;
  loader->stream = stream;

  loader->composites.head = NULL;
  loader->composites.tail = NULL;

  return FT_Err_Ok;
}

static void
tt_loader_done( TT_Loader  loader ) {
  FT_List_Finalize( &loader->composites,
                    NULL,
                    loader->face->root.memory,
                    NULL );
}

static FT_Error
tt_get_metrics( TT_Loader  loader,
                FT_UInt    glyph_index )
{
  TT_Face    face   = loader->face;
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
  TT_Driver  driver = (TT_Driver)FT_FACE_DRIVER( face );
#endif

  FT_Error   error;
  FT_Stream  stream = loader->stream;

  FT_Short   left_bearing = 0, top_bearing = 0;
  FT_UShort  advance_width = 0, advance_height = 0;

  /* we must preserve the stream position          */
  /* (which gets altered by the metrics functions) */
  FT_ULong  pos = FT_STREAM_POS();


  TT_Get_HMetrics( face, glyph_index,
                   &left_bearing,
                   &advance_width );
  TT_Get_VMetrics( face, glyph_index,
                   loader->bbox.yMax,
                   &top_bearing,
                   &advance_height );

  if ( FT_STREAM_SEEK( pos ) )
    return error;

  loader->left_bearing = left_bearing;
  loader->advance      = advance_width;
  loader->top_bearing  = top_bearing;
  loader->vadvance     = advance_height;

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
  if ( driver->interpreter_version == TT_INTERPRETER_VERSION_38 &&
       loader->exec                                             )
  {
    loader->exec->sph_tweak_flags = 0;

    /* This may not be the right place for this, but it works...  */
    /* Note that we have to unconditionally load the tweaks since */
    /* it is possible that glyphs individually switch ClearType's */
    /* backward compatibility mode on and off.                    */
    sph_set_tweaks( loader, glyph_index );
  }
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */

#ifdef FT_CONFIG_OPTION_INCREMENTAL
  /* With the incremental interface, these values are set by  */
  /* a call to `tt_get_metrics_incremental'.                  */
  if ( face->root.internal->incremental_interface == NULL )
#endif
  {
    if ( !loader->linear_def )
    {
      loader->linear_def = 1;
      loader->linear     = advance_width;
    }
  }
  return FT_Err_Ok;
}

static void
tt_loader_set_pp( TT_Loader  loader )
{
  FT_Bool  subpixel_hinting = 0;
  FT_Bool  grayscale        = 0;
  FT_Bool  use_aw_2         = 0;

#ifdef TT_CONFIG_OPTION_SUBPIXEL_HINTING
  TT_Driver driver = (TT_Driver)FT_FACE_DRIVER( loader->face );
#endif


#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
  if ( driver->interpreter_version == TT_INTERPRETER_VERSION_38 )
  {
    subpixel_hinting = loader->exec ? loader->exec->subpixel_hinting
                                    : 0;
    grayscale        = loader->exec ? loader->exec->grayscale
                                    : 0;
  }
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
  if ( driver->interpreter_version == TT_INTERPRETER_VERSION_40 )
  {
    subpixel_hinting = loader->exec ? loader->exec->subpixel_hinting_lean
                                    : 0;
    grayscale        = loader->exec ? loader->exec->grayscale_cleartype
                                    : 0;
  }
#endif

  use_aw_2 = FT_BOOL( subpixel_hinting && grayscale );

  loader->pp1.x = loader->bbox.xMin - loader->left_bearing;
  loader->pp1.y = 0;
  loader->pp2.x = loader->pp1.x + loader->advance;
  loader->pp2.y = 0;

  loader->pp3.x = use_aw_2 ? loader->advance / 2 : 0;
  loader->pp3.y = loader->bbox.yMax + loader->top_bearing;
  loader->pp4.x = use_aw_2 ? loader->advance / 2 : 0;
  loader->pp4.y = loader->pp3.y - loader->vadvance;
}

static void
tt_prepare_zone( TT_GlyphZone  zone,
                 FT_GlyphLoad  load,
                 FT_UInt       start_point,
                 FT_UInt       start_contour )
{
  zone->n_points    = (FT_UShort)load->outline.n_points -
                        (FT_UShort)start_point;
  zone->n_contours  = load->outline.n_contours -
                        (FT_Short)start_contour;
  zone->org         = load->extra_points + start_point;
  zone->cur         = load->outline.points + start_point;
  zone->orus        = load->extra_points2 + start_point;
  zone->tags        = (FT_Byte*)load->outline.tags + start_point;
  zone->contours    = (FT_UShort*)load->outline.contours + start_contour;
  zone->first_point = (FT_UShort)start_point;
}

static FT_Error
TT_Hint_Glyph( TT_Loader  loader,
               FT_Bool    is_composite )
{
#if defined TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY || \
  defined TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
  TT_Face    face   = loader->face;
  TT_Driver  driver = (TT_Driver)FT_FACE_DRIVER( face );
#endif

  TT_GlyphZone  zone = &loader->zone;

#ifdef TT_USE_BYTECODE_INTERPRETER
  FT_Long       n_ins;
#else
  FT_UNUSED( is_composite );
#endif

#ifdef TT_USE_BYTECODE_INTERPRETER
  n_ins = loader->glyph->control_len;

  /* save original point positions in `org' array */
  if ( n_ins > 0 )
    FT_ARRAY_COPY( zone->org, zone->cur, zone->n_points );

  /* Reset graphics state. */
  loader->exec->GS = loader->size->GS;

  /* XXX: UNDOCUMENTED! Hinting instructions of a composite glyph */
  /*      completely refer to the (already) hinted subglyphs.     */
  if ( is_composite )
  {
    loader->exec->metrics.x_scale = 1 << 16;
    loader->exec->metrics.y_scale = 1 << 16;

    FT_ARRAY_COPY( zone->orus, zone->cur, zone->n_points );
  }
  else
  {
    loader->exec->metrics.x_scale = loader->size->metrics->x_scale;
    loader->exec->metrics.y_scale = loader->size->metrics->y_scale;
  }
#endif // TT_USE_BYTECODE_INTERPRETER

  /* round phantom points */
  zone->cur[zone->n_points - 4].x =
    FT_PIX_ROUND( zone->cur[zone->n_points - 4].x );
  zone->cur[zone->n_points - 3].x =
    FT_PIX_ROUND( zone->cur[zone->n_points - 3].x );
  zone->cur[zone->n_points - 2].y =
    FT_PIX_ROUND( zone->cur[zone->n_points - 2].y );
  zone->cur[zone->n_points - 1].y =
    FT_PIX_ROUND( zone->cur[zone->n_points - 1].y );

#ifdef TT_USE_BYTECODE_INTERPRETER

  if ( n_ins > 0 )
  {
    FT_Error  error;

    FT_GlyphLoader  gloader         = loader->gloader;
    FT_Outline      current_outline = gloader->current.outline;


    TT_Set_CodeRange( loader->exec, tt_coderange_glyph,
                      loader->exec->glyphIns, n_ins );

    loader->exec->is_composite = is_composite;
    loader->exec->pts          = *zone;

    error = TT_Run_Context( loader->exec );
    if ( error && loader->exec->pedantic_hinting )
      return error;

    /* store drop-out mode in bits 5-7; set bit 2 also as a marker */
    current_outline.tags[0] |=
      ( loader->exec->GS.scan_type << 5 ) | FT_CURVE_TAG_HAS_SCANMODE;
  }

#endif // TT_USE_BYTECODE_INTERPRETER

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
  /* Save possibly modified glyph phantom points unless in v40 backward  */
  /* compatibility mode, where no movement on the x axis means no reason */
  /* to change bearings or advance widths.                               */
  if ( !( driver->interpreter_version == TT_INTERPRETER_VERSION_40 &&
          loader->exec->backward_compatibility ) )
  {
#endif // TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
    loader->pp1 = zone->cur[zone->n_points - 4];
    loader->pp2 = zone->cur[zone->n_points - 3];
    loader->pp3 = zone->cur[zone->n_points - 2];
    loader->pp4 = zone->cur[zone->n_points - 1];
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
  }
#endif // TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
  if ( driver->interpreter_version == TT_INTERPRETER_VERSION_38 )
  {
    if ( loader->exec->sph_tweak_flags & SPH_TWEAK_DEEMBOLDEN )
      FT_Outline_EmboldenXY( &loader->gloader->current.outline, -24, 0 );

    else if ( loader->exec->sph_tweak_flags & SPH_TWEAK_EMBOLDEN )
      FT_Outline_EmboldenXY( &loader->gloader->current.outline, 24, 0 );
  }
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
  return FT_Err_Ok;
}

static FT_Error
TT_Process_Simple_Glyph( TT_Loader  loader )
{
  FT_GlyphLoader  gloader = loader->gloader;
  FT_Error        error   = FT_Err_Ok;
  FT_Outline*     outline;
  FT_Int          n_points;

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
  FT_Memory   memory    = loader->face->root.memory;
  FT_Vector*  unrounded = NULL;
#endif

  outline  = &gloader->current.outline;
  n_points = outline->n_points;

  /* set phantom points */

  outline->points[n_points    ] = loader->pp1;
  outline->points[n_points + 1] = loader->pp2;
  outline->points[n_points + 2] = loader->pp3;
  outline->points[n_points + 3] = loader->pp4;

  outline->tags[n_points    ] = 0;
  outline->tags[n_points + 1] = 0;
  outline->tags[n_points + 2] = 0;
  outline->tags[n_points + 3] = 0;

  n_points += 4;


#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT

  if ( !IS_DEFAULT_INSTANCE( FT_FACE( loader->face ) ) )
  {
    if ( FT_NEW_ARRAY( unrounded, n_points ) )
      goto Exit;

    /* Deltas apply to the unscaled data. */
    error = TT_Vary_Apply_Glyph_Deltas( loader->face,
                                        loader->glyph_index,
                                        outline,
                                        unrounded,
                                        (FT_UInt)n_points );

    /* recalculate linear horizontal and vertical advances */
    /* if we don't have HVAR and VVAR, respectively        */

    /* XXX: change all FreeType modules to store `linear' and `vadvance' */
    /*      in 26.6 format before the `base' module scales them to 16.16 */
    if ( !( loader->face->variation_support & TT_FACE_FLAG_VAR_HADVANCE ) )
      loader->linear = FT_PIX_ROUND( unrounded[n_points - 3].x -
                                     unrounded[n_points - 4].x ) / 64;
    if ( !( loader->face->variation_support & TT_FACE_FLAG_VAR_VADVANCE ) )
      loader->vadvance = FT_PIX_ROUND( unrounded[n_points - 1].x -
                                       unrounded[n_points - 2].x ) / 64;

    if ( error )
      goto Exit;
  }

#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
  if ( IS_HINTED( loader->load_flags ) )
  {
    tt_prepare_zone( &loader->zone, &gloader->current, 0, 0 );

    FT_ARRAY_COPY( loader->zone.orus, loader->zone.cur,
                   loader->zone.n_points + 4 );
  }

  {
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
    TT_Face    face   = loader->face;
    TT_Driver  driver = (TT_Driver)FT_FACE_DRIVER( face );

    FT_String*  family         = face->root.family_name;
    FT_UInt     ppem           = loader->size->metrics->x_ppem;
    FT_String*  style          = face->root.style_name;
    FT_UInt     x_scale_factor = 1000;
#endif

    FT_Vector*  vec   = outline->points;
    FT_Vector*  limit = outline->points + n_points;

    FT_Fixed  x_scale = 0; /* pacify compiler */
    FT_Fixed  y_scale = 0;

    FT_Bool  do_scale = FALSE;

#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY

    if ( driver->interpreter_version == TT_INTERPRETER_VERSION_38 )
    {
      /* scale, but only if enabled and only if TT hinting is being used */
      if ( IS_HINTED( loader->load_flags ) )
        x_scale_factor = sph_test_tweak_x_scaling( face,
                                                   family,
                                                   ppem,
                                                   style,
                                                   loader->glyph_index );
      /* scale the glyph */
      if ( ( loader->load_flags & FT_LOAD_NO_SCALE ) == 0 ||
           x_scale_factor != 1000                         )
      {
        x_scale = FT_MulDiv( loader->size->metrics->x_scale,
                             (FT_Long)x_scale_factor, 1000 );
        y_scale = loader->size->metrics->y_scale;

        /* compensate for any scaling by de/emboldening; */
        /* the amount was determined via experimentation */
        if ( x_scale_factor != 1000 && ppem > 11 )
        {
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
          FT_Vector*  orig_points = outline->points;


          if ( !IS_DEFAULT_INSTANCE( FT_FACE( loader->face ) ) )
            outline->points = unrounded;
#endif // TT_CONFIG_OPTION_GX_VAR_SUPPORT
          FT_Outline_EmboldenXY( outline,
                                 FT_MulFix( 1280 * ppem,
                                            1000 - x_scale_factor ),
                                 0 );
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
          if ( !IS_DEFAULT_INSTANCE( FT_FACE( loader->face ) ) )
            outline->points = orig_points;
#endif // TT_CONFIG_OPTION_GX_VAR_SUPPORT
        }
        do_scale = TRUE;
      }
    }
    else

#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
    {
      /* scale the glyph */
      if ( ( loader->load_flags & FT_LOAD_NO_SCALE ) == 0 )
      {
        x_scale = loader->size->metrics->x_scale;
        y_scale = loader->size->metrics->y_scale;

        do_scale = TRUE;
      }
    }

    if ( do_scale )
    {
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
      if ( !IS_DEFAULT_INSTANCE( FT_FACE( loader->face ) ) )
      {
        FT_Vector*  u = unrounded;


        for ( ; vec < limit; vec++, u++ )
        {
          vec->x = ( FT_MulFix( u->x, x_scale ) + 32 ) >> 6;
          vec->y = ( FT_MulFix( u->y, y_scale ) + 32 ) >> 6;
        }
      }
      else
#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
      {
        for ( ; vec < limit; vec++ )
        {
          vec->x = FT_MulFix( vec->x, x_scale );
          vec->y = FT_MulFix( vec->y, y_scale );
        }
      }
    }

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
    /* if we have a HVAR table, `pp1' and/or `pp2' */
    /* are already adjusted but unscaled           */
    if ( ( loader->face->variation_support & TT_FACE_FLAG_VAR_HADVANCE ) &&
         IS_HINTED( loader->load_flags )                                 )
    {
      loader->pp1.x = FT_MulFix( loader->pp1.x, x_scale );
      loader->pp2.x = FT_MulFix( loader->pp2.x, x_scale );
      /* pp1.y and pp2.y are always zero */
    }
    else
#endif // TT_CONFIG_OPTION_GX_VAR_SUPPORT
    {
      loader->pp1 = outline->points[n_points - 4];
      loader->pp2 = outline->points[n_points - 3];
    }

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
    /* if we have a VVAR table, `pp3' and/or `pp4' */
    /* are already adjusted but unscaled           */
    if ( ( loader->face->variation_support & TT_FACE_FLAG_VAR_VADVANCE ) &&
         IS_HINTED( loader->load_flags )                                 )
    {
      loader->pp3.x = FT_MulFix( loader->pp3.x, x_scale );
      loader->pp3.y = FT_MulFix( loader->pp3.y, y_scale );
      loader->pp4.x = FT_MulFix( loader->pp4.x, x_scale );
      loader->pp4.y = FT_MulFix( loader->pp4.y, y_scale );
    }
    else
#endif // TT_CONFIG_OPTION_GX_VAR_SUPPORT
    {
      loader->pp3 = outline->points[n_points - 2];
      loader->pp4 = outline->points[n_points - 1];
    }
  }

  if ( IS_HINTED( loader->load_flags ) )
  {
    loader->zone.n_points += 4;

    error = TT_Hint_Glyph( loader, 0 );
  }

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
Exit:
  FT_FREE( unrounded );
#endif
  return error;
}

static FT_Error
TT_Process_Composite_Glyph( TT_Loader  loader,
                            FT_UInt    start_point,
                            FT_UInt    start_contour )
{
  FT_Error     error;
  FT_Outline*  outline;
  FT_UInt      i;

  outline = &loader->gloader->base.outline;

  /* make room for phantom points */
  error = FT_GLYPHLOADER_CHECK_POINTS( loader->gloader,
                                       outline->n_points + 4,
                                       0 );
  if ( error )
    return error;

  outline->points[outline->n_points    ] = loader->pp1;
  outline->points[outline->n_points + 1] = loader->pp2;
  outline->points[outline->n_points + 2] = loader->pp3;
  outline->points[outline->n_points + 3] = loader->pp4;

  outline->tags[outline->n_points    ] = 0;
  outline->tags[outline->n_points + 1] = 0;
  outline->tags[outline->n_points + 2] = 0;
  outline->tags[outline->n_points + 3] = 0;


#ifdef TT_USE_BYTECODE_INTERPRETER

  {
    FT_Stream  stream = loader->stream;
    FT_UShort  n_ins, max_ins;
    FT_ULong   tmp;


    /* TT_Load_Composite_Glyph only gives us the offset of instructions */
    /* so we read them here                                             */
    if ( FT_STREAM_SEEK( loader->ins_pos ) ||
         FT_READ_USHORT( n_ins )           )
      return error;

    FT_TRACE5(( "  Instructions size = %hu\n", n_ins ));

    /* check it */
    max_ins = loader->face->max_profile.maxSizeOfInstructions;
    if ( n_ins > max_ins )
    {
      /* don't trust `maxSizeOfInstructions'; */
      /* only do a rough safety check         */
      if ( n_ins > loader->byte_len )
      {
        FT_TRACE1(( "TT_Process_Composite_Glyph:"
                    " too many instructions (%hu) for glyph with length %u\n",
                    n_ins, loader->byte_len ));
        return FT_THROW( Too_Many_Hints );
      }

      tmp   = loader->exec->glyphSize;
      error = Update_Max( loader->exec->memory,
                          &tmp,
                          sizeof ( FT_Byte ),
                          (void*)&loader->exec->glyphIns,
                          n_ins );

      loader->exec->glyphSize = (FT_UShort)tmp;
      if ( error )
        return error;
    }
    else if ( n_ins == 0 )
      return FT_Err_Ok;

    if ( FT_STREAM_READ( loader->exec->glyphIns, n_ins ) )
      return error;

    loader->glyph->control_data = loader->exec->glyphIns;
    loader->glyph->control_len  = n_ins;
  }

#endif // TT_USE_BYTECODE_INTERPRETER

  tt_prepare_zone( &loader->zone, &loader->gloader->base,
                   start_point, start_contour );

  /* Some points are likely touched during execution of  */
  /* instructions on components.  So let's untouch them. */
  for ( i = 0; i < loader->zone.n_points; i++ )
    loader->zone.tags[i] &= ~FT_CURVE_TAG_TOUCH_BOTH;

  loader->zone.n_points += 4;
  return TT_Hint_Glyph( loader, 1 );
}

static FT_Error
TT_Process_Composite_Component( TT_Loader    loader,
                                FT_SubGlyph  subglyph,
                                FT_UInt      start_point,
                                FT_UInt      num_base_points )
{
  FT_GlyphLoader  gloader = loader->gloader;
  FT_Outline      current;
  FT_Bool         have_scale;
  FT_Pos          x, y;

  current.points   = gloader->base.outline.points +
                       num_base_points;
  current.n_points = gloader->base.outline.n_points -
                       (short)num_base_points;

  have_scale = FT_BOOL( subglyph->flags & ( WE_HAVE_A_SCALE     |
                                            WE_HAVE_AN_XY_SCALE |
                                            WE_HAVE_A_2X2       ) );

  /* perform the transform required for this subglyph */
  if ( have_scale )
    FT_Outline_Transform( &current, &subglyph->transform );

  /* get offset */
  if ( !( subglyph->flags & ARGS_ARE_XY_VALUES ) )
  {
    FT_UInt     num_points = (FT_UInt)gloader->base.outline.n_points;
    FT_UInt     k = (FT_UInt)subglyph->arg1;
    FT_UInt     l = (FT_UInt)subglyph->arg2;
    FT_Vector*  p1;
    FT_Vector*  p2;


    /* match l-th point of the newly loaded component to the k-th point */
    /* of the previously loaded components.                             */

    /* change to the point numbers used by our outline */
    k += start_point;
    l += num_base_points;
    if ( k >= num_base_points ||
         l >= num_points      )
      return FT_THROW( Invalid_Composite );

    p1 = gloader->base.outline.points + k;
    p2 = gloader->base.outline.points + l;

    x = SUB_LONG( p1->x, p2->x );
    y = SUB_LONG( p1->y, p2->y );
  }
  else
  {
    x = subglyph->arg1;
    y = subglyph->arg2;

    if ( !x && !y )
      return FT_Err_Ok;

    /* Use a default value dependent on                                  */
    /* TT_CONFIG_OPTION_COMPONENT_OFFSET_SCALED.  This is useful for old */
    /* TT fonts which don't set the xxx_COMPONENT_OFFSET bit.            */

    if ( have_scale &&
#ifdef TT_CONFIG_OPTION_COMPONENT_OFFSET_SCALED
         !( subglyph->flags & UNSCALED_COMPONENT_OFFSET ) )
#else
          ( subglyph->flags & SCALED_COMPONENT_OFFSET ) )
#endif
    {

#if FREETYPE_OG_ZERO

      /********************************************************************
       *
       * This algorithm is what Apple documents.  But it doesn't work.
       */
      int  a = subglyph->transform.xx > 0 ?  subglyph->transform.xx
                                          : -subglyph->transform.xx;
      int  b = subglyph->transform.yx > 0 ?  subglyph->transform.yx
                                          : -subglyph->transform.yx;
      int  c = subglyph->transform.xy > 0 ?  subglyph->transform.xy
                                          : -subglyph->transform.xy;
      int  d = subglyph->transform.yy > 0 ?  subglyph->transform.yy
                                          : -subglyph->transform.yy;
      int  m = a > b ? a : b;
      int  n = c > d ? c : d;


      if ( a - b <= 33 && a - b >= -33 )
        m *= 2;
      if ( c - d <= 33 && c - d >= -33 )
        n *= 2;
      x = FT_MulFix( x, m );
      y = FT_MulFix( y, n );

#else /* 1 */

      /********************************************************************
       *
       * This algorithm is a guess and works much better than the above.
       */
      FT_Fixed  mac_xscale = FT_Hypot( subglyph->transform.xx,
                                       subglyph->transform.xy );
      FT_Fixed  mac_yscale = FT_Hypot( subglyph->transform.yy,
                                       subglyph->transform.yx );


      x = FT_MulFix( x, mac_xscale );
      y = FT_MulFix( y, mac_yscale );

#endif /* 1 */

    }

    if ( !( loader->load_flags & FT_LOAD_NO_SCALE ) )
    {
      FT_Fixed  x_scale = loader->size->metrics->x_scale;
      FT_Fixed  y_scale = loader->size->metrics->y_scale;


      x = FT_MulFix( x, x_scale );
      y = FT_MulFix( y, y_scale );

      if ( subglyph->flags & ROUND_XY_TO_GRID )
      {
        TT_Face    face   = loader->face;
        TT_Driver  driver = (TT_Driver)FT_FACE_DRIVER( face );


        if ( IS_HINTED( loader->load_flags ) )
        {
          /*
           * We round the horizontal offset only if there is hinting along
           * the x axis; this corresponds to integer advance width values.
           *
           * Theoretically, a glyph's bytecode can toggle ClearType's
           * `backward compatibility' mode, which would allow modification
           * of the advance width.  In reality, however, applications
           * neither allow nor expect modified advance widths if subpixel
           * rendering is active.
           *
           */
          if ( driver->interpreter_version == TT_INTERPRETER_VERSION_35 )
            x = FT_PIX_ROUND( x );

          y = FT_PIX_ROUND( y );
        }
      }
    }
  }

  if ( x || y )
    FT_Outline_Translate( &current, x, y );
  return FT_Err_Ok;
}

static FT_Error
load_truetype_glyph( TT_Loader  loader,
                     FT_UInt    glyph_index,
                     FT_UInt    recurse_count,
                     FT_Bool    header_only )
{
  FT_Error        error   = FT_Err_Ok;
  FT_Fixed        x_scale, y_scale;
  FT_ULong        offset;
  TT_Face         face    = loader->face;
  FT_GlyphLoader  gloader = loader->gloader;

  FT_Bool  opened_frame = 0;

#ifdef FT_CONFIG_OPTION_INCREMENTAL
  FT_StreamRec    inc_stream;
  FT_Data         glyph_data;
  FT_Bool         glyph_data_loaded = 0;
#endif


#ifdef FT_DEBUG_LEVEL_TRACE
  if ( recurse_count )
    FT_TRACE5(( "  nesting level: %d\n", recurse_count ));
#endif

  /* some fonts have an incorrect value of `maxComponentDepth' */
  if ( recurse_count > face->max_profile.maxComponentDepth )
  {
    #if FREETYPE_WONT_INCLUDE
    FT_TRACE1(( "load_truetype_glyph: maxComponentDepth set to %d\n",
                recurse_count ));
    #endif
    face->max_profile.maxComponentDepth = (FT_UShort)recurse_count;
  }

#ifndef FT_CONFIG_OPTION_INCREMENTAL
  /* check glyph index */
  if ( glyph_index >= (FT_UInt)face->root.num_glyphs )
  {
    error = FT_THROW( Invalid_Glyph_Index );
    goto Exit;
  }
#endif

  loader->glyph_index = glyph_index;

  if ( loader->load_flags & FT_LOAD_NO_SCALE )
  {
    x_scale = 0x10000L;
    y_scale = 0x10000L;
  }
  else
  {
    x_scale = loader->size->metrics->x_scale;
    y_scale = loader->size->metrics->y_scale;
  }

  /* Set `offset' to the start of the glyph relative to the start of */
  /* the `glyf' table, and `byte_len' to the length of the glyph in  */
  /* bytes.                                                          */

#ifdef FT_CONFIG_OPTION_INCREMENTAL

  /* If we are loading glyph data via the incremental interface, set */
  /* the loader stream to a memory stream reading the data returned  */
  /* by the interface.                                               */
  if ( face->root.internal->incremental_interface )
  {
    error = face->root.internal->incremental_interface->funcs->get_glyph_data(
              face->root.internal->incremental_interface->object,
              glyph_index, &glyph_data );
    if ( error )
      goto Exit;

    glyph_data_loaded = 1;
    offset            = 0;
    loader->byte_len  = glyph_data.length;

    FT_ZERO( &inc_stream );
    FT_Stream_OpenMemory( &inc_stream,
                          glyph_data.pointer,
                          glyph_data.length );

    loader->stream = &inc_stream;
  }
  else

#endif /* FT_CONFIG_OPTION_INCREMENTAL */

    offset = tt_face_get_location( face, glyph_index, &loader->byte_len );

  if ( loader->byte_len > 0 )
  {
#ifdef FT_CONFIG_OPTION_INCREMENTAL
    /* for the incremental interface, `glyf_offset' is always zero */
    if ( !face->glyf_offset                          &&
         !face->root.internal->incremental_interface )
#else
    if ( !face->glyf_offset )
#endif /* FT_CONFIG_OPTION_INCREMENTAL */
    {
      #if FREETYPE_WONT_INCLUDE
      FT_TRACE2(( "no `glyf' table but non-zero `loca' entry\n" ));
      #endif
      error = FT_THROW( Invalid_Table );
      goto Exit;
    }

    error = face->access_glyph_frame( loader, glyph_index,
                                      face->glyf_offset + offset,
                                      loader->byte_len );
    if ( error )
      goto Exit;

    /* read glyph header first */
    error = face->read_glyph_header( loader );

    face->forget_glyph_frame( loader );

    if ( error )
      goto Exit;
  }

  /* a space glyph */
  if ( loader->byte_len == 0 || loader->n_contours == 0 )
  {
    loader->bbox.xMin = 0;
    loader->bbox.xMax = 0;
    loader->bbox.yMin = 0;
    loader->bbox.yMax = 0;
  }

  /* the metrics must be computed after loading the glyph header */
  /* since we need the glyph's `yMax' value in case the vertical */
  /* metrics must be emulated                                    */
  error = tt_get_metrics( loader, glyph_index );
  if ( error )
    goto Exit;

  if ( header_only )
    goto Exit;

  if ( loader->byte_len == 0 || loader->n_contours == 0 )
  {
#ifdef FT_CONFIG_OPTION_INCREMENTAL
    tt_get_metrics_incremental( loader, glyph_index );
#endif
    tt_loader_set_pp( loader );


#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT

    if ( FT_IS_NAMED_INSTANCE( FT_FACE( face ) ) ||
         FT_IS_VARIATION( FT_FACE( face ) )      )
    {
      /* a small outline structure with four elements for */
      /* communication with `TT_Vary_Apply_Glyph_Deltas'  */
      FT_Vector   points[4];
      char        tags[4]     = { 1, 1, 1, 1 };
      short       contours[4] = { 0, 1, 2, 3 };
      FT_Outline  outline;

      /* unrounded values */
      FT_Vector  unrounded[4] = { {0, 0}, {0, 0}, {0, 0}, {0, 0} };


      points[0].x = loader->pp1.x;
      points[0].y = loader->pp1.y;
      points[1].x = loader->pp2.x;
      points[1].y = loader->pp2.y;

      points[2].x = loader->pp3.x;
      points[2].y = loader->pp3.y;
      points[3].x = loader->pp4.x;
      points[3].y = loader->pp4.y;

      outline.n_points   = 4;
      outline.n_contours = 4;
      outline.points     = points;
      outline.tags       = tags;
      outline.contours   = contours;

      /* this must be done before scaling */
      error = TT_Vary_Apply_Glyph_Deltas( loader->face,
                                          glyph_index,
                                          &outline,
                                          unrounded,
                                          (FT_UInt)outline.n_points );
      if ( error )
        goto Exit;

      loader->pp1.x = points[0].x;
      loader->pp1.y = points[0].y;
      loader->pp2.x = points[1].x;
      loader->pp2.y = points[1].y;

      loader->pp3.x = points[2].x;
      loader->pp3.y = points[2].y;
      loader->pp4.x = points[3].x;
      loader->pp4.y = points[3].y;

      /* recalculate linear horizontal and vertical advances */
      /* if we don't have HVAR and VVAR, respectively        */
      if ( !( loader->face->variation_support & TT_FACE_FLAG_VAR_HADVANCE ) )
        loader->linear = FT_PIX_ROUND( unrounded[1].x -
                                       unrounded[0].x ) / 64;
      if ( !( loader->face->variation_support & TT_FACE_FLAG_VAR_VADVANCE ) )
        loader->vadvance = FT_PIX_ROUND( unrounded[3].x -
                                         unrounded[2].x ) / 64;
    }

#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */

    /* scale phantom points, if necessary; */
    /* they get rounded in `TT_Hint_Glyph' */
    if ( ( loader->load_flags & FT_LOAD_NO_SCALE ) == 0 )
    {
      loader->pp1.x = FT_MulFix( loader->pp1.x, x_scale );
      loader->pp2.x = FT_MulFix( loader->pp2.x, x_scale );
      /* pp1.y and pp2.y are always zero */

      loader->pp3.x = FT_MulFix( loader->pp3.x, x_scale );
      loader->pp3.y = FT_MulFix( loader->pp3.y, y_scale );
      loader->pp4.x = FT_MulFix( loader->pp4.x, x_scale );
      loader->pp4.y = FT_MulFix( loader->pp4.y, y_scale );
    }

    error = FT_Err_Ok;
    goto Exit;
  }

#ifdef FT_CONFIG_OPTION_INCREMENTAL
  tt_get_metrics_incremental( loader, glyph_index );
#endif
  tt_loader_set_pp( loader );


  /***********************************************************************/
  /***********************************************************************/
  /***********************************************************************/

  /* we now open a frame again, right after the glyph header */
  /* (which consists of 10 bytes)                            */
  error = face->access_glyph_frame( loader, glyph_index,
                                    face->glyf_offset + offset + 10,
                                    loader->byte_len - 10 );
  if ( error )
    goto Exit;

  opened_frame = 1;

  /* if it is a simple glyph, load it */

  if ( loader->n_contours > 0 )
  {
    error = face->read_simple_glyph( loader );
    if ( error )
      goto Exit;

    /* all data have been read */
    face->forget_glyph_frame( loader );
    opened_frame = 0;

    error = TT_Process_Simple_Glyph( loader );
    if ( error )
      goto Exit;

    FT_GlyphLoader_Add( gloader );
  }

  /***********************************************************************/
  /***********************************************************************/
  /***********************************************************************/

  /* otherwise, load a composite! */
  else if ( loader->n_contours < 0 )
  {
    FT_Memory  memory = face->root.memory;

    FT_UInt   start_point;
    FT_UInt   start_contour;
    FT_ULong  ins_pos;  /* position of composite instructions, if any */

    FT_ListNode  node, node2;


    /* normalize the `n_contours' value */
    loader->n_contours = -1;

    /*
     * We store the glyph index directly in the `node->data' pointer,
     * following the glib solution (cf. macro `GUINT_TO_POINTER') with a
     * double cast to make this portable.  Note, however, that this needs
     * pointers with a width of at least 32 bits.
     */

    /* clear the nodes filled by sibling chains */
    node = ft_list_get_node_at( &loader->composites, recurse_count );
    for ( node2 = node; node2; node2 = node2->next )
      node2->data = (void*)-1;

    /* check whether we already have a composite glyph with this index */
    if ( FT_List_Find( &loader->composites,
                       FT_UINT_TO_POINTER( glyph_index ) ) )
    {
      #if FREETYPE_WONT_INCLUDE
      FT_TRACE1(( "TT_Load_Composite_Glyph:"
                  " infinite recursion detected\n" ));
      #endif
      error = FT_THROW( Invalid_Composite );
      goto Exit;
    }

    else if ( node )
      node->data = FT_UINT_TO_POINTER( glyph_index );

    else
    {
      if ( FT_QNEW( node ) )
        goto Exit;
      node->data = FT_UINT_TO_POINTER( glyph_index );
      FT_List_Add( &loader->composites, node );
    }

    start_point   = (FT_UInt)gloader->base.outline.n_points;
    start_contour = (FT_UInt)gloader->base.outline.n_contours;

    /* for each subglyph, read composite header */
    error = face->read_composite_glyph( loader );
    if ( error )
      goto Exit;

    /* store the offset of instructions */
    ins_pos = loader->ins_pos;

    /* all data we need are read */
    face->forget_glyph_frame( loader );
    opened_frame = 0;

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT

    if ( FT_IS_NAMED_INSTANCE( FT_FACE( face ) ) ||
         FT_IS_VARIATION( FT_FACE( face ) )      )
    {
      short        i, limit;
      FT_SubGlyph  subglyph;

      FT_Outline  outline;
      FT_Vector*  points    = NULL;
      char*       tags      = NULL;
      short*      contours  = NULL;
      FT_Vector*  unrounded = NULL;


      limit = (short)gloader->current.num_subglyphs;

      /* construct an outline structure for              */
      /* communication with `TT_Vary_Apply_Glyph_Deltas' */
      outline.n_points   = (short)( gloader->current.num_subglyphs + 4 );
      outline.n_contours = outline.n_points;

      outline.points   = NULL;
      outline.tags     = NULL;
      outline.contours = NULL;

      if ( FT_NEW_ARRAY( points, outline.n_points )    ||
           FT_NEW_ARRAY( tags, outline.n_points )      ||
           FT_NEW_ARRAY( contours, outline.n_points )  ||
           FT_NEW_ARRAY( unrounded, outline.n_points ) )
        goto Exit1;

      subglyph = gloader->current.subglyphs;

      for ( i = 0; i < limit; i++, subglyph++ )
      {
        /* applying deltas for anchor points doesn't make sense, */
        /* but we don't have to specially check this since       */
        /* unused delta values are zero anyways                  */
        points[i].x = subglyph->arg1;
        points[i].y = subglyph->arg2;
        tags[i]     = 1;
        contours[i] = i;
      }

      points[i].x = loader->pp1.x;
      points[i].y = loader->pp1.y;
      tags[i]     = 1;
      contours[i] = i;

      i++;
      points[i].x = loader->pp2.x;
      points[i].y = loader->pp2.y;
      tags[i]     = 1;
      contours[i] = i;

      i++;
      points[i].x = loader->pp3.x;
      points[i].y = loader->pp3.y;
      tags[i]     = 1;
      contours[i] = i;

      i++;
      points[i].x = loader->pp4.x;
      points[i].y = loader->pp4.y;
      tags[i]     = 1;
      contours[i] = i;

      outline.points   = points;
      outline.tags     = tags;
      outline.contours = contours;

      /* this call provides additional offsets */
      /* for each component's translation      */
      if ( FT_SET_ERROR( TT_Vary_Apply_Glyph_Deltas(
                           face,
                           glyph_index,
                           &outline,
                           unrounded,
                           (FT_UInt)outline.n_points ) ) )
        goto Exit1;

      subglyph = gloader->current.subglyphs;

      for ( i = 0; i < limit; i++, subglyph++ )
      {
        if ( subglyph->flags & ARGS_ARE_XY_VALUES )
        {
          subglyph->arg1 = (FT_Int16)points[i].x;
          subglyph->arg2 = (FT_Int16)points[i].y;
        }
      }

      loader->pp1.x = points[i + 0].x;
      loader->pp1.y = points[i + 0].y;
      loader->pp2.x = points[i + 1].x;
      loader->pp2.y = points[i + 1].y;

      loader->pp3.x = points[i + 2].x;
      loader->pp3.y = points[i + 2].y;
      loader->pp4.x = points[i + 3].x;
      loader->pp4.y = points[i + 3].y;

      /* recalculate linear horizontal and vertical advances */
      /* if we don't have HVAR and VVAR, respectively        */
      if ( !( face->variation_support & TT_FACE_FLAG_VAR_HADVANCE ) )
        loader->linear =
          FT_PIX_ROUND( unrounded[outline.n_points - 3].x -
                        unrounded[outline.n_points - 4].x ) / 64;
      if ( !( face->variation_support & TT_FACE_FLAG_VAR_VADVANCE ) )
        loader->vadvance =
          FT_PIX_ROUND( unrounded[outline.n_points - 1].x -
                        unrounded[outline.n_points - 2].x ) / 64;

    Exit1:
      FT_FREE( outline.points );
      FT_FREE( outline.tags );
      FT_FREE( outline.contours );
      FT_FREE( unrounded );

      if ( error )
        goto Exit;
    }

#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */

    /* scale phantom points, if necessary; */
    /* they get rounded in `TT_Hint_Glyph' */
    if ( ( loader->load_flags & FT_LOAD_NO_SCALE ) == 0 )
    {
      loader->pp1.x = FT_MulFix( loader->pp1.x, x_scale );
      loader->pp2.x = FT_MulFix( loader->pp2.x, x_scale );
      /* pp1.y and pp2.y are always zero */

      loader->pp3.x = FT_MulFix( loader->pp3.x, x_scale );
      loader->pp3.y = FT_MulFix( loader->pp3.y, y_scale );
      loader->pp4.x = FT_MulFix( loader->pp4.x, x_scale );
      loader->pp4.y = FT_MulFix( loader->pp4.y, y_scale );
    }

    /* if the flag FT_LOAD_NO_RECURSE is set, we return the subglyph */
    /* `as is' in the glyph slot (the client application will be     */
    /* responsible for interpreting these data)...                   */
    if ( loader->load_flags & FT_LOAD_NO_RECURSE )
    {
      FT_GlyphLoader_Add( gloader );
      loader->glyph->format = FT_GLYPH_FORMAT_COMPOSITE;

      goto Exit;
    }

    /*********************************************************************/
    /*********************************************************************/
    /*********************************************************************/

    {
      FT_UInt      n, num_base_points;
      FT_SubGlyph  subglyph       = NULL;

      FT_UInt      num_points     = start_point;
      FT_UInt      num_subglyphs  = gloader->current.num_subglyphs;
      FT_UInt      num_base_subgs = gloader->base.num_subglyphs;

      FT_Stream    old_stream     = loader->stream;
      FT_UInt      old_byte_len   = loader->byte_len;


      FT_GlyphLoader_Add( gloader );

      /* read each subglyph independently */
      for ( n = 0; n < num_subglyphs; n++ )
      {
        FT_Vector  pp[4];

        FT_Int  linear_hadvance;
        FT_Int  linear_vadvance;


        /* Each time we call `load_truetype_glyph' in this loop, the */
        /* value of `gloader.base.subglyphs' can change due to table */
        /* reallocations.  We thus need to recompute the subglyph    */
        /* pointer on each iteration.                                */
        subglyph = gloader->base.subglyphs + num_base_subgs + n;

        pp[0] = loader->pp1;
        pp[1] = loader->pp2;
        pp[2] = loader->pp3;
        pp[3] = loader->pp4;

        linear_hadvance = loader->linear;
        linear_vadvance = loader->vadvance;

        num_base_points = (FT_UInt)gloader->base.outline.n_points;

        error = load_truetype_glyph( loader,
                                     (FT_UInt)subglyph->index,
                                     recurse_count + 1,
                                     FALSE );
        if ( error )
          goto Exit;

        /* restore subglyph pointer */
        subglyph = gloader->base.subglyphs + num_base_subgs + n;

        /* restore phantom points if necessary */
        if ( !( subglyph->flags & USE_MY_METRICS ) )
        {
          loader->pp1 = pp[0];
          loader->pp2 = pp[1];
          loader->pp3 = pp[2];
          loader->pp4 = pp[3];

          loader->linear   = linear_hadvance;
          loader->vadvance = linear_vadvance;
        }

        num_points = (FT_UInt)gloader->base.outline.n_points;

        if ( num_points == num_base_points )
          continue;

        /* gloader->base.outline consists of three parts:           */
        /*                                                          */
        /* 0 ----> start_point ----> num_base_points ----> n_points */
        /*    (1)               (2)                   (3)           */
        /*                                                          */
        /* (1) points that exist from the beginning                 */
        /* (2) component points that have been loaded so far        */
        /* (3) points of the newly loaded component                 */
        error = TT_Process_Composite_Component( loader,
                                                subglyph,
                                                start_point,
                                                num_base_points );
        if ( error )
          goto Exit;
      }

      loader->stream   = old_stream;
      loader->byte_len = old_byte_len;

      /* process the glyph */
      loader->ins_pos = ins_pos;
      if ( IS_HINTED( loader->load_flags ) &&
#ifdef TT_USE_BYTECODE_INTERPRETER
           subglyph                        &&
           subglyph->flags & WE_HAVE_INSTR &&
#endif
           num_points > start_point )
      {
        error = TT_Process_Composite_Glyph( loader,
                                            start_point,
                                            start_contour );
        if ( error )
          goto Exit;
      }
    }

    /* retain the overlap flag */
    if ( gloader->base.num_subglyphs                         &&
         gloader->base.subglyphs[0].flags & OVERLAP_COMPOUND )
      gloader->base.outline.flags |= FT_OUTLINE_OVERLAP;
  }

  /***********************************************************************/
  /***********************************************************************/
  /***********************************************************************/

Exit:

  if ( opened_frame )
    face->forget_glyph_frame( loader );

#ifdef FT_CONFIG_OPTION_INCREMENTAL

  if ( glyph_data_loaded )
    face->root.internal->incremental_interface->funcs->free_glyph_data(
      face->root.internal->incremental_interface->object,
      &glyph_data );

#endif
  return error;
}

static FT_Error
compute_glyph_metrics( TT_Loader  loader,
                       FT_UInt    glyph_index )
{
  TT_Face    face   = loader->face;

  FT_BBox       bbox;
  FT_Fixed      y_scale;
  TT_GlyphSlot  glyph = loader->glyph;
  TT_Size       size  = loader->size;

  y_scale = 0x10000L;
  if ( ( loader->load_flags & FT_LOAD_NO_SCALE ) == 0 )
    y_scale = size->metrics->y_scale;

  if ( glyph->format != FT_GLYPH_FORMAT_COMPOSITE )
    FT_Outline_Get_CBox( &glyph->outline, &bbox );
  else
    bbox = loader->bbox;

  /* get the device-independent horizontal advance; it is scaled later */
  /* by the base layer.                                                */
  glyph->linearHoriAdvance = loader->linear;

  glyph->metrics.horiBearingX = bbox.xMin;
  glyph->metrics.horiBearingY = bbox.yMax;
  if ( loader->widthp )
    glyph->metrics.horiAdvance = loader->widthp[glyph_index] * 64;
  else
    glyph->metrics.horiAdvance = SUB_LONG( loader->pp2.x, loader->pp1.x );

  /* set glyph dimensions */
  glyph->metrics.width  = SUB_LONG( bbox.xMax, bbox.xMin );
  glyph->metrics.height = SUB_LONG( bbox.yMax, bbox.yMin );

  /* Now take care of vertical metrics.  In the case where there is */
  /* no vertical information within the font (relatively common),   */
  /* create some metrics manually                                   */
  {
    FT_Pos  top;      /* scaled vertical top side bearing  */
    FT_Pos  advance;  /* scaled vertical advance height    */


    /* Get the unscaled top bearing and advance height. */
    if ( face->vertical_info                   &&
         face->vertical.number_Of_VMetrics > 0 )
    {
      top = (FT_Short)FT_DivFix( SUB_LONG( loader->pp3.y, bbox.yMax ),
                                 y_scale );

      if ( loader->pp3.y <= loader->pp4.y )
        advance = 0;
      else
        advance = (FT_UShort)FT_DivFix( SUB_LONG( loader->pp3.y,
                                                  loader->pp4.y ),
                                        y_scale );
    }
    else
    {
      FT_Pos  height;


      /* XXX Compute top side bearing and advance height in  */
      /*     Get_VMetrics instead of here.                   */

      /* NOTE: The OS/2 values are the only `portable' ones, */
      /*       which is why we use them, if there is an OS/2 */
      /*       table in the font.  Otherwise, we use the     */
      /*       values defined in the horizontal header.      */

      height = (FT_Short)FT_DivFix( SUB_LONG( bbox.yMax,
                                              bbox.yMin ),
                                    y_scale );
      if ( face->os2.version != 0xFFFFU )
        advance = (FT_Pos)( face->os2.sTypoAscender -
                            face->os2.sTypoDescender );
      else
        advance = (FT_Pos)( face->horizontal.Ascender -
                            face->horizontal.Descender );

      top = ( advance - height ) / 2;
    }

#ifdef FT_CONFIG_OPTION_INCREMENTAL
    {
      FT_Incremental_InterfaceRec*  incr;
      FT_Incremental_MetricsRec     incr_metrics;
      FT_Error                      error;


      incr = face->root.internal->incremental_interface;

      /* If this is an incrementally loaded font see if there are */
      /* overriding metrics for this glyph.                       */
      if ( incr && incr->funcs->get_glyph_metrics )
      {
        incr_metrics.bearing_x = 0;
        incr_metrics.bearing_y = top;
        incr_metrics.advance   = advance;

        error = incr->funcs->get_glyph_metrics( incr->object,
                                                glyph_index,
                                                TRUE,
                                                &incr_metrics );
        if ( error )
          return error;

        top     = incr_metrics.bearing_y;
        advance = incr_metrics.advance;
      }
    }

    /* GWW: Do vertical metrics get loaded incrementally too? */

#endif /* FT_CONFIG_OPTION_INCREMENTAL */

    glyph->linearVertAdvance = advance;

    /* scale the metrics */
    if ( !( loader->load_flags & FT_LOAD_NO_SCALE ) )
    {
      top     = FT_MulFix( top,     y_scale );
      advance = FT_MulFix( advance, y_scale );
    }

    /* XXX: for now, we have no better algorithm for the lsb, but it */
    /*      should work fine.                                        */
    /*                                                               */
    glyph->metrics.vertBearingX = SUB_LONG( glyph->metrics.horiBearingX,
                                            glyph->metrics.horiAdvance / 2 );
    glyph->metrics.vertBearingY = top;
    glyph->metrics.vertAdvance  = advance;
  }
  return FT_Err_Ok;
}

FT_LOCAL_DEF( FT_Error )
TT_Load_Glyph( TT_Size       size,
               TT_GlyphSlot  glyph,
               FT_UInt       glyph_index,
               FT_Int32      load_flags )
{
  FT_Error      error;
  TT_LoaderRec  loader;

  #if FREETYPE_WONT_INCLUDE
  FT_TRACE1(( "TT_Load_Glyph: glyph index %d\n", glyph_index ));
  #endif

#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS

  /* try to load embedded bitmap (if any) */
  if ( size->strike_index != 0xFFFFFFFFUL      &&
       ( load_flags & FT_LOAD_NO_BITMAP ) == 0 &&
       IS_DEFAULT_INSTANCE( glyph->face )      )
  {
    FT_Fixed  x_scale = size->root.metrics.x_scale;
    FT_Fixed  y_scale = size->root.metrics.y_scale;


    error = load_sbit_image( size, glyph, glyph_index, load_flags );
    if ( FT_ERR_EQ( error, Missing_Bitmap ) )
    {
      /* the bitmap strike is incomplete and misses the requested glyph; */
      /* if we have a bitmap-only font, return an empty glyph            */
      if ( !FT_IS_SCALABLE( glyph->face ) )
      {
        TT_Face  face = (TT_Face)glyph->face;

        FT_Short  left_bearing = 0;
        FT_Short  top_bearing  = 0;

        FT_UShort  advance_width  = 0;
        FT_UShort  advance_height = 0;


        /* to return an empty glyph, however, we need metrics data   */
        /* from the `hmtx' (or `vmtx') table; the assumption is that */
        /* empty glyphs are missing intentionally, representing      */
        /* whitespace - not having at least horizontal metrics is    */
        /* thus considered an error                                  */
        if ( !face->horz_metrics_size )
          return error;

        /* we now construct an empty bitmap glyph */
        TT_Get_HMetrics( face, glyph_index,
                         &left_bearing,
                         &advance_width );
        TT_Get_VMetrics( face, glyph_index,
                         0,
                         &top_bearing,
                         &advance_height );

        glyph->outline.n_points   = 0;
        glyph->outline.n_contours = 0;

        glyph->metrics.width  = 0;
        glyph->metrics.height = 0;

        glyph->metrics.horiBearingX = FT_MulFix( left_bearing, x_scale );
        glyph->metrics.horiBearingY = 0;
        glyph->metrics.horiAdvance  = FT_MulFix( advance_width, x_scale );

        glyph->metrics.vertBearingX = 0;
        glyph->metrics.vertBearingY = FT_MulFix( top_bearing, y_scale );
        glyph->metrics.vertAdvance  = FT_MulFix( advance_height, y_scale );

        glyph->format            = FT_GLYPH_FORMAT_BITMAP;
        glyph->bitmap.pixel_mode = FT_PIXEL_MODE_MONO;

        glyph->bitmap_left = 0;
        glyph->bitmap_top  = 0;

        return FT_Err_Ok;
      }
    }
    else if ( error )
    {
      /* return error if font is not scalable */
      if ( !FT_IS_SCALABLE( glyph->face ) )
        return error;
    }
    else
    {
      if ( FT_IS_SCALABLE( glyph->face ) ||
           FT_HAS_SBIX( glyph->face )    )
      {
        TT_Face  face = (TT_Face)glyph->face;


        /* for the bbox we need the header only */
        (void)tt_loader_init( &loader, size, glyph, load_flags, TRUE );
        (void)load_truetype_glyph( &loader, glyph_index, 0, TRUE );
        tt_loader_done( &loader );
        glyph->linearHoriAdvance = loader.linear;
        glyph->linearVertAdvance = loader.vadvance;

        /* Bitmaps from the 'sbix' table need special treatment:  */
        /* if there is a glyph contour, the bitmap origin must be */
        /* shifted to be relative to the lower left corner of the */
        /* glyph bounding box, also taking the left-side bearing  */
        /* (or top bearing) into account.                         */
        if ( face->sbit_table_type == TT_SBIT_TABLE_TYPE_SBIX &&
             loader.n_contours > 0                            )
        {
          FT_Int  bitmap_left;
          FT_Int  bitmap_top;


          if ( load_flags & FT_LOAD_VERTICAL_LAYOUT )
          {
            /* This is a guess, since Apple's CoreText engine doesn't */
            /* really do vertical typesetting.                        */
            bitmap_left = loader.bbox.xMin;
            bitmap_top  = loader.top_bearing;
          }
          else
          {
            bitmap_left = loader.left_bearing;
            bitmap_top  = loader.bbox.yMin;
          }

          glyph->bitmap_left += FT_MulFix( bitmap_left, x_scale ) >> 6;
          glyph->bitmap_top  += FT_MulFix( bitmap_top,  y_scale ) >> 6;
        }

        /* sanity checks: if `xxxAdvance' in the sbit metric */
        /* structure isn't set, use `linearXXXAdvance'      */
        if ( !glyph->metrics.horiAdvance && glyph->linearHoriAdvance )
          glyph->metrics.horiAdvance = FT_MulFix( glyph->linearHoriAdvance,
                                                  x_scale );
        if ( !glyph->metrics.vertAdvance && glyph->linearVertAdvance )
          glyph->metrics.vertAdvance = FT_MulFix( glyph->linearVertAdvance,
                                                  y_scale );
      }

      return FT_Err_Ok;
    }
  }

  if ( load_flags & FT_LOAD_SBITS_ONLY )
  {
    error = FT_THROW( Invalid_Argument );
    goto Exit;
  }

#endif /* TT_CONFIG_OPTION_EMBEDDED_BITMAPS */

  /* if FT_LOAD_NO_SCALE is not set, `ttmetrics' must be valid */
  if ( !( load_flags & FT_LOAD_NO_SCALE ) && !size->ttmetrics.valid )
  {
    error = FT_THROW( Invalid_Size_Handle );
    goto Exit;
  }

#ifdef FT_CONFIG_OPTION_SVG

  /* check for OT-SVG */
  if ( ( load_flags & FT_LOAD_COLOR ) && ( (TT_Face)glyph->face )->svg )
  {
    SFNT_Service  sfnt;

    FT_Short   leftBearing;
    FT_Short   topBearing;
    FT_UShort  advanceX;
    FT_UShort  advanceY;


    FT_TRACE3(( "Trying to load SVG glyph\n" ));
    sfnt = (SFNT_Service)( (TT_Face)glyph->face )->sfnt;

    error = sfnt->load_svg_doc( glyph, glyph_index );
    if ( !error )
    {
      TT_Face  face = (TT_Face)glyph->face;


      FT_TRACE3(( "Successfully loaded SVG glyph\n" ));

      glyph->format = FT_GLYPH_FORMAT_SVG;

      sfnt->get_metrics( face,
                         FALSE,
                         glyph_index,
                         &leftBearing,
                         &advanceX );
      sfnt->get_metrics( face,
                         TRUE,
                         glyph_index,
                         &topBearing,
                         &advanceY );

      advanceX = (FT_UShort)FT_MulDiv( advanceX,
                                       glyph->face->size->metrics.x_ppem,
                                       glyph->face->units_per_EM );
      advanceY = (FT_UShort)FT_MulDiv( advanceY,
                                       glyph->face->size->metrics.y_ppem,
                                       glyph->face->units_per_EM );

      glyph->metrics.horiAdvance = advanceX << 6;
      glyph->metrics.vertAdvance = advanceY << 6;

      return error;
    }

    FT_TRACE3(( "Failed to load SVG glyph\n" ));
  }

  /* return immediately if we only want SVG glyphs */
  if ( load_flags & FT_LOAD_SVG_ONLY )
  {
    error = FT_THROW( Invalid_Argument );
    goto Exit;
  }

#endif /* FT_CONFIG_OPTION_SVG */

  error = tt_loader_init( &loader, size, glyph, load_flags, FALSE );
  if ( error )
    goto Exit;

  /* done if we are only interested in the `hdmx` advance */
  if ( load_flags & FT_LOAD_ADVANCE_ONLY         &&
       !( load_flags & FT_LOAD_VERTICAL_LAYOUT ) &&
       loader.widthp                             )
  {
    glyph->metrics.horiAdvance = loader.widthp[glyph_index] * 64;
    goto Done;
  }

  glyph->format        = FT_GLYPH_FORMAT_OUTLINE;
  glyph->num_subglyphs = 0;
  glyph->outline.flags = 0;

  /* main loading loop */
  error = load_truetype_glyph( &loader, glyph_index, 0, FALSE );
  if ( !error )
  {
    if ( glyph->format == FT_GLYPH_FORMAT_COMPOSITE )
    {
      glyph->num_subglyphs = loader.gloader->base.num_subglyphs;
      glyph->subglyphs     = loader.gloader->base.subglyphs;
    }
    else
    {
      glyph->outline        = loader.gloader->base.outline;
      glyph->outline.flags &= ~FT_OUTLINE_SINGLE_PASS;

      /* Translate array so that (0,0) is the glyph's origin.  Note  */
      /* that this behaviour is independent on the value of bit 1 of */
      /* the `flags' field in the `head' table -- at least major     */
      /* applications like Acroread indicate that.                   */
      if ( loader.pp1.x )
        FT_Outline_Translate( &glyph->outline, -loader.pp1.x, 0 );
    }

#ifdef TT_USE_BYTECODE_INTERPRETER

    if ( IS_HINTED( load_flags ) )
    {
      if ( loader.exec->GS.scan_control )
      {
        /* convert scan conversion mode to FT_OUTLINE_XXX flags */
        switch ( loader.exec->GS.scan_type )
        {
        case 0: /* simple drop-outs including stubs */
          glyph->outline.flags |= FT_OUTLINE_INCLUDE_STUBS;
          break;
        case 1: /* simple drop-outs excluding stubs */
          /* nothing; it's the default rendering mode */
          break;
        case 4: /* smart drop-outs including stubs */
          glyph->outline.flags |= FT_OUTLINE_SMART_DROPOUTS |
                                  FT_OUTLINE_INCLUDE_STUBS;
          break;
        case 5: /* smart drop-outs excluding stubs  */
          glyph->outline.flags |= FT_OUTLINE_SMART_DROPOUTS;
          break;

        default: /* no drop-out control */
          glyph->outline.flags |= FT_OUTLINE_IGNORE_DROPOUTS;
          break;
        }
      }
      else
        glyph->outline.flags |= FT_OUTLINE_IGNORE_DROPOUTS;
    }

#endif /* TT_USE_BYTECODE_INTERPRETER */

    error = compute_glyph_metrics( &loader, glyph_index );
  }

  /* Set the `high precision' bit flag.                           */
  /* This is _critical_ to get correct output for monochrome      */
  /* TrueType glyphs at all sizes using the bytecode interpreter. */
  /*                                                              */
  if ( !( load_flags & FT_LOAD_NO_SCALE ) &&
       size->metrics->y_ppem < 24         )
    glyph->outline.flags |= FT_OUTLINE_HIGH_PRECISION;

#if FREETYPE_WONT_INCLUDE
  FT_TRACE1(( "  subglyphs = %u, contours = %hd, points = %hd,"
              " flags = 0x%.3x\n",
              loader.gloader->base.num_subglyphs,
              glyph->outline.n_contours,
              glyph->outline.n_points,
              glyph->outline.flags ));
#endif

Done:
  tt_loader_done( &loader );

Exit:
#ifdef FT_DEBUG_LEVEL_TRACE
  if ( error )
    FT_TRACE1(( "  failed (error code 0x%x)\n",
                error ));
#endif
  return error;
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
  return error;
}

static FT_Error
tt_get_kerning( FT_Face     ttface,          /* TT_Face */
                FT_UInt     left_glyph,
                FT_UInt     right_glyph,
                FT_Vector*  kerning )
{
  TT_Face       face = (TT_Face)ttface;
  SFNT_Service  sfnt = (SFNT_Service)face->sfnt;


  kerning->x = 0;
  kerning->y = 0;

  if ( sfnt )
    kerning->x = sfnt->get_kerning( face, left_glyph, right_glyph );
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
