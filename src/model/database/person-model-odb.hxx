// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERSON_MODEL_ODB_HXX
#define PERSON_MODEL_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "person-model.hxx"

#include "contact-model-odb.hxx"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // PersonModel
  //
  template <>
  struct class_traits< ::anar::model::PersonModel >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::anar::model::PersonModel >
  {
    public:
    typedef ::anar::model::PersonModel object_type;
    typedef ::std::shared_ptr< ::anar::model::PersonModel > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::uint64_t id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
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
  // PersonModel
  //
  template <typename A>
  struct pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >
  {
    // Id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    Id_type_;

    static const Id_type_ Id;

    // FirstName
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    FirstName_type_;

    static const FirstName_type_ FirstName;

    // LastName
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    LastName_type_;

    static const LastName_type_ LastName;

    // NationalCardNumber
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    NationalCardNumber_type_;

    static const NationalCardNumber_type_ NationalCardNumber;

    // Age
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        unsigned char,
        mysql::id_utiny >::query_type,
      mysql::id_utiny >
    Age_type_;

    static const Age_type_ Age;

    // PersonContact
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    PersonContact_type_;

    static const PersonContact_type_ PersonContact;

    // BusinessContact
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    BusinessContact_type_;

    static const BusinessContact_type_ BusinessContact;

    // PictureAddress
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    PictureAddress_type_;

    static const PictureAddress_type_ PictureAddress;
  };

  template <typename A>
  const typename pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::Id_type_
  pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::
  Id (A::table_name, "`id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::FirstName_type_
  pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::
  FirstName (A::table_name, "`first_name`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::LastName_type_
  pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::
  LastName (A::table_name, "`last_name`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::NationalCardNumber_type_
  pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::
  NationalCardNumber (A::table_name, "`national_card_number`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::Age_type_
  pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::
  Age (A::table_name, "`age`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::PersonContact_type_
  pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::
  PersonContact (A::table_name, "`person_contact_id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::BusinessContact_type_
  pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::
  BusinessContact (A::table_name, "`business_contact_id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::PictureAddress_type_
  pointer_query_columns< ::anar::model::PersonModel, id_mysql, A >::
  PictureAddress (A::table_name, "`picture_address`", 0);

  template <>
  class access::object_traits_impl< ::anar::model::PersonModel, id_mysql >:
    public access::object_traits< ::anar::model::PersonModel >
  {
    public:
    struct id_image_type
    {
      unsigned long long id_value;
      my_bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // Id
      //
      unsigned long long Id_value;
      my_bool Id_null;

      // FirstName
      //
      details::buffer FirstName_value;
      unsigned long FirstName_size;
      my_bool FirstName_null;

      // LastName
      //
      details::buffer LastName_value;
      unsigned long LastName_size;
      my_bool LastName_null;

      // NationalCardNumber
      //
      unsigned long long NationalCardNumber_value;
      my_bool NationalCardNumber_null;

      // Age
      //
      unsigned char Age_value;
      my_bool Age_null;

      // PersonContact
      //
      unsigned long long PersonContact_value;
      my_bool PersonContact_null;

      // BusinessContact
      //
      unsigned long long BusinessContact_value;
      my_bool BusinessContact_null;

      // PictureAddress
      //
      details::buffer PictureAddress_value;
      unsigned long PictureAddress_size;
      my_bool PictureAddress_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct PersonContact_tag;
    struct BusinessContact_tag;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mysql::object_statements<object_type> statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 8UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::anar::model::PersonModel, id_common >:
    public access::object_traits_impl< ::anar::model::PersonModel, id_mysql >
  {
  };

  // PersonModel
  //
  template <>
  struct alias_traits<
    ::anar::model::ContactModel,
    id_mysql,
    access::object_traits_impl< ::anar::model::PersonModel, id_mysql >::PersonContact_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::anar::model::ContactModel,
    id_mysql,
    access::object_traits_impl< ::anar::model::PersonModel, id_mysql >::BusinessContact_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::anar::model::PersonModel, id_mysql >
  {
    // PersonContact
    //
    typedef
    odb::alias_traits<
      ::anar::model::ContactModel,
      id_mysql,
      access::object_traits_impl< ::anar::model::PersonModel, id_mysql >::PersonContact_tag>
    PersonContact_alias_;

    // BusinessContact
    //
    typedef
    odb::alias_traits<
      ::anar::model::ContactModel,
      id_mysql,
      access::object_traits_impl< ::anar::model::PersonModel, id_mysql >::BusinessContact_tag>
    BusinessContact_alias_;
  };

  template <typename A>
  struct query_columns< ::anar::model::PersonModel, id_mysql, A >:
    query_columns_base< ::anar::model::PersonModel, id_mysql >
  {
    // Id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    Id_type_;

    static const Id_type_ Id;

    // FirstName
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    FirstName_type_;

    static const FirstName_type_ FirstName;

    // LastName
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    LastName_type_;

    static const LastName_type_ LastName;

    // NationalCardNumber
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    NationalCardNumber_type_;

    static const NationalCardNumber_type_ NationalCardNumber;

    // Age
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        unsigned char,
        mysql::id_utiny >::query_type,
      mysql::id_utiny >
    Age_type_;

    static const Age_type_ Age;

    // PersonContact
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    PersonContact_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::anar::model::ContactModel,
        id_mysql,
        PersonContact_alias_ > >
    PersonContact_pointer_type_;

    struct PersonContact_type_: PersonContact_pointer_type_, PersonContact_column_type_
    {
      PersonContact_type_ (const char* t, const char* c, const char* conv)
        : PersonContact_column_type_ (t, c, conv)
      {
      }
    };

    static const PersonContact_type_ PersonContact;

    // BusinessContact
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    BusinessContact_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::anar::model::ContactModel,
        id_mysql,
        BusinessContact_alias_ > >
    BusinessContact_pointer_type_;

    struct BusinessContact_type_: BusinessContact_pointer_type_, BusinessContact_column_type_
    {
      BusinessContact_type_ (const char* t, const char* c, const char* conv)
        : BusinessContact_column_type_ (t, c, conv)
      {
      }
    };

    static const BusinessContact_type_ BusinessContact;

    // PictureAddress
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    PictureAddress_type_;

    static const PictureAddress_type_ PictureAddress;
  };

  template <typename A>
  const typename query_columns< ::anar::model::PersonModel, id_mysql, A >::Id_type_
  query_columns< ::anar::model::PersonModel, id_mysql, A >::
  Id (A::table_name, "`id`", 0);

  template <typename A>
  const typename query_columns< ::anar::model::PersonModel, id_mysql, A >::FirstName_type_
  query_columns< ::anar::model::PersonModel, id_mysql, A >::
  FirstName (A::table_name, "`first_name`", 0);

  template <typename A>
  const typename query_columns< ::anar::model::PersonModel, id_mysql, A >::LastName_type_
  query_columns< ::anar::model::PersonModel, id_mysql, A >::
  LastName (A::table_name, "`last_name`", 0);

  template <typename A>
  const typename query_columns< ::anar::model::PersonModel, id_mysql, A >::NationalCardNumber_type_
  query_columns< ::anar::model::PersonModel, id_mysql, A >::
  NationalCardNumber (A::table_name, "`national_card_number`", 0);

  template <typename A>
  const typename query_columns< ::anar::model::PersonModel, id_mysql, A >::Age_type_
  query_columns< ::anar::model::PersonModel, id_mysql, A >::
  Age (A::table_name, "`age`", 0);

  template <typename A>
  const typename query_columns< ::anar::model::PersonModel, id_mysql, A >::PersonContact_type_
  query_columns< ::anar::model::PersonModel, id_mysql, A >::
  PersonContact (A::table_name, "`person_contact_id`", 0);

  template <typename A>
  const typename query_columns< ::anar::model::PersonModel, id_mysql, A >::BusinessContact_type_
  query_columns< ::anar::model::PersonModel, id_mysql, A >::
  BusinessContact (A::table_name, "`business_contact_id`", 0);

  template <typename A>
  const typename query_columns< ::anar::model::PersonModel, id_mysql, A >::PictureAddress_type_
  query_columns< ::anar::model::PersonModel, id_mysql, A >::
  PictureAddress (A::table_name, "`picture_address`", 0);
}

#include "person-model-odb.ixx"

#include <odb/post.hxx>

#endif // PERSON_MODEL_ODB_HXX
