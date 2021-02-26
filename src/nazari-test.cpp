#include "nazari-test.hpp"

#include <iostream>
#include <vector>

#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/MySQL/MySQLException.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/FileStream.h"

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

namespace anar::test {
   void NazariTest::TestPocoReadAndWrite() {
      Poco::FileStream oFileStream;
      oFileStream.open("test.txt", std::ios::out);
      oFileStream.write("Test1\n", 6);
      oFileStream.write("Test2\n", 6);
      oFileStream.write("Test3\n", 6);
      oFileStream.close();
      char str[50];
      Poco::FileStream iFileStream;
      iFileStream.open("test.txt", std::ios::out);
      iFileStream.getline(str, sizeof(str));
      std::cout << str << std::endl;
      iFileStream.getline(str, sizeof(str));
      std::cout << str << std::endl;
      iFileStream.getline(str, sizeof(str));
      std::cout << str << std::endl;
      iFileStream.close();
   }
   void NazariTest::TestPocoMySQL() {
      Poco::Data::MySQL::Connector::registerConnector();
//      try {
//         std::string str = "host=localhost;user=root;password=mypassword;compress=true;auto-reconnect=true";
//         Poco::Data::Session test(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY, str));
//      } catch (Poco::Data::MySQL::ConnectionException& e) {
//         std::cout << e.what() << std::endl;
//         return;
//      } catch (Poco::Data::MySQL::StatementException& e) {
//         std::cout << e.what() << std::endl;
//         return;
//      }

      // register SQLite connector
      Poco::Data::SQLite::Connector::registerConnector();

      // create a session
//      Session session("SQLite", "sample.db");

      // drop sample table, if it exists
//      session << "DROP TABLE IF EXISTS Person", now;

      // (re)create table
//      session << "CREATE TABLE Person (Name VARCHAR(30), Address VARCHAR, Age INTEGER(3))", now;

      // insert some rows
//      Person person = {"Bart Simpson", "Springfield", 12};

//      Statement insert(session);
//      insert << "INSERT INTO Person VALUES(?, ?, ?)", use(person.name), use(person.address), use(person.age);

//      insert.execute();

//      person.name = "Lisa Simpson";
//      person.address = "Springfield";
//      person.age = 10;

//      insert.execute();

      // a simple query
//      Statement select(session);
//      select << "SELECT Name, Address, Age FROM Person", into(person.name), into(person.address), into(person.age), range(0, 1);  //  iterate over result set one row at a time

//      while (!select.done()) {
//         select.execute();
//         std::cout << person.name << " " << person.address << " " << person.age << std::endl;
//      }
   }
}  // namespace anar