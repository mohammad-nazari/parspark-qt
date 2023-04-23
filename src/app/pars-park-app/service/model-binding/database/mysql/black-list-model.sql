/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `black_list`;

CREATE TABLE `black_list` (
  `creating_user_id` BIGINT UNSIGNED NOT NULL,
  `updating_user_id` BIGINT UNSIGNED NULL,
  `created_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP(),
  `updated_time` timestamp NULL , 
CHECK(`updated_time` > `created_time`),
  `id` BIGINT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  `plate_number_en` VARCHAR(20) NOT NULL CHECK(`plate_number_en` != ''),
  `description` VARCHAR(4096) NOT NULL CHECK(`description` != ''))
 ENGINE=InnoDB;


ALTER TABLE `black_list`
  ADD CONSTRAINT `black_list_creating_user_id_fk`
    FOREIGN KEY (`creating_user_id`)
    REFERENCES `user` (`id`),
  ADD CONSTRAINT `black_list_updating_user_id_fk`
    FOREIGN KEY (`updating_user_id`)
    REFERENCES `user` (`id`)


