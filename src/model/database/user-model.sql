/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `user`;

CREATE TABLE `user` (
  `id` BIGINT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  `user_name` VARCHAR(100) NOT NULL CHECK(LENGTH(`user_name`) > 6),
  `pass_word` VARCHAR(1024) NOT NULL CHECK(LENGTH(`pass_word`) > 64),
  `person_id` BIGINT UNSIGNED NULL,
  `type` ENUM('admin', 'manager', 'employee') NOT NULL DEFAULT 'employee',
  `creating_user_id` BIGINT UNSIGNED NOT NULL,
  `updating_user_id` BIGINT UNSIGNED NULL,
  `created_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP(),
  `updated_time` timestamp NULL , 
CHECK(`updated_time` > `created_time`)
  /*
  CONSTRAINT `user_creating_user_id_fk`
    FOREIGN KEY (`creating_user_id`)
    REFERENCES `user` (`id`)
  */
  /*
  CONSTRAINT `user_updating_user_id_fk`
    FOREIGN KEY (`updating_user_id`)
    REFERENCES `user` (`id`)
  */)
 ENGINE=InnoDB;

CREATE UNIQUE INDEX `user_name_i`
  ON `user` (`user_name`);

/*
ALTER TABLE `user`
  ADD CONSTRAINT `user_person_id_fk`
    FOREIGN KEY (`person_id`)
    REFERENCES `person` (`id`)
*/
