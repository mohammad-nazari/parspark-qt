// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "user-model-odb.hxx"

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
  // UserModel
  //

  const char alias_traits<  ::anar::parspark::model::PersonModel,
    id_mysql,
    access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::Person_tag>::
  table_name[] = "`person_id`";

  const char alias_traits<  ::anar::parspark::model::UserModel,
    id_mysql,
    access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::CreatingUser_tag>::
  table_name[] = "`creating_user_id`";

  const char alias_traits<  ::anar::parspark::model::UserModel,
    id_mysql,
    access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::UpdatingUser_tag>::
  table_name[] = "`updating_user_id`";

  struct access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::extra_statement_cache_type
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

  access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::id_type
  access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::id_type
  access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  bool access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // Id
    //
    t[0UL] = 0;

    // UserName
    //
    if (t[1UL])
    {
      i.UserName_value.capacity (i.UserName_size);
      grew = true;
    }

    // PassWord
    //
    if (t[2UL])
    {
      i.PassWord_value.capacity (i.PassWord_size);
      grew = true;
    }

    // Person
    //
    t[3UL] = 0;

    // Type
    //
    if (t[4UL])
    {
      if (mysql::enum_traits::grow (i.Type_value, i.Type_size))
        grew = true;
      else
        t[4UL] = 0;
    }

    // CreatingUser
    //
    t[5UL] = 0;

    // UpdatingUser
    //
    t[6UL] = 0;

    // CreatedTime
    //
    t[7UL] = 0;

    // UpdatedTime
    //
    t[8UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

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

    // UserName
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.UserName_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.UserName_value.capacity ());
    b[n].length = &i.UserName_size;
    b[n].is_null = &i.UserName_null;
    n++;

    // PassWord
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.PassWord_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.PassWord_value.capacity ());
    b[n].length = &i.PassWord_size;
    b[n].is_null = &i.PassWord_null;
    n++;

    // Person
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.Person_value;
    b[n].is_null = &i.Person_null;
    n++;

    // Type
    //
    mysql::enum_traits::bind (b[n],
                              i.Type_value,
                              i.Type_size,
                              &i.Type_null);
    n++;

    // CreatingUser
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.CreatingUser_value;
    b[n].is_null = &i.CreatingUser_null;
    n++;

    // UpdatingUser
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.UpdatingUser_value;
    b[n].is_null = &i.UpdatingUser_null;
    n++;

    // CreatedTime
    //
    b[n].buffer_type = MYSQL_TYPE_TIMESTAMP;
    b[n].buffer = &i.CreatedTime_value;
    b[n].is_null = &i.CreatedTime_null;
    n++;

    // UpdatedTime
    //
    b[n].buffer_type = MYSQL_TYPE_TIMESTAMP;
    b[n].buffer = &i.UpdatedTime_value;
    b[n].is_null = &i.UpdatedTime_null;
    n++;
  }

  void access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

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

    // UserName
    //
    {
      ::std::string const& v =
        o.UserName;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.UserName_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.UserName_value,
        size,
        is_null,
        v);
      i.UserName_null = is_null;
      i.UserName_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.UserName_value.capacity ());
    }

    // PassWord
    //
    {
      ::std::string const& v =
        o.PassWord;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.PassWord_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.PassWord_value,
        size,
        is_null,
        v);
      i.PassWord_null = is_null;
      i.PassWord_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.PassWord_value.capacity ());
    }

    // Person
    //
    {
      ::anar::parspark::model::PersonModelPtr const& v =
        o.Person;

      typedef object_traits< ::anar::parspark::model::PersonModel > obj_traits;
      typedef odb::pointer_traits< ::anar::parspark::model::PersonModelPtr > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_image (
          i.Person_value, is_null, id);
        i.Person_null = is_null;
      }
      else
        i.Person_null = 1;
    }

    // Type
    //
    {
      ::anar::parspark::model::UserType const& v =
        o.Type;

      bool is_null (false);
      if (mysql::enum_traits::set_image (
            i.Type_value,
            i.Type_size,
            is_null,
            v))
        grew = true;

      i.Type_null = is_null;
    }

    // CreatingUser
    //
    {
      ::anar::parspark::model::UserModelPtr const& v =
        o.CreatingUser;

      typedef object_traits< ::anar::parspark::model::UserModel > obj_traits;
      typedef odb::pointer_traits< ::anar::parspark::model::UserModelPtr > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_image (
          i.CreatingUser_value, is_null, id);
        i.CreatingUser_null = is_null;
      }
      else
        throw null_pointer ();
    }

    // UpdatingUser
    //
    {
      ::anar::parspark::model::UserModelPtr const& v =
        o.UpdatingUser;

      typedef object_traits< ::anar::parspark::model::UserModel > obj_traits;
      typedef odb::pointer_traits< ::anar::parspark::model::UserModelPtr > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_image (
          i.UpdatingUser_value, is_null, id);
        i.UpdatingUser_null = is_null;
      }
      else
        i.UpdatingUser_null = 1;
    }

    // CreatedTime
    //
    {
      ::time_t const& v =
        o.CreatedTime;

      bool is_null (false);
      mysql::value_traits<
          ::time_t,
          mysql::id_timestamp >::set_image (
        i.CreatedTime_value, is_null, v);
      i.CreatedTime_null = is_null;
    }

    // UpdatedTime
    //
    {
      ::std::shared_ptr<time_t> const& v =
        o.UpdatedTime;

      bool is_null (true);
      mysql::value_traits<
          ::std::shared_ptr<time_t>,
          mysql::id_timestamp >::set_image (
        i.UpdatedTime_value, is_null, v);
      i.UpdatedTime_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

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

    // UserName
    //
    {
      ::std::string& v =
        o.UserName;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.UserName_value,
        i.UserName_size,
        i.UserName_null);
    }

    // PassWord
    //
    {
      ::std::string& v =
        o.PassWord;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.PassWord_value,
        i.PassWord_size,
        i.PassWord_null);
    }

    // Person
    //
    {
      ::anar::parspark::model::PersonModelPtr& v =
        o.Person;

      typedef object_traits< ::anar::parspark::model::PersonModel > obj_traits;
      typedef odb::pointer_traits< ::anar::parspark::model::PersonModelPtr > ptr_traits;

      if (i.Person_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_value (
          id,
          i.Person_value,
          i.Person_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mysql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }

    // Type
    //
    {
      ::anar::parspark::model::UserType& v =
        o.Type;

      mysql::enum_traits::set_value (
        v,
        i.Type_value,
        i.Type_size,
        i.Type_null);
    }

    // CreatingUser
    //
    {
      ::anar::parspark::model::UserModelPtr& v =
        o.CreatingUser;

      typedef object_traits< ::anar::parspark::model::UserModel > obj_traits;
      typedef odb::pointer_traits< ::anar::parspark::model::UserModelPtr > ptr_traits;

      if (i.CreatingUser_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_value (
          id,
          i.CreatingUser_value,
          i.CreatingUser_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mysql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }

    // UpdatingUser
    //
    {
      ::anar::parspark::model::UserModelPtr& v =
        o.UpdatingUser;

      typedef object_traits< ::anar::parspark::model::UserModel > obj_traits;
      typedef odb::pointer_traits< ::anar::parspark::model::UserModelPtr > ptr_traits;

      if (i.UpdatingUser_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_value (
          id,
          i.UpdatingUser_value,
          i.UpdatingUser_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mysql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }

    // CreatedTime
    //
    {
      ::time_t& v =
        o.CreatedTime;

      mysql::value_traits<
          ::time_t,
          mysql::id_timestamp >::set_value (
        v,
        i.CreatedTime_value,
        i.CreatedTime_null);
    }

    // UpdatedTime
    //
    {
      ::std::shared_ptr<time_t>& v =
        o.UpdatedTime;

      mysql::value_traits<
          ::std::shared_ptr<time_t>,
          mysql::id_timestamp >::set_value (
        v,
        i.UpdatedTime_value,
        i.UpdatedTime_null);
    }
  }

  void access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  const char access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::persist_statement[] =
  "INSERT INTO `user` "
  "(`id`, "
  "`user_name`, "
  "`pass_word`, "
  "`person_id`, "
  "`type`, "
  "`creating_user_id`, "
  "`updating_user_id`, "
  "`created_time`, "
  "`updated_time`) "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::find_statement[] =
  "SELECT "
  "`user`.`id`, "
  "`user`.`user_name`, "
  "`user`.`pass_word`, "
  "`user`.`person_id`, "
  "CONCAT(`user`.`type`+0,' ',`user`.`type`), "
  "`user`.`creating_user_id`, "
  "`user`.`updating_user_id`, "
  "`user`.`created_time`, "
  "`user`.`updated_time` "
  "FROM `user` "
  "WHERE `user`.`id`=?";

  const char access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::update_statement[] =
  "UPDATE `user` "
  "SET "
  "`user_name`=?, "
  "`pass_word`=?, "
  "`person_id`=?, "
  "`type`=?, "
  "`creating_user_id`=?, "
  "`updating_user_id`=?, "
  "`created_time`=?, "
  "`updated_time`=? "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::erase_statement[] =
  "DELETE FROM `user` "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::query_statement[] =
  "SELECT\n"
  "`user`.`id`,\n"
  "`user`.`user_name`,\n"
  "`user`.`pass_word`,\n"
  "`user`.`person_id`,\n"
  "CONCAT(`user`.`type`+0,' ',`user`.`type`),\n"
  "`user`.`creating_user_id`,\n"
  "`user`.`updating_user_id`,\n"
  "`user`.`created_time`,\n"
  "`user`.`updated_time`\n"
  "FROM `user`\n"
  "LEFT JOIN `person` AS `person_id` ON `person_id`.`id`=`user`.`person_id`\n"
  "LEFT JOIN `user` AS `creating_user_id` ON `creating_user_id`.`id`=`user`.`creating_user_id`\n"
  "LEFT JOIN `user` AS `updating_user_id` ON `updating_user_id`.`id`=`user`.`updating_user_id`";

  const char access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::erase_query_statement[] =
  "DELETE FROM `user`";

  const char access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::table_name[] =
  "`user`";

  void access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  void access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  void access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::pointer_type
  access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  bool access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  bool access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  bool access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  result< access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::object_type >
  access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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

  unsigned long long access::object_traits_impl< ::anar::parspark::model::UserModel, id_mysql >::
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
