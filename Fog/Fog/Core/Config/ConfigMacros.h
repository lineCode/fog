// [Fog-Core]
//
// [License]
// MIT, See COPYING file in package

#ifndef _FOG_CORE_CONFIG_CONFIGMACROS_H
#define _FOG_CORE_CONFIG_CONFIGMACROS_H

#if !defined(FOG_IDE) && !defined(_FOG_CORE_CONFIG_CONFIG_H)
#error "Fog::Core::Config - ConfigMacros.h can be only included by Fog/Core/Config/Config.h"
#endif // _FOG_CORE_CONFIG_CONFIG_H

// ============================================================================
// [Fog::Core::Build - Standard Macros]
// ============================================================================

//! @addtogroup Fog_Core_Macros
//! @{

//! @brief Some systems hasn't defined @c offsetof keyword, but FOG_OFFSET_OF
//! is always defined and it's possible to use it to get offset from a class
//! member (only single inheritance is allowed).
#define FOG_OFFSET_OF(_Struct_, _Field_) ((sysuint_t) ((const uint8_t*) &((const _Struct_*)0x1)->_Field_) - 1)

//! @brief Size of static table. Do not use this macro to get size of dynamic
//! table, you can't get it by this way!!!
//!
//! Use it for example in following way:
//! @code
//! uint table[] = { 1, 2, 3, 4, 5 };
//! uint i;
//!
//! for (i = 0; i != FOG_ARRAY_SIZE(table); i++)
//! {
//!   printf("table[%u]=%u\n", i, table[i]);
//! }
//! @endcode
#define FOG_ARRAY_SIZE(element) ( sizeof(element) / sizeof(element[0]) )

#if FOG_BYTE_ORDER == FOG_LITTLE_ENDIAN
#define FOG_MAKE_UINT16_SEQ(_V0_, _V1_) \
  (uint16_t) ( ((uint16_t)(_V0_) <<  0) | \
               ((uint16_t)(_V1_) <<  8) )
#define FOG_MAKE_UINT32_SEQ(_V0_, _V1_, _V2_, _V3_) \
  (uint32_t) ( ((uint32_t)(_V0_) <<  0) | \
               ((uint32_t)(_V1_) <<  8) | \
               ((uint32_t)(_V2_) << 16) | \
               ((uint32_t)(_V3_) << 24) )
#define FOG_MAKE_UINT64_SEQ(_V0_, _V1_, _V2_, _V3_, _V4_, _V5_, _V6_, _V7_) \
  (uint64_t) ( ((uint64_t)(_V0_) <<  0) | \
               ((uint64_t)(_V1_) <<  8) | \
               ((uint64_t)(_V2_) << 16) | \
               ((uint64_t)(_V3_) << 24) | \
               ((uint64_t)(_V4_) << 32) | \
               ((uint64_t)(_V5_) << 40) | \
               ((uint64_t)(_V6_) << 48) | \
               ((uint64_t)(_V7_) << 56) )
#else
#define FOG_MAKE_UINT16_SEQ(_V0_, _V1_) \
  (uint16_t) ( ((uint16_t)(_V1_) <<  0) | \
               ((uint16_t)(_V0_) <<  8) )
#define FOG_MAKE_UINT32_SEQ(_V0_, _V1_, _V2_, _V3_) \
  (uint32_t) ( ((uint32_t)(_V3_) <<  0) | \
               ((uint32_t)(_V2_) <<  8) | \
               ((uint32_t)(_V1_) << 16) | \
               ((uint32_t)(_V0_) << 24) )
#define FOG_MAKE_UINT64_SEQ(_V0_, _V1_, _V2_, _V3_, _V4_, _V5_, _V6_, _V7_) \
  (uint64_t) ( ((uint64_t)(_V7_) <<  0) | \
               ((uint64_t)(_V6_) <<  8) | \
               ((uint64_t)(_V5_) << 16) | \
               ((uint64_t)(_V4_) << 24) | \
               ((uint64_t)(_V3_) << 32) | \
               ((uint64_t)(_V2_) << 40) | \
               ((uint64_t)(_V1_) << 48) | \
               ((uint64_t)(_V0_) << 56) )
#endif

#define FOG_RETURN_ON_ERROR(_Expression_) \
  FOG_MACRO_BEGIN \
    err_t _ErrInside = (_Expression_); \
    if (FOG_UNLIKELY(_ErrInside != ::Fog::ERR_OK)) return _ErrInside; \
  FOG_MACRO_END

#define FOG_IS_ERROR(_Code_) (FOG_UNLIKELY((_Code_) != ERR_OK))
#define FOG_IS_NULL(_Var_) (FOG_UNLIKELY((_Var_) == NULL))

// ============================================================================
// [Noop]
// ============================================================================

#define FOG_NOP ((void)0)

//! @}

#endif // _FOG_CORE_CONFIG_CONFIGMACROS_H
