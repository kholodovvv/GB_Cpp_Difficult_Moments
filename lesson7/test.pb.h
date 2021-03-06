// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_test_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_test_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_test_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_test_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_2eproto;
class Car;
struct CarDefaultTypeInternal;
extern CarDefaultTypeInternal _Car_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Car* Arena::CreateMaybeMessage<::Car>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Car final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Car) */ {
 public:
  inline Car() : Car(nullptr) {}
  ~Car() override;
  explicit constexpr Car(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Car(const Car& from);
  Car(Car&& from) noexcept
    : Car() {
    *this = ::std::move(from);
  }

  inline Car& operator=(const Car& from) {
    CopyFrom(from);
    return *this;
  }
  inline Car& operator=(Car&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Car& default_instance() {
    return *internal_default_instance();
  }
  static inline const Car* internal_default_instance() {
    return reinterpret_cast<const Car*>(
               &_Car_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Car& a, Car& b) {
    a.Swap(&b);
  }
  inline void Swap(Car* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Car* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Car* New() const final {
    return new Car();
  }

  Car* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Car>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Car& from);
  void MergeFrom(const Car& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Car* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Car";
  }
  protected:
  explicit Car(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBrandFieldNumber = 1,
    kModelFieldNumber = 2,
    kYearFieldNumber = 3,
  };
  // string brand = 1;
  void clear_brand();
  const std::string& brand() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_brand(ArgT0&& arg0, ArgT... args);
  std::string* mutable_brand();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_brand();
  void set_allocated_brand(std::string* brand);
  private:
  const std::string& _internal_brand() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_brand(const std::string& value);
  std::string* _internal_mutable_brand();
  public:

  // string model = 2;
  void clear_model();
  const std::string& model() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_model(ArgT0&& arg0, ArgT... args);
  std::string* mutable_model();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_model();
  void set_allocated_model(std::string* model);
  private:
  const std::string& _internal_model() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_model(const std::string& value);
  std::string* _internal_mutable_model();
  public:

  // int32 year = 3;
  void clear_year();
  ::PROTOBUF_NAMESPACE_ID::int32 year() const;
  void set_year(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_year() const;
  void _internal_set_year(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:Car)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr brand_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr model_;
  ::PROTOBUF_NAMESPACE_ID::int32 year_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_test_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Car

// string brand = 1;
inline void Car::clear_brand() {
  brand_.ClearToEmpty();
}
inline const std::string& Car::brand() const {
  // @@protoc_insertion_point(field_get:Car.brand)
  return _internal_brand();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Car::set_brand(ArgT0&& arg0, ArgT... args) {
 
 brand_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Car.brand)
}
inline std::string* Car::mutable_brand() {
  // @@protoc_insertion_point(field_mutable:Car.brand)
  return _internal_mutable_brand();
}
inline const std::string& Car::_internal_brand() const {
  return brand_.Get();
}
inline void Car::_internal_set_brand(const std::string& value) {
  
  brand_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Car::_internal_mutable_brand() {
  
  return brand_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Car::release_brand() {
  // @@protoc_insertion_point(field_release:Car.brand)
  return brand_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Car::set_allocated_brand(std::string* brand) {
  if (brand != nullptr) {
    
  } else {
    
  }
  brand_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), brand,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Car.brand)
}

// string model = 2;
inline void Car::clear_model() {
  model_.ClearToEmpty();
}
inline const std::string& Car::model() const {
  // @@protoc_insertion_point(field_get:Car.model)
  return _internal_model();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Car::set_model(ArgT0&& arg0, ArgT... args) {
 
 model_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Car.model)
}
inline std::string* Car::mutable_model() {
  // @@protoc_insertion_point(field_mutable:Car.model)
  return _internal_mutable_model();
}
inline const std::string& Car::_internal_model() const {
  return model_.Get();
}
inline void Car::_internal_set_model(const std::string& value) {
  
  model_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Car::_internal_mutable_model() {
  
  return model_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Car::release_model() {
  // @@protoc_insertion_point(field_release:Car.model)
  return model_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Car::set_allocated_model(std::string* model) {
  if (model != nullptr) {
    
  } else {
    
  }
  model_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), model,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Car.model)
}

// int32 year = 3;
inline void Car::clear_year() {
  year_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Car::_internal_year() const {
  return year_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Car::year() const {
  // @@protoc_insertion_point(field_get:Car.year)
  return _internal_year();
}
inline void Car::_internal_set_year(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  year_ = value;
}
inline void Car::set_year(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_year(value);
  // @@protoc_insertion_point(field_set:Car.year)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_test_2eproto
