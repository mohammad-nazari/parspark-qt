/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `car`;

CREATE TABLE `car` (
  `creating_user_id` BIGINT UNSIGNED NOT NULL,
  `updating_user_id` BIGINT UNSIGNED NULL,
  `created_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP(),
  `updated_time` timestamp NULL , 
CHECK(`updated_time` > `created_time`),
  `id` BIGINT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  `plate_number_en` VARCHAR(20) NOT NULL CHECK(`plate_number_en` != ''),
  `driver_id` BIGINT UNSIGNED NULL,
  `person_id` BIGINT UNSIGNED NULL,
  `picture_address` VARCHAR(1024) NULL CHECK(`picture_address` != ''))
 ENGINE=InnoDB;

ALTER TABLE `car`
  ADD CONSTRAINT `car_creating_user_id_fk`
    FOREIGN KEY (`creating_user_id`)
    REFERENCES `user` (`id`),
  ADD CONSTRAINT `car_updating_user_id_fk`
    FOREIGN KEY (`updating_user_id`)
    REFERENCES `user` (`id`),
  ADD CONSTRAINT `car_driver_id_fk`
    FOREIGN KEY (`driver_id`)
    REFERENCES `driver` (`id`),
  ADD CONSTRAINT `car_person_id_fk`
    FOREIGN KEY (`person_id`)
    REFERENCES `organization` (`id`)

