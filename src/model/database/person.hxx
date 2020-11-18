// person.hxx
//

#ifndef PERSON_HXX
#define PERSON_HXX

#include <string>

#include <odb/core.hxx>     // (1)

#pragma db object           // (2)
class users
{
 public:
	 users(
		 const std::string& username_,
		 const std::string& password_,
		 const std::string& fname_,
		 const std::string& lname_,
		 const std::string& address_,
		 const std::string& phone_)
	  :username_(username_),
		 password_(password_),
		 fname_(fname_),
		 lname_(lname_),
		 address_(address_),
		 phone_(phone_) {};

         unsigned long id() const { return id_; }
         void id(unsigned long id) { id_ = id; }
         const std::string &username() const { return username_; }
         void username(const std::string &username) { username_ = username; }
         const std::string &password() const { return password_; }
         void password(const std::string &password) { password_ = password; }
         const std::string &fname() const { return fname_; }
         void fname(const std::string &fname) { fname_ = fname; }
         const std::string &lname() const { return lname_; }
         void lname(const std::string &lname) { lname_ = lname; }
         const std::string &address() const { return address_; }
         void address(const std::string &address) { address_ = address; }
         const std::string &phone() const { return phone_; }
         void phone(const std::string &phone) { phone_ = phone; }

       private:
	users() {}              // (3)

  friend class odb::access; // (4)

  #pragma db id auto        // (5)
  unsigned long id_;        // (5)

  std::string username_;
  std::string password_;
  std::string fname_;
  std::string lname_;
  std::string address_;
  std::string phone_;
};

#endif // PERSON_HXX