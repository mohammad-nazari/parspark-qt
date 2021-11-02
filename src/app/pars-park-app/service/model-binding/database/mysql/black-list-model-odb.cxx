// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "black-list-model-odb.hxx"

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
  // BlackListModel
  //

  struct access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::extra_statement_cache_type
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

  access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::id_type
  access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::id_type
  access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  bool access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // CreateModifyDeleteModel base
    //
    if (object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::grow (
          i, t + 0UL))
      grew = true;

    // Id
    //
    t[4UL] = 0;

    // PlateNumberEn
    //
    if (t[5UL])
    {
      i.PlateNumberEn_value.capacity (i.PlateNumberEn_size);
      grew = true;
    }

    // Description
    //
    if (t[6UL])
    {
      i.Description_value.capacity (i.Description_size);
      grew = true;
    }

    return grew;
  }

  void access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // CreateModifyDeleteModel base
    //
    object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::bind (b + n, i, sk);
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

    // PlateNumberEn
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.PlateNumberEn_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.PlateNumberEn_value.capacity ());
    b[n].length = &i.PlateNumberEn_size;
    b[n].is_null = &i.PlateNumberEn_null;
    n++;

    // Description
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.Description_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.Description_value.capacity ());
    b[n].length = &i.Description_size;
    b[n].is_null = &i.Description_null;
    n++;
  }

  void access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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
    if (object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::init (i, o, sk))
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

    // PlateNumberEn
    //
    {
      ::std::string const& v =
        o.PlateNumberEn;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.PlateNumberEn_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.PlateNumberEn_value,
        size,
        is_null,
        v);
      i.PlateNumberEn_null = is_null;
      i.PlateNumberEn_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.PlateNumberEn_value.capacity ());
    }

    // Description
    //
    {
      ::std::string const& v =
        o.Description;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.Description_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.Description_value,
        size,
        is_null,
        v);
      i.Description_null = is_null;
      i.Description_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.Description_value.capacity ());
    }

    return grew;
  }

  void access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // CreateModifyDeleteModel base
    //
    object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::init (o, i, db);

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

    // PlateNumberEn
    //
    {
      ::std::string& v =
        o.PlateNumberEn;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.PlateNumberEn_value,
        i.PlateNumberEn_size,
        i.PlateNumberEn_null);
    }

    // Description
    //
    {
      ::std::string& v =
        o.Description;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.Description_value,
        i.Description_size,
        i.Description_null);
    }
  }

  void access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  const char access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::persist_statement[] =
  "INSERT INTO `black_list` "
  "(`creating_user_id`, "
  "`updating_user_id`, "
  "`created_time`, "
  "`updated_time`, "
  "`id`, "
  "`plate_number_en`, "
  "`description`) "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::find_statement[] =
  "SELECT "
  "`black_list`.`creating_user_id`, "
  "`black_list`.`updating_user_id`, "
  "`black_list`.`created_time`, "
  "`black_list`.`updated_time`, "
  "`black_list`.`id`, "
  "`black_list`.`plate_number_en`, "
  "`black_list`.`description` "
  "FROM `black_list` "
  "WHERE `black_list`.`id`=?";

  const char access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::update_statement[] =
  "UPDATE `black_list` "
  "SET "
  "`creating_user_id`=?, "
  "`updating_user_id`=?, "
  "`created_time`=?, "
  "`updated_time`=?, "
  "`plate_number_en`=?, "
  "`description`=? "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::erase_statement[] =
  "DELETE FROM `black_list` "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::query_statement[] =
  "SELECT\n"
  "`black_list`.`creating_user_id`,\n"
  "`black_list`.`updating_user_id`,\n"
  "`black_list`.`created_time`,\n"
  "`black_list`.`updated_time`,\n"
  "`black_list`.`id`,\n"
  "`black_list`.`plate_number_en`,\n"
  "`black_list`.`description`\n"
  "FROM `black_list`\n"
  "LEFT JOIN `user` AS `creating_user_id` ON `creating_user_id`.`id`=`black_list`.`creating_user_id`\n"
  "LEFT JOIN `user` AS `updating_user_id` ON `updating_user_id`.`id`=`black_list`.`updating_user_id`";

  const char access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::erase_query_statement[] =
  "DELETE FROM `black_list`";

  const char access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::table_name[] =
  "`black_list`";

  void access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  void access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  void access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::pointer_type
  access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  bool access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  bool access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  bool access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  result< access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::object_type >
  access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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

  unsigned long long access::object_traits_impl< ::anar::parspark::model::BlackListModel, id_mysql >::
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
