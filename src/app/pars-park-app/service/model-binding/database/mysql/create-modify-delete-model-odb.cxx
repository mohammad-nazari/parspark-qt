// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "create-modify-delete-model-odb.hxx"

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
  // CreateModifyDeleteModel
  //

  const char alias_traits<  ::anar::parspark::model::UserModel,
    id_mysql,
    access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::CreatingUser_tag>::
  table_name[] = "`creating_user_id`";

  const char alias_traits<  ::anar::parspark::model::UserModel,
    id_mysql,
    access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::UpdatingUser_tag>::
  table_name[] = "`updating_user_id`";

  bool access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // CreatingUser
    //
    t[0UL] = 0;

    // UpdatingUser
    //
    t[1UL] = 0;

    // CreatedTime
    //
    t[2UL] = 0;

    // UpdatedTime
    //
    t[3UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

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

  bool access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

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
      ::std::shared_ptr< time_t > const& v =
        o.UpdatedTime;

      bool is_null (true);
      mysql::value_traits<
          ::std::shared_ptr< time_t >,
          mysql::id_timestamp >::set_image (
        i.UpdatedTime_value, is_null, v);
      i.UpdatedTime_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::anar::parspark::model::CreateModifyDeleteModel, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

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
      ::std::shared_ptr< time_t >& v =
        o.UpdatedTime;

      mysql::value_traits<
          ::std::shared_ptr< time_t >,
          mysql::id_timestamp >::set_value (
        v,
        i.UpdatedTime_value,
        i.UpdatedTime_null);
    }
  }
}

#include <odb/post.hxx>