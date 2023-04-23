// This code was generated by CLI, a command line interface
// compiler for C++.
//

// Begin prologue.
//
//
// End prologue.

namespace odb
{
  namespace oracle
  {
    namespace details
    {
      namespace cli
      {
        // unknown_mode
        //
        inline unknown_mode::
        unknown_mode (value v)
        : v_ (v)
        {
        }

        // exception
        //
        inline ::std::ostream&
        operator<< (::std::ostream& os, const exception& e)
        {
          e.print (os);
          return os;
        }

        // unknown_option
        //
        inline unknown_option::
        unknown_option (const std::string& option)
        : option_ (option)
        {
        }

        inline const std::string& unknown_option::
        option () const
        {
          return option_;
        }

        // unknown_argument
        //
        inline unknown_argument::
        unknown_argument (const std::string& argument)
        : argument_ (argument)
        {
        }

        inline const std::string& unknown_argument::
        argument () const
        {
          return argument_;
        }

        // missing_value
        //
        inline missing_value::
        missing_value (const std::string& option)
        : option_ (option)
        {
        }

        inline const std::string& missing_value::
        option () const
        {
          return option_;
        }

        // invalid_value
        //
        inline invalid_value::
        invalid_value (const std::string& option,
                       const std::string& value)
        : option_ (option),  value_ (value)
        {
        }

        inline const std::string& invalid_value::
        option () const
        {
          return option_;
        }

        inline const std::string& invalid_value::
        value () const
        {
          return value_;
        }

        // file_io_failure
        //
        inline file_io_failure::
        file_io_failure (const std::string& file)
        : file_ (file)
        {
        }

        inline const std::string& file_io_failure::
        file () const
        {
          return file_;
        }

        // unmatched_quote
        //
        inline unmatched_quote::
        unmatched_quote (const std::string& argument)
        : argument_ (argument)
        {
        }

        inline const std::string& unmatched_quote::
        argument () const
        {
          return argument_;
        }

        // argv_scanner
        //
        inline argv_scanner::
        argv_scanner (int& argc, char** argv, bool erase)
        : i_ (1), argc_ (argc), argv_ (argv), erase_ (erase)
        {
        }

        inline argv_scanner::
        argv_scanner (int start, int& argc, char** argv, bool erase)
        : i_ (start), argc_ (argc), argv_ (argv), erase_ (erase)
        {
        }

        inline int argv_scanner::
        end () const
        {
          return i_;
        }

        // argv_file_scanner
        //
        inline argv_file_scanner::
        argv_file_scanner (int& argc,
                           char** argv,
                           const std::string& option,
                           bool erase)
        : argv_scanner (argc, argv, erase),
          option_ (option),
          options_ (&option_info_),
          options_count_ (1),
          skip_ (false)
        {
          option_info_.option = option_.c_str ();
          option_info_.search_func = 0;
        }

        inline argv_file_scanner::
        argv_file_scanner (int start,
                           int& argc,
                           char** argv,
                           const std::string& option,
                           bool erase)
        : argv_scanner (start, argc, argv, erase),
          option_ (option),
          options_ (&option_info_),
          options_count_ (1),
          skip_ (false)
        {
          option_info_.option = option_.c_str ();
          option_info_.search_func = 0;
        }

        inline argv_file_scanner::
        argv_file_scanner (int& argc,
                           char** argv,
                           const option_info* options,
                           std::size_t options_count,
                           bool erase)
        : argv_scanner (argc, argv, erase),
          options_ (options),
          options_count_ (options_count),
          skip_ (false)
        {
        }

        inline argv_file_scanner::
        argv_file_scanner (int start,
                           int& argc,
                           char** argv,
                           const option_info* options,
                           std::size_t options_count,
                           bool erase)
        : argv_scanner (start, argc, argv, erase),
          options_ (options),
          options_count_ (options_count),
          skip_ (false)
        {
        }
      }
    }
  }
}

namespace odb
{
  namespace oracle
  {
    namespace details
    {
      // options
      //

      inline const std::string& options::
      user () const
      {
        return this->user_;
      }

      inline bool options::
      user_specified () const
      {
        return this->user_specified_;
      }

      inline const std::string& options::
      password () const
      {
        return this->password_;
      }

      inline bool options::
      password_specified () const
      {
        return this->password_specified_;
      }

      inline const std::string& options::
      database () const
      {
        return this->database_;
      }

      inline bool options::
      database_specified () const
      {
        return this->database_specified_;
      }

      inline const std::string& options::
      service () const
      {
        return this->service_;
      }

      inline bool options::
      service_specified () const
      {
        return this->service_specified_;
      }

      inline const std::string& options::
      host () const
      {
        return this->host_;
      }

      inline bool options::
      host_specified () const
      {
        return this->host_specified_;
      }

      inline const unsigned int& options::
      port () const
      {
        return this->port_;
      }

      inline bool options::
      port_specified () const
      {
        return this->port_specified_;
      }

      inline const std::string& options::
      options_file () const
      {
        return this->options_file_;
      }

      inline bool options::
      options_file_specified () const
      {
        return this->options_file_specified_;
      }
    }
  }
}

// Begin epilogue.
//
//
// End epilogue.
