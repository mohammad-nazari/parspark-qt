/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `person`;

CREATE TABLE `person` (
  `id` BIGINT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  `first_name` VARCHAR(100) NOT NULL CHECK(`first_name` != ''),
  `last_name` VARCHAR(100) NOT NULL CHECK(`last_name` != ''),
  `national_card_number` BIGINT UNSIGNED NULL CHECK(`national_card_number` BETWEEN 1000000000 AND 9999999999),
  `age` TINYINT UNSIGNED NULL CHECK(`age` BETWEEN 1 AND 255),
  `email` VARCHAR(100) NOT NULL CHECK(`email` != ''),
  `address` VARCHAR(500) NULL CHECK(`address` != ''),
  `phone` VARCHAR(12) NULL CHECK(`phone` != ''),
  `mobile` VARCHAR(12) NULL CHECK(`mobile` != ''),
  `picture_address` VARCHAR(1024) NULL CHECK(`picture_address` != ''))
 ENGINE=InnoDB;
