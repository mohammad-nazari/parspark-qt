// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "parking-log-model-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/mysql/traits.hxx>
#include <odb/mysql/database.hxx>
#include <odb/mysql/transaction.hxx>
#include <odb/mysql/connection.hxx>
#include <odb/mysql/statement.hxx>
#include <odb/mysql/statement-cache.hxx>
#include <odb/mysql/simple-object-statements.hxx>
#include <odb/mysql/container-statements.hxx>
#include <odb/mysql/exceptions.hxx>
#include <odb/mysql/simple-object-result.hxx>
#include <odb/mysql/enum.hxx>

namespace odb
{
  // ParkingLogModel
  //

  const char alias_traits<  ::anar::model::CardModel,
    id_mysql,
    access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::Card_tag>::
  table_name[] = "`card_id`";

  const char alias_traits<  ::anar::model::SubscriptionModel,
    id_mysql,
    access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::Subscription_tag>::
  table_name[] = "`subscription_id`";

  struct access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      mysql::connection&,
      image_type&,
      id_image_type&,
      mysql::binding&,
      mysql::binding&)
    {
    }
  };

  access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::id_type
  access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  id (const id_image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          ::uint64_t,
          mysql::id_ulonglong >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::id_type
  access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  id (const image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          ::uint64_t,
          mysql::id_ulonglong >::set_value (
        id,
        i.Id_value,
        i.Id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // CreateModifyDeleteModel base
    //
    if (object_traits_impl< ::anar::model::CreateModifyDeleteModel, id_mysql >::grow (
          i, t + 0UL))
      grew = true;

    // Id
    //
    t[4UL] = 0;

    // Card
    //
    t[5UL] = 0;

    // EnterPlateNumber
    //
    if (t[6UL])
    {
      i.EnterPlateNumber_value.capacity (i.EnterPlateNumber_size);
      grew = true;
    }

    // ExitPlateNumber
    //
    if (t[7UL])
    {
      i.ExitPlateNumber_value.capacity (i.ExitPlateNumber_size);
      grew = true;
    }

    // EnteredTime
    //
    t[8UL] = 0;

    // ExitedTime
    //
    t[9UL] = 0;

    // ParkingCost
    //
    t[10UL] = 0;

    // EnterPictureAddress
    //
    if (t[11UL])
    {
      i.EnterPictureAddress_value.capacity (i.EnterPictureAddress_size);
      grew = true;
    }

    // ExitPictureAddress
    //
    if (t[12UL])
    {
      i.ExitPictureAddress_value.capacity (i.ExitPictureAddress_size);
      grew = true;
    }

    // Subscription
    //
    t[13UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // CreateModifyDeleteModel base
    //
    object_traits_impl< ::anar::model::CreateModifyDeleteModel, id_mysql >::bind (b + n, i, sk);
    n += 4UL;

    // Id
    //
    if (sk != statement_update)
    {
      b[n].buffer_type = MYSQL_TYPE_LONGLONG;
      b[n].is_unsigned = 1;
      b[n].buffer = &i.Id_value;
      b[n].is_null = &i.Id_null;
      n++;
    }

    // Card
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.Card_value;
    b[n].is_null = &i.Card_null;
    n++;

    // EnterPlateNumber
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.EnterPlateNumber_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.EnterPlateNumber_value.capacity ());
    b[n].length = &i.EnterPlateNumber_size;
    b[n].is_null = &i.EnterPlateNumber_null;
    n++;

    // ExitPlateNumber
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.ExitPlateNumber_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.ExitPlateNumber_value.capacity ());
    b[n].length = &i.ExitPlateNumber_size;
    b[n].is_null = &i.ExitPlateNumber_null;
    n++;

    // EnteredTime
    //
    b[n].buffer_type = MYSQL_TYPE_TIMESTAMP;
    b[n].buffer = &i.EnteredTime_value;
    b[n].is_null = &i.EnteredTime_null;
    n++;

    // ExitedTime
    //
    b[n].buffer_type = MYSQL_TYPE_TIMESTAMP;
    b[n].buffer = &i.ExitedTime_value;
    b[n].is_null = &i.ExitedTime_null;
    n++;

    // ParkingCost
    //
    b[n].buffer_type = MYSQL_TYPE_LONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.ParkingCost_value;
    b[n].is_null = &i.ParkingCost_null;
    n++;

    // EnterPictureAddress
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.EnterPictureAddress_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.EnterPictureAddress_value.capacity ());
    b[n].length = &i.EnterPictureAddress_size;
    b[n].is_null = &i.EnterPictureAddress_null;
    n++;

    // ExitPictureAddress
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.ExitPictureAddress_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.ExitPictureAddress_value.capacity ());
    b[n].length = &i.ExitPictureAddress_size;
    b[n].is_null = &i.ExitPictureAddress_null;
    n++;

    // Subscription
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.Subscription_value;
    b[n].is_null = &i.Subscription_null;
    n++;
  }

  void access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    // CreateModifyDeleteModel base
    //
    if (object_traits_impl< ::anar::model::CreateModifyDeleteModel, id_mysql >::init (i, o, sk))
      grew = true;

    // Id
    //
    if (sk == statement_insert)
    {
      ::uint64_t const& v =
        o.Id;

      bool is_null (false);
      mysql::value_traits<
          ::uint64_t,
          mysql::id_ulonglong >::set_image (
        i.Id_value, is_null, v);
      i.Id_null = is_null;
    }

    // Card
    //
    {
      ::anar::model::CardModelPtr const& v =
        o.Card;

      typedef object_traits< ::anar::model::CardModel > obj_traits;
      typedef odb::pointer_traits< ::anar::model::CardModelPtr > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_image (
          i.Card_value, is_null, id);
        i.Card_null = is_null;
      }
      else
        throw null_pointer ();
    }

    // EnterPlateNumber
    //
    {
      ::std::shared_ptr< ::std::basic_string< char > > const& v =
        o.EnterPlateNumber;

      bool is_null (true);
      std::size_t size (0);
      std::size_t cap (i.EnterPlateNumber_value.capacity ());
      mysql::value_traits<
          ::std::shared_ptr< ::std::basic_string< char > >,
          mysql::id_string >::set_image (
        i.EnterPlateNumber_value,
        size,
        is_null,
        v);
      i.EnterPlateNumber_null = is_null;
      i.EnterPlateNumber_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.EnterPlateNumber_value.capacity ());
    }

    // ExitPlateNumber
    //
    {
      ::std::shared_ptr< ::std::basic_string< char > > const& v =
        o.ExitPlateNumber;

      bool is_null (true);
      std::size_t size (0);
      std::size_t cap (i.ExitPlateNumber_value.capacity ());
      mysql::value_traits<
          ::std::shared_ptr< ::std::basic_string< char > >,
          mysql::id_string >::set_image (
        i.ExitPlateNumber_value,
        size,
        is_null,
        v);
      i.ExitPlateNumber_null = is_null;
      i.ExitPlateNumber_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.ExitPlateNumber_value.capacity ());
    }

    // EnteredTime
    //
    {
      ::time_t const& v =
        o.EnteredTime;

      bool is_null (false);
      mysql::value_traits<
          ::time_t,
          mysql::id_timestamp >::set_image (
        i.EnteredTime_value, is_null, v);
      i.EnteredTime_null = is_null;
    }

    // ExitedTime
    //
    {
      ::std::shared_ptr< time_t > const& v =
        o.ExitedTime;

      bool is_null (true);
      mysql::value_traits<
          ::std::shared_ptr<time_t >,
          mysql::id_timestamp >::set_image (
        i.ExitedTime_value, is_null, v);
      i.ExitedTime_null = is_null;
    }

    // ParkingCost
    //
    {
      ::std::shared_ptr< unsigned int > const& v =
        o.ParkingCost;

      bool is_null (true);
      mysql::value_traits<
          ::std::shared_ptr< unsigned int >,
          mysql::id_ulong >::set_image (
        i.ParkingCost_value, is_null, v);
      i.ParkingCost_null = is_null;
    }

    // EnterPictureAddress
    //
    {
      ::std::shared_ptr< ::std::basic_string< char > > const& v =
        o.EnterPictureAddress;

      bool is_null (true);
      std::size_t size (0);
      std::size_t cap (i.EnterPictureAddress_value.capacity ());
      mysql::value_traits<
          ::std::shared_ptr< ::std::basic_string< char > >,
          mysql::id_string >::set_image (
        i.EnterPictureAddress_value,
        size,
        is_null,
        v);
      i.EnterPictureAddress_null = is_null;
      i.EnterPictureAddress_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.EnterPictureAddress_value.capacity ());
    }

    // ExitPictureAddress
    //
    {
      ::std::shared_ptr< ::std::basic_string< char > > const& v =
        o.ExitPictureAddress;

      bool is_null (true);
      std::size_t size (0);
      std::size_t cap (i.ExitPictureAddress_value.capacity ());
      mysql::value_traits<
          ::std::shared_ptr< ::std::basic_string< char > >,
          mysql::id_string >::set_image (
        i.ExitPictureAddress_value,
        size,
        is_null,
        v);
      i.ExitPictureAddress_null = is_null;
      i.ExitPictureAddress_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.ExitPictureAddress_value.capacity ());
    }

    // Subscription
    //
    {
      ::anar::model::SubscriptionModelPtr const& v =
        o.Subscription;

      typedef object_traits< ::anar::model::SubscriptionModel > obj_traits;
      typedef odb::pointer_traits< ::anar::model::SubscriptionModelPtr > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_image (
          i.Subscription_value, is_null, id);
        i.Subscription_null = is_null;
      }
      else
        i.Subscription_null = 1;
    }

    return grew;
  }

  void access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // CreateModifyDeleteModel base
    //
    object_traits_impl< ::anar::model::CreateModifyDeleteModel, id_mysql >::init (o, i, db);

    // Id
    //
    {
      ::uint64_t& v =
        o.Id;

      mysql::value_traits<
          ::uint64_t,
          mysql::id_ulonglong >::set_value (
        v,
        i.Id_value,
        i.Id_null);
    }

    // Card
    //
    {
      ::anar::model::CardModelPtr& v =
        o.Card;

      typedef object_traits< ::anar::model::CardModel > obj_traits;
      typedef odb::pointer_traits< ::anar::model::CardModelPtr > ptr_traits;

      if (i.Card_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_value (
          id,
          i.Card_value,
          i.Card_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mysql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }

    // EnterPlateNumber
    //
    {
      ::std::shared_ptr< ::std::basic_string< char > >& v =
        o.EnterPlateNumber;

      mysql::value_traits<
          ::std::shared_ptr< ::std::basic_string< char > >,
          mysql::id_string >::set_value (
        v,
        i.EnterPlateNumber_value,
        i.EnterPlateNumber_size,
        i.EnterPlateNumber_null);
    }

    // ExitPlateNumber
    //
    {
      ::std::shared_ptr< ::std::basic_string< char > >& v =
        o.ExitPlateNumber;

      mysql::value_traits<
          ::std::shared_ptr< ::std::basic_string< char > >,
          mysql::id_string >::set_value (
        v,
        i.ExitPlateNumber_value,
        i.ExitPlateNumber_size,
        i.ExitPlateNumber_null);
    }

    // EnteredTime
    //
    {
      ::time_t& v =
        o.EnteredTime;

      mysql::value_traits<
          ::time_t,
          mysql::id_timestamp >::set_value (
        v,
        i.EnteredTime_value,
        i.EnteredTime_null);
    }

    // ExitedTime
    //
    {
      ::std::shared_ptr< time_t >& v =
        o.ExitedTime;

      mysql::value_traits<
          ::std::shared_ptr< time_t >,
          mysql::id_timestamp >::set_value (
        v,
        i.ExitedTime_value,
        i.ExitedTime_null);
    }

    // ParkingCost
    //
    {
      ::std::shared_ptr< unsigned int >& v =
        o.ParkingCost;

      mysql::value_traits<
          ::std::shared_ptr< unsigned int >,
          mysql::id_ulong >::set_value (
        v,
        i.ParkingCost_value,
        i.ParkingCost_null);
    }

    // EnterPictureAddress
    //
    {
      ::std::shared_ptr< ::std::basic_string< char > >& v =
        o.EnterPictureAddress;

      mysql::value_traits<
          ::std::shared_ptr< ::std::basic_string< char > >,
          mysql::id_string >::set_value (
        v,
        i.EnterPictureAddress_value,
        i.EnterPictureAddress_size,
        i.EnterPictureAddress_null);
    }

    // ExitPictureAddress
    //
    {
      ::std::shared_ptr< ::std::basic_string< char > >& v =
        o.ExitPictureAddress;

      mysql::value_traits<
          ::std::shared_ptr< ::std::basic_string< char > >,
          mysql::id_string >::set_value (
        v,
        i.ExitPictureAddress_value,
        i.ExitPictureAddress_size,
        i.ExitPictureAddress_null);
    }

    // Subscription
    //
    {
      ::anar::model::SubscriptionModelPtr& v =
        o.Subscription;

      typedef object_traits< ::anar::model::SubscriptionModel > obj_traits;
      typedef odb::pointer_traits< ::anar::model::SubscriptionModelPtr > ptr_traits;

      if (i.Subscription_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_value (
          id,
          i.Subscription_value,
          i.Subscription_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mysql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }
  }

  void access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      mysql::value_traits<
          ::uint64_t,
          mysql::id_ulonglong >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::persist_statement[] =
  "INSERT INTO `parking_log` "
  "(`creating_user_id`, "
  "`updating_user_id`, "
  "`created_time`, "
  "`updated_time`, "
  "`id`, "
  "`card_id`, "
  "`enter_plate_number`, "
  "`exit_plate_number`, "
  "`entered_time`, "
  "`exited_time`, "
  "`parking_cost`, "
  "`enter_picture_address`, "
  "`exit_picture_address`, "
  "`subscription_id`) "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::find_statement[] =
  "SELECT "
  "`parking_log`.`creating_user_id`, "
  "`parking_log`.`updating_user_id`, "
  "`parking_log`.`created_time`, "
  "`parking_log`.`updated_time`, "
  "`parking_log`.`id`, "
  "`parking_log`.`card_id`, "
  "`parking_log`.`enter_plate_number`, "
  "`parking_log`.`exit_plate_number`, "
  "`parking_log`.`entered_time`, "
  "`parking_log`.`exited_time`, "
  "`parking_log`.`parking_cost`, "
  "`parking_log`.`enter_picture_address`, "
  "`parking_log`.`exit_picture_address`, "
  "`parking_log`.`subscription_id` "
  "FROM `parking_log` "
  "WHERE `parking_log`.`id`=?";

  const char access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::update_statement[] =
  "UPDATE `parking_log` "
  "SET "
  "`creating_user_id`=?, "
  "`updating_user_id`=?, "
  "`created_time`=?, "
  "`updated_time`=?, "
  "`card_id`=?, "
  "`enter_plate_number`=?, "
  "`exit_plate_number`=?, "
  "`entered_time`=?, "
  "`exited_time`=?, "
  "`parking_cost`=?, "
  "`enter_picture_address`=?, "
  "`exit_picture_address`=?, "
  "`subscription_id`=? "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::erase_statement[] =
  "DELETE FROM `parking_log` "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::query_statement[] =
  "SELECT\n"
  "`parking_log`.`creating_user_id`,\n"
  "`parking_log`.`updating_user_id`,\n"
  "`parking_log`.`created_time`,\n"
  "`parking_log`.`updated_time`,\n"
  "`parking_log`.`id`,\n"
  "`parking_log`.`card_id`,\n"
  "`parking_log`.`enter_plate_number`,\n"
  "`parking_log`.`exit_plate_number`,\n"
  "`parking_log`.`entered_time`,\n"
  "`parking_log`.`exited_time`,\n"
  "`parking_log`.`parking_cost`,\n"
  "`parking_log`.`enter_picture_address`,\n"
  "`parking_log`.`exit_picture_address`,\n"
  "`parking_log`.`subscription_id`\n"
  "FROM `parking_log`\n"
  "LEFT JOIN `user` AS `creating_user_id` ON `creating_user_id`.`id`=`parking_log`.`creating_user_id`\n"
  "LEFT JOIN `user` AS `updating_user_id` ON `updating_user_id`.`id`=`parking_log`.`updating_user_id`\n"
  "LEFT JOIN `card` AS `card_id` ON `card_id`.`id`=`parking_log`.`card_id`\n"
  "LEFT JOIN `subscription` AS `subscription_id` ON `subscription_id`.`id`=`parking_log`.`subscription_id`";

  const char access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::erase_query_statement[] =
  "DELETE FROM `parking_log`";

  const char access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::table_name[] =
  "`parking_log`";

  void access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    im.Id_value = 0;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj.Id = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;
    using mysql::update_statement;

    callback (db, obj, callback_event::pre_update);

    mysql::transaction& tr (mysql::transaction::current ());
    mysql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.Id);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  erase (database& db, const id_type& id)
  {
    using namespace mysql;

    ODB_POTENTIALLY_UNUSED (db);

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::pointer_type
  access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  find (database& db, const id_type& id)
  {
    using namespace mysql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  reload (database& db, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.Id);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mysql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::object_type >
  access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  query (database&, const query_base_type& q)
  {
    using namespace mysql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += "\n";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        true,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) mysql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::anar::model::ParkingLogModel, id_mysql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
