// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef CREATE_MODIFY_DELETE_MODEL_ODB_HXX
#define CREATE_MODIFY_DELETE_MODEL_ODB_HXX

// Begin prologue.
//
#include "anar/service/model-binding/database/traits/traits.hxx"
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <cstddef>
#include <memory>
#include <odb/callback.hxx>
#include <odb/container-traits.hxx>
#include <odb/core.hxx>
#include <odb/details/shared-ptr.hxx>
#include <odb/details/unused.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/pre.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>
#include <odb/traits.hxx>
#include <odb/wrapper-traits.hxx>
#include <utility>

#include "contact-model-odb.hxx"
#include "model/database/create-modify-delete-model.hpp"
#include "person-model-odb.hxx"
#include "user-model-odb.hxx"

namespace odb
{
  // CreateModifyDeleteModel
  //
  template <>
  struct class_traits< ::anar::parspark::model::CreateModifyDeleteModel >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::anar::parspark::model::CreateModifyDeleteModel >
  {
    public:
    typedef ::anar::parspark::model::CreateModifyDeleteModel object_type;
    typedef ::std::shared_ptr< ::anar::parspark::model::CreateModifyDeleteModel > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    static const bool abstract = true;
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>
#include <odb/mysql/query.hxx>

namespace odb
{
  // CreateModifyDeleteModel
  //
  template <typename A>
  struct pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >
  {
    // CreatingUser
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    CreatingUser_type_;

    static const CreatingUser_type_ CreatingUser;

    // UpdatingUser
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    UpdatingUser_type_;

    static const UpdatingUser_type_ UpdatingUser;

    // CreatedTime
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::time_t,
        mysql::id_timestamp >::query_type,
      mysql::id_timestamp >
    CreatedTime_type_;

    static const CreatedTime_type_ CreatedTime;

    // UpdatedTime
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_timestamp >::query_type,
      mysql::id_timestamp >
    UpdatedTime_type_;

    static const UpdatedTime_type_ UpdatedTime;
  };

  template <typename A>
  const typename pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::CreatingUser_type_
  pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::
  CreatingUser (A::table_name, "`creating_user_id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::UpdatingUser_type_
  pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::
  UpdatingUser (A::table_name, "`updating_user_id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::CreatedTime_type_
  pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::
  CreatedTime (A::table_name, "`created_time`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::UpdatedTime_type_
  pointer_query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::
  UpdatedTime (A::table_name, "`updated_time`", 0);

  template <>
  class access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >:
    public access::object_traits< ::anar::parspark::model::CreateModifyDeleteModel >
  {
    public:
    struct image_type
    {
      // CreatingUser
      //
      unsigned long long CreatingUser_value;
      my_bool CreatingUser_null;

      // UpdatingUser
      //
      unsigned long long UpdatingUser_value;
      my_bool UpdatingUser_null;

      // CreatedTime
      //
      MYSQL_TIME CreatedTime_value;
      my_bool CreatedTime_null;

      // UpdatedTime
      //
      MYSQL_TIME UpdatedTime_value;
      my_bool UpdatedTime_null;
    };

    struct CreatingUser_tag;
    struct UpdatingUser_tag;

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);
  };

  // CreateModifyDeleteModel
  //
  template <>
  struct alias_traits<
    ::anar::parspark::model::UserModel,
    id_mysql,
    access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::CreatingUser_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::anar::parspark::model::UserModel,
    id_mysql,
    access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::UpdatingUser_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >
  {
    // CreatingUser
    //
    typedef
    odb::alias_traits<
      ::anar::parspark::model::UserModel,
      id_mysql,
      access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::CreatingUser_tag>
    CreatingUser_alias_;

    // UpdatingUser
    //
    typedef
    odb::alias_traits<
      ::anar::parspark::model::UserModel,
      id_mysql,
      access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::UpdatingUser_tag>
    UpdatingUser_alias_;
  };

  template <typename A>
  struct query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >:
    query_columns_base< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >
  {
    // CreatingUser
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    CreatingUser_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::anar::parspark::model::UserModel,
        id_mysql,
        CreatingUser_alias_ > >
    CreatingUser_pointer_type_;

    struct CreatingUser_type_: CreatingUser_pointer_type_, CreatingUser_column_type_
    {
      CreatingUser_type_ (const char* t, const char* c, const char* conv)
        : CreatingUser_column_type_ (t, c, conv)
      {
      }
    };

    static const CreatingUser_type_ CreatingUser;

    // UpdatingUser
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    UpdatingUser_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::anar::parspark::model::UserModel,
        id_mysql,
        UpdatingUser_alias_ > >
    UpdatingUser_pointer_type_;

    struct UpdatingUser_type_: UpdatingUser_pointer_type_, UpdatingUser_column_type_
    {
      UpdatingUser_type_ (const char* t, const char* c, const char* conv)
        : UpdatingUser_column_type_ (t, c, conv)
      {
      }
    };

    static const UpdatingUser_type_ UpdatingUser;

    // CreatedTime
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::time_t,
        mysql::id_timestamp >::query_type,
      mysql::id_timestamp >
    CreatedTime_type_;

    static const CreatedTime_type_ CreatedTime;

    // UpdatedTime
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_timestamp >::query_type,
      mysql::id_timestamp >
    UpdatedTime_type_;

    static const UpdatedTime_type_ UpdatedTime;
  };

  template <typename A>
  const typename query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::CreatingUser_type_
  query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::
  CreatingUser (A::table_name, "`creating_user_id`", 0);

  template <typename A>
  const typename query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::UpdatingUser_type_
  query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::
  UpdatingUser (A::table_name, "`updating_user_id`", 0);

  template <typename A>
  const typename query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::CreatedTime_type_
  query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::
  CreatedTime (A::table_name, "`created_time`", 0);

  template <typename A>
  const typename query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::UpdatedTime_type_
  query_columns< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >::
  UpdatedTime (A::table_name, "`updated_time`", 0);
}

#include "create-modify-delete-model-odb.ixx"

#include <odb/post.hxx>

#endif // CREATE_MODIFY_DELETE_MODEL_ODB_HXX
