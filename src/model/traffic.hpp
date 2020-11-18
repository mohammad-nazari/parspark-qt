#ifndef ANAR_TRAFFIC_HPP
#define ANAR_TRAFFIC_HPP

#include "base-model.hpp"
#include "user.hpp"

namespace anar::model {
   namespace TrafficType {
      constexpr char SUBSCRIBED[] = "";
      constexpr char PUBLIC[] = "";
   };  // namespace TrafficType

   class TrafficSection;
   using TrafficSectionPtr = std::shared_ptr<TrafficSection>;
   class TrafficSection : public BaseModel {
     public:
      static TrafficSectionPtr Create();
      TrafficSection();

      [[nodiscard]] const std::string& License() const {
         return m_license;
      }
      void License(const std::string& license) {
         m_license = license;
      }
      [[nodiscard]] uint64_t Time() const {
         return m_time;
      }
      void Time(uint64_t time) {
         m_time = time;
      }
      [[nodiscard]] const std::string& PictureAddress() const {
         return m_pictureAddress;
      }
      void PictureAddress(const std::string& pictureAddress) {
         m_pictureAddress = pictureAddress;
      }
      [[nodiscard]] const std::string& Picture() const {
         return m_picture;
      }
      void Picture(const std::string& picture) {
         m_picture = picture;
      }
      [[nodiscard]] const UserPtr& User() const {
         return m_user;
      }
      void User(const UserPtr& user) {
         m_user = user;
      }

     private:
      std::string m_license;
      uint64_t m_time{0};
      std::string m_pictureAddress;
      std::string m_picture;  // Base64
      UserPtr m_user;
   };

   class Traffic;
   using TrafficPtr = std::shared_ptr<Traffic>;
   class Traffic : public BaseModel {
     public:
      static TrafficPtr Create();
      Traffic();

     private:
      std::string m_code;  // FRID card number
      uint32_t m_cost{0};
      std::string m_type{TrafficType::PUBLIC};
      TrafficSectionPtr m_enter;
      TrafficSectionPtr m_exit;
   };
}  // namespace anar::model
#endif  // ANAR_TRAFFIC_HPP
