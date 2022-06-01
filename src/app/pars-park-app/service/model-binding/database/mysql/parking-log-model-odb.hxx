// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PARKING_LOG_MODEL_ODB_HXX
#define PARKING_LOG_MODEL_ODB_HXX

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

#include "car-model-odb.hxx"
#include "card-model-odb.hxx"
#include "contact-model-odb.hxx"
#include "create-modify-delete-model-odb.hxx"
#include "driver-model-odb.hxx"
#include "model/database/parking-log-model.hpp"
#include "organization-model-odb.hxx"
#include "person-model-odb.hxx"
#include "subscription-model-odb.hxx"
#include "user-model-odb.hxx"

namespace odb
{
  // ParkingLogModel
  //
  template <>
  struct class_traits< anar::parspark::model::ParkingLogModel >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< anar::parspark::model::ParkingLogModel >
  {
    public:
    typedef anar::parspark::model::ParkingLogModel object_type;
    typedef ::std::shared_ptr< anar::parspark::model::ParkingLogModel > pointer_type;
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
  // ParkingLogModel
  //
  template <typename A>
  struct pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >:
    pointer_query_columns< anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >
  {
    // CreateModifyDeleteModel
    //
    typedef pointer_query_columns< anar::parspark::model::CreateModifyDeleteModel, id_mysql, A > CreateModifyDeleteModel;

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

    // Card
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    Card_type_;

    static const Card_type_ Card;

    // EnterPlateNumber
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    EnterPlateNumber_type_;

    static const EnterPlateNumber_type_ EnterPlateNumber;

    // ExitPlateNumber
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    ExitPlateNumber_type_;

    static const ExitPlateNumber_type_ ExitPlateNumber;

    // EnteredTime
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::time_t,
        mysql::id_timestamp >::query_type,
      mysql::id_timestamp >
    EnteredTime_type_;

    static const EnteredTime_type_ EnteredTime;

    // ExitedTime
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_timestamp >::query_type,
      mysql::id_timestamp >
    ExitedTime_type_;

    static const ExitedTime_type_ ExitedTime;

    // ParkingCost
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        unsigned int,
        mysql::id_ulong >::query_type,
      mysql::id_ulong >
    ParkingCost_type_;

    static const ParkingCost_type_ ParkingCost;

    // EnterPictureAddress
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    EnterPictureAddress_type_;

    static const EnterPictureAddress_type_ EnterPictureAddress;

    // ExitPictureAddress
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    ExitPictureAddress_type_;

    static const ExitPictureAddress_type_ ExitPictureAddress;

    // Subscription
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    Subscription_type_;

    static const Subscription_type_ Subscription;
  };

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::Id_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  Id (A::table_name, "`id`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::Card_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  Card (A::table_name, "`card_id`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::EnterPlateNumber_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  EnterPlateNumber (A::table_name, "`enter_plate_number`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::ExitPlateNumber_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  ExitPlateNumber (A::table_name, "`exit_plate_number`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::EnteredTime_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  EnteredTime (A::table_name, "`entered_time`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::ExitedTime_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  ExitedTime (A::table_name, "`exited_time`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::ParkingCost_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  ParkingCost (A::table_name, "`parking_cost`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::EnterPictureAddress_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  EnterPictureAddress (A::table_name, "`enter_picture_address`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::ExitPictureAddress_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  ExitPictureAddress (A::table_name, "`exit_picture_address`", 0);

  template <typename A>
  const typename pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::Subscription_type_
  pointer_query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  Subscription (A::table_name, "`subscription_id`", 0);

  template <>
  class access::object_traits_impl< anar::parspark::model::ParkingLogModel, id_mysql >:
    public access::object_traits< anar::parspark::model::ParkingLogModel >
  {
    public:
    struct id_image_type
    {
      unsigned long long id_value;
      my_bool id_null;

      std::size_t version;
    };

    struct image_type: object_traits_impl< anar::parspark::model::CreateModifyDeleteModel, id_mysql >::image_type
    {
      // Id
      //
      unsigned long long Id_value;
      my_bool Id_null;

      // Card
      //
      unsigned long long Card_value;
      my_bool Card_null;

      // EnterPlateNumber
      //
      details::buffer EnterPlateNumber_value;
      unsigned long EnterPlateNumber_size;
      my_bool EnterPlateNumber_null;

      // ExitPlateNumber
      //
      details::buffer ExitPlateNumber_value;
      unsigned long ExitPlateNumber_size;
      my_bool ExitPlateNumber_null;

      // EnteredTime
      //
      MYSQL_TIME EnteredTime_value;
      my_bool EnteredTime_null;

      // ExitedTime
      //
      MYSQL_TIME ExitedTime_value;
      my_bool ExitedTime_null;

      // ParkingCost
      //
      unsigned int ParkingCost_value;
      my_bool ParkingCost_null;

      // EnterPictureAddress
      //
      details::buffer EnterPictureAddress_value;
      unsigned long EnterPictureAddress_size;
      my_bool EnterPictureAddress_null;

      // ExitPictureAddress
      //
      details::buffer ExitPictureAddress_value;
      unsigned long ExitPictureAddress_size;
      my_bool ExitPictureAddress_null;

      // Subscription
      //
      unsigned long long Subscription_value;
      my_bool Subscription_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct Card_tag;
    struct Subscription_tag;

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

    static const std::size_t column_count = 14UL;
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
  class access::object_traits_impl< anar::parspark::model::ParkingLogModel, id_common >:
    public access::object_traits_impl< anar::parspark::model::ParkingLogModel, id_mysql >
  {
  };

  // ParkingLogModel
  //
  template <>
  struct alias_traits<
    anar::parspark::model::CardModel,
    id_mysql,
    access::object_traits_impl< anar::parspark::model::ParkingLogModel, id_mysql >::Card_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    anar::parspark::model::SubscriptionModel,
    id_mysql,
    access::object_traits_impl< anar::parspark::model::ParkingLogModel, id_mysql >::Subscription_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< anar::parspark::model::ParkingLogModel, id_mysql >
  {
    // Card
    //
    typedef
    odb::alias_traits<
      anar::parspark::model::CardModel,
      id_mysql,
      access::object_traits_impl< anar::parspark::model::ParkingLogModel, id_mysql >::Card_tag>
    Card_alias_;

    // Subscription
    //
    typedef
    odb::alias_traits<
      anar::parspark::model::SubscriptionModel,
      id_mysql,
      access::object_traits_impl< anar::parspark::model::ParkingLogModel, id_mysql >::Subscription_tag>
    Subscription_alias_;
  };

  template <typename A>
  struct query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >:
    query_columns_base< anar::parspark::model::ParkingLogModel, id_mysql >,
    query_columns< anar::parspark::model::CreateModifyDeleteModel, id_mysql, A >
  {
    // CreateModifyDeleteModel
    //
    typedef query_columns< anar::parspark::model::CreateModifyDeleteModel, id_mysql, A > CreateModifyDeleteModel;

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

    // Card
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    Card_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        anar::parspark::model::CardModel,
        id_mysql,
        Card_alias_ > >
    Card_pointer_type_;

    struct Card_type_: Card_pointer_type_, Card_column_type_
    {
      Card_type_ (const char* t, const char* c, const char* conv)
        : Card_column_type_ (t, c, conv)
      {
      }
    };

    static const Card_type_ Card;

    // EnterPlateNumber
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    EnterPlateNumber_type_;

    static const EnterPlateNumber_type_ EnterPlateNumber;

    // ExitPlateNumber
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    ExitPlateNumber_type_;

    static const ExitPlateNumber_type_ ExitPlateNumber;

    // EnteredTime
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::time_t,
        mysql::id_timestamp >::query_type,
      mysql::id_timestamp >
    EnteredTime_type_;

    static const EnteredTime_type_ EnteredTime;

    // ExitedTime
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_timestamp >::query_type,
      mysql::id_timestamp >
    ExitedTime_type_;

    static const ExitedTime_type_ ExitedTime;

    // ParkingCost
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        unsigned int,
        mysql::id_ulong >::query_type,
      mysql::id_ulong >
    ParkingCost_type_;

    static const ParkingCost_type_ ParkingCost;

    // EnterPictureAddress
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    EnterPictureAddress_type_;

    static const EnterPictureAddress_type_ EnterPictureAddress;

    // ExitPictureAddress
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    ExitPictureAddress_type_;

    static const ExitPictureAddress_type_ ExitPictureAddress;

    // Subscription
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::uint64_t,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    Subscription_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        anar::parspark::model::SubscriptionModel,
        id_mysql,
        Subscription_alias_ > >
    Subscription_pointer_type_;

    struct Subscription_type_: Subscription_pointer_type_, Subscription_column_type_
    {
      Subscription_type_ (const char* t, const char* c, const char* conv)
        : Subscription_column_type_ (t, c, conv)
      {
      }
    };

    static const Subscription_type_ Subscription;
  };

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::Id_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  Id (A::table_name, "`id`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::Card_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  Card (A::table_name, "`card_id`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::EnterPlateNumber_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  EnterPlateNumber (A::table_name, "`enter_plate_number`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::ExitPlateNumber_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  ExitPlateNumber (A::table_name, "`exit_plate_number`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::EnteredTime_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  EnteredTime (A::table_name, "`entered_time`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::ExitedTime_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  ExitedTime (A::table_name, "`exited_time`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::ParkingCost_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  ParkingCost (A::table_name, "`parking_cost`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::EnterPictureAddress_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  EnterPictureAddress (A::table_name, "`enter_picture_address`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::ExitPictureAddress_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  ExitPictureAddress (A::table_name, "`exit_picture_address`", 0);

  template <typename A>
  const typename query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::Subscription_type_
  query_columns< anar::parspark::model::ParkingLogModel, id_mysql, A >::
  Subscription (A::table_name, "`subscription_id`", 0);
}

#include "parking-log-model-odb.ixx"

#include <odb/post.hxx>

#endif // PARKING_LOG_MODEL_ODB_HXX
