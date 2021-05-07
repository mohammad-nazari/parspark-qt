#ifndef ANAR_TRAITS_MYSQL_HXX
#define ANAR_TRAITS_MYSQL_HXX

#include "Poco/DateTime.h"
//#include "model/database/user-model.hxx"
#include "odb/mysql/traits.hxx"

namespace odb {
   namespace mysql {
      template <>
      class value_traits<time_t, id_timestamp> {
        public:
         typedef time_t value_type;
         typedef time_t query_type;
         typedef MYSQL_TIME image_type;

         static void set_value(time_t &v, const MYSQL_TIME &i, bool is_null) {
            if (!is_null) {
               v = Poco::DateTime(i.year, i.month, i.day, i.hour, i.minute, i.second, i.second_part / 1000, i.second_part % 1000).timestamp().raw();
            } else {
               v = 0;
            }
         }

         static void set_image(MYSQL_TIME &i, bool &is_null, const time_t &v) {
            is_null = false;
            i.neg = false;
            Poco::DateTime dateTime((Poco::Timestamp(v)));
            i.year = dateTime.year();
            i.month = dateTime.month();
            i.day = dateTime.day();
            i.hour = dateTime.hour();
            i.minute = dateTime.minute();
            i.second = dateTime.second();
            i.second_part = (dateTime.millisecond() * 10) + dateTime.microsecond();
         }
      };

      template <>
      class value_traits<std::shared_ptr<time_t>, id_timestamp> {
        public:
         typedef std::shared_ptr<time_t> value_type;
         typedef std::shared_ptr<time_t> query_type;
         typedef MYSQL_TIME image_type;

         static void set_value(std::shared_ptr<time_t> &v, const MYSQL_TIME &i, bool is_null) {
            if (!is_null)
               *v = Poco::DateTime(i.year, i.month, i.day, i.hour, i.minute, i.second, i.second_part / 1000, i.second_part % 1000).timestamp().raw();
            else
               v = nullptr;
         }

         static void set_image(MYSQL_TIME &i, bool &is_null, const std::shared_ptr<time_t> &v) {
            is_null = false;
            i.neg = false;
            Poco::DateTime dateTime((Poco::Timestamp(*v)));
            i.year = dateTime.year();
            i.month = dateTime.month();
            i.day = dateTime.day();
            i.hour = dateTime.hour();
            i.minute = dateTime.minute();
            i.second = dateTime.second();
            i.second_part = (dateTime.millisecond() * 1000) + dateTime.microsecond();
         }
      };
   }  // namespace mysql
}  // namespace odb

#endif  // ANAR_TRAITS_MYSQL_HXX
